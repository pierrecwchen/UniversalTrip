//*********************************************************
//	Matrix.h			Copyright by Pierre Chen.
//
//	A class store 16 float in an array as matrix. Provide
//	matrix multiplication and rotate, translate, and scale
//	current matrix. Model view matrix LOOKAT, projection
//	matrix ortho, perspective, and frustum are also applied.
//
//
//	The matrix store in the patern:
//	0 4 8 12
//	1 5 9 13
//	2 6 10 14
//	3 7 11 15
//
//*********************************************************

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "Point.h"
#include "Color.h"

class Matrix
{

private:

	float matrix_[16];

public:

	Matrix();
	Matrix( float , float, float, float,
			float , float, float, float,
			float , float, float, float,
			float , float, float, float);


	float getCurrentMatrixComponent(int positionOfComponent)const
	{return matrix_[positionOfComponent];}; // Return one of array elements.
	
	float* getAllMatrixComponents()
	{return matrix_;}; // Return all array elements in one array.
	
	void setCurrentMatrixComponent(int positionOfComponent, float component)
	{matrix_[positionOfComponent] = component;}; // Set an array element by provideing a position.
	

	Matrix operator*(const Matrix& matrix)const;
	Vector operator*(const Vector& vector)const;
	Point operator*(const Point& point)const;


	void rotateCurrentMatrixInXAxisByDegree(float rotatingDegree);
	void rotateCurrentMatrixInYAxisByDegree(float rotatingDegree);
	void rotateCurrentMatrixInZAxisByDegree(float rotatingDegree);

	void translateCurrentMatrixByVector(Vector& vecter);

	void scaleCurrentMatrixByScaleVector(Vector& vector);


	void lookAt(Point &eye, Point &at, Vector &up);


	void frustum(float leftOfView, float rightOfView, float bottomOfView, float topOfView, float nearOfView, float farOfView);
	void perspective(float fovy, float aspect, float nearOfView, float farOfView);
	void ortho(float leftOfView, float rightOfView, float bottomOfView, float topOfView, float nearOfView, float farOfView);
};
#endif