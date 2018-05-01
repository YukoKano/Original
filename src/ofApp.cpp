#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
    ofBackground(255);
    ofEnableAlphaBlending();
    ofSetCircleResolution(30);
    ofSetFrameRate(30);


    //Sound start
    soundplayer[0].load("do.mp3");
    soundplayer[1].load("re.mp3");
    soundplayer[2].load("mi.mp3");
    soundplayer[3].load("fa.mp3");
    soundplayer[4].load("so.mp3");
    soundplayer[5].load("ra.mp3");
    soundplayer[6].load("si.mp3");
    for(int i=0; i<7; i++){
        soundplayer[i].setVolume(0.8);
    }
    //Sound end
    
    
    //Kinect start
    kinect.setup();
    kinect.setRegister(true);
    kinect.setMirror(true);

    kinect.addDepthGenerator();
    kinect.addImageGenerator();
    kinect.getDepthGenerator().GetAlternativeViewPointCap().SetViewPoint(kinect.getImageGenerator());
    
    kinect.setUseDepthRawPixels(true);
    
    kinect.addHandsGenerator();
    kinect.addAllHandFocusGestures();
    kinect.setMaxNumHands(1);
    
    kinect.start();
    
    maskedImage.allocate(640, 480, OF_IMAGE_COLOR_ALPHA);

    
    //Kinect end

    
    //Circle start
    for(int i=0;i<50;i++){
        Cpos[i].x=ofRandom(ofGetWidth());
        Cpos[i].y=ofRandom(ofGetHeight());
        Cvel[i]=ofRandom(8);
    }
    //Circle end
    
    
    //Moji start
    for(int i=0;i<30;i++){
        fontSize = ofRandom(20,100);
        font[i].loadFont("Batang.ttf",fontSize);
        Mpos[i].x=ofRandom(ofGetWidth());
        Mpos[i].y=ofRandom(ofGetHeight());
        Mvel[i]=-1*ofRandom(6);
    }
    //Moji end
    
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    //Circle start
    for(int i=0;i<30;i++){
        Cpos[i].y+=Cvel[i]+(i+5)/50;
        if(Cpos[i].y>ofGetHeight()+200){
            Cpos[i].y=-200;
            Cpos[i].x=ofRandom(ofGetWidth());
            Cvel[i]=ofRandom(8);
        }
    }
    //Circle end
    
    
    //Kinect start
    kinect.update();
    unsigned char *maskedImageData = maskedImage.getPixels().getData();
    unsigned char *imageData=kinect.getImagePixels().getData();
    unsigned short *depthData = kinect.getDepthRawPixels().getData();
    
    for(int k=0; k<640*480; k++){
        maskedImageData[k*4+0]=imageData[k*3+0];
        maskedImageData[k*4+1]=imageData[k*3+1];
        maskedImageData[k*4+2]=imageData[k*3+2];
        
        if(300 <= depthData[k] && depthData[k]<600){
            maskedImageData[k*4+3]=255;
        }else{
            maskedImageData[k*4+3]=0;
        }
    }
    maskedImage.setFromPixels(maskedImageData,640,480,OF_IMAGE_COLOR_ALPHA);
    //kinect end
    
    
    //Moji start
    for(int i=0;i<30;i++){
        Mpos[i].y+=Mvel[i]-(i+10)/50;
        if(Mpos[i].y<0){
            fontSize = ofRandom(20,100);
            Mpos[i].y=ofGetHeight()+150;
            Mpos[i].x=ofRandom(ofGetWidth());
            Mvel[i]=-1*ofRandom(6);
        }
    }
    //Moji end
    
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Circle start
    ofSetColor(150,100);
    for(int i=0;i<30;i++){
        r=i*2.5;
        ofDrawCircle(Cpos[i].x,Cpos[i].y,r);
    }
    //Circle end
    
    
    //Kinect start
    ofSetColor(10,255);
    maskedImage.draw(0,0,640,480);
    //Kinect end
    
    
    //Moji start
    ofSetColor(0);
    font[0].drawString("あ",Mpos[0].x,Mpos[0].y);
    font[1].drawString("い",Mpos[1].x,Mpos[1].y);
    font[2].drawString("う",Mpos[2].x,Mpos[2].y);
    font[3].drawString("え",Mpos[3].x,Mpos[3].y);
    font[4].drawString("お",Mpos[4].x,Mpos[4].y);
    font[5].drawString("か",Mpos[5].x,Mpos[5].y);
    font[6].drawString("き",Mpos[6].x,Mpos[6].y);
    font[7].drawString("く",Mpos[7].x,Mpos[7].y);
    font[8].drawString("け",Mpos[8].x,Mpos[8].y);
    font[9].drawString("こ",Mpos[9].x,Mpos[9].y);
    font[10].drawString("さ",Mpos[10].x,Mpos[10].y);
    font[11].drawString("し",Mpos[11].x,Mpos[11].y);
    font[12].drawString("す",Mpos[12].x,Mpos[12].y);
    font[13].drawString("せ",Mpos[13].x,Mpos[13].y);
    font[14].drawString("そ",Mpos[14].x,Mpos[14].y);
    font[15].drawString("た",Mpos[15].x,Mpos[15].y);
    font[16].drawString("ち",Mpos[16].x,Mpos[16].y);
    font[17].drawString("つ",Mpos[17].x,Mpos[17].y);
    font[18].drawString("て",Mpos[18].x,Mpos[18].y);
    font[19].drawString("と",Mpos[19].x,Mpos[19].y);
    font[20].drawString("な",Mpos[20].x,Mpos[20].y);
    font[21].drawString("に",Mpos[21].x,Mpos[21].y);
    font[22].drawString("ぬ",Mpos[22].x,Mpos[22].y);
    font[23].drawString("ね",Mpos[23].x,Mpos[23].y);
    font[24].drawString("の",Mpos[24].x,Mpos[24].y);
    font[25].drawString("は",Mpos[25].x,Mpos[25].y);
    font[26].drawString("ひ",Mpos[26].x,Mpos[26].y);
    font[27].drawString("ふ",Mpos[27].x,Mpos[27].y);
    font[28].drawString("へ",Mpos[28].x,Mpos[28].y);
    font[29].drawString("ほ",Mpos[29].x,Mpos[29].y);
    //Moji end
    
    
    //Sound start
    if(kinect.getNumTrackedHands()>0){
        for(int i=0; i<kinect.getNumTrackedHands();i++){
            
            ofxOpenNIHand hand = kinect.getTrackedHand(i);
            ofPoint p = hand.getPosition();
            ofSetColor(150,100);
            ofDrawCircle(p.x, p.y, 20);
            /* int j = ofRandom(30);
            if(Mpos[j].x-10<p.x && p.x<Mpos[j].x+10 && Mpos[j].y-10<p.y && p.y<Mpos[j].y+10){
                    int a = ofRandom(7);
                    soundplayer[a].play();
            } */
        }
    }
    
    //Sound end
    
    
    //FrameRateを描いてくれるやつ
    ofDrawBitmapString(ofToString(ofGetFrameRate()), 10,10);
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}


