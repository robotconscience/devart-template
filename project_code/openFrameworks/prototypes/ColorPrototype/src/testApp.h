#pragma once

#include "ofMain.h"
#ifdef USE_OPENNI
#include "ofxNI2.h"
#else
#include "ofxKinect.h"
#endif

#include "ofxUI.h"

class ColorLayer {
public:
    ofColor color;
    float   z;
};

class testApp : public ofBaseApp{

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
#ifdef USE_OPENNI
        ofxNI2::Device * device;
        ofxNI2::DepthStream depth;
        ofxNI2::ColorStream color;
#else
        ofxKinect kinect;
#endif

        ofPixels remappedPix;
        ofImage  remappedImage;
        ofVboMesh vbo;
    
        ofShader bumpShader;
    
        ofEasyCam camera;
        ofxUICanvas * gui;
    
        // sediment-style layers
        vector<ColorLayer> colors;
    
        // 3D color cube
        vector<ofColor> cubeColors;
        ofFbo colorImageFront, colorImageBack;
};
