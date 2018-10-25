
#ifndef Bird_hpp
#define Bird_hpp



#include "ofMain.h"

class Bird {
    
public:
    void setup();
    void update();
    void draw();
    
    //void keyPressed(int key);
    
    void applyForce(ofPoint f);
    void steeringForce(ofPoint target);
    
    void steeringArriveForce(ofPoint target);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    float r;
    float maxSpeed;
    float maxForce;
    
    
   
    
};


#endif /* Bird_hpp */
