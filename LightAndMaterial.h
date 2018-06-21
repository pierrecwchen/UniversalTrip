//**************************************************************
//	LightAndMaterial.h			Copyright by Pierre Chen.
//
//	A model class which store location of light source, light
//	color, and 5 materials.
//
//**************************************************************

#ifndef _LIGHTANDMATERIAL_H_
#define _LIGHTANDMATERIAL_H_

#include "Matrix.h"

class LightAndMaterial
{
private:

	Point lightPosition;


	Color lightColor[3];


	Color materialAmbient[5];

	Color materialDiffuse[5];

	Color materialSpecular[5];

	float materialShininess[5];


public:
	LightAndMaterial();



	// Setters for material's ambient, diffuse, specular, and shininess coefficient.
	void setMaterialAmbient(int indexOfMaterial, Color &materialAmbient_)
	{materialAmbient[indexOfMaterial] = materialAmbient_;};

	void setMaterialDiffuse(int indexOfMaterial, Color &materialDiffuse_)
	{materialDiffuse[indexOfMaterial] = materialDiffuse_;};

	void setMaterialSpecular(int indexOfMaterial, Color &materialSpecular_)
	{materialSpecular[indexOfMaterial] = materialSpecular_;};

	void setMaterialShininess(int indexOfMaterial, float materialShininess_)
	{materialShininess[indexOfMaterial] = materialShininess_;};



	// Getters for material's ambient, diffuse, specular, and shininess coefficient.
	Color getMaterialAmbient(int indexOfMaterial)
	{return materialAmbient[indexOfMaterial];};

	Color getMaterialDiffuse(int indexOfMaterial)
	{return materialDiffuse[indexOfMaterial];};

	Color getMaterialSpecular(int indexOfMaterial)
	{return materialSpecular[indexOfMaterial];};

	float getMaterialShininess(int indexOfMaterial)
	{return materialShininess[indexOfMaterial];};


	// Setter for light source position.
	void setLightPosition(Point &lightPosition_)
	{lightPosition = lightPosition_;};

	// Move the light source position.
	void moveLightPosition(Vector &movingVector)
	{lightPosition += movingVector;};

	// Getter for light source position.
	Point getLightPosition(void)
	{return lightPosition;};




	// Setters for light source's ambient, diffuse, and specular.
	void setLightAmbient(Color &lightAmbient)
	{lightColor[0] = lightAmbient;};

	void setLightDiffuse(Color &lightDiffuse)
	{lightColor[1] = lightDiffuse;};

	void setLightSpecular(Color &lightSpecular)
	{lightColor[2] = lightSpecular;};


	// Getters for light source's ambient, diffuse, and specular.
	Color getLightAmbient(void)
	{return lightColor[0];};

	Color getLightDiffuse(void)
	{return lightColor[1];};

	Color getLightSpecular(void)
	{return lightColor[2];};


	// Getters for product of ambient, diffuse, and specular of light source and material.
	Color getMaterialAmbientProduct(int indexOfMaterial)
	{return lightColor[0] * materialAmbient[indexOfMaterial];};

	Color getMaterialDiffuseProduct(int indexOfMaterial)
	{return lightColor[1] * materialDiffuse[indexOfMaterial];};

	Color getMaterialSpecularProduct(int indexOfMaterial)
	{return lightColor[2] * materialSpecular[indexOfMaterial];};

};
#endif