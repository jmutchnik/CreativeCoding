#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    
    ofBackground(0,0,0);
    
    width = 320;
    height = 240;
    
    video.initGrabber(width, height, true);
    
    //cv images
    rgb.allocate(width, height);
    hsb.allocate(width, height);
    hue.allocate(width, height);
    sat.allocate(width, height);
    bri.allocate(width, height);
    filtered.allocate(width, height);

}

//--------------------------------------------------------------
void testApp::update(){
    
    video.update();
    
    if (video.isFrameNew()) {
        
        //pixels to rgb
        rgb.setFromPixels(video.getPixels(), width, height);
        
        //mirror image
        rgb.mirror(false, true);
        
        //rgb
        hsb = rgb;
        
        //hsb
        hsb.convertRgbToHsv();
        
        //grayscale
        hsb.convertToGrayscalePlanarImages(hue, sat, bri);
       
        //filter image
        for (int i=0; i<width*height; i++) {
            filtered.getPixels()[i] = ofInRange(hue.getPixels()[i],HueFinder-5,HueFinder+5) ? 255 : 0;
        }
        filtered.flagImageChanged();
        
        //contour finder on the filtered image to find blobs with a certain hue
        contours.findContours(filtered, 50, width*height/2, 1, false);
    }
}
    


//--------------------------------------------------------------
void testApp::draw(){
    ofSetColor(255,255,255);
    
    //draw cv images
    rgb.draw(0,0);
    hsb.draw(640,0);
    hue.draw(0,240);
    sat.draw(320,240);
    bri.draw(640,240);
    filtered.draw(0,480);
    contours.draw(0,480);
    
    
    }




//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    
    
    int mx = x % width;
    int my = y % height;
    
    //get hue value on mouse position
    HueFinder = hue.getPixels()[my*width+mx];

}

