#version 330 core

    in vec3 frag_position;
    int iterCount(float cr, float ci){
        float mx = 25;
        float zr = 0;
        float zi = 0;
        float lengthsq = 0;
        int count = 0;

        while ((lengthsq <4.0) && (count<mx)){
            float temp = zr * zr - zi * zi  + cr;
            zi = 2 * zr * zi + ci;
            zr = temp;
            lengthsq = zr * zr + zi * zi;
            count++;
        }
        return count;
        }

    void main(){
    float r = frag_position.x2;
    float i = frag_position.y2;
    int color = iterCount(r,i);

    gl_FragColor = vec4(color/25.0, color/25.0, color/25.0, 1);

    }
