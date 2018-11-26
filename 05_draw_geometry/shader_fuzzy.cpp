
#include <stdio.h>
#include <FPSCounter.h>
#include <emscripten.h>
#include <unistd.h>
#include <ShaderProgram.h>
#include <BufferObject.h>
#include <Texture.h>
#include <FileLoader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Graphics.h>

FPSCounter fpsCounter;

  const char* vertexShaderES = "";
  const char* fragmentShaderBlur = 
	  			"precision mediump float; \n"
			   	"varying vec2 fPosition; "
                "uniform float border;"
                "uniform float radius;"
                "uniform vec4 mainColor;"
                "uniform vec4 subColor;"

 				"void main() "
 				"{ "
                    "float aspect = 800.0/600.0;"
                    "float dist = length(vec2(aspect*fPosition.x, fPosition.y));"

                    "float lower = smoothstep(radius-border, radius, dist); "

                    "float upper = smoothstep(radius, radius+border, dist);"

                    "float alpha = lower+upper;"
                    "alpha = pow(4.0*alpha*(1.0-alpha), 0.75)/1.2;"


                    "vec4 finalColor = mix(mainColor, subColor, alpha);"
 				    " gl_FragColor = vec4(finalColor.xyz, alpha);"
 				"}";




  
  const char* fragmentShaderWave = 
	  			"precision mediump float; \n"
			   	"varying vec2 fPosition; "
                "uniform float time;"
                "uniform vec4 mainColor;"
                "uniform vec4 subColor;"

                "float random (in vec2 _st) {"
"    return fract(sin(dot(_st.xy,"
"                         vec2(12.9898,78.233)))*"
"        43758.5453123);"
"}"

"float noise (in vec2 _st) {"
"    vec2 i = floor(_st);"
"    vec2 f = fract(_st);"

    "float a = random(i);"
    "float b = random(i + vec2(1.0, 0.0));"
    "float c = random(i + vec2(0.0, 1.0));"
    "float d = random(i + vec2(1.0, 1.0));"

    "vec2 u = f * f * (3.0 - 2.0 * f);"

    "return mix(a, b, u.x) +"
            "(c - a)* u.y * (1.0 - u.x) +"
            "(d - b) * u.x * u.y;"
"}"


"float fbm ( in vec2 _st) {"
    "float v = 0.0;"
    "float a = 0.5;"
    "vec2 shift = vec2(100.0);"
    // Rotate to reduce axial bias
    "mat2 rot = mat2(cos(0.5), sin(0.5),"
                    "-sin(0.5), cos(0.50));"
    "for (int i = 0; i < 7; ++i) {"
        "v += a * noise(_st);"
        "_st = rot * _st * 2.0 + shift;"
        "a *= 0.75;"//<
    "}"
    "return v;"
"}"
 				"void main() \n"
 				"{"
                    "vec2 pos = vec2(1.0-fPosition.y, 1.0-fPosition.x);"                 
                   "vec2 q = vec2(0.0);"
                   "q.x = fbm(pos + 0.00*time);"
                   "q.y = fbm(pos + vec2(1.0));"

                   "vec2 r = vec2(0.);"
                   "r.x = fbm(pos + 1.0*q + vec2(1.7, 9.2) + 0.15 * time);"
                   "r.y = fbm(pos + 1.0*q + vec2(8.3, 2.8) + 0.126 * time);"
                   "float f = fbm(pos+r);"

                   "vec3 color = vec3(0.0, 0.0, 0.0);"
                    "color = mix(mainColor.rgb,"
                    "vec3(0.666667,0.666667,2.0*0.498039),"
                    "clamp((f*f)*4.0,0.0,1.0));"

                    "color = mix(color,"
                    "vec3(0,0,0.164706),"
                    "clamp(length(q),0.0,1.0));"

                    "color = mix(color,"
                    "vec3(0.366667,0.4,1),"
                    "clamp(length(r.x),0.0,1.0));"

                    "gl_FragColor = vec4((f*f*f+.6*f*f+.5*f)*color,1.0);"
 				"}";



void loadShaders();
void setupBuffers();
void setupState();

struct Uniforms 
{
    GLint border;
    GLint radius;
    GLint mainColor;
    GLint subColor;
    GLint time;
} uniforms;
//Swap buffers are handled by the browsers themselves
cac::ShaderProgram shaderBlur;
cac::ShaderProgram shaderWave;

float at = 0.0f;
float act=0.0f;
void frame() 
{
    at+=0.75f*fpsCounter.deltaTime;
    act+=fpsCounter.deltaTime;

    glClear(GL_COLOR_BUFFER_BIT);

    if(act >= 1.0f)
    { 
        printf("FPS: %i  dt:%f\n", fpsCounter.fps, fpsCounter.deltaTime);
        act = 0;
    }
    
    shaderWave.use();
    shaderWave.setUniform(uniforms.time, at);
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    shaderBlur.use();
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

    fpsCounter.update();
}

cac::BufferObject buffer;
cac::BufferObject bgbuffer;
int main()
{
    cac::Graphics graphics;
    graphics.init(800, 600);

    glClearColor(0,0,0,0);

    loadShaders();

    setupBuffers();
    setupState();


    emscripten_set_main_loop(frame, 0, 1);



    return 0;
}

float vertices[] = {
    //plane
    -0.5f,  0.5f,
     0.5f,  0.5f,
    -0.5f, -0.5f,
     0.5f, -0.5f
};

float verticesBG[] = {
    //plane
    -1.0f,  1.0f,
     1.0f,  1.0f,
    -1.0f, -1.0f,
     1.0f, -1.0f
};
void loadShaders() 
{   
    shaderBlur.create();
	shaderBlur.setAtrribLoc(0, "position");
    bool result = shaderBlur.create(vertexShaderES, fragmentShaderBlur);
    
    if(!result) {
        printf("Failed to create shader\n");
        return;
    }
    shaderBlur.use();

    uniforms.border = shaderBlur.getUniformLoc("border");
    uniforms.radius = shaderBlur.getUniformLoc("radius");
    uniforms.mainColor = shaderBlur.getUniformLoc("mainColor");
    uniforms.subColor = shaderBlur.getUniformLoc("subColor");

    shaderBlur.setUniform(uniforms.border, 0.02f);
    shaderBlur.setUniform(uniforms.radius, 0.4f);
    shaderBlur.setUniform(uniforms.subColor, glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
    shaderBlur.setUniform(uniforms.mainColor,  glm::vec4(0.0f, 0.0f, 1.0f, 1.0f));


    shaderWave.create();
    shaderWave.setAtrribLoc(0, "position");
    result = shaderWave.create(vertexShaderES, fragmentShaderWave);
    
    if(!result) {
        printf("Failed to create shader\n");
        return;
    }
    shaderWave.use();

    uniforms.time = shaderWave.getUniformLoc("time");
    uniforms.mainColor = shaderWave.getUniformLoc("mainColor");
    uniforms.subColor = shaderWave.getUniformLoc("subColor");

}

void setupBuffers()
{
    //quad vertexBuffer
    buffer.create();
    buffer.bind<cac::EBufferObjectTarget::ARRAY_BUFFER>();
    buffer.setData<cac::EBufferObjectUsage::DYNAMIC>(sizeof(vertices), vertices);
    buffer.enableAttribPointer(0);
    buffer.setAttributePointer<cac::EBufferObjectDataType::FLOAT>(0, 2, false, 0, nullptr);

    bgbuffer.create();
    bgbuffer.bind<cac::EBufferObjectTarget::ARRAY_BUFFER>();
    bgbuffer.setData<cac::EBufferObjectUsage::DYNAMIC>(sizeof(verticesBG), verticesBG);
    bgbuffer.enableAttribPointer(0);
    bgbuffer.setAttributePointer<cac::EBufferObjectDataType::FLOAT>(0, 2, false, 0, nullptr);
}

void setupState()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}