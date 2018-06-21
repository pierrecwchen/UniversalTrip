//**************************************************************
//	Universe.h			Copyright by Pierre Chen.
//
//	A model class which store all information about the Universe.
//
//**************************************************************

#ifndef _UNIVERSE_H_
#define _UNIVERSE_H_

#include "Planets.h"

class Universe
{
private:

	int seedOfRandom;
	int numTotalVerticesOfPlanets;
	

	double densityOfPlanet;


	double minPlanetSizeInRadius;
	double maxPlanetSizeInRadius;
	

	Sphere singleSphere;
	

	Planets planetList;
	

	Point* planets;

	Vector* normalOfPoints;


public:

	Universe();
	Universe(int numSeed_, double densityOfPlanet_, double minPlanetSizeInRadius_, double maxPlanetSizeInRadius_);
	
	Universe(const Universe &universe);
	Universe operator=(const Universe &universe);
	~Universe();


	void generatePlanets(int numSeed, double densityOfPlanet, double minPlanetSize, double maxPlanetSize);


	// Return planet list.
	Planets getPlanetList(void)
	{return planetList;};
	
	// Return all points for universe.
	Point* getPointsOfPlanets(void)
	{return planets;};

	// Return all normals for universe vertices.
	Vector* getNormalOfPoints(void)
	{return normalOfPoints;};


	// Return number of planet in the universe.
	int getNumPlanets(void)const
	{return (static_cast<int>(densityOfPlanet * 1000000000) + 1);};

	// Return number of points for one planet.
	int getNumPointsPerPlanet(void)const
	{return singleSphere.getNumOfVertices();};

	// Return number of points for a circle of a planet.
	int getNumPointsPerCircleOfPlanet(void)const
	{return singleSphere.getNumOfVertexEachCircle();};

	// Return number of layers along z-axis of a planet.
	int getNumZLayersOfPlanet(void)const
	{return singleSphere.getNumOfZLayers();};

};
#endif