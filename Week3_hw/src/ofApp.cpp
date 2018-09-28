#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    ofSetBackgroundAuto(false);
    
    for(int i=0;i<numOfBalls;i++){
        ballsPos[i].set(ofRandom(0,ofGetWindowWidth()), ofRandom(0,ofGetWindowHeight()));
                            
        ballsVel[i].set(ofRandom(-5,5),ofRandom(-5,5));
        
        radius[i] = 10;
        R[i] = 200;
        G[i] = 100;
        B[i] = 250;
        
        
        
        
        
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i=0;i<numOfBalls;i++){
        ballsPos[i] += ballsVel[i];
        
        if(ballsPos[i].x < radius[i]) {
            ballsPos[i].x= radius[i];
            ballsVel[i] *= -1;
        }
        
        if(ballsPos[i].x > ofGetWindowWidth()-radius[i]) {
            ballsPos[i].x= ofGetWindowWidth()-radius[i];
            ballsVel[i] *= -1;
        }
        
        if(ballsPos[i].y < radius[i]) {
            ballsPos[i].y= radius[i];
            ballsVel[i] *= -1;
        }
        
        if(ballsPos[i].y > ofGetWindowHeight()-radius[i]) {
            ballsPos[i].y= ofGetWindowHeight()-radius[i];
            ballsVel[i] *= -1;
        }
        
        
        
//        if(ballsPos[i].x > ofGetMouseX()-radius[i] &&
//           ballsPos[i].x < ofGetMouseX() + rectWidth +radius[i] && ballsPos[i].y > ofGetMouseY()-radius[i] && ballsPos[i].y <ofGetMouseY()+rectHeight+radius[i])
        
        float d = ofDist(ballsPos[i].x,ballsPos[i].y, ofGetMouseX(),ofGetMouseY());
        
        
        if(d<radius[i]+radius2){
            
        
            
            ballsVel[i] *= -1;
            R[i] -=5;
            G[i] +=5;
            B[i] +=5;
            
            
            if(R[i]==0){
                R[i]= 255;

            }

           
        }
        
        
        
        
        
      
        
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    rectWidth = 100;
    rectHeight=100;
    radius2 = 50;
    //ofSetColor(255);
//    ofDrawRectangle(ofGetMouseX(),ofGetMouseY(),rectWidth,rectHeight);
    
    
    
    for (int i=0;i<numOfBalls;i++){
        ofSetColor(R[i], G[i], B[i],50);
        ofDrawCircle(ballsPos[i], radius[i]);
        
        
        
    }
    
    ofNoFill();
    ofDrawCircle(ofGetMouseX(), ofGetMouseY(),radius2);
    
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
