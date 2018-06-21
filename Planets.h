//***********************************************************
//	Planets.h			Copyright by Pierre Chen.
//
//	A class which stores a list of planets with their radius
//	and center point. Organize them based on which quadrant
//	the center point is in.
//
//***********************************************************

#ifndef _PLANETS_H_
#define _PLANETS_H_

#include "Spaceship.h"
#include <vector>

using namespace std;

class Planets
{

private:

	vector<Point> posPosPosLocation;
	vector<Point> posPosNegLocation;
	vector<Point> posNegPosLocation;
	vector<Point> negPosPosLocation;
	vector<Point> negNegPosLocation;
	vector<Point> negPosNegLocation;
	vector<Point> posNegNegLocation;
	vector<Point> negNegNegLocation;

	vector<float> posPosPosRadius;
	vector<float> posPosNegRadius;
	vector<float> posNegPosRadius;
	vector<float> negPosPosRadius;
	vector<float> negNegPosRadius;
	vector<float> negPosNegRadius;
	vector<float> posNegNegRadius;
	vector<float> negNegNegRadius;


public:

	Planets(){}; // Defult constructor, create empty planet list.
	

	bool isOccupied(Point &centerOfPlanet, float radiusOfPlanet);
	bool isDistanceLessThanTwoRadius(Point &centerOfPlanet1, float radiusOfPlanet1, Point &centerOfPlanet2, float radiusOfPlanet2);
	

	void setPlanetInfomation(Point &centerOfPlanet, float radiusOfPlanet);
};
#endif