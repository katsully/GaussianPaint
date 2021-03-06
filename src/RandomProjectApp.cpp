#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"
#include "PaintSpot.h"
#include <list>

using namespace ci;
using namespace ci::app;

class RandomProjectApp : public AppNative {
  public:
    void prepareSettings ( Settings *settings );
    void setup();
	void mouseDown( MouseEvent event );	
	void dS();
	void draw();
    
    Vec2f mMousePosition;
    
    std::list<PaintSpot> mPaintSpots;
};

void RandomProjectApp::prepareSettings( Settings *settings ){
    settings->setWindowSize( 1000, 1000 );
}

void RandomProjectApp::setup(){
    gl::clear( Color ( 1, 1, 1 ) );
}

void RandomProjectApp::mouseDown( MouseEvent event ){
    mMousePosition = event.getPos();
    PaintSpot mPaintSpot = PaintSpot( mMousePosition );
    mPaintSpot.createVectors();
    mPaintSpots.push_back( mPaintSpot );
}

void RandomProjectApp::draw(){
    // TODO have the paint fall down the canvas
    for( std::list<PaintSpot>::iterator p = mPaintSpots.begin(); p != mPaintSpots.end(); ++p ){
        p->render();
    }
}

CINDER_APP_NATIVE( RandomProjectApp, RendererGl )
