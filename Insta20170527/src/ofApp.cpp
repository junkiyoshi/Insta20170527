#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(30);
	ofBackground(0);
	ofSetWindowTitle("Sphere");

	this->radius = 250;
	for (int i = 0; i < 3; i++) {
		this->noise_a[i] = ofRandom(10);
		this->noise_b[i] = ofRandom(10);
	}
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	cam.begin();

	for (int i = 0; i < 3; i++) {
		int a = ofNoise(this->noise_a[i]) * 760;
		int b = ofNoise(this->noise_b[i]) * 180;
		this->noise_a[i] += 0.01;
		this->noise_b[i] += 0.02;
		int s_radius = this->radius * 1.5;
		int s_x = s_radius * cos(a * DEG_TO_RAD) * sin(b * DEG_TO_RAD);
		int s_y = s_radius * sin(a * DEG_TO_RAD) * sin(b * DEG_TO_RAD);
		int s_z = s_radius * cos(b * DEG_TO_RAD);
		this->c_locations[i] = ofVec3f(s_x, s_y, s_z);

	}

	int span = 5;
	for (int i = 0; i < 360; i += span) {
		for (int j = 0; j < 180; j += span) {
			int x = radius * cos(i * DEG_TO_RAD) * sin(j * DEG_TO_RAD);
			int y = radius * sin(i * DEG_TO_RAD) * sin(j * DEG_TO_RAD);
			int z = radius * cos(j * DEG_TO_RAD);

			ofSetColor(255);
			ofVec3f location = ofVec3f(x, y, z);
			//float noise_value = ofNoise(x / (span * 100.f), y / (span * 100.f), z / (span * 100.f), ofGetFrameNum() * 0.05);

			int color_value[3] = { 0, 0, 0 };

			bool c_flag = false;
			for (int i = 0; i < 3; i++) {
				ofVec3f distance = this->c_locations[i] - location;
				if (distance.length() < this->radius) {
					color_value[i] = 255;
					c_flag = true;
				}
			}

			if (c_flag) {
				ofSetColor(color_value[0], color_value[1], color_value[2]);
				location *= 1.5;
			} else {
				ofSetColor(128);
			}
			ofSphere(location, 5);
		}
	}

	cam.end();
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
