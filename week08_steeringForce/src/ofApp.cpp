#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
   ofBackground(0);
   ofEnableSmoothing();
   ofSetCircleResolution(50);

    
   for(int i = 0; i< TOTALNUM; i++){
        Bird b;
        b.setup();
        birds.push_back(b);
   }
    
    
     //birds.setup();
    
}

//--------------------------------------------------------------
void ofApp::update(){

    for(int i = 0; i< TOTALNUM; i++){
        birds[i].draw();
    
        birds[i].steeringArriveForce(ofPoint(mouseX,mouseY));
        //birds.steeringForce(ofPoint(mouseX,mouseY));
        
        
        birds[i].update();
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for(int i = 0; i< TOTALNUM; i++){
        birds[i].draw();
    }
    
       // birds.draw();
    
}

//--------------------------------------------------------------
//void ofApp::keyPressed(int key){
//
//}

