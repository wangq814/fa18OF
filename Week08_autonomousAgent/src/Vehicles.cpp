//  Vehicles.cpp
//  Week08_autonomousAgent
//
//  Created by Qinglin Wang on 10/19/18.
//

#include "Vehicles.hpp"


//--------------------------------------------------------------
void Vehicles::setup(){
    
    //loc.set(ofRandomWidth(),ofRandomHeight());
    loc.set(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
    //vel.set(ofRandom(-1,5),ofRandom(-1,5));
    vel.set(0,0);
    acc.set(0,0);
    
    r = 2;
    maxSpeed = 5;
    maxForce = ofRandom(0.5,1);
}

//--------------------------------------------------------------
void Vehicles::update(){
    
    vel += acc;
    loc += vel;
    
    acc *= 0;
}

//--------------------------------------------------------------
void Vehicles::draw(){

    ofSetColor(0,0,0,10);
    ofFill();
    ofDrawCircle(loc.x, loc.y, 1);

    
}



void Vehicles::applyForce(ofPoint _f){
    acc += _f;
    
    
}


void Vehicles::steeringForce(ofPoint target){
    
    ofPoint steer;
    ofPoint desired = target - loc;
    desired.normalize();
    

    desired *= maxSpeed;
    
    steer = desired  - vel;
    steer.limit(maxForce);
    applyForce(steer);
    
    
}

void Vehicles::steeringWithArriveForce(ofPoint target){
  
    
    ofPoint desired = target - loc;
    float dist = desired.length();
    desired.normalize();
    if (dist < 500) {
    float m = ofMap(dist, 0, 500, 0, maxSpeed);
    desired *= m;
}else{
    desired *= maxSpeed;
}
    
    
    desired *= maxSpeed;
    ofPoint steer;
    steer = desired  - vel;
    steer.limit(maxForce);

    applyForce(steer);
    
    
}
