#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(640, 480);
    ofBackground(255);
    ofEnableAlphaBlending();
    ofSetCircleResolution(30);
    ofSetFrameRate(30);
    
    
    //Circle start
    for(int i=0;i<30;i++){
        Cpos[i].x=ofRandom(ofGetWidth());
        Cpos[i].y=ofRandom(0,ofGetHeight()-100);
        Cvel[i]=ofRandom(8);
    }
    //Circle end
    
    
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

    
    //Moji start
    for(int i=0;i<24;i++){
        font[i].loadFont("Batang.ttf",fontSize[i]);
        Mpos[i].x=ofRandom(ofGetWidth());
        Mpos[i].y=ofRandom(ofGetHeight());
        Mvel[i]=-1*ofRandom(6);
    }
    
    //Moji end
    
    
    //Sound start
    soundplayer[0].load("do1.mp3");
    soundplayer[1].load("re1.mp3");
    soundplayer[2].load("mi1.mp3");
    soundplayer[3].load("fa1.mp3");
    soundplayer[4].load("so1.mp3");
    soundplayer[5].load("ra1.mp3");
    soundplayer[6].load("si1.mp3");
    soundplayer[7].load("do2.mp3");
    
    for (int i=0; i<8; i++) {
        soundplayer[i].setLoop(false);
    }
    
    
    
    //Sound end
}

//--------------------------------------------------------------
void ofApp::update(){
    //Circle start
    for(int i=0;i<30;i++){
        Cpos[i].y+=Cvel[i]+(i+5)/60;
        if(Cpos[i].y>ofGetHeight()+200){
            Cpos[i].y=-200;
            Cpos[i].x=ofRandom(ofGetWidth());
            Cvel[i]=ofRandom(2,6);
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
    for(int i=0;i<24;i++){
        Mpos[i].y+=Mvel[i]-(i+20)/20;
        if(Mpos[i].y<0){
            Mpos[i].y=ofGetHeight()+150;
            Mpos[i].x=ofRandom(ofGetWidth());
            Mvel[i]=-1*ofRandom(1, 3);
        }
    }
    //Moji end
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    //Circle start
    ofSetColor(150,100);
    for(int i=0;i<30;i++){
        r=(i+2)*3;
        ofDrawCircle(Cpos[i].x,Cpos[i].y,r);
    }
    //Circle end
    
    
    //Kinect start
    ofSetColor(10,255);
    maskedImage.draw(-30,-20,640,480); //描かれないところがあるので、中心に持ってきた
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
    //Moji end
    
    
    //Sound start
    if(kinect.getNumTrackedHands()>0){
        for(int k=0; k<kinect.getNumTrackedHands();k++){
            ofxOpenNIHand hand = kinect.getTrackedHand(k);
            ofPoint p = hand.getPosition();
            
            for(int i=0;i<24;i++){
                if(Mpos[i].x-10<p.x && p.x<Mpos[i].x+50 && Mpos[i].y-10<p.y && p.y<Mpos[i].y+50){
                    int a=ofRandom(0,7);
                    if(fontSize[i]<40){
                        soundplayer[a].setVolume(0.2);
                    }else if(fontSize[i]>=40&&fontSize[i]<60){
                        soundplayer[a].setVolume(0.4);
                    }else if(fontSize[i]>=60&&fontSize[i]<80){
                        soundplayer[a].setVolume(0.6);
                    }else if(fontSize[i]>=80&&fontSize[i]<100){
                        soundplayer[a].setVolume(0.8);
                    }
                    soundplayer[a].play();
                    ofSetColor(255, 20, 147);
                    ofDrawCircle(Mpos[i].x+20, Mpos[i].y-20, 50);
                    Mpos[i].y = -100;
                
                    if(Mpos[i].y < -150){
                        Mpos[i].y = 500;
                    }
            }
            }
        }
    }
    //Sound end

    //音がドしか出てない　あまりをうまく使えていない　fontSize　soundplayer play setVolumeをいじる
    
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


