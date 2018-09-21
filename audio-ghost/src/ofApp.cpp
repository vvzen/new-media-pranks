#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    // load sounds into the appropriate vectors
    load_sounds("rattle", "wav", &rattle_sounds);
    can_play_sound = true;
    start_time = steady_clock::now();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    // update the sound playing system
    ofSoundUpdate();

    // check the elapsed time
    current_time = steady_clock::now();
    int elapsed_seconds = duration_cast<seconds>(current_time - start_time).count();
    int millis_modulo = ofGetElapsedTimeMillis() % 1000;
    int seconds_interval = 5 * 60;
    can_play_sound = elapsed_seconds % seconds_interval == 1;

    // ofLogNotice() << "Elapsed seconds: " << elapsed_seconds;
    // ofLogNotice() << "can_play_sound: " << can_play_sound;
    // ofLogNotice() << "millis_modulo:  " << millis_modulo;

    if (can_play_sound){
        if (millis_modulo < 25)
        play_random_sound(&rattle_sounds);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(40);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'p'){
        play_random_sound(&rattle_sounds);
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

//--------------------------------------------------------------
void ofApp::play_random_sound(vector<ofSoundPlayer> * sounds){

    int random_index = (int) floor(ofRandom(sounds->size()));
    try {
        ofLogNotice("play_random_sound") << "playing back sound at index " << random_index;
        sounds->at(random_index).play();
    }
    catch (bad_alloc &e){
        ofLogError("play_random_sound") << "error while playing back sound at index " << random_index;
    }
}