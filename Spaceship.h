//*********************************************************
//	Spaceship.h			Copyright by Pierre Chen.
//
//	A class which stores the information of the spaceship.
//*********************************************************

#ifndef _SPACESHIP_H_
#define _SPACESHIP_H_

#include "Camera.h"

class Spaceship
{

private:

	float radiusOfSpaceship;
	float velocityOfSpaceship;


	Point locationOfSpaceship;
	Point lookingAt;


	Vector movingOfSpaceship;
	Vector upVectorOfSpaceship;

public:

	Spaceship();


	// Setter and Getter for location of the spaceship.
	void setLocationOfSpaceship(Point &locationOfSpaceship_)
	{locationOfSpaceship = locationOfSpaceship_;};

	Point getLocationOfSpaceship(void)const
	{return locationOfSpaceship;};


	// Setter and Getter for velocity of the movement.
	void setVelocityOfSpaceship(float velocityOfSpaceship_)
	{velocityOfSpaceship = velocityOfSpaceship_;};

	float getVelocityOfSpaceship(void)
	{return velocityOfSpaceship;};
	

	// Setter and Getter for moving vector of the spaceship.
	void setMovingOfSpaceship(Vector &movingOfSpaceship_)
	{movingOfSpaceship = movingOfSpaceship_;};

	// Has to be the updated one.
	Vector getMovingOfSpaceship(void){

		// Reset and change the direction of movement.
		movingOfSpaceship = Vector( lookingAt.getXCoordinate(), lookingAt.getYCoordinate(), lookingAt.getZCoordinate(), 0.0f );
		
		// Change the speed of movement.
		movingOfSpaceship.scaleCurrentVector(velocityOfSpaceship);
		
		return movingOfSpaceship;

	};


	// Setter and Getter for up vector of the spaceship.
	void setUpVectorOfSpaceship(Vector &upVectorOfSpaceship_)
	{upVectorOfSpaceship = upVectorOfSpaceship_;};

	Vector getUpVectorOfSpaceship(void)
	{return upVectorOfSpaceship;};


	void setLookingDirection(float changingRadianInX_, float changingRadianInY_);
	Point getLookingDirection(void);


	void updateTheSpaceship();
};
#endif