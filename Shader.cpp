#include "Shader.h"

using namespace std;

// Read shader source from text file, store in char array, and return it.
// Show message if the file is not opened.
char* Shader::readShaderSource(const char* shaderFile){
	
	string line, result;
	char* fileText;
	ifstream file (shaderFile);
	

	if(file.is_open()){
		

		while(file.good()){
			
			getline(file, line);
			result += line;
			result += "\n";

		}
		

		file.close();
		
		fileText = new char[result.size()+1];
		
		size_t length;
		
		#pragma warning(disable:4996)
		// Remove a warning which is Microsoft-specific.
		length = result.copy(fileText, result.size(), 0);
		#pragma warning(default:4996)
		
		fileText[length] = '\0'; // End the array.
	}


	else cout<<"Unable to open file";


	return fileText;

}

// Initialize the shaders by given shaders text file, attach them to the program, link the program, and return the program.
Shader::Shader(const char* vertexShaderFile, const char* fragmentShaderFile) {
	
	shaderProgram = glCreateProgram();
    
	GLchar*	vertexShaderSource = readShaderSource(vertexShaderFile);
	GLchar* fragmentShaderSource = readShaderSource(fragmentShaderFile);



    // create, compile, and attach vertex shader
	GLuint	vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1,(const GLchar**)&vertexShaderSource, 0);
    glCompileShader(vertexShader);


	// Check if it correctly compiled.
	GLint  compiled;
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &compiled );
	
	if ( !compiled ) {
	    
		cerr << "Vertex shader failed to compile:" << endl;
	    
		GLint  logSize_;
	    glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &logSize_ );
	    
		char* logMessage_ = new char[logSize_];
	    glGetShaderInfoLog(vertexShader, logSize_, NULL, logMessage_ );
	    
		cerr << logMessage_ << endl;
	    
		delete [] logMessage_;

	    exit( EXIT_FAILURE );
	}

    glAttachShader(shaderProgram, vertexShader);



    // Create, compile, and attach fragment shader
    GLuint	fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, (const GLchar**)&fragmentShaderSource, 0);
    glCompileShader(fragmentShader);


	// Check if it correctly compiled.
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &compiled );
	
	if ( !compiled ) {
	    
		cerr << "Fragment shader failed to compile:" << endl;
	    
		GLint  logSize_;
	    glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &logSize_ );
	    
		char* logMessage_ = new char[logSize_];
	    glGetShaderInfoLog(fragmentShader, logSize_, NULL, logMessage_ );
	    
		cerr << logMessage_ << endl;
	    
		delete [] logMessage_;

	    exit( EXIT_FAILURE );
	}


	glAttachShader(shaderProgram, fragmentShader);


    // link the two shaders into a program.
    glLinkProgram(shaderProgram);

}