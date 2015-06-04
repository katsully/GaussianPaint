//
//  PaintSpot.h
//  RandomProject
//
//  Created by Kathleen Sullivan on 5/29/15.
//
//

#include "cinder/Perlin.h"
#include <vector>

using namespace ci;
using namespace std;

class PaintSpot {
    public:
        PaintSpot();
        PaintSpot( float, float );
        void createVectors();
        void render();
    
        ci::Color mColor;
        float noiseCount;
        Vec2f mMouseLoc;
        Vec2f mNOff;
    
        std::vector<ci::Vec2f> mVectors;
        ci::Perlin mPerlin;
};