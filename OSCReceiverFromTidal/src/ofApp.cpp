#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // basic setting
    ofSetFrameRate(60);
    ofSetBackgroundColor(0);
    
    // OSC setting
    cout << "listening for osc messages on port " << PORT << endl;
    receiver.setup(PORT);
    
}

//--------------------------------------------------------------
void ofApp::update(){

    while(receiver.hasWaitingMessages()){
        ofxOscMessage m;
        receiver.getNextMessage(m);
        
        cout << "addess:" << m.getAddress() << " >> ";
        
        //dump osc message into console
        dumpOSC(m);
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){

    string buf;
    buf = "listening for osc messages on port" + ofToString(PORT);
    ofDrawBitmapString(buf, 10, 20);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::dumpOSC(ofxOscMessage m) {
    
    string msg_string;
    msg_string = m.getAddress();
    for (int i=0; i<m.getNumArgs(); i++ ) {
        msg_string += " ";
        if(m.getArgType(i) == OFXOSC_TYPE_INT32)
            msg_string += ofToString( m.getArgAsInt32(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_FLOAT)
            msg_string += ofToString( m.getArgAsFloat(i));
        else if(m.getArgType(i) == OFXOSC_TYPE_STRING)
            msg_string += m.getArgAsString(i);
    }
    cout << msg_string << endl;
}

//--------------------------------------------------------------
