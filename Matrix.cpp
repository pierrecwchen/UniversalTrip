#include "Matrix.h"
#include <cmath>

const float PI = 3.14159265f;

// Defult constructor; generate an identity matrix.
Matrix::Matrix(){

	matrix_[0] = 1.0f;
	matrix_[1] = 0.0f;
	matrix_[2] = 0.0f;
	matrix_[3] = 0.0f;
	matrix_[4] = 0.0f;
	matrix_[5] = 1.0f;
	matrix_[6] = 0.0f;
	matrix_[7] = 0.0f;
	matrix_[8] = 0.0f;
	matrix_[9] = 0.0f;
	matrix_[10] = 1.0f;
	matrix_[11] = 0.0f;
	matrix_[12] = 0.0f;
	matrix_[13] = 0.0f;
	matrix_[14] = 0.0f;
	matrix_[15] = 1.0f;

}


// Constructor which takes 16 floats as parameters.
Matrix::Matrix( float rowOneColumnOne, float rowOneColumnTwo, float rowOneColumnThree, float rowOneColumnFour,
				float rowTwoColumnOne, float rowTwoColumnTwo, float rowTwoColumnThree, float rowTwoColumnFour,
				float rowThreeColumnOne, float rowThreeColumnTwo, float rowThreeColumnThree, float rowThreeColumnFour,
				float rowFourColumnOne, float rowFourColumnTwo, float rowFourColumnThree, float rowFourColumnFour){

	matrix_[0] = rowOneColumnOne;
	matrix_[1] = rowTwoColumnOne;
	matrix_[2] = rowThreeColumnOne;
	matrix_[3] = rowFourColumnOne;
	matrix_[4] = rowOneColumnTwo;
	matrix_[5] = rowTwoColumnTwo;
	matrix_[6] = rowThreeColumnTwo;
	matrix_[7] = rowFourColumnTwo;
	matrix_[8] = rowOneColumnThree;
	matrix_[9] = rowTwoColumnThree;
	matrix_[10] = rowThreeColumnThree;
	matrix_[11] = rowFourColumnThree;
	matrix_[12] = rowOneColumnFour;
	matrix_[13] = rowTwoColumnFour;
	matrix_[14] = rowThreeColumnFour;
	matrix_[15] = rowFourColumnFour;

}


// Operator * which provides matrix multiplied by another matrix and return matrix.
Matrix Matrix::operator*(const Matrix& matrix)const{

	Matrix resultMatrix = Matrix();

	for(int i=0; i<4; i++){
		for(int j=0; j<4; j++){

			float newMatrixComponent_ = matrix_[j] * matrix.getCurrentMatrixComponent( 4 * i ) + 
										matrix_[j+4] * matrix.getCurrentMatrixComponent( 4 * i + 1 ) + 
										matrix_[j+8] * matrix.getCurrentMatrixComponent( 4 * i + 2 ) + 
										matrix_[j+12] * matrix.getCurrentMatrixComponent( 4 * i + 3 );


			resultMatrix.setCurrentMatrixComponent(4 * i + j, newMatrixComponent_);
		
		}
	}

	return resultMatrix;

}


// Operator * which provides matrix multiplied by a vector and return vector.
Vector Matrix::operator*(const Vector& vector)const{
	
	Vector resultVector = Vector();


	resultVector.setXCoordinate( matrix_[0] * vector.getXCoordinate() + matrix_[4] * vector.getYCoordinate() + matrix_[8] * vector.getZCoordinate() + matrix_[12] * vector.getWCoordinate());
	
	resultVector.setYCoordinate( matrix_[1] * vector.getXCoordinate() + matrix_[5] * vector.getYCoordinate() + matrix_[9] * vector.getZCoordinate() + matrix_[13] * vector.getWCoordinate());
	
	resultVector.setZCoordinate( matrix_[2] * vector.getXCoordinate() + matrix_[6] * vector.getYCoordinate() + matrix_[10] * vector.getZCoordinate() + matrix_[14] * vector.getWCoordinate());
	
	resultVector.setWCoordinate( matrix_[3] * vector.getXCoordinate() + matrix_[7] * vector.getYCoordinate() + matrix_[11] * vector.getZCoordinate() + matrix_[15] * vector.getWCoordinate());
	

	return resultVector;

}


// Operator * which provides matrix multiplied by a point and return point.
Point Matrix::operator*(const Point& point)const{
	
	Point resultPoint = Point();

	
	resultPoint.setXCoordinate( matrix_[0] * point.getXCoordinate() + matrix_[4] * point.getYCoordinate() + matrix_[8] * point.getZCoordinate() + matrix_[12] * point.getWCoordinate() );
	
	resultPoint.setYCoordinate( matrix_[1] * point.getXCoordinate() + matrix_[5] * point.getYCoordinate() + matrix_[9] * point.getZCoordinate() + matrix_[13] * point.getWCoordinate() );
	
	resultPoint.setZCoordinate( matrix_[2] * point.getXCoordinate() + matrix_[6] * point.getYCoordinate() + matrix_[10] * point.getZCoordinate() + matrix_[14] * point.getWCoordinate() );
	
	resultPoint.setWCoordinate( matrix_[3] * point.getXCoordinate() + matrix_[7] * point.getYCoordinate() + matrix_[11] * point.getZCoordinate() + matrix_[15] * point.getWCoordinate() );
	

	return resultPoint;

}


// Rotate current matrix with a degree alone x-axis
void Matrix::rotateCurrentMatrixInXAxisByDegree(float rotatingDegree){
	
	Matrix matrixGenerated = Matrix();

	
	matrixGenerated.setCurrentMatrixComponent(5, static_cast<float>( cos( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(9, static_cast<float>( -sin( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(6, static_cast<float>( sin( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(10, static_cast<float>( cos( rotatingDegree * PI / 180.0 ) ) );

	
	*this = *this * matrixGenerated;

}


// Rotate current matrix with a degree alone y-axis
void Matrix::rotateCurrentMatrixInYAxisByDegree(float rotatingDegree){

	Matrix matrixGenerated = Matrix();

	
	matrixGenerated.setCurrentMatrixComponent(0, static_cast<float>( cos( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(8, static_cast<float>( sin( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(2, static_cast<float>( -sin( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(10, static_cast<float>( cos( rotatingDegree * PI / 180.0 ) ) );

	
	*this = *this * matrixGenerated;

}


// Rotate current matrix with a degree alone z-axis
void Matrix::rotateCurrentMatrixInZAxisByDegree(float rotatingDegree){
	
	Matrix matrixGenerated = Matrix();

	
	matrixGenerated.setCurrentMatrixComponent(0, static_cast<float>( cos( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(4, static_cast<float>( -sin( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(1, static_cast<float>( sin( rotatingDegree * PI / 180.0 ) ) );
	
	matrixGenerated.setCurrentMatrixComponent(5, static_cast<float>( cos( rotatingDegree * PI / 180.0 ) ) );


	*this = *this * matrixGenerated;

}


// Translate current matrix with a vector
void Matrix::translateCurrentMatrixByVector(Vector& vector){

	Matrix matrixGenerated = Matrix();


	matrixGenerated.setCurrentMatrixComponent( 12, vector.getXCoordinate() );
	
	matrixGenerated.setCurrentMatrixComponent( 13, vector.getYCoordinate() );
	
	matrixGenerated.setCurrentMatrixComponent( 14, vector.getZCoordinate() );


	*this = *this * matrixGenerated;

}


// Scale current matrix with a vector
void Matrix::scaleCurrentMatrixByScaleVector(Vector& vector){
	
	Matrix matrixGenerated = Matrix();


	matrixGenerated.setCurrentMatrixComponent( 0, vector.getXCoordinate() );
	
	matrixGenerated.setCurrentMatrixComponent( 5, vector.getYCoordinate() );
	
	matrixGenerated.setCurrentMatrixComponent( 10, vector.getZCoordinate() );


	*this = *this * matrixGenerated;

}


// Return a look at model view matrix by given eye position, at position, and up vector.
void Matrix::lookAt(Point &eye, Point &at, Vector &up){
	
	*this = Matrix(); // Reset to identity matrix.


	// Generate view plan normal and normalize it.
	Vector viewPlanNormal = eye - at;
	viewPlanNormal.normalizeCurrentVector();
	

	// Generate side vector and normalize it.
	Vector sideVectorOfVPN = up.crossProduct(viewPlanNormal);
	sideVectorOfVPN.normalizeCurrentVector();


	// Generate new up vector and normalize it.
	Vector upVector = viewPlanNormal.crossProduct(sideVectorOfVPN);
	upVector.normalizeCurrentVector();


	// Setup the matrix.
	matrix_[0] = sideVectorOfVPN.getXCoordinate();
	matrix_[4] = sideVectorOfVPN.getYCoordinate();
	matrix_[8] = sideVectorOfVPN.getZCoordinate();
	
	matrix_[1] = upVector.getXCoordinate();
	matrix_[5] = upVector.getYCoordinate();
	matrix_[9] = upVector.getZCoordinate();
	
	matrix_[2] = viewPlanNormal.getXCoordinate();
	matrix_[6] = viewPlanNormal.getYCoordinate();
	matrix_[10] = viewPlanNormal.getZCoordinate();


	// Transform the camera back to origin.
	translateCurrentMatrixByVector( Vector( -eye.getXCoordinate(), -eye.getYCoordinate(), -eye.getZCoordinate(), 0.0f ) );

}


// Generate and return a frustum projection matrix.
void Matrix::frustum(float leftOfView, float rightOfView, float bottomOfView, float topOfView, float nearOfView, float farOfView){
	
	*this = Matrix(); // Reset to identity matrix.


	// Setup the matrix.
	matrix_[0] = 2.0f * nearOfView / ( rightOfView - leftOfView );
	
	matrix_[5] = 2.0f * nearOfView / ( topOfView - bottomOfView );
	
	matrix_[8] = ( rightOfView+leftOfView ) / ( rightOfView - leftOfView );
	
	matrix_[9] = ( topOfView+bottomOfView ) / ( topOfView - bottomOfView );
	
	matrix_[10] = -( farOfView + nearOfView ) / ( farOfView - nearOfView);
	
	matrix_[11] = -1.0f;
	
	matrix_[14] = -2.0f * farOfView * nearOfView / ( farOfView - nearOfView );
	
	matrix_[15] = 0.0f;

}


// Generate and return a perspective projection matrix.
void Matrix::perspective(float fovy, float aspect, float nearOfView, float farOfView){
	
	*this = Matrix(); // Reset to identity matrix.


	// Calculate the top of view and right of view.
	float topOfView = nearOfView * static_cast<float>( tan( fovy / 2.0 ) );
	float rightOfView = topOfView * aspect;
	
	
	// Setup the matrix.
	matrix_[0] = nearOfView / rightOfView;
	
	matrix_[5] = nearOfView / topOfView;
	
	matrix_[10] = -( farOfView + nearOfView ) / ( farOfView - nearOfView );
	
	matrix_[11] = -1.0f;
	
	matrix_[14] = -2.0f * farOfView * nearOfView / (farOfView - nearOfView);
	
	matrix_[15] = 0.0f;

}


// Generate and return a ortho projection matrix.
void Matrix::ortho(float leftOfView, float rightOfView, float bottomOfView, float topOfView, float nearOfView, float farOfView){
	
	*this = Matrix(); // Reset to identity matrix.


	// Setup the matrix.
	matrix_[0] = 2.0f / ( rightOfView - leftOfView );
    
	matrix_[5] = 2.0f / ( topOfView - bottomOfView );
    
	matrix_[10] = 2.0f / ( nearOfView - farOfView );
    
	matrix_[12] = -( rightOfView + leftOfView ) / ( rightOfView - leftOfView );
    
	matrix_[13] = -( topOfView + bottomOfView ) / ( topOfView - bottomOfView );
    
	matrix_[14] = -( farOfView + nearOfView ) / ( farOfView - nearOfView );

}