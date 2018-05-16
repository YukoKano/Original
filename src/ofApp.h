#pragma once

#include "ofMain.h"
#include "ofxOpenNI.h"
#include "ofxTrueTypeFontUC.h"

class ofApp : public ofBaseApp{

private:
    ofxOpenNI kinect;
    ofImage maskedImage;
    ofxTrueTypeFontUC font[50];
    
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
    
    
    ofSoundPlayer soundplayer[8];
    
    ofVec2f Cpos[30];
    ofVec2f Mpos[24];
    float Cvel[30];
    float Mvel[24];
    float r;

    int fontSize[24]={20,24,28,32,36,40,44,48,52,56,60,64,68,72,76,80,84,88,92,96};

};



