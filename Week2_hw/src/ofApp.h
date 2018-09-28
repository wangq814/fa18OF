#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
   
    ofPoint pos1;
     ofPoint pos2;
     ofPoint pos3;
     ofPoint pos4;
     ofPoint pos5;
     ofPoint pos6;
    ofPoint pos7;
    
    float radius1;
    float radius2;
    float radius3;
    float radius4;
    float radius5;
    float radius6;
    float radius7;
    
    float angle;
    
    
		
};
