#ifndef CACATUIDAE_CAMERA_H
#define CACATUIDAE_CAMERA_H

#include <glm/matrix.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace cac 
{
    struct Camera 
    {
        mat4 view;
        mat4 projection;     


        void orthoProjection(float left, float right, float bottom, float top, float nearPlane, float farPlane) 
        {
            projection = ortho(left, right, bottom, top, nearPlane, farPlane);
        }   

        void lookAtView(vec3 eyePos, vec3 target, vec3 up)
        {
            lookAt(eyePos, target, up);
        }
    };


}



#endif