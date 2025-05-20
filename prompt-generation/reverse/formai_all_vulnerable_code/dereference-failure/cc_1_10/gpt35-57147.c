//FormAI DATASET v1.0 Category: Fractal Generation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

// Struct used to represent a complex number
typedef struct {
    double real;
    double imag;
} Complex;

// Returns the absolute value of a complex number
double absVal(Complex z) {
    return sqrt(z.real*z.real + z.imag*z.imag);
}

// Returns the squared magnitude of a complex number
double magSq(Complex z) {
    return z.real*z.real + z.imag*z.imag;
}

// Returns the result of adding two complex numbers
Complex add(Complex a, Complex b) {
    Complex result = { a.real+b.real, a.imag+b.imag };
    return result;
}

// Returns the result of multiplying two complex numbers
Complex multiply(Complex a, Complex b) {
    Complex result = { a.real*b.real - a.imag*b.imag, a.real*b.imag + a.imag*b.real };
    return result;
}

// Generates a color for a given complex number
int genColor(Complex z, int maxIter) {
    int iter = 0;
    Complex c = z;
    while (iter < maxIter && magSq(z) < 4) {
        z = add(multiply(z, z), c);
        iter++;
    }
    if (iter == maxIter) {
        return 1; // black
    } else {
        return iter % 6 + 2; // rotate through 6 colors (red, green, blue, yellow, cyan, magenta)
    }
}

// Prints the Mandelbrot fractal to the console
void printFractal(int width, int height, double xMin, double xMax, double yMin, double yMax, int maxIter) {
    int x, y, color;
    Complex z;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            z.real = xMin + (double)x / width * (xMax - xMin);
            z.imag = yMin + (double)y / height * (yMax - yMin);
            color = genColor(z, maxIter);
            printf("\033[3%dm ", color); // print colored space
        }
        printf("\033[0m\n"); // reset color formatting
    }
}

int main(int argc, char* argv[]) {
    // Default parameters
    int width = 80;
    int height = 40;
    double xMin = -2.0;
    double xMax = 2.0;
    double yMin = -1.0;
    double yMax = 1.0;
    int maxIter = 20;

    // Update parameters from command line arguments
    if (argc > 1) {
        width = atoi(argv[1]);
    }
    if (argc > 2) {
        height = atoi(argv[2]);
    }
    if (argc > 3) {
        xMin = atof(argv[3]);
    }
    if (argc > 4) {
        xMax = atof(argv[4]);
    }
    if (argc > 5) {
        yMin = atof(argv[5]);
    }
    if (argc > 6) {
        yMax = atof(argv[6]);
    }
    if (argc > 7) {
        maxIter = atoi(argv[7]);
    }

    // Print the Mandelbrot fractal
    printFractal(width, height, xMin, xMax, yMin, yMax, maxIter);

    return 0;
}