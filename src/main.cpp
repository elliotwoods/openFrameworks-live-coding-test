#include "ofAppGlutWindow.h"
#include "appWrapper.h"

int main() {
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 640, 480, OF_WINDOW);
	ofRunApp(new appWrapper());
}
