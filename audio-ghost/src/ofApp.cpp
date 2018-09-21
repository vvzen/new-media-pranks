#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // load sounds into the appropriate vectors
    load_sounds("rattle", "wav", &rattle_sounds);
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // update the sound playing system
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p'){
        int random_index = (int) floor(ofRandom(rattle_sounds.size()));
        try {
            ofLogNotice() << "playing back sound at index " << random_index;
            rattle_sounds.at(random_index).play();
        }
        catch (bad_alloc &e){
            ofLogError() << "error while playing back sound at index " << random_index;
        }
    }
}

//--------------------------------------------------------------
void ofApp::load_sounds(string path, string file_ext, vector<ofSoundPlayer> * sounds){

    ofDirectory dir(path);
    dir.allowExt(file_ext);
    dir.listDir();

    for (int i = 0; i < dir.size(); i++){
        ofLogNotice() << dir.getPath(i);
        
        ofSoundPlayer sound;
        sound.load(dir.getPath(i));
        
        sounds->push_back(sound);
    }
}