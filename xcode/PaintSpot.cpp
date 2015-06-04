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
    mNOff = Vec2f ( randFloat( 1000 ), randFloat( 1000 ) );
    mColor = Color ( CM_HSV, randFloat(), 1, 1  );
}

void PaintSpot::createVectors(){
    mVectors.clear();
    mVectors.push_back( Vec2f( mX, mY) );
    float x;
    float y;
    // TODO: seperate if statements - 1 x+,y+ 2 x+,y-, etc etc
    for( int i = 0; i < 20; i++ ){
        if( i < 5 ){
            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, 0.0f, mX + 200.0f );
            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, 0.0f, mY + 200.0f );
        } else if (i >= 5 && i < 10 ){
            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, 0.0f, mX + 200.0f );
            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, 0.0f, mY - 200.0f );
        } else if ( i >= 10 && i < 15 ){
            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, 0.0f, mX - 200.0f );
            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, 0.0f, mY - 200.0f );

        } else {
            x = lmap( mPerlin.fBm(mNOff.x), -1.0f, 1.0f, 0.0f, mX - 200.0f );
            y = lmap( mPerlin.fBm(mNOff.y), -1.0f, 1.0f, 0.0f, mY + 200.0f );
        }
        mVectors.push_back( Vec2f( x, y ) );
        mNOff += Vec2f( 0.01f, 0.01 );
    }
}

void PaintSpot::render(){
    gl::color(Color ( mColor ) );
    glBegin( GL_POLYGON );
    for(int i=0; i<21; i++){
        gl::vertex( mVectors[i] );
    }
    glEnd();

}

