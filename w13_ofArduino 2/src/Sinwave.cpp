//
//  Sinwave.cpp
//  final
//
//  Created by Qinglin Wang on 2018/12/19.
//

#include "Sinwave.hpp"



Sinwave::Sinwave(){

frequency = 0;
amp  = 0;
space = 0;
d = 1;
t = 0;
dt = 5;
amplitude = 0;
hue = 0;
    
}

Sinwave::Sinwave(float _amp, float _space, float _amplitude, float _hue){
    frequency = 0;
    amp  = _amp;
    space = _space;
    d = 3;
    t = 0;
    dt = 5;
    amplitude = _amplitude;
    hue = _hue;
}


//--------------------------------------------------------------
void Sinwave::setup(){
}

//--------------------------------------------------------------


void Sinwave::setFrequency(float _frquency){
    frequency = _frquency;
}
//
//void Sinwave::setAmplitude(float _amp){
//    amp = _amp;
//    amplitude += 1;
//        if(amplitude >= amp) {
//            amplitude = 0;
//        }
//}
//--------------------------------------------------------------
//void Sinwave::update(float _amp){
//    amp = _amp;
//    t += dt;
//    amplitude += 0.5;
//    if(amplitude >= amp) {
//        amplitude = 0;
//    }
//}

void Sinwave::update(float _amp){
    t += dt;
    amp = _amp;
    amplitude += 0.5;
    if(amplitude >= amp) {
        amplitude = 0;
    }
}
//--------------------------------------------------------------


void Sinwave::draw(float _space){
    ofPushStyle();
    space = _space;
    ofColor color = ofColor::fromHsb(hue,100,255);
    
    for (int i=0;i<ofGetWidth();i++){
        ofSetColor(color);
        ofDrawCircle(i, amplitude* cos(frequency*(t+i))+space, d);
    }
    ofPopStyle();
}


void Sinwave::keyPressed(int key){
}



