#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(10); // set desired framerate
    ofSetVerticalSync(true); // try to lock the framerate to the current OS display sync
    
    //hide the mouse cursor whenevr it enters the window
    ofHideCursor();

    
  ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
  
    ofSetColor(255);
    angle=0;
    radius=200;
    circcenterx=ofGetWidth()/2;
    circcentery=ofGetHeight()/2;
    
    eSize=40;
    eFillColor=(ofRandom(255),ofRandom(255),ofRandom(255));
    bool drawOnce=false;
    counter=1;

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofSetColor(255);
    eHeight= ofMap(ofGetMouseX(), 0, ofGetWidth(), -250, 250);
    eWidth= ofMap(ofGetMouseY(), 0, ofGetHeight(), -250, 250);
    //using a sin/cos for object motion
    xpos=circcenterx+(cos(angle)*radius)+ofRandom(-10,10);
    ypos=circcentery+(sin(angle)*radius)+ofRandom(-10,10);
    
    
    if (ofGetMousePressed){
        ofSetFrameRate(50);
        ofSetBackgroundAuto(true);

        makeEllipses(1);
    }
    //key press makes random rects
    if (ofGetKeyPressed()) {
        ofSetFrameRate(50);
        ofSetBackgroundAuto(false);
        makeRects(1);
    }

    
    ofSetColor(255,ofRandom(255),255);
    ofDrawEllipse(xpos, ypos, eHeight, eWidth);
    angle+=ofRandom(.02, .1);

    
    
}




//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
 ofSetBackgroundColor(ofRandom(255), ofRandom(255), ofRandom(255));

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


