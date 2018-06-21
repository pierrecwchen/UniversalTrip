#include "Spaceship.h"
#include <cmath>

const float PI = 3.14159265f;


// Defualt constructor, generate a 0.005 radius sphere as spaceship with initial position (0, 0, 0) which point to (0, 0, 0.005).
Spaceship::Spaceship(){


	radiusOfSpaceship = 0.005f;
	velocityOfSpaceship = 0.0f;

	locationOfSpaceship = Point( 0.0f, 0.0f, 0.0f, 1.0f );
	movingOfSpaceship = Vector(0.0f, 0.0f, 0.0f, 0.0f);
	upVectorOfSpaceship = Vector(0.0f, 0.005f, 0.0f, 0.0f);

	setLookingDirection( 0.0f, PI / 2.0f );

}


// Set the point where we look at in the origin by sphere parametric equation.
void Spaceship::setLookingDirection(float changingRadianInX_, float changingRadianInY_){
	
	lookingAt = Point(  static_cast<float>( radiusOfSpaceship * sin(changingRadianInY_) * sin(changingRadianInX_)),
						static_cast<float>( radiusOfSpaceship * cos(changingRadianInY_) ),
						static_cast<float>( radiusOfSpaceship * sin(changingRadianInY_) * cos(changingRadianInX_)),
						1.0f );

}


// Return the look at point. Transform the point to right position (world coordinate) before return it.
Point Spaceship::getLookingDirection(void){

	Point result = locationOfSpaceship + lookingAt;

	return result;

}


// Update the movement vector by reset the vector with the direction we are looking and a scale factor (velocity).
// Also update the location of spaceship.
void Spaceship::updateTheSpaceship(){

	// Reset and change the direction of movement.
	movingOfSpaceship = Vector( lookingAt.getXCoordinate(), lookingAt.getYCoordinate(), lookingAt.getZCoordinate(), 0.0f );

	
	// Change the speed of movement.
	movingOfSpaceship.scaleCurrentVector(velocityOfSpaceship);

	
	// Update the location of spaceship.
	locationOfSpaceship = locationOfSpaceship + movingOfSpaceship;

}