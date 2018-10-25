#pragma once

#include "ofMain.h"
#include "Bird.hpp"

#define TOTALNUM 10


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    

		//void keyPressed(int key);
    
       vector<Bird> birds;
       // Bird birds;
		  
};
