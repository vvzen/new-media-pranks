#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		void load_sounds(string path, string file_ext, vector<ofSoundPlayer> * sounds);

		vector<ofSoundPlayer> rattle_sounds;
	
};
