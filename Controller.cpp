#include <ctime>
#include "Controller.h"
#define BUFFER_OFFSET(bytes)((GLvoid*) (bytes))

const float PI = 3.14159265f;
const float CHANGINGRADIANIN = PI / 360.0f;

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

using namespace std;


// Defult constructor. Initialize universe and matrices for model view and projection.
Controller::Controller(){
	
	windowXSize = 9;
	windowYSize = 9;
	xCoordinateOfMouse = 5;
	yCoordinateOfMouse = 5;

	pointOfView = FIRSTPERSON;


	// Look at (0, 0, 0.005)
	radianChangingInX = 0.0f;
	radianChangingInY = PI / 2.0f;
	changingVelocity = 0.0f;


	spaceship = Spaceship();

	camera = Camera();

	camera.updateCamera(pointOfView, spaceship.getLocationOfSpaceship(), 
						spaceship.getLookingDirection(), spaceship.getUpVectorOfSpaceship());


	modelViewMatrix = Matrix();


	// Default projection is super big view.
	projectionMatrix = Matrix();
	projectionMatrix.perspective(PI/2.0f, 1.0f, 0.005f, 500.0f);
	

	// Universe with seed 1800, 900planets in universe, minimun size 1 in radius, and 10 in radius for maximum.
	universe = Universe(1800, 900.0/1000000000.0, 1.0, 10.0);
	
	planetList = universe.getPlanetList();
	
	lightAndMaterial = LightAndMaterial();

}


// Store the where is the mouse at on the screen.
void Controller::changeDirectionOfSpaceship(int xCoordinateOfMouse_, int yCoordinateOfMouse_, int windowXSize_, int windowYSize_){

	windowXSize = windowXSize_;
	windowYSize = windowYSize_;
	xCoordinateOfMouse = xCoordinateOfMouse_;
	yCoordinateOfMouse = yCoordinateOfMouse_;

}


// In usage of change the movement velocity and switch between two projection.
void Controller::changeVelocityOfSpaceship(int increaseOrDecrease){

	// Increase the velocity.
	if(increaseOrDecrease == INCREASE){
		
		// Cannot go faster than 0.25 unit each time in forward direction.
		if(changingVelocity < 50.0f){

			changingVelocity += 1.0f; // 0.005 unit faster.
		
		}
		
	}


	// Decrease the velocity.
	else if(increaseOrDecrease == DECREASE){
		
		// Cannot go faster than 0.25 unit each time in backward direction.
		if(changingVelocity > -50.0f){

			changingVelocity -= 1.0f; // 0.005 unit slower.

		}
	}


	// Stop the spaceship.
	else if(increaseOrDecrease == HOLT){

		changingVelocity = 0.0f;
	
	}


	// Increase to super speed.
	else if(increaseOrDecrease == SUPERSPEED){

		changingVelocity = 200.0f; // Move ship 1 unit along moving direction every time screen redraw.
	
	}


	// Switch to wide view.
	else if(increaseOrDecrease == SUPERWIDEVIEW){

		projectionMatrix.perspective(PI/2.0f, 1.0f, 0.005f, 500.0f);

	}


	// Switch to normal view.
	else if(increaseOrDecrease == NORMALVIEW){

		projectionMatrix.perspective(PI/2.0f, 1.0f, 0.005f, 50.0f);

	}


	// Setup the velocity of spaceship.
	spaceship.setVelocityOfSpaceship(changingVelocity);

}


// Update the information of the spaceship. Includes determine the distance between spaceship and a planet, update the moving vector,
// update location of the spaceship, update location of spotlight source, update where the spaceship looking at, and generate new model view matrix.
void Controller::updateSpaceship(){

	// Determine where the spaceship looking at along x-axis by the mouse position.
	if( (2*windowXSize/3) < xCoordinateOfMouse ){

			radianChangingInX -= CHANGINGRADIANIN*2;

	}

	else if ( (windowXSize/3) > xCoordinateOfMouse ){

			radianChangingInX += CHANGINGRADIANIN*2;

	}

	// Determine where the spaceship looking at along y-axis by the mouse position.
	// Restrict the angle so that camera can only have angle in y-axis between 10 to 170 degree. (0.175 and 2.967 in radians)
	if( (windowYSize/3) > yCoordinateOfMouse ){

		if(radianChangingInY > 0.175){

			radianChangingInY -= CHANGINGRADIANIN;

		}

	}

	else if ( (2*windowYSize/3) < yCoordinateOfMouse ){

		if(radianChangingInY < 2.967){

			radianChangingInY += CHANGINGRADIANIN;

		}

	}



	// If the distance between eye and planet center and the distance between at and planet center are both less than planet radius
	// and spaceship radius, the spaceship stops.
	// Or, if the next movement of spaceship will go into a planet, the spaceship stops.
	
	if( ( ( planetList.isOccupied(spaceship.getLocationOfSpaceship(), 0.005f) && 
			planetList.isOccupied(spaceship.getLookingDirection(), 0.005f) ) ||
			planetList.isOccupied(spaceship.getLocationOfSpaceship() + spaceship.getMovingOfSpaceship(), 0.005f) ) ){
			
			spaceship.setVelocityOfSpaceship(0.0);

	}


	// Update spaceship before using moving vector and at position for the following.
	spaceship.updateTheSpaceship();


	spaceship.setLookingDirection(radianChangingInX, radianChangingInY);


	lightAndMaterial.setLightPosition(spaceship.getLookingDirection());


	// Update camera
	camera.updateCamera(pointOfView, spaceship.getLocationOfSpaceship(), 
						spaceship.getLookingDirection(), spaceship.getUpVectorOfSpaceship());


	// Generate a new look at model view matrix.
	modelViewMatrix.lookAt(camera.getLocationOfCamera(), camera.getLookingAt(), camera.getUpVectorOfCamera());

}


// For drawing.
void Controller::display(){

	// clear the window
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	// Pass the model view matrix array into shader.
	glUniformMatrix4fv(modelViewMatrixLocation, 1, GL_FALSE, modelViewMatrix.getAllMatrixComponents());

	// Pass the projection matrix array into shader.
	glUniformMatrix4fv(projectionMatrixLocation, 1, GL_FALSE, projectionMatrix.getAllMatrixComponents());
	
	// Pass the eye location into shader.
	glUniform4fv(eyePositionLocation, 1, camera.getLocationOfCamera().getPoint());

	// Pass the light position into shader.
	glUniform4fv(lightPositionLocation, 1, lightAndMaterial.getLightPosition().getPoint());

	// Pass the light direction into shader.
	glUniform4fv(lightDirectionLocation, 1, (spaceship.getLookingDirection() - spaceship.getLocationOfSpaceship()).getVector());
    
	
	// Matrix for spaceship transformation.
	Matrix spaceshipMovementTransformMatrix = Matrix();
	spaceshipMovementTransformMatrix.translateCurrentMatrixByVector( Vector( spaceship.getLocationOfSpaceship().getXCoordinate(),
																			spaceship.getLocationOfSpaceship().getYCoordinate(),
																			spaceship.getLocationOfSpaceship().getZCoordinate(), 0.0f ) );

	
	// draw the points

	const int NUMPOINTPERFAN = universe.getNumPointsPerCircleOfPlanet() + 1; // Fan points count.
	const int NUMPOINTPERSTRIP = universe.getNumPointsPerPlanet() - 2 * NUMPOINTPERFAN; // Strip points count.

	// Draw spaceship.

	// Pass the material information of the planet into shader.
	glUniform4fv(ambientProductLocation, 1, lightAndMaterial.getMaterialAmbientProduct( 0 ).getColor());
		
	glUniform4fv(diffuseProductLocation, 1, lightAndMaterial.getMaterialDiffuseProduct( 0 ).getColor());
		
	glUniform4fv(specularProductLocation, 1, lightAndMaterial.getMaterialSpecularProduct( 0 ).getColor());
		
	glUniform1f(shininessLocation, lightAndMaterial.getMaterialShininess( 0 ));

	// Transform the spaceship.
	glUniformMatrix4fv(spaceshipMovementLocation, 1, GL_FALSE, spaceshipMovementTransformMatrix.getAllMatrixComponents());

	glDrawArrays(GL_TRIANGLE_FAN, 0, NUMPOINTPERFAN);

	glDrawArrays(GL_TRIANGLE_FAN, NUMPOINTPERFAN, NUMPOINTPERFAN);

	glDrawArrays(GL_TRIANGLE_STRIP, NUMPOINTPERFAN * 2, NUMPOINTPERSTRIP);

	// Reset to identity matrix, only the vertices of spaceship been transformed.
	spaceshipMovementTransformMatrix = Matrix();

	glUniformMatrix4fv(spaceshipMovementLocation, 1, GL_FALSE, spaceshipMovementTransformMatrix.getAllMatrixComponents());

	// Draw planets.
	for(int i = 1; i < universe.getNumPlanets(); i++){

		int indexOfMaterial = i % 5;

		// Pass the material information of the planet into shader.
		glUniform4fv(ambientProductLocation, 1, lightAndMaterial.getMaterialAmbientProduct( indexOfMaterial ).getColor());
		
		glUniform4fv(diffuseProductLocation, 1, lightAndMaterial.getMaterialDiffuseProduct( indexOfMaterial ).getColor());
		
		glUniform4fv(specularProductLocation, 1, lightAndMaterial.getMaterialSpecularProduct( indexOfMaterial ).getColor());
		
		glUniform1f(shininessLocation, lightAndMaterial.getMaterialShininess( indexOfMaterial ));


		// First point of each draw.
		int firstTriangleFan = i * universe.getNumPointsPerPlanet();

		int secondTriangleFan = firstTriangleFan + NUMPOINTPERFAN;

		int triangleStrip = secondTriangleFan + NUMPOINTPERFAN;



		glDrawArrays(GL_TRIANGLE_FAN, firstTriangleFan, NUMPOINTPERFAN);

		glDrawArrays(GL_TRIANGLE_FAN, secondTriangleFan, NUMPOINTPERFAN);

		glDrawArrays(GL_TRIANGLE_STRIP, triangleStrip, NUMPOINTPERSTRIP);

	}
	
    // send the framebuffer to the screen
    glFlush();
}


// Clock function.
void Controller::waitForSecond(float seconds){

	clock_t endwait;
	
	endwait = clock () + static_cast<clock_t>(seconds * CLOCKS_PER_SEC);
	
	while (clock() < endwait) {}

}