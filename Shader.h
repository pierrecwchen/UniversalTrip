//*********************************************************
//	Shader.h			Copyright by Pierre Chen.
//
//	A class which create a new program, link vertex shader
//	and fragment shader to the program, and the ability of
//	getting the location of the program.
//*********************************************************

#ifndef _SHADER_H_
#define _SHADER_H_

#include <iostream>
#include <tchar.h>
#include <fstream>
#include <string>

#include <SDKDDKVer.h>
#include <GL\glew.h>
#include <GL\glut.h>

class Shader
{

private:

	GLuint shaderProgram;

public:

	Shader(const char*, const char*);

	
	GLuint getShaderProgram(void)
	{return shaderProgram;}; // Return the location of the program.
	

	char* readShaderSource(const char*);

};
#endif