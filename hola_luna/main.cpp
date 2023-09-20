#include <iostream>
#include <box2d/box2d.h>

int main() {

    //Creacion del mundo y de la gravedad
    b2Vec2 gravity(0.0f, -1.62f);
    b2World world(gravity);

    //===========SUELO========================================
    //Creacion de las caracteristicas del suelo
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    //Creamos el suelo
    b2Body*groundBody = world.CreateBody(&groundBodyDef);

    //Crear su forma del suelo
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50,1);

    groundBody->CreateFixture(&groundBox, 0.0f);//propiedades fisicas del suelo

    //===========OBJETO=======================================
    //Creacion de las caracteristicas de la caja
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody; //definicion de un objeto dinamico porque se va a mover
    bodyDef.position.Set(0.0f, 20.0); //posicion del objeto

    b2Body* body = world.CreateBody(&bodyDef); //instanciar el objeto

    b2PolygonShape dynamicBox; //darle propiedad de poligono
    dynamicBox.SetAsBox(1.0f, 1.0f); //darle forma de caja al objeto

    b2FixtureDef fixtureDef; //definicion del fixture, el cual ya cuenta con propiedades
    fixtureDef.shape = &dynamicBox; //forma de caja
    fixtureDef.density = 1.0f; //densidad
    fixtureDef.friction = 0.03f; //friccion menor porque está en la luna

    body ->CreateFixture(&fixtureDef);

    float timeStep = 1.0f/60.0f;

    int32 velocityIterations = 6;
    int32 positionIteration = 2;

    //Ciclo for para tomar las coordenadas del objeto cayendo a 60 iteraciones por segundo
    for (int32 i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIterations, positionIteration); //mueve las iteraciones del paso del tiempo en el mundo
        b2Vec2 position = body->GetPosition(); //obtiene la posicion en x y y del objeto, x no cambia
        float angle = body->GetAngle(); //obtiene el angulo del objeto cayendo
        printf("%4.2f %4.2f %4.2f\n", position.x,position.y,angle);//imprime coordenadas de la caja cayendo
    }

}
