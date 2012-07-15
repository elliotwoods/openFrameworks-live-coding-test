//
//  appWrapper.cpp
//  dynamicLoad
//

#include "appWrapper.h"

//---------
appWrapper::appWrapper() {
	this->libraryPath = "/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/testApp.dylib";
	this->sourcePath = "/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/src/testApp.cpp";
	this->buildScriptPath = "/Users/elliot/dev/openFrameworks/openFrameworks/apps/tests/dynamicLoad/build_shared.sh";
	
	this->app = 0;
	this->valid = false;
	this->newSource = false;
	
	this->loadApp();
	if (this->valid)
		this->app = newApp();
}

//---------
appWrapper::~appWrapper() {
	if (this->valid) {
		deleteApp(app);
	}
	this->unloadApp();
}

//---------
//from http://linux.studenti.polito.it/elda/elda/HowTo/Inglese/mini-HowTo/HTML-pagina_singola/C%2B%2B-dlopen.html
void appWrapper::loadApp() {
	this->unloadApp();
	
	//update timestamp of our loaded source
	struct stat fileStat;
	if (stat(this->sourcePath.c_str(), &fileStat) >= 0) {
		this->fileStat = fileStat;
	}
	this->newSource = false;
	
	//perform build
	system(this->buildScriptPath.c_str());
	
	// load the app class library
    symbols = dlopen(this->libraryPath.c_str(), RTLD_LAZY);
    if (!symbols) {
        ofLogError() << "Cannot load library testApp.dylib: " << dlerror() << endl;
		char cwd[200];
		getcwd(cwd, 200);
		ofLogError() << "Current folder is " << cwd << endl;
        this->valid = false;
		return;
    }
	
    // load the symbols
    newApp = (create_t*) dlsym(symbols, "create");
    deleteApp = (destroy_t*) dlsym(symbols, "destroy");
    if (!newApp || !deleteApp) {
        ofLogError() << "Cannot load symbols: " << dlerror() << endl;
        this->valid = false;
		return;
    }
	
	this->valid = true;
	
	//pseudo-unreachable code. 
	//this is a hack to make sure we have a bunch of symbols
	//ideally we'll use -Wl,-all_load on the linker to include all symbols from openFrameworks.a
	//but we can't do that right now as there are duplicate symbols
	if ((int)symbols==1) {
		this->symbolSet();
	}
}

//---------
void appWrapper::unloadApp() {
	if (!this->valid)
		return;
	dlclose(symbols);
	this->valid = false;
}

//---------
bool appWrapper::checkValid() {
	if (this->valid)
		return true;
	else {
		//try reloading
		this->loadApp();
		if (this->valid)
			return true;
		
		cout << "App is not valid." << endl;
		return false;
	}
}

//---------
void appWrapper::setup() {
	if (this->checkValid())
		this->app->setup();
}

//---------
void appWrapper::update() {
	
	if (this->newSource) {
		this->loadApp();
	}
	
	struct stat fileStat;
	if (stat(this->sourcePath.c_str(), &fileStat) >= 0) {
		if (fileStat.st_mtimespec.tv_sec > this->fileStat.st_mtimespec.tv_sec) {
			//source file has been changed, reload next frame
			this->newSource = true;
		}
	}
	
	if (this->checkValid())
		this->app->update();
}

//---------
void appWrapper::draw() {
	if (this->checkValid())
		this->app->draw();
	if (this->newSource)
		this->drawOverlay();
}

//---------
void appWrapper::keyPressed(int key) {
	if (this->checkValid())
		this->app->keyPressed(key);
}

//---------
void appWrapper::keyReleased(int key) {
	if (key ==  ' ')
		loadApp();
	
	if (this->checkValid())
		this->app->keyReleased(key);
}

//---------
void appWrapper::mouseMoved(int x, int y) {
	if (this->checkValid())
		this->app->mouseMoved(x, y);
}

//---------
void appWrapper::mouseDragged(int x, int y, int button) {
	if (this->checkValid())
		this->app->mouseDragged(x, y, button);
}

//---------
void appWrapper::mousePressed(int x, int y, int button) {
	if (this->checkValid())
		this->app->mousePressed(x, y, button);
}

//---------
void appWrapper::mouseReleased(int x, int y, int button) {
	if (this->checkValid())
		this->app->mouseReleased(x, y, button);
}


//---------
void appWrapper::windowResized(int w, int h) {
	if (this->checkValid())
		this->app->windowResized(w, h);
}

//---------
void appWrapper::dragEvent(ofDragInfo dragInfo) {
	if (this->checkValid())
		this->app->dragEvent(dragInfo);
}

//---------
void appWrapper::gotMessage(ofMessage msg) {
	if (this->checkValid())
		this->app->gotMessage(msg);
}

//---------
void appWrapper::windowEntry(int state) {
	if (this->checkValid())
		this->app->windowEntry(state);
}

//---------
void appWrapper::drawOverlay() {
	
	ofPushStyle();
	ofEnableAlphaBlending();
	
	ofSetColor(0, 0, 0, 150);
	ofRect(ofGetCurrentViewport());
	
	ofNoFill();
	
	ofSetColor(255);
	ofPoint position;
	string message = "compiling";
	position.x = ofGetWidth() / 2 - message.length() * 8 / 2;
	position.y = ofGetHeight() / 2 - 15;
	ofDrawBitmapString(message, position);
	position.x += 1;
	ofDrawBitmapString(message, position);
	message = "Please wait....";
	position.y += 15;
	position.x = ofGetWidth() / 2 - message.length() * 8 / 2;
	ofDrawBitmapString(message, position);
	
	ofPopStyle();	
}

//---------
void appWrapper::symbolSet() {
	ofSetFrameRate(0);
	cout << ofGetFrameRate();
	cout << ofGetFrameNum();
	ofSetVerticalSync(false);
	
	ofLine(0, 0, 0, 0);
	ofRect(0, 0, 0, 0);
	ofBackground(0);
	ofToggleFullscreen();
	ofEnableSmoothing();
	
	ofVec3f position;
	ofEasyCam camera;
	camera.draw();
	camera.begin();
	camera.end();
	ofDrawGrid(100);
	ofBox(0);
	ofTranslate(position);
	
	ofDrawBitmapString("", 0, 0);
	ofDrawBitmapString(ofToString(ofGetFrameRate()), 10, 10);
	ofToString(float());
	ofToString(int());
	ofPushMatrix();
	ofPopMatrix();
	
	ofRandom(0, 100);
	
	glEnable(GL_DEPTH_FUNC);
	glDisable(GL_DEPTH_FUNC);
}
