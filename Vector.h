//***************************************************************
//	Vector.h			Copyright by Pierre Chen.
//
//	A singleton class which store a 4D float vector as an array.
//***************************************************************

#ifndef _VECTOR_H_
#define _VECTOR_H_
class Vector
{

private:

	float vector_[4];

public:

	Vector();
	Vector(float , float, float, float);

	float getXCoordinate(void)const
	{return vector_[0];}; // Return X coordinate value.
	float getYCoordinate(void)const
	{return vector_[1];}; // Return Y coordinate value.
	float getZCoordinate(void)const
	{return vector_[2];}; // Return Z coordinate value.
	float getWCoordinate(void)const
	{return vector_[3];}; // Return W coordinate value.
	
	
	// Getter for all coordinates.
	float* getVector(void){return vector_;};


	void setXCoordinate(float coordinateXValue_)
	{vector_[0] = coordinateXValue_;}; // Return X coordinate value.
	void setYCoordinate(float coordinateYValue_)
	{vector_[1] = coordinateYValue_;}; // Return Y coordinate value.
	void setZCoordinate(float coordinateZValue_)
	{vector_[2] = coordinateZValue_;}; // Return Z coordinate value.
	void setWCoordinate(float coordinateWValue_)
	{vector_[3] = coordinateWValue_;}; // Return W coordinate value.
	

	float dotProduct(const Vector &otherVector);

	Vector crossProduct(const Vector &otherVector);


	float calculateMagnitudeOfCurrentVector();
	
	
	void normalizeCurrentVector(void);

	void scaleCurrentVector(const float scale);
	

	Vector operator+(const Vector &otherVector)const;
	Vector operator+=(const Vector &otherVector);

	Vector operator*(const float factor);

};
#endif