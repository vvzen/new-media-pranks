#pragma once

#include "ofMain.h"
using namespace std::chrono;

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

		void load_sounds(string path, string file_ext, vector<ofSoundPlayer> * sounds);
		void play_random_sound(vector<ofSoundPlayer> * sounds);

		vector<ofSoundPlayer> rattle_sounds;


		steady_clock::time_point start_time, current_time;
		bool can_play_sound;
};