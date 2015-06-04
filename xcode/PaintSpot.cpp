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

PaintSpot::PaintSpot( float mMouseX, float mMouseY ){
    mMouseLoc = Vec2f( mMouseX, mMouseY);
    mNOff = Vec2f ( randFloat( 1000 ), randFloat( 1000 ) );
    mColor = Color ( CM_HSV, randFloat(), 1, 1  );
    noiseCount = randFloat( 1000.0f );
}

void PaintSpot::createVectors(){
    mVectors.clear();
//    float x;
//    float y;
//    for( int i = 0; i < 20; i++ ){
//        if( i < 5 ){
//            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, mMouseLoc.x, mMouseLoc.x + 75.0f );
//            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, mMouseLoc.y, mMouseLoc.y + 75.0f );
//        } else if (i >= 5 && i < 10 ){
//            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, mMouseLoc.x, mMouseLoc.x + 75.0f );
//            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, 0.0f, abs( mMouseLoc.y - 75.0f ) );
//        } else if ( i >= 10 && i < 15 ){
//            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, 0.0f, abs( mMouseLoc.x - 75.0f ) );
//            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, 0.0f, abs( mMouseLoc.y - 75.0f ) );
//        } else {
//            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, 0.0f, abs( mMouseLoc.x - 75.0f ) );
//            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, mMouseLoc.y, mMouseLoc.y + 75.0f );
//        }
//        mVectors.push_back( Vec2f( x, y ) );
//        mNOff += Vec2f( 5.0f, 5.0f );
//    }
    int radius = 150;
    float numPoints = 100.0f;
    float pointDegree = 300 / numPoints;
    for( int i=0; i < numPoints; i++ ){
        float x = cos( pointDegree * i) * radius;
        float y = sin( pointDegree * i) * radius;
        float n = mPerlin.noise( noiseCount ) * 20;
        mVectors.push_back( Vec2f( x + n + mMouseLoc.x, y + n + mMouseLoc.y ) );
        noiseCount += 2.0f;
    }


}

void PaintSpot::render(){
//    gl::color(Color ( mColor ) );
//    glBegin( GL_POLYGON );
//    for(int i=0; i<20; i++){
//        gl::vertex( mVectors[i] );
//    }
//    glEnd();

    gl::color( Color( mColor) );
    glBegin( GL_POLYGON );
    for( int i = 0; i < mVectors.size(); i++ ){
        gl::vertex( mVectors[i] );
    }
    glEnd();
}

