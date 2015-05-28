#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/Rand.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class RandomProjectApp : public AppNative {
  public:
    void prepareSettings ( Settings *settings );
    void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
    
    int mMouseX;
    int mMouseY;
    
    Vec3f rotationIncrement;
    Vec3f currentRotation;
    
    Rand *mGenerator;
};

void RandomProjectApp::prepareSettings( Settings *settings ){
    settings->setWindowSize( 800, 800 );
    rotationIncrement = Vec3f( 0, 0, 5 );
    mGenerator = new Rand();
}

void RandomProjectApp::setup(){
    gl::clear( Color ( 1, 1, 1 ) );
}

void RandomProjectApp::mouseDown( MouseEvent event ){
    mMouseX = event.getX();
    mMouseY = event.getY();
    gl::color( randFloat(), randFloat(), randFloat() );
    currentRotation = Vec3f( 0, 0, 0 );
}

void RandomProjectApp::update()
{
}

void RandomProjectApp::draw(){
    
    //console() << currentRotation;
    // TODO have the paint fall down the canvas
    float num = (float)mGenerator->nextGaussian();
    
    float sd = 10;
    float mean1 = mMouseX;
    float mean2 = mMouseY;
    float numX = ( num * sd ) + mean1;
    float numY = ( num * sd ) + mean2;
    gl::pushModelView();
    gl::translate( Vec2f( numX, numY ) );
    currentRotation += rotationIncrement;
    gl::rotate( currentRotation );
    gl::drawSolidCircle( Vec2f( 15, 15 ), 5.0f );
    //gl::translate( Vec2f( -numX, -numY) );
    gl::popModelView();
    
    
}

CINDER_APP_NATIVE( RandomProjectApp, RendererGl )
