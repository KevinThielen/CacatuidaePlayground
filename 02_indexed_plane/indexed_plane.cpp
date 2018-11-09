
#include <stdio.h>
#include <GLContext.h>
#include <FPSCounter.h>
#include <emscripten.h>
#include <unistd.h>
#include <ShaderProgram.h>
#include <BufferObject.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

FPSCounter fpsCounter;

const char* vertexShaderES = ""
			   	"attribute vec3 vPosition; "
                "uniform mat4 transform;"
 				"void main() "
 				"{ "
 				" gl_Position = transform * vec4(vPosition, 1.0); "
 				"}"; 
  
  
  const char* fragmentShaderES = 
	  			"precision mediump float; \n"
                "uniform vec4 color;"
 				"void main() \n"
 				"{ \n"
 				" gl_FragColor = vec4(color); \n"
 				"} \n";

float vertices[] = {
		//front
        -1, 1, 0,
	   -1, -1, 0,
	    1, -1, 0,
        1,  1, 0,
        //back
        -1, 1, 0,
	    -1, -1, 0,
	     1, -1, 0,
         1,  1, 0,
	};


unsigned int indices[] = {
    0, 1, 2, 
    0, 2, 3,
};

unsigned int lineIndices[] = {
    0, 1, 2, 0, 
    0, 2, 3, 0
};

cac::ShaderProgram program;

glm::mat4 transform = glm::mat4(1);
cac::BufferObject indexBuffer;
cac::BufferObject lineIndexBuffer;


glm::vec4 faceColor = glm::vec4(1.0f, 0.0f,0.0f, 1.0f);
glm::vec4 wireColor = glm::vec4(1.0f, 1.0f,1.0f, 1.0f);

//Swap buffers are handled by the browsers themselves
void frame() 
{
    glClear(GL_COLOR_BUFFER_BIT);



    auto loc = glGetUniformLocation(program.id, "transform");
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(transform));
 
    auto colorLoc = glGetUniformLocation(program.id, "color");
    glUniform4fv(colorLoc, 1, glm::value_ptr(faceColor));

    transform = glm::rotate(transform, fpsCounter.deltaTime, glm::vec3(0.0f, 1.0f, 0.0f));
    indexBuffer.bind<cac::EBufferObjectTarget::ELEMENT_ARRAY_BUFFER>();
    
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    
    glUniform4fv(colorLoc, 1, glm::value_ptr(wireColor));

    lineIndexBuffer.bind<cac::EBufferObjectTarget::ELEMENT_ARRAY_BUFFER>();
    glDrawElements(GL_LINE_LOOP, 8, GL_UNSIGNED_INT, 0);

    fpsCounter.update();
}


int main()
{
    createWGLContext(800, 600);

    glClearColor(0,0,0,0);

    //load shaders
    bool result = program.create(vertexShaderES, fragmentShaderES);
	glBindAttribLocation(program.id, 0, "position");
    
    if(!result)
        printf("Failed to create shader\n");

    program.use();

    transform = glm::scale(transform, glm::vec3(.5f, .5f, .5f));


    //create triangle
    cac::BufferObject buffer;
    buffer.create();
    buffer.bind<cac::EBufferObjectTarget::ARRAY_BUFFER>();
    buffer.setData<cac::EBufferObjectUsage::DYNAMIC>(sizeof(vertices), vertices);
    buffer.enableAttribPointer(0);
    buffer.setAttributePointer<cac::EBufferObjectDataType::FLOAT>(0, 4, false, sizeof(float)*3, nullptr);

    //index buffer
    indexBuffer.create();
    indexBuffer.bind<cac::EBufferObjectTarget::ELEMENT_ARRAY_BUFFER>();
    indexBuffer.setData<cac::EBufferObjectUsage::STATIC>(sizeof(indices), indices);

    lineIndexBuffer.create();
    lineIndexBuffer.bind<cac::EBufferObjectTarget::ELEMENT_ARRAY_BUFFER>();
    lineIndexBuffer.setData<cac::EBufferObjectUsage::STATIC>(sizeof(lineIndices), lineIndices);

    glCullFace(GL_FRONT_AND_BACK);
    glDepthFunc(GL_ALWAYS);

    glLineWidth(2.0f);

    emscripten_set_main_loop(frame, 0, 1);

    return 0;
}
