#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "ofxOpenCv.h"

class testApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void mousePressed(int x, int y, int button);
    
    ofVideoGrabber video;
    
    ofxCvColorImage rgb,hsb;
    ofxCvGrayscaleImage hue,sat,bri,filtered;
    ofxCvContourFinder contours;
    
    int width,height;
    int HueFinder;
};

#endif

