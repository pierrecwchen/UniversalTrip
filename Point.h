//*************************************************************
//	Point.h			Copyright by Pierre Chen.
//
//	A singleton class which store a 4D float point as an array.
//*************************************************************

#ifndef _POINT_H_
#define _POINT_H_

#include "Vector.h"

class Point
{

private:

	float point_[4];

public:

	Point();
	Point(float , float, float, float);


	float getXCoordinate(void)const
	{return point_[0];}; // Return X coordinate value.
	float getYCoordinate(void)const
	{return point_[1];}; // Return Y coordinate value.
	float getZCoordinate(void)const
	{return point_[2];}; // Return Z coordinate value.
	float getWCoordinate(void)const
	{return point_[3];}; // Return W coordinate value.


	// Getter for all coordinate.
	float* getPoint(void){return point_;};


	void setXCoordinate(float coordinateXValue_)
	{point_[0] = coordinateXValue_;}; // Return X coordinate value.
	void setYCoordinate(float coordinateYValue_)
	{point_[1] = coordinateYValue_;}; // Return Y coordinate value.
	void setZCoordinate(float coordinateZValue_)
	{point_[2] = coordinateZValue_;}; // Return Z coordinate value.
	void setWCoordinate(float coordinateWValue_)
	{point_[3] = coordinateWValue_;}; // Return W coordinate value.
	

	Point operator+(const Point &otherPoint)const;
	Point operator+(const Vector &vector)const;


	Point operator+=(const Point &otherPoint);
	Point operator+=(const Vector &otherVector);
	

	Vector operator-(const Point &otherPoint)const;

};
#endif