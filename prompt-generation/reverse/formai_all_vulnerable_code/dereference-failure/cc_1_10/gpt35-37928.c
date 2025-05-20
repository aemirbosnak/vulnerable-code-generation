//FormAI DATASET v1.0 Category: Fractal Generation ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct complex{
    double real, imag;
}complex;

// Function to perform addition of two complex numbers
complex add(complex c1, complex c2){
    complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to perform multiplication of two complex numbers
complex mul(complex c1, complex c2){
    complex result;
    result.real = c1.real*c2.real - c1.imag*c2.imag;
    result.imag = c1.real*c2.imag + c1.imag*c2.real;
    return result;
}

// Function to compute the absolute value of a complex number
double absolute(complex c){
    return sqrt(c.real*c.real + c.imag*c.imag);
}

// Function that generates the fractal
void generateFractal(int N, double limit){
    int rows = N, cols = N, i, j, k;
    double xmin = -1.5, xmax = 1.5, ymin = -1.5, ymax = 1.5;
    double dx = (xmax - xmin)/cols, dy = (ymax - ymin)/rows;
    complex c, z, z0, zOld;
    double a;
    int iterations;
    
    // Create the 2D array to store the fractal
    int **fractal;
    fractal = (int**)malloc(rows*sizeof(int*));
    for(i=0;i<rows;i++){
        fractal[i] = (int*)malloc(cols*sizeof(int));
    }
    
    // Initialize the fractal array to 0
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            fractal[i][j] = 0;
        }
    }
    
    // Iterate over the complex plane and compute the fractal
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            c.real = xmin + j*dx;
            c.imag = ymin + i*dy;
            z = c;
            z0 = c;
            iterations = 0;
            while (absolute(z) < limit && iterations < 100){
                zOld = z;
                z = add(mul(z,z), z0);
                if (absolute(zOld) >= 1.0 && absolute(z) < 1.0){
                    a = atan2(z.imag, z.real)/(2*M_PI) + 0.5;
                    k = (int)(a*255);
                    fractal[i][j] = k+1;
                }
                iterations++;
            }
        }
    }
    
    // Print out the fractal as an image
    FILE *fp;
    char *filename = "fractal.ppm";
    fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", cols, rows);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            putc(fractal[i][j], fp);
            putc(fractal[i][j], fp);
            putc(fractal[i][j], fp);
        }
    }
    fclose(fp);
}

int main(){
    generateFractal(500, 1.5);
    return 0;
}