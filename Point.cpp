#include "Point.h"

// Defult constructor.
Point::Point()
{

	point_[0] = 0.0f;
	point_[1] = 0.0f;
	point_[2] = 0.0f;
	point_[3] = 1.0f;

}


// Constructor which takes 4 float number as x, y, z, and w.
Point::Point (float coordinateXValue_, float coordinateYValue_, float coordinateZValue_, float coordinateWValue_)
{

	point_[0] = coordinateXValue_;
	point_[1] = coordinateYValue_;
	point_[2] = coordinateZValue_;
	point_[3] = coordinateWValue_;

}


// Operator + for addition between two points.
Point Point::operator+(const Point &otherPoint)const{

	Point result = Point();

	result.setXCoordinate(point_[0] + otherPoint.getXCoordinate());
	result.setYCoordinate(point_[1] + otherPoint.getYCoordinate());
	result.setZCoordinate(point_[2] + otherPoint.getZCoordinate());
	result.setWCoordinate(1.0f);

	return result;
}


// Operator + for addition between a point and a vector.
Point Point::operator+(const Vector &vector)const{

	Point result = Point();

	result.setXCoordinate(point_[0] + vector.getXCoordinate());
	result.setYCoordinate(point_[1] + vector.getYCoordinate());
	result.setZCoordinate(point_[2] + vector.getZCoordinate());
	result.setWCoordinate(1.0f);

	return result;

}


// Operator += for add one point to current point.
Point Point::operator+=(const Point &otherPoint){
	
	point_[0] += otherPoint.getXCoordinate();
	point_[1] += otherPoint.getYCoordinate();
	point_[2] += otherPoint.getZCoordinate();
	point_[3] = 1.0f;

	return *this;
}


// Operator += for add one vector to current point.
Point Point::operator+=(const Vector &otherVector){
	
	point_[0] += otherVector.getXCoordinate();
	point_[1] += otherVector.getYCoordinate();
	point_[2] += otherVector.getZCoordinate();
	point_[3] = 1.0f;

	return *this;
}


// Substract 2 points to get a vector.
Vector Point::operator-(const Point &otherPoint)const{

	Vector result = Vector();

	result.setXCoordinate(point_[0] - otherPoint.getXCoordinate());
	result.setYCoordinate(point_[1] - otherPoint.getYCoordinate());
	result.setZCoordinate(point_[2] - otherPoint.getZCoordinate());
	result.setWCoordinate(0.0f);

	return result;
}