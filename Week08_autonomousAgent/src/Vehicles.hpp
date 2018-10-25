//  Vehicles.hpp
//  Week08_autonomousAgent
//
//  Created by Qinglin Wang on 10/19/18.


#ifndef Vehicles_hpp
#define Vehicles_hpp

#include "ofMain.h"

class Vehicles {
    
public:
    void setup();
    void update();
    void draw();
    
    void applyForce(ofPoint _f);
    void steeringForce(ofPoint target);
    
    void steeringWithArriveForce(ofPoint target);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    
    float r;
    float maxSpeed;
    float maxForce;
};


#endif /* Vehicles_hpp */
