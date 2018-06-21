#include "Vector.h"
#include <cmath>

// Defult constructor.
Vector::Vector(){
	
	vector_[0] = 0.0f;
	vector_[1] = 0.0f;
	vector_[2] = 0.0f;
	vector_[3] = 0.0f;

}

// Constructor which takes 2 float number as x, y, and z.
Vector::Vector (float coordinateXValue_, float coordinateYValue_, float coordinateZValue_, float coordinateWValue_){
	
	vector_[0] = coordinateXValue_;
	vector_[1] = coordinateYValue_;
	vector_[2] = coordinateZValue_;
	vector_[3] = coordinateWValue_;

}


// Return dot product of current vector and the other vector.
float Vector::dotProduct(const Vector &otherVector){
	
	float result =  vector_[0] * otherVector.getXCoordinate() +
					vector_[1] * otherVector.getYCoordinate() + 
					vector_[2] * otherVector.getZCoordinate();

	return result;
	
}


// Return cross product of current vector and the other vector.
Vector Vector::crossProduct(const Vector &otherVector){
	
	Vector result = Vector();

	result.setXCoordinate( static_cast<float>( vector_[1] * otherVector.getZCoordinate() - vector_[2] * otherVector.getYCoordinate() ) );

	result.setYCoordinate( static_cast<float>( vector_[2] * otherVector.getXCoordinate() - vector_[0] * otherVector.getZCoordinate() ) );

	result.setZCoordinate( static_cast<float>( vector_[0] * otherVector.getYCoordinate() - vector_[1] * otherVector.getXCoordinate() ) );

	return result;

}


// Return absolute value for current vector.
float Vector::calculateMagnitudeOfCurrentVector(){
	
	float absoluteValue = static_cast<float>( sqrt( ( pow( vector_[0], 2 ) + pow( vector_[1], 2 ) + pow( vector_[2], 2 ) ) ) );

	return absoluteValue;

}


// Normalize current vector.
void Vector::normalizeCurrentVector(void){

	float absoluteValue = calculateMagnitudeOfCurrentVector();
	
	vector_[0] /= absoluteValue;
	vector_[1] /= absoluteValue;
	vector_[2] /= absoluteValue;

}


// Scale current vector without using scale matrix.
void Vector::scaleCurrentVector(const float scale){

	vector_[0] *= scale;
	vector_[1] *= scale;
	vector_[2] *= scale;

}


// Operator + for addition between current vector and the other vector.
Vector Vector::operator+(const Vector &otherVector)const{
	
	Vector result = Vector();

	result.setXCoordinate( vector_[0] + otherVector.getXCoordinate() );
	result.setYCoordinate( vector_[1] + otherVector.getYCoordinate() );
	result.setZCoordinate( vector_[2] + otherVector.getZCoordinate() );

	return *this;

}


// Operator += for add the other vector to current vector.
Vector Vector::operator+=(const Vector &otherVector){

	vector_[0] += otherVector.getXCoordinate();
	vector_[1] += otherVector.getYCoordinate();
	vector_[2] += otherVector.getZCoordinate();
	vector_[3] = 0.0f;

	return *this;

}

// Scale current vector with operator *.
Vector Vector::operator*(const float factor){

	Vector resultVector = Vector();

	resultVector.setXCoordinate(vector_[0] * factor);
	resultVector.setYCoordinate(vector_[1] * factor);
	resultVector.setZCoordinate(vector_[2] * factor);

	return resultVector;

}