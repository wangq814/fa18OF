#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    ofSetBackgroundAuto(false);
    
    
    radius1 = 140;
    radius2 = 120;
    radius3 = 100;
    radius4 = 80;
    radius5 = 60;
    radius6 = 40;
    radius7 = 20;
   
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    
   
    
    
    float t = ofGetElapsedTimef();
    float sinOutput = sin(t*10);
    float cosOutput = cos(t*10);
    //radius1 = ofMap(sinOutput, 0, 1, 200, 300);
    //radius2 = ofMap(cosOutput, 0, 1, 250, 300);

//    pos1.x = ofGetWindowWidth()/2 - cos(angle)*radius1*sinOutput;
    
    pos1.x = ofGetWindowWidth()/2 - cos(angle)*radius1;
    pos1.y = ofGetWindowHeight()/2 - sin(angle)*radius1;
    
    pos2.x = ofGetWindowWidth()/2 - cos(angle)*radius2;
    pos2.y = ofGetWindowHeight()/2 - sin(angle)*radius2;
    
    pos3.x = ofGetWindowWidth()/2 - cos(angle)*radius3;
    pos3.y = ofGetWindowHeight()/2 - sin(angle)*radius3;
    
    pos4.x = ofGetWindowWidth()/2 - cos(angle)*radius4;
    pos4.y = ofGetWindowHeight()/2 - sin(angle)*radius4;
    
    pos5.x = ofGetWindowWidth()/2 - cos(angle)*radius5;
    pos5.y = ofGetWindowHeight()/2 - sin(angle)*radius5;
    
    pos6.x = ofGetWindowWidth()/2 - cos(angle)*radius6;
    pos6.y = ofGetWindowHeight()/2 - sin(angle)*radius6;
    
    pos7.x = ofGetWindowWidth()/2 - cos(angle)*radius7;
    pos7.y = ofGetWindowHeight()/2 - sin(angle)*radius7;
    
    

    angle += ofDegToRad(1);
    
    if (t>7 && t<10){
    radius1 += 0.2;
    radius2 += 0.2;
    radius3 += 0.2;
    radius4 += 0.2;
    radius5 += 0.2;
    radius6 += 0.2;
    radius7 += 0.2;
    }
    
    if (t>10){
        radius1 += 0.39;
        radius2 += 0.39;
        radius3 += 0.39;
        radius4 += 0.39;
        radius5 += 0.39;
        radius6 += 0.39;
        radius7 += 0.39;
    }
    
//    if(pos1.y>ofGetWindowHeight()/2){
//
//        pos1.y = ofGetWindowHeight()/2;
//        angle -= ofDegToRad(1);
//
//
//    }
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    
    ofSetHexColor(0xff8389);
    ofDrawCircle(pos7,11);
    ofSetHexColor(0xffc47d);
    ofDrawCircle(pos6,11);
    ofSetHexColor(0xfff576);
    ofDrawCircle(pos5,11);
    ofSetHexColor(0xa1d28e);
    ofDrawCircle(pos4,11);
    ofSetHexColor(0xa4def7);
    ofDrawCircle(pos3,11);
    ofSetHexColor(0xa7bee3);
    ofDrawCircle(pos2,11);
    ofSetHexColor(0xcca8cf);
    ofDrawCircle(pos1,11);
    
    

    
    
  
    
   
    

    
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
