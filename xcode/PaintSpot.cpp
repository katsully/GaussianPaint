//
//  PaintSpot.cpp
//  RandomProject
//
//  Created by Kathleen Sullivan on 5/29/15.
//
//

#include "PaintSpot.h"
#include "cinder/Rand.h"

using namespace ci;

PaintSpot::PaintSpot(){
}

PaintSpot::PaintSpot( float mMouseX, float mMouseY ){
    mX = mMouseX;
    mY = mMouseY;
    mColor = Color ( CM_HSV, randFloat(), 1, 1  );
}

void PaintSpot::createVectors(){
    mVectors.clear();
    float t = 0.0f;
    for( int i = 0; i < 20; i++ ){
//        float nX = mX * 0.05f;
//        float nY = mY * 0.05f;
//        float nZ = t;
//        float n = mPerlin.fBm( nX, nY, nZ );
//        float step = n * 15.0f;
        mVectors.push_back( Vec2f( mX + randFloat(-90, 90), mY + randFloat(-90, 90) ) );
        //mVectors.push_back( Vec2f (mX + step, mY + step ) );
//        t += 5.0f;
    }
    
}

void PaintSpot::render(){
    
    gl::color(Color ( mColor ) );
    glBegin( GL_POLYGON );
//    gl::vertex( mVectors[0] );
//    gl::vertex( mVectors[1] );
//    gl::vertex( mVectors[2] );
//    gl::vertex( mVectors[3] );
//    gl::vertex( mVectors[4] );
//    gl::vertex( mVectors[5] );
    for(int i=0; i<20; i++){
        gl::vertex( mVectors[i] );
    }
    glEnd();

}

