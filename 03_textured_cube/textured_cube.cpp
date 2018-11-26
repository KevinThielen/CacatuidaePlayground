
#include <stdio.h>
#include <GLContext.h>
#include <FPSCounter.h>
#include <emscripten.h>
#include <unistd.h>
#include <ShaderProgram.h>
#include <BufferObject.h>
#include <Texture.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

FPSCounter fpsCounter;

const char* vertexShaderES = ""
			   	"attribute vec3 vPosition; "
                "uniform mat4 transform;"
                "uniform sampler2D texture;"
                "attribute vec2 uv;"
		        "varying vec2 fragmentUV;"
 				"void main() "
 				"{ "
                    "fragmentUV = uv;\n"
                    " gl_Position = transform * vec4(vPosition, 1.0); "
 				"}"; 
  
  
  const char* fragmentShaderES = 
	  			"precision mediump float; \n"
                "uniform sampler2D texture;"
                "varying vec2 fragmentUV;"
 				"void main() \n"
 				"{ \n"
 				" gl_FragColor = vec4(texture2D(texture, fragmentUV).rgb, 1.0); \n"
 				"} \n";

float vertices[] = {
		//front
        -1, 1, 1, 0, 0,
	   -1, -1, 1, 0, 1,
	    1, -1, 1, 1, 1,
        1,  1, 1, 1, 0,

        //back
        -1, 1, -1, 1, 0,
	   -1, -1, -1, 1, 1,
	    1, -1, -1, 0, 1,
        1,  1, -1, 0, 0
    };


unsigned int indices[] = {
    //front
    0, 1, 2, 
    0, 2, 3,

    //back
    4, 6, 5, 
    4, 7, 6,

    //right
    3, 2, 7,
    7, 2, 6,

    //left
    0, 4, 1,
    5, 1, 4
};

unsigned int lineIndices[] = {
    0, 1, 2, 0, 
    0, 2, 3, 0
};

 unsigned char imageRGB[] =
  {
    0xFF,0, 0, 
    0, 0xFF, 0,
    0, 0, 0xFF,
    0xFF, 0xFF, 0xFF
  };


cac::ShaderProgram program;

glm::mat4 transform = glm::mat4(1);
cac::BufferObject indexBuffer;
cac::Texture texture;


//Swap buffers are handled by the browsers themselves
void frame() 
{
    glClear(GL_COLOR_BUFFER_BIT);



    auto loc = glGetUniformLocation(program.id, "transform");
    glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(transform));
 
    transform = glm::rotate(transform, fpsCounter.deltaTime, glm::vec3(0.0f, 1.0f, 0.0f));
    indexBuffer.bind<cac::EBufferObjectTarget::ELEMENT_ARRAY_BUFFER>();
    
    auto texLoc = glGetUniformLocation(program.id, "texture");
    glUniform1i(texLoc, 0);

    glDrawElements(GL_TRIANGLES, 24, GL_UNSIGNED_INT, 0);
    


    fpsCounter.update();
}


int main()
{
    createWGLContext(800, 600);

    glClearColor(0,0,0,0);

    //load shaders
    bool result = program.create(vertexShaderES, fragmentShaderES);
	glBindAttribLocation(program.id, 0, "position");
	glBindAttribLocation(program.id, 1, "uv");
    
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
    buffer.setAttributePointer<cac::EBufferObjectDataType::FLOAT>(0, 3, false, sizeof(float)*5, nullptr);
    buffer.enableAttribPointer(1);
    buffer.setAttributePointer<cac::EBufferObjectDataType::FLOAT>(1, 2, true, sizeof(float)*5, (const void*)(sizeof(float)*3));

    //using RGB texture, so we need to align
    glPixelStorei(GL_UNPACK_ALIGNMENT, 2);
    texture.create();
    texture.bind(cac::ETextureTarget::TEXTURE_2D);
    texture.setMinMagFilter(cac::EMinFilter::NEAREST, cac::EMagFilter::NEAREST);
    texture.setWrapST(cac::ETextureWrap::CLAMP_TO_EDGE, cac::ETextureWrap::CLAMP_TO_EDGE);
    texture.setData(0, 2, 2, cac::EInternalFormat::RGB, cac::EDataType::UNSIGNED_BYTE, &imageRGB[0]);
    //index buffer
    indexBuffer.create();
    indexBuffer.bind<cac::EBufferObjectTarget::ELEMENT_ARRAY_BUFFER>();
    indexBuffer.setData<cac::EBufferObjectUsage::STATIC>(sizeof(indices), indices);

    glActiveTexture(GL_TEXTURE0);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    emscripten_set_main_loop(frame, 0, 1);

    return 0;
}
