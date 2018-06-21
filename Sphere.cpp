#include "Sphere.h"
#include <cmath>

const float PI = 3.14159265f;

// Defult constructor which generate a sphere with 1 radius in the origin.
Sphere::Sphere(){

	numZLayers = 30;
	numVertexEachCircle = 25;


	// Number of points for a sphere.
	numPointsPerSphere = numZLayers * numVertexEachCircle;


	// Number of points for really draw a sphere in triangles.
	numTotalPointsForDrawing = numPointsPerSphere * 2 + 2;


	radiusOfSphere = 1.0f;
	

	pointsPerSphere = new Point[numPointsPerSphere];
	totalPointsForDrawing = new Point[numTotalPointsForDrawing];
	
	// Generate sphere points.
	generateVerticesOfSphere();
	
	// Generate sphere points which can really draw a sphere in triangles.
	generateDrawableSphere();

}


// Constructor which takes number of layers along Z axis, number of points per circle, and the radius of sphere for parameter,
// and generate the sphere based on them.
Sphere::Sphere(int numZLayers, int numVertexEachCircle, float radiusOfSphere_){

	numZLayers = numZLayers;
	numVertexEachCircle = numVertexEachCircle;


	// Number of points for a sphere.
	numPointsPerSphere = numZLayers * numVertexEachCircle;


	// Number of points for really draw a sphere in triangles.
	numTotalPointsForDrawing = numPointsPerSphere * 2 + 2;


	radiusOfSphere = radiusOfSphere_;
	

	pointsPerSphere = new Point[numPointsPerSphere];
	totalPointsForDrawing = new Point[numTotalPointsForDrawing];
	

	// Generate sphere points
	generateVerticesOfSphere();
	
	// Generate sphere points which can really draw a sphere in triangles.
	generateDrawableSphere();

}


// Copy constructor.
Sphere::Sphere(const Sphere &sphere){

	numZLayers = sphere.numZLayers;
	numVertexEachCircle = sphere.numVertexEachCircle;


	numPointsPerSphere = sphere.numPointsPerSphere;
	numTotalPointsForDrawing = sphere.numTotalPointsForDrawing;


	radiusOfSphere = sphere.radiusOfSphere;


	pointsPerSphere = new Point[numPointsPerSphere];


	for(int i = 0; i < numPointsPerSphere; i++){

		pointsPerSphere[i] = sphere.pointsPerSphere[i];

	}


	totalPointsForDrawing = new Point[numTotalPointsForDrawing];

	for(int i = 0; i < numTotalPointsForDrawing; i++){

		totalPointsForDrawing[i] = sphere.totalPointsForDrawing[i];

	}

}


// Assignment.
Sphere Sphere::operator=(const Sphere &sphere){
	
	numZLayers = sphere.numZLayers;
	numVertexEachCircle = sphere.numVertexEachCircle;


	numPointsPerSphere = sphere.numPointsPerSphere;
	numTotalPointsForDrawing = sphere.numTotalPointsForDrawing;


	radiusOfSphere = sphere.radiusOfSphere;


	pointsPerSphere = new Point[numPointsPerSphere];

	for(int i = 0; i < numPointsPerSphere; i++){

		pointsPerSphere[i] = sphere.pointsPerSphere[i];

	}


	totalPointsForDrawing = new Point[numTotalPointsForDrawing];

	for(int i = 0; i < numTotalPointsForDrawing; i++){

		totalPointsForDrawing[i] = sphere.totalPointsForDrawing[i];

	}


	return *this;
}


// Destructor.
Sphere::~Sphere(){

	delete[] pointsPerSphere;

	pointsPerSphere = 0;


	delete[] totalPointsForDrawing;

	totalPointsForDrawing = 0;

}


// Generate vertices on a sphere.
void Sphere::generateVerticesOfSphere(){
	
	int index = 0;
	
	// Interval angle in radian for Z layer.
	const float intervalAngleRadian_ = static_cast<float>( PI / static_cast<float>( numZLayers ) );
	
	// Interval angle in radian for circle.
	const float radiansIntervalOfCircle_ = static_cast<float>( 2.0f * PI / ( static_cast<float>( numVertexEachCircle ) - 1.0f ) );
	
	float angleOfZCoordinate_ = 0.0f; // From 0 to 180.
	

	// For each layer, calculate the vertices of circle.
	for(int i = 0; i < numZLayers; i++){

		for(int j = 0; j<numVertexEachCircle-1; j++){


			pointsPerSphere[index] = Point( static_cast<float>( radiusOfSphere * sin(angleOfZCoordinate_) * cos(radiansIntervalOfCircle_ * j) ),
											static_cast<float>( radiusOfSphere * sin(angleOfZCoordinate_) * sin(radiansIntervalOfCircle_ * j) ),
											static_cast<float>( radiusOfSphere * cos(angleOfZCoordinate_) ),
											1.0f);
			
			index++;

		}

		// Forms a loop
		pointsPerSphere[index] = Point( static_cast<float>( radiusOfSphere * sin(angleOfZCoordinate_) * cos(0.0) ),
										static_cast<float>( radiusOfSphere * sin(angleOfZCoordinate_) * sin(0.0) ),
										static_cast<float>( radiusOfSphere * cos(angleOfZCoordinate_) ),
										1.0f);
		
		index++;

		
		angleOfZCoordinate_ += intervalAngleRadian_;
	
	}

}


// Generate sphere points which can really draw a sphere in triangles.
void Sphere::generateDrawableSphere(){

	int index_ = 0;


	// The top pole of Z.
	totalPointsForDrawing[0] = Point(0.0f, 0.0f, radiusOfSphere , 1.0f);
	
	index_++;



	// Vertices of first top circle.
	for(int i = 1; i <= numVertexEachCircle; i++){

		totalPointsForDrawing[index_] = pointsPerSphere[i-1];

		index_++;

	}



	// The button pole of Z.
	totalPointsForDrawing[index_] = Point(0.0f, 0.0f, -radiusOfSphere, 1.0f);

	index_++;



	// Vertices of first button circle.
	for(int i = 1; i <= numVertexEachCircle; i++){

		totalPointsForDrawing[index_] = pointsPerSphere[numPointsPerSphere-i];

		index_++;

	}

	

	int x = 0;
	int y = numVertexEachCircle;

	
	// Total number of vertices of drawing a sphere is twice much than number of vertices which forms a sphere plus
	// 2 points: two for top and button points.

	// Intersect two array of vertices of a sphere to generate vertices which drawing a sphere in triangle.
	while(index_ < numTotalPointsForDrawing){
		
		totalPointsForDrawing[index_] = pointsPerSphere[x];
		
		x++;
		index_++;
		
		totalPointsForDrawing[index_] = pointsPerSphere[y];
		
		y++;
		index_++;

	}

}