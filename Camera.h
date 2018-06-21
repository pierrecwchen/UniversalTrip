//*********************************************************
//	Camera.h			Copyright by Pierre Chen.
//
//	A class which stores the information of the camera.
//*********************************************************

#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "Sphere.h"

class Camera
{

private:

	Point locationOfCamera;
	Point lookingAt;

	Vector upVectorOfCamera;


public:

	Camera(){};


	// Setter and Getter for location of the spaceship.
	void setLocationOfCamera(Point &locationOfCamera_)
	{locationOfCamera = locationOfCamera_;};

	Point getLocationOfCamera(void)const
	{return locationOfCamera;};


	// Setter and Getter for up vector of the spaceship.
	void setUpVectorOfCamera(Vector &upVectorOfCamera_)
	{upVectorOfCamera = upVectorOfCamera_;};

	Vector getUpVectorOfCamera(void)
	{return upVectorOfCamera;};


	// Setter and Getter for location of where look at.
	void setLookingAt(Point & lookingAt_)
	{lookingAt = lookingAt_;};
	
	// Getter for look at point.
	Point getLookingAt(void)
	{return lookingAt;};

	
	void updateCamera(int pointOfView, Point &spaceshipLocation, Point &spaceshipLookAt, Vector &upVectorOfSpaceship);

};
#endif