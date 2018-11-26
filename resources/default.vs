attribute vec2 position;
varying vec2 fPosition;
void main()
{
    gl_Position = vec4(position.xy, 0.0, 1.0);
    fPosition=position;
}; 
  