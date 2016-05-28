#pragma once
#include "ofMain.h"
#include "ofxLiquidFun.h"
#include "ofxGui.h"

// -------------------------------------------------

class ofApp : public ofBaseApp {
    
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void resized(int w, int h);
    
    ofxBox2d box2d;
    vector <ofPtr<ofxBox2dCircle> >	circles;		  //	default box2d circles
    vector <ofPtr<ofxBox2dRect> > boxes;			  //	defalut box2d rects
    ofxBox2dParticleSystem particles;			      //    LiquidFun particle system
    
    
    ofxPanel gui;
    
    //ofxIntSlider ParticleSize;
    ofxIntSlider CircleSize;
    ofxIntSlider BoxSize;
    
    ofxIntSlider red1;
    ofxIntSlider green1;
    ofxIntSlider blue1;
    
    ofxIntSlider red2;
    ofxIntSlider green2;
    ofxIntSlider blue2;
    
    
    ofxIntSlider red3;
    ofxIntSlider green3;
    ofxIntSlider blue3;
    

};