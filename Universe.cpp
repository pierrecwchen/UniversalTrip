#include "Universe.h"
#include <cmath>
#include <new>


// Default constructor. Generate an universe with 1000 planets, random seed 100, minimum size 1 radius, and maximum size 10 radius.
Universe::Universe(){

	seedOfRandom = 100;


	densityOfPlanet = 1000/1000000000;

	minPlanetSizeInRadius = 1.0f;
	maxPlanetSizeInRadius = 10.0f;


	singleSphere = Sphere(); // Sphere which used to generate all planets.


	numTotalVerticesOfPlanets = (static_cast<int>(densityOfPlanet * 1000000000) + 1) * singleSphere.getNumOfVertices();


	planetList = Planets();


	planets = new Point[numTotalVerticesOfPlanets];

	normalOfPoints = new Vector[numTotalVerticesOfPlanets];


	generatePlanets(seedOfRandom, densityOfPlanet, minPlanetSizeInRadius, maxPlanetSizeInRadius);

}


// Destructor.
Universe::~Universe(){

	delete[] planets;
	planets = 0;

	delete[] normalOfPoints;
	normalOfPoints = 0;

}


// Copy constructor.
Universe::Universe(const Universe &otherUniverse){
	
	seedOfRandom = otherUniverse.seedOfRandom;

	numTotalVerticesOfPlanets = otherUniverse.numTotalVerticesOfPlanets;


	densityOfPlanet = otherUniverse.densityOfPlanet;

	minPlanetSizeInRadius = otherUniverse.minPlanetSizeInRadius;
	maxPlanetSizeInRadius = otherUniverse.maxPlanetSizeInRadius;


	singleSphere = otherUniverse.singleSphere;
	

	planetList = otherUniverse.planetList;


	planets = new Point[numTotalVerticesOfPlanets];

	normalOfPoints = new Vector[numTotalVerticesOfPlanets];

	for(int i = 0; i < numTotalVerticesOfPlanets; i++){
		
		planets[i] = otherUniverse.planets[i];
		normalOfPoints[i] = otherUniverse.normalOfPoints[i];
	
	}

}


// Assignment.
Universe Universe::operator=(const Universe &otherUniverse){
	
	seedOfRandom = otherUniverse.seedOfRandom;

	numTotalVerticesOfPlanets = otherUniverse.numTotalVerticesOfPlanets;


	densityOfPlanet = otherUniverse.densityOfPlanet;

	minPlanetSizeInRadius = otherUniverse.minPlanetSizeInRadius;
	maxPlanetSizeInRadius = otherUniverse.maxPlanetSizeInRadius;


	singleSphere = otherUniverse.singleSphere;
	

	planetList = otherUniverse.planetList;


	planets = new Point[numTotalVerticesOfPlanets];

	normalOfPoints = new Vector[numTotalVerticesOfPlanets];

	for(int i = 0; i < numTotalVerticesOfPlanets; i++){
		
		planets[i] = otherUniverse.planets[i];
		normalOfPoints[i] = otherUniverse.normalOfPoints[i];
	
	}


	return *this;

}


// Constructor which generate an universe by given information.
Universe::Universe(int numSeed, double densityOfPlanet_, double minPlanetSizeInRadius_, double maxPlanetSizeInRadius_){
	
	seedOfRandom = numSeed;
	
	densityOfPlanet = densityOfPlanet_;

	minPlanetSizeInRadius = minPlanetSizeInRadius_;
	maxPlanetSizeInRadius = maxPlanetSizeInRadius_;


	singleSphere = Sphere();


	numTotalVerticesOfPlanets = (static_cast<int>(densityOfPlanet * 1000000000) + 1) * singleSphere.getNumOfVertices();


	planetList = Planets();


	planets = new Point[numTotalVerticesOfPlanets];

	normalOfPoints = new Vector[numTotalVerticesOfPlanets];
	

	generatePlanets(seedOfRandom, densityOfPlanet, minPlanetSizeInRadius, maxPlanetSizeInRadius);

}


// Generate planets in the universe.
void Universe::generatePlanets(int numSeed, double densityOfPlanet, double minPlanetSize, double maxPlanetSize){

	srand(numSeed);


	int numPlanet = static_cast<int>(densityOfPlanet * 1000000000) + 1;


	double differenceBetweenMaxAndMinSize = maxPlanetSize - minPlanetSize;


	int planetCounter = 0;


	Point initialSpaceshipLocation = Point( 0.0f, 0.0f, 0.0f, 1.0f );


	// Generate the spaceship

	Matrix spaceshipScaleMatrix = Matrix();
	spaceshipScaleMatrix.scaleCurrentMatrixByScaleVector(Vector(0.005f, 0.005f, 0.005f, 0.0f));

	for(int i = 0; i < singleSphere.getNumOfVertices(); i++){
				
		normalOfPoints[i] = Vector(singleSphere.getPointsOfSphere()[i].getXCoordinate(),
																	singleSphere.getPointsOfSphere()[i].getYCoordinate(),
																	singleSphere.getPointsOfSphere()[i].getZCoordinate(), 0.0f);

		planets[i] = spaceshipScaleMatrix * singleSphere.getPointsOfSphere()[i];
			
	}

	planetCounter++;

	while(planetCounter < numPlanet){

		// X, Y, Z between -500 and 500.
		Point centerOfPlanet = Point( static_cast<float>( (rand() % 1001 - 500) ), 
									  static_cast<float>( (rand() % 1001 - 500) ), 
									  static_cast<float>( (rand() % 1001 - 500) ), 1.0f);

		// Radius = minimum radius + a small interval.
		float radiusOfPlanet = static_cast<float>( rand() % 101 / 100 ) * static_cast<float>( differenceBetweenMaxAndMinSize ) + static_cast<float>( minPlanetSize );


		// Determine whether there is an exist planet or not. If not, generate a planet with vertices and normals.
		if(!planetList.isOccupied(centerOfPlanet, radiusOfPlanet) &&
			!planetList.isDistanceLessThanTwoRadius(initialSpaceshipLocation, 0.005f, centerOfPlanet, radiusOfPlanet)){

			
			// Matrices for scale and transform the sphere in order to generate a new planet.
			Matrix translateMatrix = Matrix();
			Matrix scaleMatrix = Matrix();
			
			scaleMatrix.scaleCurrentMatrixByScaleVector( Vector( radiusOfPlanet, radiusOfPlanet, radiusOfPlanet, 0.0f ) );
			
			translateMatrix.translateCurrentMatrixByVector( Vector( centerOfPlanet.getXCoordinate(),
																	centerOfPlanet.getYCoordinate(), 
																	centerOfPlanet.getZCoordinate(), 0.0f ) );

			
			for(int i = 0; i < singleSphere.getNumOfVertices(); i++){
				
				normalOfPoints[planetCounter*singleSphere.getNumOfVertices()+i] = Vector(singleSphere.getPointsOfSphere()[i].getXCoordinate(),
																						 singleSphere.getPointsOfSphere()[i].getYCoordinate(),
																						 singleSphere.getPointsOfSphere()[i].getZCoordinate(), 0.0f);

				planets[planetCounter*singleSphere.getNumOfVertices()+i] = translateMatrix * scaleMatrix * singleSphere.getPointsOfSphere()[i];
			
			}


			// Add the planet into list
			planetList.setPlanetInfomation(centerOfPlanet, radiusOfPlanet);


			planetCounter++;
			
		}
	
	}

}