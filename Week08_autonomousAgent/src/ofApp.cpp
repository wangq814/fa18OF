#include "ofApp.h"


void ofApp::setup(){
    ofBackground(255);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);
  
    for(int i = 0;i<TOTALNUM;i++){
        Vehicles v;
        v.setup();
        vehicle.push_back(v);
        
    }
}


void ofApp::update(){

    for(int i = 0;i<TOTALNUM;i++){
vehicle[i].steeringWithArriveForce(ofPoint(mouseX,mouseY));
    vehicle[i].update();
         }
}


void ofApp::draw(){
    for(int i = 0;i<TOTALNUM;i++){
    vehicle[i].draw();
    }
}

