//
//  Bird.cpp
//  week08_steeringForce
//
//  Created by Qinglin Wang on 10/23/18.
//

#include "Bird.hpp"

void Bird::setup(){
    loc.set(ofRandomWidth(),ofRandomHeight());
    vel.set(0,0);
    acc.set(0,0);
    
    r = 5;
    maxSpeed = 2;
    maxSpeed = 0.1;
    
}


void Bird::update(){
    vel += acc;
    loc += vel;
    acc *= 0;
}


void Bird::draw(){
    float angle = atan2(vel.y,vel.x);
    float heading = ofRadToDeg(angle);
    
    ofSetColor(255,0,0);
    ofFill();
    
    
    ofPushMatrix();
    ofTranslate(loc.x,loc.y);
    ofRotateZDeg(heading);
    ofDrawTriangle(0, -r*2, -r, r*2, r, r*2);
    ofPopMatrix();
}

//--------------------------------------------------------------
void Bird::applyForce(ofPoint f){
    acc += f;
}


//--------------------------------------------------------------
void Bird::steeringForce(ofPoint target){
 
    ofPoint steer;
    
    ofPoint desired = target - loc;
    desired.normalize();
    desired *= maxSpeed;
    
    steer = desired - vel;
    
    steer.limit(maxForce);
    

    applyForce(steer);
}

//--------------------------------------------------------------
void Bird::steeringArriveForce(ofPoint target){
    
    ofPoint desired = target - loc;
    
    
    float dist = desired.length();
    desired.normalize();
   
    if(dist < 100){
        float m = ofMap(dist, 0, 100, 0, maxSpeed);
        desired *= m;
    } else {
        desired *= maxSpeed;
    }
    
    ofPoint steer;
    steer = desired - vel;
    steer.limit(maxForce);
    
    
    applyForce(steer);
}
