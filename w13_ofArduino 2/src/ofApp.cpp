/*
 horizontal: 6 tracks - different sounds
 vertical: 3 variations - different tempo
 restistor: all 680 ohm
 GROUP WORK WITH YVONNE:
 https://github.com/yvonne-dong/dongy987_dtOF_2018/tree/master/w13_ofArduino
*/

#include "ofApp.h"
//float am = 0;
const int nSounds = 6; //length of sound vector - all sounds in the folder
const int nValAnalog = 6; //A0 - A5 6 tracks
const int radius = 40;
//--------------------------------------------------------------
void ofApp::setup(){
    //ofBackground(255, 100, 100);
    ofBackground(255);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    ofSetFrameRate(60);
    
    font.load("franklinGothic.otf", 20);
    smallFont.load("franklinGothic.otf", 14);
    
    ard.connect("/dev/cu.usbmodem14201", 57600);
    
    ofAddListener(ard.EInitialized, this, &ofApp::setupArduino);
    bSetupArduino = false;
    
    
    for(int k = 0; k < 6; k++){
        float setHue = ofMap(k,0,6,0,255);
        Sinwave w = Sinwave(0,0,0,setHue);
        bool waveUpdate = false;
        w.setFrequency(0.1);
       // w.setAmplitude(10);
        
        
        
        updateWave.push_back(waveUpdate);
        wave.push_back(w);
    }
    
    
    
    for (int i = 0; i < nSounds; i ++){
        ofSoundPlayer sound;
        int nameNum = i+1;
        sound.load(ofToString(nameNum) + ".mp3");
        sounds.push_back(sound);
    }
    
    
    for (int j = 0; j < nValAnalog; j ++) {
        string analogValue = "value";
        string resistanceVal = "rVal";
        float floatValResistance = 0.;
        valAnalog.push_back(analogValue);
        valResistance.push_back(resistanceVal);
        fValResistance.push_back(floatValResistance);
    }
    
    
//    for (int k = 0; k < nSounds; k++){
//
//        buttonPos[k].set((ofGetWidth()/7)*(k+1),ofGetHeight()-300);
//
//}
    
}

//--------------------------------------------------------------
void ofApp::update(){
    updateArduino();
    
    for(int k = 0; k < 6; k++){
        if (updateWave[k] == true) {
            wave[k].update(am);
        } else {
            wave[k].amp = 0;
            wave[k].amplitude = 0;
            wave[k].space = 0;
        }
    }
    
    
//    for (int k = 0; k < nSounds; k++){
//
//        buttonPos[k].set((ofGetWidth()/7)*(k+1),ofGetHeight()-300);
//    }
}

//--------------------------------------------------------------
void ofApp::setupArduino(const int & version) {
    
    ofRemoveListener(ard.EInitialized, this, &ofApp::setupArduino);
    
    bSetupArduino = true;
    
    /*
    ofLogNotice() << ard.getFirmwareName();
    ofLogNotice() << "firmata v" << ard.getMajorFirmwareVersion() << "." << ard.getMinorFirmwareVersion();
    */
    
    //loop to setup analog inputs
    for (int i = 0; i < nValAnalog; i ++) {
        ard.sendAnalogPinReporting(i, ARD_ANALOG);
    }
//    //A0 - analog input
//    ard.sendAnalogPinReporting(0, ARD_ANALOG);
//    //A1 - analog input
//    ard.sendAnalogPinReporting(1, ARD_ANALOG);
    
    
    // Listen for changes (digital and analog pins)
//    ofAddListener(ard.EDigitalPinChanged, this, &ofApp::digitalPinChanged);
    ofAddListener(ard.EAnalogPinChanged, this, &ofApp::analogPinChanged);
}

//--------------------------------------------------------------
void ofApp::updateArduino(){
    //update the arduino, get any data or messages.
    ard.update();
}
//--------------------------------------------------------------
//calculate resistance change for each track
void ofApp::calculateResistance(int _pinNum){
    int raw = 0;
    int Vin = 5;
    float Vout = 0;
    float R1 = 1000;
    float R2 = 0;
    float buffer = 0;

    raw = ard.getAnalog(_pinNum);
    fValResistance[_pinNum] = raw;
    valResistance[_pinNum] = ofToString(raw);

}

//--------------------------------------------------------------
void ofApp::analogPinChanged(const int & pinNum) {
   
    if (pinNum == 0) {
        valAnalog[0] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
        
    } else if (pinNum == 1) {
        valAnalog[1] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
       
    } else if (pinNum == 2) {
        valAnalog[2] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
      
    } else if (pinNum == 3) {
        valAnalog[3] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 4) {
        valAnalog[4] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    } else if (pinNum == 5) {
        valAnalog[5] = ofToString(ard.getAnalog(pinNum));
        calculateResistance(pinNum);
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    ofEnableAlphaBlending();
    ofSetColor(0, 0, 0, 127);
    ofDisableAlphaBlending();
    ofSetColor(255, 255, 255);
    
   // for(int k = 0; k < 6; k++){
       // wave[k].draw(100*(k+1));
    
    
    if (!bSetupArduino){
        
    
        //font.drawString("arduino not ready...\n", 515, 40);
    }
    else {
        for (int i = 0; i < valAnalog.size(); i ++) {
            
            ofPushStyle();
            
            ofSetColor(0);
           
            font.drawString("analog pin"+ ofToString(i)+ ": "+valAnalog[i], 515, 40+i*40);
            font.drawString("R2: "+ valResistance[i], 515, 60+i*40);
            
             ofPopStyle();
        }
        //loop through all the resistance values and play sounds
        for (int j = 0; j < fValResistance.size(); j ++) {
            
            
            
             wave[j].draw((ofGetHeight()/7)*(j+1));
            
            if((fValResistance[j] > 450 && fValResistance[j] < 600) && !sounds[j].isPlaying()) {
                am=10;
                stopSound(j);
                sounds[j].play();
                sounds[j].setSpeed(0.5f);
                updateWave[j]=true;
               // wave[j].setAmplitude(10);
                
                
            } else if((fValResistance[j] > 600 && fValResistance[j] < 700) && !sounds[j].isPlaying()){
                am=20;
                stopSound(j);
                sounds[j].play();
                sounds[j].setSpeed(1.0f);
                updateWave[j]=true;
                //wave[j].setAmplitude(30);
                
            } else if ((fValResistance[j] > 700 && fValResistance[j] < 820)&& !sounds[j].isPlaying()) {
                stopSound(j);
                sounds[j].play();
                sounds[j].setSpeed(1.5f);
                updateWave[j]=true;
                //wave[j].setAmplitude(45);
                am=40;
            } else if (fValResistance[j] > 820 || fValResistance[j] == 0) {
                stopSound(j);
                updateWave[j]=false;
               //wave[j].setAmplitude(0);
               

            }
           
       // }
        }
        
//        if((fValResistance[0] > 600 && fValResistance[0] < 800) && !sounds[0].isPlaying()) {
//
//            stopSound(0);
//            sounds[0].play();
//            sounds[0].setSpeed(1.0f);
//
//        } else if((fValResistance[0] > 300 && fValResistance[0] < 600) && !sounds[0].isPlaying()){
//
//            stopSound(0);
//            sounds[0].play();
//            sounds[0].setSpeed(0.2f);
//
//        }
//        if((fValResistance[1] > 600 && fValResistance[1] < 800) && !sounds[1].isPlaying()) {
//
//            stopSound(1);
//            sounds[1].play();
//            sounds[1].setSpeed(1.0f);
//
//        } else if((fValResistance[1] > 300 && fValResistance[1] < 600) && !sounds[1].isPlaying()){
//
//            stopSound(1);
//            sounds[1].play();
//            sounds[1].setSpeed(0.2f);
//
//        }
    }
}
//--------------------------------------------------------------
void ofApp::stopSound(int _soundNum){
    if (sounds[_soundNum].isPlaying()) {
        sounds[_soundNum].stop();
    }
}


