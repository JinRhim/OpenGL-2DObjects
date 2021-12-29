//
//  planets.hpp
//  planet_rotation
//
//  Created by Jin Chul Rhim on 10/28/21.
//

#ifndef planets_hpp
#define planets_hpp
#include "colors.h"
#include <stdio.h>
#include "glPlatform.h"


class Planet {
protected:
    float radius_, orbitalRadius_;
    ColorCode orbitalColor_;
    ColorCode fillcolor_;
    bool planetRing_;
    ColorCode ringColor_;
    bool extraDecor_;
    bool satellite_;
    
public:
    Planet(float radius, float orbitalRadius, ColorCode orbitalColor, ColorCode fillcolor, bool PlanetRing, ColorCode ringColor, bool extraDecor, bool satellite);
    ~Planet(void);
    void draw(void) const;

};



#endif /* plan*ets_hpp */
