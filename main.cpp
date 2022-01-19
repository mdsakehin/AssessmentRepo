#include "ofMain.h"
#include "ofApp.h"

//========================================================================
int main( ){

    ofGLFWWindowSettings settings; // declares ofGLFWWindowSettings settings 
    settings.resizable = false; // sets resizable to flase
    settings.setSize(1024, 768); // sets the size of settings to 1024 length and 768 height
    ofCreateWindow(settings); // uses ofCreateWindow function with settings passed in 
    return ofRunApp(new ofApp); // returns ofRunApp 
}
