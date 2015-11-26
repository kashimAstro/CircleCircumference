#include "ofMain.h"
#include "ofAppGlutWindow.h"
#include "circle.h"

class xApp : public ofBaseApp {
	public:
		ofEasyCam cam;
		int w,h;
		vector<Circle> circle;
		vector<ofColor> colors;
		bool line;

		int remove[10];

		void setup(){
			ofSetVerticalSync(false);
			ofSetFrameRate(150);
			w=ofGetScreenWidth();
			h=ofGetScreenHeight();
			float time;

			for(int i = 0; i < 60; i++){
				for(int j = 0; j < 50; j++){
					if(j % 2 == 0)
						time = .16f;
					else
						time = .35f;
					int radius=50;
					int offset=-25;
					Circle p;
					int x=i*((radius*2)+offset);
					int y=j*((radius*2)+offset);
					p.setup(radius,time,x,y,0,60);
					circle.push_back(p);
					ofColor c = ofColor(0);
					colors.push_back(c);
				}
			}
		}

		void update(){
			for(int i = 0; i < circle.size(); i++) {
				circle[i].update();
			}
		}

		void draw(){
			ofBackground(255);
			for(int i = 0; i < circle.size(); i++) circle[i].draw(colors[i],ofColor::black,line);
		}

		void keyPressed(int key){
			line=!line;
		}
};

int main( ){
	ofAppGlutWindow window;
	ofSetupOpenGL(&window, 1280, 720, OF_WINDOW);
	ofRunApp(new xApp());

}
