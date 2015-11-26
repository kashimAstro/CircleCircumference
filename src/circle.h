class Circle{
	public:

        float angle;
        float sine;
        float cosine;
        float tangent;
        float rotationSpeed;
        int radius;
        ofPoint point;
	int x,y,z;

	void setup(int _radius, float _speed, int _x, int _y, int _z, int resolution){
		angle=0;
	        cosine=0;
        	sine=0;
	        tangent=0;
	        rotationSpeed = _speed;
	        radius = _radius;
		x = _x;
		y = _y;
		z = _z;
	        ofSetCircleResolution(resolution);
	}

	ofPoint getPosition(){
		return ofPoint(x,y,z);
	}

	ofPoint getPoint(){
		return point;
	}

	void update(){
                angle+=rotationSpeed;
		if (angle>=TWO_PI) {
	                angle=0;
	        }
        	cosine=cos(angle);
	        sine=sin(angle);
	        tangent=tan(angle);
	        point.set(cosine * radius, sine * radius, 0);
	}

	void draw(ofColor c, ofColor c1, bool line=true){
		ofPushMatrix();
		ofTranslate(x,y,z);
		if(line){
			ofSetLineWidth(1.2);
			ofNoFill();
	        	ofSetColor(c);
		        ofCircle(0,0, radius);
		}
		ofFill();
	        ofSetColor(c1);
	        ofCircle(point, 4);
		ofPopMatrix();
	}
};
