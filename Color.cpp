#include"Color.h"

// Defult constructor.
Color::Color(){

	color_[0] = 0.0f;
	color_[1] = 0.0f;
	color_[2] = 0.0f;
	color_[3] = 0.0f;

}


// Constructor which takes components as value.
Color::Color(float redComponent_, float greenComponent_, float blueComponent_, float alphaComponent_){
	color_[0] = redComponent_;
	color_[1] = greenComponent_;
	color_[2] = blueComponent_;
	color_[3] = alphaComponent_;
}


// Operator *: multiply each component to corresponding component.
Color Color::operator*(const Color& otherColor)const{
	
	Color result;

	result.setRedComponent(color_[0] * otherColor.getRedComponent());
	result.setGreenComponent(color_[1] * otherColor.getGreenComponent());
	result.setBlueComponent(color_[2] * otherColor.getBlueComponent());
	result.setAlphaComponent(color_[3] * otherColor.getAlphaComponent());

	return result;
}