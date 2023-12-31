#include <iostream>
#include <box2d/box2d.h>

int main() {
    //Creacion del mundo y de la gravedad
    b2Vec2 gravity(0.0f, -9.81f);
    b2World world(gravity);

    //Creacion de las caracteristicas del piso
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0.0f, -10.0f);

    //Creamos el piso
    b2Body*groundBody = world.CreateBody(&groundBodyDef);

    //Crear la forma del piso
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50,1);

    groundBody->CreateFixture(&groundBox, 0.0f);

    //Triangulo===============================================
    b2Vec2 verTr[3];
    verTr[0].Set(0.0f, 1.0f);
    verTr[1].Set(0.0f, 0.0f);
    verTr[2].Set(1.0f, 0.0f);

    b2BodyDef bodyDefTR;
    bodyDefTR.type = b2_dynamicBody;
    bodyDefTR.position.Set(0.0f, 5.0);

    b2Body* bodyTR = world.CreateBody(&bodyDefTR);

    b2PolygonShape trianguloRect;
    trianguloRect.Set(verTr, 3);

    b2FixtureDef fixtureTR;
    fixtureTR.shape = &trianguloRect;
    fixtureTR.density = 1.0f;
    fixtureTR.friction = 0.3f;

    bodyTR ->CreateFixture(&fixtureTR);

    //Cuadrado ===============================================
    b2Vec2 verCuad[4];
    verCuad[0].Set(2.5f, 1.0f);
    verCuad[1].Set(1.5f, 1.0f);
    verCuad[2].Set(1.5f, 0.0f);
    verCuad[3].Set(0.0f, 2.5f);

    b2BodyDef bodyDefCuad;
    bodyDefCuad.type = b2_dynamicBody;
    bodyDefCuad.position.Set(5.0f, 5.0);

    b2Body* bodyCuad = world.CreateBody(&bodyDefCuad);

    b2PolygonShape cuadrado;
    cuadrado.Set(verCuad, 4);

    b2FixtureDef fixtureCuad;
    fixtureCuad.shape = &cuadrado;
    fixtureCuad.density = 1.0f;
    fixtureCuad.friction = 0.3f;

    bodyCuad ->CreateFixture(&fixtureCuad);

    //Pentagono ===============================================
    b2Vec2 verPen[5];
    verPen[0].Set(3.0f, 0.6f);
    verPen[1].Set(2.8f, 0.4f);
    verPen[2].Set(0.0f, 3.0f);
    verPen[3].Set(0.0f, 3.4f);
    verPen[4].Set(3.6f, 0.4f);

    b2BodyDef bodyDefPen;
    bodyDefPen.type = b2_dynamicBody;
    bodyDefPen.position.Set(10.0f, 5.0);

    b2Body* bodyPen = world.CreateBody(&bodyDefPen);

    b2PolygonShape pentagono;
    pentagono.Set(verPen, 5);

    b2FixtureDef fixturePen;
    fixturePen.shape = &pentagono;
    fixturePen.density = 1.0f;
    fixturePen.friction = 0.3f;

    bodyPen ->CreateFixture(&fixturePen);

    //Hexagono ===============================================
    b2Vec2 verHex[6];
    verHex[0].Set(5.0f, 0.8f);
    verHex[1].Set(4.6f, 0.6f);
    verHex[2].Set(4.6f, 0.2f);
    verHex[3].Set(5.0f, 0.0f);
    verHex[4].Set(5.4f, 0.2f);
    verHex[5].Set(5.4f, 0.6f);

    b2BodyDef bodyDefHex;
    bodyDefHex.type = b2_dynamicBody;
    bodyDefHex.position.Set(15.0f, 5.0);

    b2Body* bodyHex = world.CreateBody(&bodyDefHex);

    b2PolygonShape hexagono;
    hexagono.Set(verHex, 6);

    b2FixtureDef fixtureHex;
    fixtureHex.shape = &hexagono;
    fixtureHex.density = 1.0f;
    fixtureHex.friction = 0.3f;

    bodyHex ->CreateFixture(&fixtureHex);

    //Octagono ===============================================
    b2Vec2 verOct[8];
    verOct[0].Set(6.5f, 0.8f);
    verOct[1].Set(6.1f, 0.8f);
    verOct[2].Set(5.9f, 0.6f);
    verOct[3].Set(5.9f, 0.2f);
    verOct[4].Set(6.1f, 0.0f);
    verOct[5].Set(6.5f, 0.0f);
    verOct[6].Set(6.7f, 0.2f);
    verOct[7].Set(6.7f, 0.6f);

    b2BodyDef bodyDefOct;
    bodyDefOct.type = b2_dynamicBody;
    bodyDefOct.position.Set(20.0f, 5.0);

    b2Body* bodyOct = world.CreateBody(&bodyDefOct);

    b2PolygonShape Octagono;
    Octagono.Set(verOct, 8);

    b2FixtureDef fixtureOct;
    fixtureOct.shape = &Octagono;
    fixtureOct.density = 1.0f;
    fixtureOct.friction = 0.3f;

    bodyOct ->CreateFixture(&fixtureOct);

    //Octagono ===============================================

    float timeStep = 1.0f/60.0f;

    int32 velocityIterations = 6;
    int32 positionIteration = 2;

    for (int32 i = 0; i < 60; ++i) {
        world.Step(timeStep, velocityIterations, positionIteration);

        b2Vec2 positionTR = bodyTR->GetPosition();
        float angleTR = bodyTR->GetAngle();
        printf("Triangulo %4.2f %4.2f %4.2f\n", positionTR.x,positionTR.y,angleTR);

        b2Vec2 positionCuad = bodyCuad->GetPosition();
        float angleCuad = bodyCuad->GetAngle();
        printf("Cuadrado %4.2f %4.2f %4.2f\n", positionCuad.x,positionCuad.y,angleCuad);


        b2Vec2 positionPen = bodyPen->GetPosition();
        float anglePen = bodyPen->GetAngle();
        printf("Pentagono %4.2f %4.2f %4.2f\n", positionPen.x,positionPen.y,anglePen);

        b2Vec2 positionHex = bodyHex->GetPosition();
        float angleHex = bodyHex->GetAngle();
        printf("Hexagono %4.2f %4.2f %4.2f\n", positionHex.x,positionHex.y,angleHex);

        b2Vec2 positionOct = bodyOct->GetPosition();
        float angleOct = bodyOct->GetAngle();
        printf("Octagono %4.2f %4.2f %4.2f\n", positionOct.x,positionOct.y,angleOct);


    }

}
