#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "CiTextField.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class CiTextFieldApp : public AppNative {
public:
    void setup();
    void mouseDown( MouseEvent event );
    void update();
    void draw();
    
    CiTextField *tf1;
    CiTextField *tf2;
};

void CiTextFieldApp::setup() {
    ci::Font fontOne("Helvetica", 40);
    ci::Font fontTwo("Times New Roman", 16);
    
    tf1 = new CiTextField("Booya", Rectf(100,100,300, 150), fontOne );
    tf2 = new CiTextField("Grandma", Rectf(100,200,300, 225), fontTwo );
}

void CiTextFieldApp::mouseDown( MouseEvent event ){
}

void CiTextFieldApp::update(){
    
}

void CiTextFieldApp::draw() {
    
    gl::enableAlphaBlending();
    
    // clear out the window with black
    gl::clear( Color( 0, 0, 0 ) );
    
    tf1->draw();
    tf2->draw();
}

CINDER_APP_NATIVE( CiTextFieldApp, RendererGl )
