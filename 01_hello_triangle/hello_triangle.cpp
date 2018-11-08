
#include <stdio.h>
#include <GLContext.h>
#include <FPSCounter.h>
#include <emscripten.h>
#include <unistd.h>
#include <ShaderProgram.h>
#include <BufferObject.h>

FPSCounter fpsCounter;

const char* vertexShaderES = ""
			   	"attribute vec4 vPosition; "
 				"void main() "
 				"{ "
 				" gl_Position = vPosition; "
 				"}"; 
  
  
  const char* fragmentShaderES = 
	  			"precision mediump float; \n"
 				"void main() \n"
 				"{ \n"
 				" gl_FragColor = vec4(1.0, 0.0, 0.0, 1.0); \n"
 				"} \n";

float vertices[] = {
		0, 1,
	   -1,-1,
	    1,-1
	};

//Swap buffers are handled by the browsers themselves
void frame() 
{
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    fpsCounter.update();
}


int main()
{
    createWGLContext(800, 600);

    glClearColor(0,0,0,0);

    //load shaders
    cac::ShaderProgram program;
    bool result = program.create(vertexShaderES, fragmentShaderES);
    
    if(!result)
        printf("Failed to create shader\n");

    program.use();
	glBindAttribLocation(program.id, 0, "position");



    //create triangle
    cac::BufferObject buffer;
    buffer.create();
    buffer.bind<cac::EBufferObjectTarget::ARRAY_BUFFER>();
    buffer.setData<cac::EBufferObjectUsage::DYNAMIC>(sizeof(vertices), &vertices[0]);
    buffer.enableAttribPointer(0);
    buffer.setAttributePointer<cac::EBufferObjectDataType::FLOAT>(0, 2, false, sizeof(float)*2, nullptr);



    emscripten_set_main_loop(frame, 0, 1);

    return 0;
}
