#include "Bird.hpp"

void Bird::setup(){
    loc.set(ofRandomWidth(),ofRandomHeight());
    //loc.set(300,300);
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

    ofSetColor(255,0,0);
    ofFill();
    ofDrawCircle(loc.x, loc.y, 10);

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
