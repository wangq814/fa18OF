#pragma once

#include "ofMain.h"
#include "ofEvents.h"
#include "Sinwave.hpp"


class ofApp : public ofBaseApp{
    
public:
    
    void setup();
    void update();
    void draw();
    
    void stopSound(int _soundNum);
   
    
    ofTrueTypeFont      font;
    ofTrueTypeFont      smallFont;
    ofArduino           ard;

    
    //ofPoint buttonPos[TOTALNUM];
    //ofColor color[TOTALNUM];
//    vector<Sinwave> wave;
    vector<ofSoundPlayer> sounds;
    float       soundNum;
    bool        bSetupArduino;
    // vector<ofPoint> buttonPos;
    float am;
    
    
    
private:
    
    void setupArduino(const int & version);
    void digitalPinChanged(const int & pinNum);
    void analogPinChanged(const int & pinNum);
    void updateArduino();
    
    void calculateResistance(int _pinNum);
    string buttonState;
    
    vector<string> valAnalog;
    vector<string> valResistance;
    vector<float> fValResistance;
    vector<bool> updateWave;
    vector<Sinwave> wave;
    int radius = 50;
    float Rval;

};

