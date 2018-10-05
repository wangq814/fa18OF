#include "ofApp.h"
//paint brush
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofBackground(0);
    ofSetCircleResolution(50);
    ofEnableSmoothing();
    ofSetBackgroundAuto(false);

}

//--------------------------------------------------------------
void ofApp::update(){
    for(int i = 0; i<particles.size(); i++){
        particles[i].pos += particles[i].vel;
        
        float age = ofGetElapsedTimef() - particles[i].born;
        
        particles[i].color.a = ofMap(age, 0, 1, 255, 0);
        
        if(age > 1){
            particles.erase(particles.begin() + i);
        }
        
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
  
    Particle p;
    
    p.radius = ofRandom(1,3);
    p.born = ofGetElapsedTimef();
    p.pos.set(ofGetMouseX(), ofGetMouseY());
    p.vel.set(ofRandom(-1,1),ofRandom(-1,1));
    p.color.setHsb(ofRandom(150,255), 100, ofRandom(150,255));
    
    particles.push_back(p);
    
    for(int i = 0; i<particles.size(); i++){
        ofSetColor(particles[i].color);
        ofDrawCircle(particles[i].pos, particles[i].radius);
    }
    
}

