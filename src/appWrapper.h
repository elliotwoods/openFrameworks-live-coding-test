//
//  appWrapper.h
//  dynamicLoad
//
#pragma once

#include <dlfcn.h>
#include <sys/stat.h>
#include "ofMain.h"

#include "wrappedApp.h"

class appWrapper : public ofBaseApp {
public:
	appWrapper();
	~appWrapper();
	
	void loadApp();
	void unloadApp();
	bool checkValid();
	
	//-------
	//ofBaseApp
	//
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
	virtual void windowEntry (int state);
	//
	//--------
	
protected:
	void drawOverlay();
	void symbolSet();
	
	string libraryPath;
	string sourcePath;
	string buildScriptPath;
	
	ofBaseApp * app;
	bool valid;
	
	void * symbols;
	create_t * newApp;
	destroy_t * deleteApp;
	
	struct stat fileStat;
	bool newSource;
};