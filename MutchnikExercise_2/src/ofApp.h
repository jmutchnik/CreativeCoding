#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    float  eHeight;
    float eWidth;
    float fractionDone;
    float angle;
    int radius;
    float xpos;
    float ypos;
    float circcenterx;
    float circcentery;
    ofColor eFillColor;
    float eSize;
    bool drawOnce;
    int counter;
		
    
    void makeEllipses(int maxEllipses) {
        bool drawOnce=true;
        for (int i=0; i<maxEllipses; i++) {
         
            ofSetColor(255,ofRandom(255),255, (0,50));
            ofDrawEllipse(ofRandom(ofGetHeight()),ofRandom(ofGetWidth()), ofRandom(10,15), ofRandom(10,15));
        }
    }
    
    
    void makeRects(int maxRects) {
        bool drawOnce=true;
        for (int i=0; i<maxRects; i++) {
            ofSetColor(255,ofRandom(255),255, (50,200));
            ofDrawRectangle(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()), ofRandom(25, 50), ofRandom(25, 50));
        }
    }

    
};
