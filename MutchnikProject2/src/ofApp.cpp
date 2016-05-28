#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofSetBackgroundColor(0);
    ofSetVerticalSync(true);
    ofSetFrameRate(700);
   
    ofSoundStreamListDevices();
    //fft.fft.stream.setDeviceID(2);
    fft.setup();

    fftSmooth.resize(fft.getNumFFTbins());
    
    
//    fftSmooth = new float [3000];
//    for (int j = 0; j < 8192; j++) {
//        fftSmooth[j] = 0;
//        
//    }
    
    //bands = 10;
    
   
    
    
    
    angle =10;

    for (int i=0; i<75; i++) {
        balls[i].x = ofRandomWidth();
        balls[i].y = ofRandomHeight();
        balls[i].vx = ofRandom(-10,10);
        balls[i].vy = ofRandom(-10,10);
        balls[i].radius = ofRandom(1,5);
    }
    
    

    
    
    

    
    circleButton.set(100, 450);
    radius = 55;
    bCircleButton = false;
    bCircleVisual = false;
    
    
    rectButton.set(250, 400, 100, 100);
    bRectButton = false;
    bRectVisual = false;
    



    triangleButton.addVertex(655, 500);
    triangleButton.addVertex( 705,410);
    triangleButton.addVertex(755,500);
    triangleButton.close();
    
    bTriangleButton = false;
    bTriangleVisual = false;
    
    //    ofTranslate(500,350);
    //    ofBeginShape();
    //    ofVertex(0, -50);
    //    ofVertex(14, -20);
    //    ofVertex(47, -15);
    //    ofVertex(23, 7);
    //    ofVertex(29, 40);
    //    ofVertex(0, 25);
    //    ofVertex(-29, 40);
    //    ofVertex(-23, 7);
    //    ofVertex(-47, -15);
    //    ofVertex(-14, -20);
   
    starButton.addVertex(472, 472);
    starButton.addVertex(473, 434);
    starButton.addVertex(452, 411);
    starButton.addVertex(484, 406);
    starButton.addVertex(498, 376);
    starButton.addVertex(513, 404);
    starButton.addVertex(544, 411);
    starButton.addVertex(524, 432);
    starButton.addVertex(530, 471);
    starButton.addVertex(499, 455);
    starButton.close();
    
    bStarButton = false;
    bStarVisual = false;


    diamondButton.addVertex(850, 455);
    diamondButton.addVertex(900,510);
    diamondButton.addVertex(950,455);
    diamondButton.addVertex(900,400);
    diamondButton.close();

    bDiamondButton = false;
    bDiamondVisual = false;
    
    
    
    
   

    live.setup();
//    live.update();
    
//    live.getTrack(0)->getClip("LNL_Funky-Guitar1_110_Am")->stop();
//    live.getTrack(1)->getClip("LNL_Semi-Acoustic4_80_Dm")->stop();
//    live.getTrack(2)->getClip("MJ_120_E_BBGuit1")->stop();
//    live.getTrack(4)->getClip("2020_EP_123_DrumLp7")->stop();
//    live.getTrack(3)->getClip("US_wurlie_Dm7Em7Fm7_95")->stop();
    

    
}

//--------------------------------------------------------------
void ofApp::update(){

    ofSoundUpdate();

    fft.update();
    vector<float> spectrum = fft.getSpectrum();
    for (int j = 0; j < spectrum.size(); j++) {
        fftSmooth[j] *= 0.9f;
        if (fftSmooth[j] < spectrum[j]) {
            fftSmooth[j] = spectrum[j];
        }
    }
    //fftSmooth = spectrum;
    
//    float * value = ofSoundGetSpectrum(bands);
//    for (int j = 0; j < bands; j++) {
//        fftSmooth[j] *= 0.9f;
//        if (fftSmooth[j] < value[j]) {
//            fftSmooth[j] = value[j];
//        }
//    }
    
    
    for (int i=0; i<75; i++) {
        
        balls[i].x = balls[i].x + balls[i].vx;
        balls[i].y = balls[i].y + balls[i].vy;
        
        if (balls[i].x<0 || balls[i].x > ofGetWidth()) {
            balls[i].vx = -balls[i].vx;
        }
        
        if (balls[i].y<0 || balls[i].y > ofGetHeight()) {
            balls[i].vy = -balls[i].vy;
        }
    }
    
//    if (bCircleButton){
//        ofxAbletonLiveTrack *track = live.getTrack(0);
//        track->printClips();
//        track->printDevices();
//        ofxAbletonLiveClip *clip = track->getClip("LNL_Funky-Guitar1_110_Am");
//     
//        clip->play();
        
//        bCircleVisual = true;
    
//    }

//    
//    
//    if (bRectButton){
//        ofxAbletonLiveTrack *track = live.getTrack(1);
//        track->printClips();
//        ofxAbletonLiveClip *clip = track->getClip("LNL_Semi-Acoustic4_80_Dm");
//        clip->play();
//        
//        bRectVisual = true;
//
//
//     
//
//    }
    
    
    if (bTriangleButton){
        ofxAbletonLiveTrack *track = live.getTrack(3);
        track->printClips();
        ofxAbletonLiveClip *clip = track->getClip("sm101_db_tropicanalinnstep_110bpm");
        clip->play();

        bTriangleVisual = true;
        
    }


    if (bStarButton){
        ofxAbletonLiveTrack *track = live.getTrack(2);
        track->printClips();
        ofxAbletonLiveClip *clip = track->getClip("DP_Leads_145_A_04");
        clip->play();

        bStarVisual = true;
        
    }

    if (bDiamondButton){
        ofxAbletonLiveTrack *track = live.getTrack(4);
        track->printClips();
        ofxAbletonLiveClip *clip = track->getClip("HI_128_A_Vox_Vocalworkloop");
        clip->play();
        
        bDiamondVisual = true;
    }

    
  
    live.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    if(bStarVisual == true){
        
        ofPushMatrix();
        
        
        
        ofTranslate(ofGetWidth()/2+500, ofGetHeight()/2);
        x+=0.025;
        for (int i = 0; i < 500; i+=inc) {
            ofRotate(ofDegToRad(-x)/2);
            ofTranslate(inc, 0);
            
            
            for (int j = 0; j < 500; j+=inc) {
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofRotate(ofDegToRad(x));
                    ofTranslate(0, inc);
                    
                    ofPushMatrix();
                    
                    ofSetColor(255, 255, 0);
                    
                    
                    ofDrawLine(0, 0, 10* (fftSmooth[4]*20), 0);
                }
                ofPopMatrix();
            }
            
        }
        
        
        ofTranslate(ofGetWidth()/2+200, ofGetHeight()/2);
        x+=0.2;
        for (int i = 0; i < 500; i+=inc) {
            ofRotate(ofDegToRad(x)/2);
            ofTranslate(inc, 0);
            
            
            for (int j = 0; j < 500; j+=inc) {
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofRotate(ofDegToRad(x));
                    ofTranslate(0, inc);
                    
                    ofPushMatrix();
                    
                    ofSetColor(255, 255, 0);
                    
                   
                    ofDrawLine(0, 0, 10* (fftSmooth[4]*5), 0);
                }
                ofPopMatrix();
            }
            
        }
        
        
        ofPopMatrix();
    }

    if(bTriangleVisual == true){
        
        ofFill();
        
        ofSetBackgroundAuto(true);
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()/4, ofGetHeight()/2);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(angle);
                    
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[2]*0.04));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[2]*0.035));
                    
                    ofSetColor(0,200,0);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y*(fftSmooth[2]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        

        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()*3/4, ofGetHeight()/2);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(angle);
                    
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[2]*0.04));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[2]*0.035));
                    
                    ofSetColor(0,200,0);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y*(fftSmooth[2]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        
        
        

        
        
    }
    if(bDiamondVisual == true){
        
        ofSetBackgroundAuto(true);
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(-angle);
                    
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[5]*0.075));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[5]*0.07));
                    
                    ofSetColor(255,155,0);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y*(fftSmooth[1]*0.06));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        
        
        
        
        
        
    }
    
    if(bRectVisual == true){
        ofFill();
        fft.drawBars();
        
        
        ofSetColor(0, 0, 255);
        
        
        ofDrawRectangle(824, 1500, 200, 200);
        ofDrawRectangle(824, 1500, 200, 200);
        ofDrawRectangle(824, 1500, 200, 200);
        ofDrawRectangle(824, 1500, 200, 200);
        
        ofSetBackgroundAuto(true);
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/4);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(angle);
                    
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[5]*0.05));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[5]*0.035));
                    
                    ofSetColor(0,0,255);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y*(fftSmooth[1]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()/2, ofGetHeight()*3/4);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(angle);
                    
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[5]*0.04));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-30 ,y +30,x +30, y +30 * (fftSmooth[5]*0.035));
                    
                    ofSetColor(0,0,255);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y*(fftSmooth[1]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        
        
    }
    


    if(bCircleVisual == true){
        
        ofFill();
        for (int i=0; i<75; i++) {
            for (int j=0; j<fftSmooth.size(); j++) {
                
                ofSetColor(255);
                ofDrawCircle(balls[i].x, balls[i].y, balls[i].radius+5 * (fftSmooth[3]*0.06));
            }
            
            
            for (int i=0; i<75; i++) {
                ofSetColor(ofRandom(200,255), 0, 0);
                ofDrawCircle(balls[i].x, balls[i].y, balls[i].radius* (fftSmooth[3]*0.06));
            }
            
        }
        
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()/3, ofGetHeight()/3.25);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(-angle);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.05));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.035));
                    
                    ofSetColor(255,0,0);
                    
                    ofDrawTriangle(x,y, x-10 ,y +10,x +10, y*(fftSmooth[2]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()/3, ofGetHeight()*3/4);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(-angle);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.05));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.035));
                    
                    ofSetColor(255,0,0);
                    
                    ofDrawTriangle(x,y, x-10 ,y +10,x +10, y*(fftSmooth[2]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()*2/3, ofGetHeight()/3.25);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(-angle);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.05));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.035));
                    
                    ofSetColor(255,0,0);
                    
                    ofDrawTriangle(x,y, x-10 ,y +10,x +10, y*(fftSmooth[2]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        
        
        ofPushMatrix();
        ofFill();
        ofTranslate(ofGetWidth()*2/3, ofGetHeight()*3/4);
        
        
        
        
        
        ofFill();
        for(int x = 50; x < 100; x +=10){
            for(int y = 20; y < 100; y +=300){
                
                for (int j=0; j<fftSmooth.size(); j++) {
                    ofSetColor(255);
                    
                    angle += 0.00001;
                    
                    ofRotate(-angle);
                    
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.05));
                    
                    ofSetColor(0);
                    ofDrawTriangle(x,y, x-20 ,y +20,x +20, y +20 * (fftSmooth[3]*0.035));
                    
                    ofSetColor(255,0,0);
                    
                    ofDrawTriangle(x,y, x-10 ,y +10,x +10, y*(fftSmooth[2]*0.03));
                    
                    
                }
            }
        }
        ofPopMatrix();
        

        
    }
    
    
    
    
   

    
    
    
    
    


    
    
    
// buttons
ofFill();
ofSetColor(255);
ofDrawCircle(100, 450, 55);

ofSetColor(255,0,0);
ofDrawCircle(100, 450, 50);
    

    
    

    

        

    ofFill();
    ofSetColor(255);
    ofDrawRectangle(245, 395, 110, 110);
    ofSetColor(0, 0, 255);
    ofDrawRectangle(250, 400, 100, 100);
    
    ofSetColor(255);
    ofDrawTriangle(645, 507, 705, 395, 765, 507);
    ofSetColor(0, 255, 0);
    ofDrawTriangle(655, 500, 705, 410, 755, 500);
    
   
    
    ofSetColor(255);
    ofBeginShape();
    ofVertex(845, 455);
    ofVertex(900,515);
    ofVertex(955,455);
    ofVertex(900,395);
    ofEndShape();

    ofSetColor(255, 155,0 );
    ofBeginShape();
    ofVertex(850, 455);
    ofVertex(900,510);
    ofVertex(950,455);
    ofVertex(900,400);
    ofEndShape();
    
    
    
    
    ofPushMatrix();
    ofSetColor(255);
    ofTranslate(500,430);
    ofScale(1.75, 1.75);
    ofBeginShape();
    ofVertex(0, -50);
    ofVertex(14, -20);
    ofVertex(47, -15);
    ofVertex(23, 7);
    ofVertex(29, 40);
    ofVertex(0, 25);
    ofVertex(-29, 40);
    ofVertex(-23, 7);
    ofVertex(-47, -15);
    ofVertex(-14, -20);
    ofEndShape();
    ofPopMatrix();


    // filled star
    ofFill();
    ofSetColor(255, 255, 0);
    
    
    // star outline
//    ofSetColor(255, 255, 0);
//    ofNoFill();
//    ofSetLineWidth(4);
//    starButton.draw();
//    ofSetLineWidth(1);
    
    ofPushMatrix();
    ofTranslate(500,430);
    ofBeginShape();
    ofVertex(0, -50);
    ofVertex(14, -20);
    ofVertex(47, -15);
    ofVertex(23, 7);
    ofVertex(29, 40);
    ofVertex(0, 25);
    ofVertex(-29, 40);
    ofVertex(-23, 7);
    ofVertex(-47, -15);
    ofVertex(-14, -20);
    ofEndShape();
    ofPopMatrix();
    
  
}

//--------------------------------------------------------------
void ofApp::exit() {
    live.stop();
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key=='1')
    {
        live.printAll();
        // or just the tracks
        live.printTracks();
    }

    if (key=='2')
    {
        live.stop();
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
    ofLog() << x << " " << y;
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

    if (circleButton.distance(ofPoint(x,y)) < radius) {
        bCircleButton = !bCircleButton;
        
        ofxAbletonLiveTrack *track = live.getTrack(0);
        //track->printClips();
        //track->printDevices();
        ofxAbletonLiveClip *clip = track->getClip("nd_drm120_slowjam2");
        
        if(bCircleButton) {
            clip->play();
            bCircleVisual = true;
        }
        else {
            clip->stop();
            bCircleVisual = false;
        }
    }
    
    if (rectButton.inside(x, y)) {
        bRectButton = !bRectButton;
        
        
        ofxAbletonLiveTrack *track = live.getTrack(1);
        track->printClips();
        ofxAbletonLiveClip *clip = track->getClip("Cl_125_Dm_Pianohook5");
        clip->play();
        
        bRectVisual = true;
        

        
    }

    if (triangleButton.inside(ofPoint(x,y))) {
        bTriangleButton = !bTriangleButton;
        
        
    }

    if (starButton.inside(ofPoint(x,y))) {
        bStarButton = !bStarButton;
    }
    
    if (diamondButton.inside(ofPoint(x,y))) {
        bDiamondButton = !bDiamondButton;
    }


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
