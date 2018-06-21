//*************************************************************
//	Sphere.h			Copyright by Pierre Chen.
//
//	A class which generate a sphere using parametric equation.
//*************************************************************

#ifndef _SPHERE_H_
#define _SPHERE_H_

#include "Matrix.h"

class Sphere
{

private:

	int numZLayers;
	int numVertexEachCircle;
	int numPointsPerSphere;
	int numTotalPointsForDrawing;


	float radiusOfSphere;


	Point* pointsPerSphere;
	Point* totalPointsForDrawing;
	

	void generateVerticesOfSphere();
	void generateDrawableSphere();

public:

	Sphere();
	Sphere(int numZLayers, int numVertexEachCircle, float radiusOfSphere_);
	
	Sphere(const Sphere &sphere);
	Sphere operator=(const Sphere &sphere);
	~Sphere();
	

	int getNumOfVertexEachCircle(void)const
	{return numVertexEachCircle;}; // Return number of vertices for each circle.
	
	int getNumOfZLayers(void)const
	{return numZLayers;}; // Return number of layers along Z axis.
	
	int getNumOfVertices(void)const
	{return numTotalPointsForDrawing;}; // Return number of vertices for drawing a sphere.
	

	Point* getPointsOfSphere(void)
	{return totalPointsForDrawing;}; // Return the points needed to draw a sphere

};
#endif