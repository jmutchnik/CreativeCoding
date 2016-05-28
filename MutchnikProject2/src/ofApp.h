#pragma once

#include "ofMain.h"
#include "ofxAbletonLive.h"
#include "ofxProcessFFT.h"

struct Ball {
    int x;
    int y;
    int vx;
    int vy;
    int radius;
};


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

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
    
    
    ofSoundPlayer sample1;
    ofSoundPlayer sample2;
    ofSoundPlayer sample3;
    ofSoundPlayer sample4;
    ofSoundPlayer sample5;
    
    ofSoundStream soundStream;
    
   
    float sampleRate;
    float lAudio;
    float rAudio;
    
    
    
    vector<float> fftSmooth;
    int bands;
    float angle;
		
    ofPoint circleButton;
    bool bCircleButton;
    bool bCircleVisual;
    int radius;
    
    ofRectangle rectButton;
    bool bRectButton;
    bool bRectVisual;
    
    
    ofPolyline starButton;
    bool bStarButton;
    bool bStarVisual;
    
    ofPolyline triangleButton;
    bool bTriangleButton;
    bool bTriangleVisual;
    
    ofPolyline diamondButton;
    bool bDiamondButton;
    bool bDiamondVisual;
    
   
    ProcessFFT fft;
    
    ofxAbletonLive live;
    
    Ball balls[75];
    

    int inc = 30;
    float x=-1;
    

    
    
};
