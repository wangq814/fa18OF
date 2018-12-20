//
//  Sinwave.hpp
//  final
//
//  Created by Qinglin Wang on 2018/12/19.
//

#ifndef Sinwave_hpp
#define Sinwave_hpp

//#pragma once

#include "ofMain.h"

//#define NUMOFDOT 1200

class Sinwave {
    

    
public:
    
    Sinwave();
    Sinwave(float _amp, float _space, float _amplitude,float _hue);
    void setup();
    void update(float _amp);
    //void update();
    void draw(float _space);
    void setFrequency(float _frequency);
    void setAmplitude(float _amp);
    void keyPressed(int key);
    
    
    //float amp;
//    float space;
//    float frequency;
  
    
    
    float hue;
    float frequency;
    float amp;
    float space;
    int d;
    float t;
    float dt;
    float amplitude;
    
    
    
    
    
    
    
    
    
    
    
    
    
} ;

#endif /* Sinwave_hpp */


