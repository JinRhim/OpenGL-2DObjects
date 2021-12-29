#include <iostream>
#include <cmath>
#include <vector>
#include <cmath>
#include <math.h>
#include <iomanip>
#include "planets.hpp"


Planet::Planet(float radius, float orbitalRadius, ColorCode orbitalColor, ColorCode fillcolor, bool PlanetRing, ColorCode ringColor, bool extraDecor, bool satellite)
{
    radius_ = radius;
    orbitalRadius_ = orbitalRadius;
    orbitalColor_ = orbitalColor;
    fillcolor_ = fillcolor;
    planetRing_ = PlanetRing;
    ringColor_ = ringColor;
    extraDecor_ = extraDecor;
    satellite_ = satellite;
}

Planet::~Planet(void) {
    
}


void Planet::draw(void) const {
    
    glColor3f(COLOR[orbitalColor_][0], COLOR[orbitalColor_][1], COLOR[orbitalColor_][2]);
    glBegin(GL_LINES);
    for (int i = 0; i < 200; i++) {
        glVertex2f(orbitalRadius_*sinf(M_PI/100*i),orbitalRadius_*cosf(M_PI/100*i));
    }
    glEnd();
    
    glTranslatef(orbitalRadius_, 0.0f, 0.0f);
    
    if (extraDecor_) {
        glColor3f(COLOR[ringColor_][0], COLOR[ringColor_][1], COLOR[ringColor_][2]);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 20; i++) {
            glVertex2f(radius_*0.1*sinf(M_PI/180*90+M_PI/180*120*i), radius_*0.1*cosf(M_PI/180*90+M_PI/180*120*i));
        }
        glEnd();
    }
    
    
    glColor3f(COLOR[fillcolor_][0], COLOR[fillcolor_][1], COLOR[fillcolor_][2]);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 500; i++) {
        glVertex2f(radius_*sinf(M_PI/250*i), radius_*cosf(M_PI/250*i));
    }
    glEnd();
    
    if (planetRing_) {
        glRotatef(0.1f, 0.f, 0.f, 1.f);
        glBegin(GL_LINES);
        glColor3f(COLOR[ringColor_][0], COLOR[ringColor_][1], COLOR[ringColor_][2]);
        for (int i = 0; i < 500; i++) {
            glVertex2f(radius_*0.5*sinf(M_PI/250*i), 2*radius_*cosf(M_PI/250*i));
        }
        glEnd();
        
    }
    
    if (satellite_) {
        glColor3f(COLOR[ringColor_][0], COLOR[ringColor_][1], COLOR[ringColor_][2]);
        glBegin(GL_LINES);
        for (int i = 0; i < 200; i++) {
            glVertex2f(radius_*3*sinf(M_PI/100*i), radius_*3*cosf(M_PI/100*i));
        }
        glEnd();
        glTranslatef(radius_*3, 0.0f, 0.0f);
        glRotatef(0.1f, 0.0f, 0.0f, 1.0f);
        glBegin(GL_POLYGON);
        for (int i = 0; i < 500; i++) {
            glVertex2f(radius_*0.3*sinf(M_PI/100*i),radius_*0.3*cosf(M_PI/100*i));
        }
        glEnd();
        
    }
    
    
}
