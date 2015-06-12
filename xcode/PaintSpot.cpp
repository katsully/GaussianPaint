//
//  PaintSpot.cpp
//  RandomProject
//
//  Created by Kathleen Sullivan on 5/29/15.
//
//

#include "PaintSpot.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"

using namespace ci;

PaintSpot::PaintSpot(){
}

PaintSpot::PaintSpot( Vec2f mMousePosition ){
    mMouseLoc = mMousePosition;
    mNOff = Vec2f ( randFloat( 1000 ), randFloat( 1000 ) );
    mColor = Color ( CM_HSV, randFloat(), 1, 1  );
    noiseCount = randFloat( 1000.0f );
    mPerlin = Perlin();
}

void PaintSpot::createVectors(){
    mVectors.clear();
    Vec2f newPoint;
    for(int i = 0; i < 100; i++){
        newPoint.x = lmap( mPerlin.fBm(mNOff.x), -0.5f, 0.5f, -200.0f, 200.0f );
        newPoint.y = lmap( mPerlin.fBm(mNOff.y), -0.5f, 0.5f, -200.0f, 200.0f );
        mVectors.push_back( newPoint + mMouseLoc);
        mNOff += Vec2f( 0.01, 0.01 );

    }
}

void PaintSpot::render(){
    gl::color( Color( mColor) );
    glBegin( GL_POLYGON );
    for( int i = 0; i < mVectors.size(); i++ ){
        gl::vertex( mVectors[i] );
    }
    glEnd();

}

