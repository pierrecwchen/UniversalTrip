//**********************************************************************
//	UniverseTrip.cpp			Copyright by Pierre Chen.
//
//	A driver class which has several events callback, initialize
//	the VAO and VBO, and draw and show things on screen. 
//
//	Press:
//
//	"up" and "down" to increase and decrease speed of spaceship,
//
//	"F1" for first person view, "F2" for third person view,
//
//	"F3" for back shoulder view, "F4" for god view,
//
//	"s" for super speed,
//
//	"z" and "x" for normal and wide view,
//
//	"h" for stop the spaceship,
//
//	"q" or "esc" to exit program,
//
//	And move mouse to rotate the spaceship.
//
//	Notice: the rotation of left and right will be narrowed
//	as the rotation of up and down is more near to up or down.
//
//
//	By default:
//
//	Number of planets = 900 with max = 10 and min = 1,
//
//	First person view,
//	
//	Spaceship initially placed in (0, 0, 0) and look at (0, 0, 0.005),
//
//	Wide view mode,
//
//	Spotlight source at (0, 0, 0.002).
//
//**********************************************************************
#include "Controller.h"

using namespace std;

#define BUFFER_OFFSET(bytes)((GLvoid*) (bytes))

const int INCREASE = 0;
const int DECREASE = 1;
const int HOLT = 2;
const int SUPERSPEED = 3;
const int SUPERWIDEVIEW = 6;
const int NORMALVIEW = 7;

const int FIRSTPERSON = 0;
const int THIRDPERSON = 1;
const int BACKSHOULDER = 2;
const int GODVIEW = 3;

static Controller controller;


// Initialize controller, VAO, VBO, shader, program, and get bunch of uniform variable location.
void init(){

	controller = Controller();


	Shader shader = Shader("VertexShader.txt", "FragmentShader.txt");


	// Initialize the shader magic
	controller.setShaderProgram(shader.getShaderProgram());

	glUseProgram(controller.getShaderProgram());



	GLuint vertexArrayObject;

    // Create a vertex array object
    glGenVertexArrays( 1, &vertexArrayObject );
    glBindVertexArray( vertexArrayObject );



	GLuint vertexBuffer;

    // Create and initialize a buffer object
    glGenBuffers( 1, &vertexBuffer );
    glBindBuffer( GL_ARRAY_BUFFER, vertexBuffer );

	// Fill the buffer with point and color array.
	glBufferData( GL_ARRAY_BUFFER, sizeof(Point) * controller.getNumberOfVertices() * 2, NULL, GL_STATIC_DRAW );
	
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Point)*controller.getNumberOfVertices(), controller.getPointsOfSphere());
	
	glBufferSubData(GL_ARRAY_BUFFER, sizeof(Point)*controller.getNumberOfVertices(), 
					sizeof(Point)*controller.getNumberOfVertices(), controller.getNormalOfPoints());

	
	
	// Get the location of the points, enable it, and send down the points to shader.
	GLuint vertexPositionVariableIndex = glGetAttribLocation(controller.getShaderProgram(), "vPosition");
    
	glEnableVertexAttribArray(vertexPositionVariableIndex);
   
	glVertexAttribPointer(vertexPositionVariableIndex, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));



	// Get the location of the normals, enable it, and send down the points to shader.
	GLuint vertexNormalVariableIndex = glGetAttribLocation(controller.getShaderProgram(), "vNormal");
    
	glEnableVertexAttribArray(vertexNormalVariableIndex);
    
	glVertexAttribPointer(vertexNormalVariableIndex, 4, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(sizeof(Point) * controller.getNumberOfVertices()));




	// Get and store the location of model view matrix.
	GLuint modelViewMatrixLocation = glGetUniformLocation(controller.getShaderProgram(), "modelViewMatrix");
	GLuint projectionMatrixLocation = glGetUniformLocation(controller.getShaderProgram(), "projectionMatrix");
	
	GLuint ambientProductLocation = glGetUniformLocation(controller.getShaderProgram(), "ambientProduct");
	GLuint diffuseProductLocation = glGetUniformLocation(controller.getShaderProgram(), "diffuseProduct");
	GLuint specularProductLocation = glGetUniformLocation(controller.getShaderProgram(), "specularProduct");
	GLuint shininessLocation = glGetUniformLocation(controller.getShaderProgram(), "shininess");
	
	GLuint lightPositionLocation = glGetUniformLocation(controller.getShaderProgram(), "lightPosition");
	GLuint lightDirectionLocation = glGetUniformLocation(controller.getShaderProgram(), "lightDirection");
	GLuint eyePositionLocation = glGetUniformLocation(controller.getShaderProgram(), "eyePosition");
	
	GLuint spaceshipMovementLocation = glGetUniformLocation(controller.getShaderProgram(), "spaceshipMovement");


	controller.setModelViewMatrixLocation(modelViewMatrixLocation);
	controller.setProjectionMatrixLocation(projectionMatrixLocation);
	
	controller.setAmbientProductLocation(ambientProductLocation);
	controller.setDiffuseProductLocation(diffuseProductLocation);
	controller.setSpecularProductLocation(specularProductLocation);
	controller.setShininessLocation(shininessLocation);
	
	controller.setLightPositionLocation(lightPositionLocation);
	controller.setLightDirectionLocation(lightDirectionLocation);
	controller.setEyePositionLocation(eyePositionLocation);

	controller.setSpaceshipMovementLocation(spaceshipMovementLocation);



	// Call the z-buffer algorithm.
	glEnable(GL_DEPTH_TEST); 
	

	// Black background
    glClearColor( 0.0, 0.0, 0.0, 1.0 );

}


// Keyboard callback function.
void myKeyBoard(unsigned char keyTyped, int x, int y){
	
	// Quit when 'q' is pressed.
	if(keyTyped == 033 || keyTyped == 'Q' || keyTyped == 'q'){

		exit(0);

	}
	

	// Stop spaceship when 'h' pressed.
	if(keyTyped == 'H' || keyTyped == 'h'){

		controller.changeVelocityOfSpaceship(HOLT);

	}


	// Use the super speed when 's' pressed.
	else if(keyTyped == 'S' || keyTyped == 's'){

		controller.changeVelocityOfSpaceship(SUPERSPEED);

	}


	// Switch to wide view when 'x' pressed.
	else if(keyTyped == 'X' || keyTyped == 'x'){

		controller.changeVelocityOfSpaceship(SUPERWIDEVIEW);

	}


	// Switch to normal view when 'z' pressed.
	else if(keyTyped == 'Z' || keyTyped == 'z'){

		controller.changeVelocityOfSpaceship(NORMALVIEW);

	}
}


// Special keyboard callback function.
void specialKeys(int keyTyped, int x, int y){

	// Increase speed when 'up' pressed
	if(keyTyped == GLUT_KEY_UP){

		controller.changeVelocityOfSpaceship(INCREASE);

	}


	// Decrease speed when 'down' pressed
	else if(keyTyped == GLUT_KEY_DOWN){

		controller.changeVelocityOfSpaceship(DECREASE);

	}


	// Switch to first person view by pressing F1
	else if(keyTyped == GLUT_KEY_F1){

		controller.changePointOfView(FIRSTPERSON);

	}


	// Switch to third person view by pressing F2
	else if(keyTyped == GLUT_KEY_F2){

		controller.changePointOfView(THIRDPERSON);

	}


	// Switch to back shoulder view by pressing F3
	else if(keyTyped == GLUT_KEY_F3){

		controller.changePointOfView(BACKSHOULDER);

	}


	// Switch to god view by pressing F4
	else if(keyTyped == GLUT_KEY_F4){

		controller.changePointOfView(GODVIEW);

	}

}


// Mouse passive motion callback function.
void mousePassiveMotion(int x, int y){

	controller.changeDirectionOfSpaceship(x, y, glutGet(GLUT_WINDOW_WIDTH), glutGet(GLUT_WINDOW_HEIGHT));

}


// Idle callback function.
void idle(void){

	// 25 FPS.
	controller.waitForSecond(0.025f);

	// Update camera.
	controller.updateSpaceship();

	// Redraw.
	glutPostRedisplay();
}


// Display function that draws the cube by passing in the model view matrix.
void display( void ) {

	controller.display();

}

// Reshape function, reshape screen to the largest square in window.
void reshape(int width, int height){

	if(width<height){

		glViewport(0, (height-width)/2, width,width);

	}


	else if(width>height){

		glViewport((width-height)/2, 0, height,height);

	}


	else{

		glViewport(0, 0, width, height);

	}

}

// Driver.
int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);

    glutInitWindowSize(700, 700);


    glutCreateWindow("Universe Trip");


    glewInit();


	init();


	glutDisplayFunc(display);

	glutReshapeFunc(reshape);

	glutKeyboardFunc(myKeyBoard);

	glutSpecialFunc(specialKeys);

	glutPassiveMotionFunc(mousePassiveMotion);

	glutIdleFunc(idle);


    glutMainLoop();

	return 0;
}
