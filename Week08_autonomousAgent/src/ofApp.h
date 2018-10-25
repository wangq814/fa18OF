#pragma once

#include "ofMain.h"
#include "Vehicles.hpp"

#define TOTALNUM 1000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

    vector<Vehicles> vehicle;
    
    
    
    
    
};
