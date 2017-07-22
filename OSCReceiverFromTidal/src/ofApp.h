#pragma once

#include "ofMain.h"
#include "ofxOsc.h"

// set OSC port number as 8000
static const int PORT = 8000;

class ofApp : public ofBaseApp{

public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void dumpOSC(ofxOscMessage m);
		
    ofxOscReceiver receiver;
};
