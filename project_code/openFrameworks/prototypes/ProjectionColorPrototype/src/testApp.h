#pragma once

#include "ofMain.h"
#include "ofxOpenCv.h"
#include "ofxKinect.h"
#include "ofxCamaraLucida.h"

#include "ofxUI.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void exit();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
        // CAMERA
        ofxKinect kinect;
    
        // Camera lucida stuff  
        cml::CamaraLucida *cml;
        
        void render_texture(ofEventArgs &args);
        void render_3d(ofEventArgs &args);
        void render_2d(ofEventArgs &args);
    
        // UI
        ofxUICanvas * gui;
    
        // gobstopper map
        ofFbo       colorMap;
        ofShader    gobStopper;
        vector<ofFloatColor> colors;
        float * colorsGLSL;
        ofVec3f center;
        ofMesh colorMesh;
};
