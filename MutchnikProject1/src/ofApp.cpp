#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(1000);
    ofSetBackgroundAuto(false);
    ofSetBackgroundColor(0);
    
    
    
    
    // load tracks
    track1.load("01 untitled 07 l levitate.mp3");
    track2.load("02 Father Stretch My Hands, Pt. 1 (feat. Kid Cudi).mp3");
    track3.load("02 Drake - Pop Style (New Verse) (Radio Rip).mp3");
    
    
    
    // set FFT
    fftSmooth = new float [3000];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0;
        
    }
    
    bands = 10;
    
    
    
    
    angle =10;
    
    
    //color change bools
    colorchange1 = false;
    
    colorchange2 =  false;
    
    colorchange3 = false;
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofSoundUpdate();
    
    
    
    //get amplitude
    
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftSmooth[i] *= 0.9f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i];
        }
    }
    


}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetBackgroundAuto(true);
    
    
    
    //visuals
    
    for (int i=0; i<bands; i++) {
        
        angle += 0.01;
        
        ofTranslate(500, 400);
        ofScale(0.25,.5);
        
        for (int i=0; i<ofGetWidth();i+=275) {
            for (int j=0; j<ofGetHeight(); j+=275) {
                
                
                ofRotate(-angle/100);
                
                ofPushMatrix();
                ofSetLineWidth(i/50);
                
                
                ofTranslate(i, j);
                ofRotate(angle*2);
                
                ofDrawRectangle(600,400, -(fftSmooth[i]*50), ofGetHeight());
                
                ofDrawRectangle(600,500,100,100);
                ofDrawRectangle(-(fftSmooth[i-10]*100), -(fftSmooth[i-10]*50), -(fftSmooth[i-10]*100), -(fftSmooth[i-10]*50));
                
                ofPushMatrix();
                
                for (int k=0; k<ofGetWidth(); k+=40) {
                    
                    //ofSetColor(i, 600, 600);
                    ofTranslate(100, 300);
                    //ofRotate(angle/50);
                    ofScale(0.5, .8);
                    //ofDrawRectangle(200, 100, 100, 100);
                }
                ofPopMatrix();
                
            }
            
        }
        
        
        for (int i=0; i<bands; i++) {
            
            angle += 0.01;
            
            ofTranslate(ofGetWidth()/3, ofGetHeight()/4);
            ofScale(0.5,.8);
            
            for (int i=0; i<ofGetWidth();i+=275) {
                for (int j=0; j<ofGetHeight(); j+=275) {
                    
                    
                    ofRotate(-angle/100);
                    
                    ofPushMatrix();
                    ofSetLineWidth(i/10);
                    
                    
                    ofTranslate(i, j);
                    ofRotate(-angle*2);
                    
                    ofDrawRectangle(600,400, -(fftSmooth[i]*50), ofGetHeight());
                    
                    ofDrawRectangle(600,500,100,100);
                    ofDrawRectangle(-(fftSmooth[i-10]*100), -(fftSmooth[i-10]*50), -(fftSmooth[i-10]*100), -(fftSmooth[i-10]*50));
                    
                    ofPushMatrix();
                    
                    for (int k=0; k<ofGetWidth(); k+=40) {
                        
                        //ofSetColor(i, 600, 600);
                        ofTranslate(100, 300);
                        ofRotate(angle/50);
                        ofScale(0.25, .5);
                        //ofDrawRectangle(200, 100, 100, 100);
                    }
                    ofPopMatrix();
                    
                }
            }
            
            
            
            
            for (int i=0; i<bands; i++) {
                for (int i=0; i<ofGetWidth();i+=275) {
                    for (int j=0; j<ofGetHeight(); j+=275) {
                        
              
                        //change colors
                        
                        if (colorchange1) {
                            ofColor ecolor1 (160,32,ofRandom(200,240));
                            ofColor ecolor2 (ofRandom(0,20),ofRandom(0,100),0);
                            ofColor ecolor3 (255);
                            
                            ofEnableSmoothing();
                            ofRotate(-angle/100);
                            
                            ofPushMatrix();
                            ofSetLineWidth(i/200);
                            
                            
                            ofTranslate(i, j);
                            ofRotate(-angle);
                            ofSetColor(255);
                            ofDrawRectangle(200,600, -(fftSmooth[i]*1250), ofGetHeight());
                            
                            
                            ofTranslate(i, j);
                            ofRotate(-angle);
                            ofSetColor(ecolor1);
                            
                            ofDrawRectangle(100,400, -(fftSmooth[i]*1750), ofGetHeight());
                            
                            ofTranslate(j, i);
                            ofRotate(-angle);
                            ofSetColor(ecolor3);
                            ofDrawRectangle(700,400, -(fftSmooth[i]*300), ofGetHeight());
                            
                            
                            
                            ofTranslate(i, j);
                            ofRotate(angle);
                            ofSetColor(ecolor2);
                            ofDrawRectangle(400,400, ofGetWidth(), -(fftSmooth[i]*2200));
                            

                                             
                        }else{
                        ofColor ecolor1 (0, 0, ofRandom(0,255));
                        ofColor ecolor2  (ofRandom(0,255), 0, 0);
                        ofColor ecolor3 ((0,255),(0,255), 0);
                        
                        
                        ofRotate(-angle/100);
                        
                        ofPushMatrix();
                        ofSetLineWidth(i/200);
                        
                        
                        ofTranslate(i, j);
                        ofRotate(angle);
                        ofSetColor(255);
                        ofDrawRectangle(200,600, -(fftSmooth[i]*1250), ofGetHeight());
                        
                        
                        ofTranslate(i, j);
                        ofRotate(angle);
                        ofSetColor(ecolor1);
                        
                        ofDrawRectangle(100,400, -(fftSmooth[i]*1750), ofGetHeight());
                        
                        ofTranslate(j, i);
                        ofRotate(-angle);
                        ofSetColor(ecolor3);
                        ofDrawRectangle(700,400, -(fftSmooth[i]*300), ofGetHeight());
                        
                        
                        
                        ofTranslate(i, j);
                        ofRotate(angle);
                        ofSetColor(ecolor2);
                        ofDrawRectangle(400,400, ofGetWidth(), -(fftSmooth[i]*2200));
                        
                    
                        
                        
                        
                        
                        
                    }
                    ofPopMatrix();
                }
            }
        }
        
    }
}
}



//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
    // play tracks with key press
    switch (key) {
        case '1':
            track1.play();
            track2.stop();
            break;
            
        case '2':
            track1.stop();
            track2.play();
            
            break;
        case '3':
            track1.stop();
            track2.stop();
            track3.play();
            
            break;
            
            
            
    }
    
    if(key == 'c'){
        
        colorchange1 = true;
    }
    
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
