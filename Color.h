//***************************************************************
//	Color.h			Copyright by Pierre Chen.
//
//	A singleton class which store a RGBA color as an float array.
//***************************************************************

#ifndef _COLOR_H_
#define _COLOR_H_
class Color
{
	float color_[4];

public:
	
	Color();
	Color(float, float, float, float);

	// Getter for each component.
	float getRedComponent(void)const
	{return color_[0];};
	float getGreenComponent(void)const
	{return color_[1];};
	float getBlueComponent(void)const
	{return color_[2];};
	float getAlphaComponent(void)const
	{return color_[3];};

	// Getter for all component.
	float* getColor(void)
	{return color_;};

	// Setter for each component.
	void setRedComponent(float redComponent)
	{color_[0] = redComponent;};
	void setGreenComponent(float greenComponent)
	{color_[1] = greenComponent;};
	void setBlueComponent(float blueComponent)
	{color_[2] = blueComponent;};
	void setAlphaComponent(float alphaComponent)
	{color_[3] = alphaComponent;};

	Color operator*(const Color& otherColor)const;

};
#endif