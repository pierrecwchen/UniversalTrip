//*********************************************************
//	Controller.h			Copyright by Pierre Chen.
//
//	A fake controller which holds all logics needed for view 
//	class and passes data that needed to be stored to 
//	model class (universe). And store things needed for
//	glut and glew.
//
//*********************************************************

#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

#include "Shader.h"
#include "Universe.h"
#include "LightAndMaterial.h"

class Controller
{

	int windowXSize;
	int windowYSize;

	int xCoordinateOfMouse;
	int yCoordinateOfMouse;

	int pointOfView;


	float radianChangingInX;
	float radianChangingInY;


	float changingVelocity;


	GLuint program;


	GLuint modelViewMatrixLocation;
	GLuint projectionMatrixLocation;


	GLuint ambientProductLocation;
	GLuint diffuseProductLocation;
	GLuint specularProductLocation;
	GLuint shininessLocation;


	GLuint lightPositionLocation;
	GLuint lightDirectionLocation;


	GLuint eyePositionLocation;

	GLuint spaceshipMovementLocation;

	Spaceship spaceship;

	Camera camera;


	Matrix modelViewMatrix;
	Matrix projectionMatrix;


	Universe universe;


	Planets planetList;


	LightAndMaterial lightAndMaterial;

public:
	
	Controller();


	// Setter and Getter for program.
	void setShaderProgram(GLuint shaderProgram)
	{program = shaderProgram;};
	GLuint getShaderProgram(void)const
	{return program;};


	// Setter and Getter for uniform location of model view matrix.
	void setModelViewMatrixLocation(GLuint locationOfUniform)
	{modelViewMatrixLocation = locationOfUniform;};
	GLuint getModelViewMatrixLocation(void)const
	{return modelViewMatrixLocation;};
	

	// Setter and Getter for uniform location of projection matrix.
	void setProjectionMatrixLocation(GLuint locationOfUniform)
	{projectionMatrixLocation = locationOfUniform;};
	GLuint getProjectionMatrixLocation(void)const
	{return projectionMatrixLocation;};


	// Setter and Getter for uniform location of ambient product.
	void setAmbientProductLocation(GLuint locationOfUniform)
	{ambientProductLocation = locationOfUniform;};
	GLuint getAmbientProductLocation(void)const
	{return ambientProductLocation;};
	

	// Setter and Getter for uniform location of diffuse product.
	void setDiffuseProductLocation(GLuint locationOfUniform)
	{diffuseProductLocation = locationOfUniform;};
	GLuint getDiffuseProductLocation(void)const
	{return diffuseProductLocation;};
	

	// Setter and Getter for uniform location of specular product.
	void setSpecularProductLocation(GLuint locationOfUniform)
	{specularProductLocation = locationOfUniform;};
	GLuint getSpecularProductLocation(void)const
	{return specularProductLocation;};
	

	// Setter and Getter for uniform location of shininess coefficient.
	void setShininessLocation(GLuint locationOfUniform)
	{shininessLocation = locationOfUniform;};
	GLuint getShininessLocation(void)const
	{return shininessLocation;};
	

	// Setter and Getter for uniform location of light position.
	void setLightPositionLocation(GLuint locationOfUniform)
	{lightPositionLocation = locationOfUniform;};
	GLuint getLightPositionLocation(void)const
	{return lightPositionLocation;};
	

	// Setter and Getter for uniform location of light direction.
	void setLightDirectionLocation(GLuint locationOfUniform)
	{lightDirectionLocation = locationOfUniform;};
	GLuint getLightDirectionLocation(void)const
	{return lightDirectionLocation;};


	// Setter and Getter for uniform location of eye position.
	void setEyePositionLocation(GLuint locationOfUniform)
	{eyePositionLocation = locationOfUniform;};
	GLuint getEyePositionLocation(void)const
	{return eyePositionLocation;};


	// Setter and Getter for uniform location of spaceship movement.
	void setSpaceshipMovementLocation(GLuint locationOfUniform)
	{spaceshipMovementLocation = locationOfUniform;};
	GLuint getSpaceshipMovementLocation(void)const
	{return spaceshipMovementLocation;};


	// Return number of vertices for all universe.
	int getNumberOfVertices(void)const{return universe.getNumPlanets() * universe.getNumPointsPerPlanet();};
	

	// Return points of planets and normal vecters.
	Point* getPointsOfSphere(void){return universe.getPointsOfPlanets();};
	Vector* getNormalOfPoints(void){return universe.getNormalOfPoints();};


	void changeDirectionOfSpaceship(int xCoordinateOfMouse_, int yCoordinateOfMouse_, int windowXSize_, int windowYSize_);
	void changeVelocityOfSpaceship(int increaseOrDecrease);
	void changePointOfView(int pointOfView_)
	{pointOfView = pointOfView_;};
	void updateSpaceship();


	void display(void);


	void waitForSecond(float seconds);

};
#endif