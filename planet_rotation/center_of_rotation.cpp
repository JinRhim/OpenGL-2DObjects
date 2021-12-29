#include <stdlib.h>
#include <cstdlib>
#include <stdio.h>
#include "glPlatform.h"
#include <cmath>
#include "math.h"
#include <iostream>
#include <iomanip>
#include "planets.hpp"

void myIdleFunc(void);
using namespace std;


float gTheta = 0.f;


Planet p1 = Planet(0.04f, 0.0f,kWHITE, kRED, false, kYELLOW, true, false);
Planet p2 = Planet(0.01f,0.1f, kWHITE, kBLUE, true, kThistle, false, false);
Planet p3 = Planet(0.02f, 0.2f, kWHITE, kYELLOW, true, kTurquoise, false, false);
Planet p4 = Planet(0.03f, 0.4f, kWHITE, kGREEN, false, kWHITE, false, true);

//Planet(float radius, float orbitalRadius, ColorCode orbitalColor, ColorCode fillcolor, bool PlanetRing, ColorCode ringColor, bool extraDecor);

void myDisplayFunc(void)
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.f);
    p1.draw();
    glPopMatrix();
    
    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.f);
    glRotatef(gTheta, 0.f, 0.f, 1.f);
    p2.draw();
    glPopMatrix();
    
    
    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.f);
    glRotatef(gTheta*1.3, 0.f, 0.f, 1.f);
    p3.draw();
    glPopMatrix(); 
    
    glPushMatrix();
    glTranslatef(0.5f, 0.5f, 0.f);
    glRotatef(gTheta*1.6, 0.f, 0.f, 1.f);
    p4.draw();
    glPopMatrix();
    
    glutSwapBuffers();
}

void myKeyboardFunc(unsigned char c, int x, int y)
{
    switch (c)
    {
        case 27:
            exit(0);
            break;
            
        case 'q':
            exit(0);
            break;
        default:
            break;
    }
}

void myIdleFunc(void)
{
    //    At each tick, I just increment the value of theta.s
    gTheta += 0.2f;
    
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    
    //    Initialize glut and create a new window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1000, 1500);
    glutInitWindowPosition(100, 40);
    glutCreateWindow(argv[0]);
    
    //    set up the callbacks
    glutDisplayFunc(myDisplayFunc);
    glutKeyboardFunc(myKeyboardFunc);
    glutIdleFunc(myIdleFunc);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);

    //    we set up earlier will be called when the corresponding event
    //    occurs
    glutMainLoop();

    //    This will never be executed (the exit point will be in one of the
    //    call back functions).
    return 0;
}
