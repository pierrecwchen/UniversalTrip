#include "LightAndMaterial.h"


// Defult constructor which initialize all information for one light source and 5 materials.
LightAndMaterial::LightAndMaterial(){


	lightPosition = Point(0.0f, 0.0f, 0.005f, 1.0f);



	// Light, from angel.
	lightColor[0] = Color(0.2f, 0.2f, 0.2f, 1.0f); // Light ambient.

	lightColor[1] = Color(1.0f, 1.0f, 1.0f, 1.0f); // Light diffuse.

	lightColor[2] = Color(1.0f, 1.0f, 1.0f, 1.0f); // Light specular.




	// First material, from angel.
	materialAmbient[0] = Color(1.0f, 0.0f, 1.0f, 1.0f);

	materialDiffuse[0] = Color(1.0f, 0.8f, 0.0f, 1.0f);

	materialSpecular[0] = Color(1.0f, 0.8f, 0.0f, 1.0f);

	materialShininess[0] = 100.0f;




	// Second material, from angel.
	materialAmbient[1] = Color(1.0f, 0.0f, 1.0f, 1.0f);

	materialDiffuse[1] = Color(1.0f, 0.8f, 0.0f, 1.0f);

	materialSpecular[1] = Color(1.0f, 0.0f, 1.0f, 1.0f);

	materialShininess[1] = 5.0f;




	// 3rd material
	materialAmbient[2] = Color(0.5f, 0.5f, 0.5f, 1.0f);

	materialDiffuse[2] = Color(0.8f, 1.0f, 0.3f, 1.0f);

	materialSpecular[2] = Color(0.6f, 0.8f, 0.1f, 1.0f);

	materialShininess[2] = 20.0f;




	// 4th material
	materialAmbient[3] = Color(0.8f, 0.4f, 1.0f, 1.0f);

	materialDiffuse[3] = Color(0.0f, 0.8f, 0.7f, 1.0f);

	materialSpecular[3] = Color(0.0f, 0.8f, 0.9f, 1.0f);

	materialShininess[3] = 10.0f;




	// 5th material
	materialAmbient[4] = Color(0.4f, 0.6f, 0.7f, 1.0f);

	materialDiffuse[4] = Color(0.0f, 0.1f, 0.2f, 1.0f);

	materialSpecular[4] = Color(1.0f, 0.8f, 1.0f, 1.0f);

	materialShininess[4] = 200.0f;

}