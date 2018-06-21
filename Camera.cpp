#include "Camera.h"
#include <cmath>

const float PI = 3.14159265f;

const int FIRSTPERSON = 0;
const int THIRDPERSON = 1;
const int BACKSHOULDER = 2;
const int GODVIEW = 3;


// Update camera based on spaceship and point of view.
void Camera::updateCamera(int pointOfView, Point &spaceshipLocation, Point &spaceshipLookAt, Vector &upVectorOfSpaceship){

	// Generate new Z coordinate and normalize it.
	Vector newZCoordinate = spaceshipLookAt - spaceshipLocation;
	newZCoordinate.normalizeCurrentVector();
	

	// Generate new X coordinate and normalize it.
	Vector newXCoordinate = upVectorOfSpaceship.crossProduct(newZCoordinate);
	newXCoordinate.normalizeCurrentVector();


	// Generate new Y coordinate and normalize it.
	Vector newYCoordinate = newZCoordinate.crossProduct(newXCoordinate);
	newYCoordinate.normalizeCurrentVector();

	
	// Calculate camera location based on the point of view.
	
	// First person: camera is in front of spaceship; at the edge of the front side of spaceship.
	if(pointOfView == FIRSTPERSON){

		locationOfCamera = spaceshipLocation + (newZCoordinate * 0.005f);
		lookingAt = locationOfCamera + newZCoordinate;
		upVectorOfCamera = newYCoordinate;

	}


	// Third person: camera is at up-back side of spaceship. Look at top of spaceship.
	else if(pointOfView == THIRDPERSON){

		locationOfCamera = spaceshipLocation + (newZCoordinate * (-0.05f)) + (newYCoordinate * 0.05f);
		lookingAt = spaceshipLocation + (newYCoordinate * 0.02f);
		upVectorOfCamera = newYCoordinate;

	}


	// Back shoulder: camera is at up-back-right side of spaceship. Look at the same direction the spaceship move.
	else if(pointOfView == BACKSHOULDER){

		locationOfCamera = spaceshipLocation + (newZCoordinate * (-0.013f)) + (newYCoordinate * 0.005f) + (newXCoordinate * (-0.005f));
		lookingAt = locationOfCamera + newZCoordinate;
		upVectorOfCamera = newYCoordinate;

	}


	// God view: camera is on the top of spaceship and look at spaceship.
	else if(pointOfView == GODVIEW){

		locationOfCamera = spaceshipLocation + (newYCoordinate * 0.05f);
		lookingAt = spaceshipLocation;
		upVectorOfCamera = newZCoordinate;

	}

}