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
    
    
    ofSoundPlayer soundplayer[7];
    
    ofVec2f Cpos[50];
    ofVec2f Mpos[30];
    float Cvel[50];
    float Mvel[30];
    float r;
    int a;
    int fontSize;
};



