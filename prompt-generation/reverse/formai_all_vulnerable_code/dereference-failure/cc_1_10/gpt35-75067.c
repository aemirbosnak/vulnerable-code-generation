//FormAI DATASET v1.0 Category: Fractal Generation ; Style: detailed
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 600
#define HEIGHT 600
#define MAX_ITER 100000

// Define the complex number struct
typedef struct {
    double real;
    double imag;
} Complex;

// Define the pixel struct
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Define the color palette 
Pixel color_palette[] = {
    {66, 30, 15},
    {25, 7, 26},
    {9, 1, 47},
    {4, 4, 73},
    {0, 7, 100},
    {12, 44, 138},
    {24, 82, 177},
    {57, 125, 209},
    {134, 181, 229},
    {211, 236, 248},
    {241, 233, 191},
    {248, 201, 95},
    {255, 170, 0},
    {204, 128, 0},
    {153, 87, 0},
    {106, 52, 3}
};

// Define the function to create a new complex number
Complex new_complex(double real, double imag) {
    Complex c;
    c.real = real;
    c.imag = imag;
    return c;
}

// Define the function to calculate the absolute value of a complex number
double abs_complex(Complex c) {
    return sqrt(c.real*c.real + c.imag*c.imag);
}

// Define the function to calculate the square of a complex number
Complex square_complex(Complex c) {
    Complex result;
    result.real = c.real*c.real - c.imag*c.imag;
    result.imag = 2*c.real*c.imag;
    return result;
}

// Define the function to generate the fractal
void generate_fractal(int max_iter, double zoom, double x_offset, double y_offset, Pixel *image) {
    int x, y, i;
    double x_min = -2/zoom + x_offset;
    double x_max = 2/zoom + x_offset;
    double y_min = -2/zoom + y_offset;
    double y_max = 2/zoom + y_offset;
    Complex c, z, z_old;
    int palette_size = sizeof(color_palette)/sizeof(color_palette[0]);
    srand(time(0)); // To randomly select a color from the palette
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            c = new_complex(x_min + (double)x/((double)WIDTH-1)*(x_max-x_min),y_min + (double)y/((double)HEIGHT-1)*(y_max-y_min));
            z = new_complex(0,0);
            for (i = 0; i < max_iter; i++) {
                z_old = z;
                z = square_complex(z_old);
                z.real += c.real;
                z.imag += c.imag;
                if (abs_complex(z) > 2) {
                    image[y*WIDTH + x] = color_palette[rand()%palette_size];
                    break;
                }
            }
            if (i == max_iter) {
                image[y*WIDTH + x] = color_palette[palette_size-1];
            }
        }
    }
}

// Define the main function
int main() {
    Pixel *image = malloc(WIDTH*HEIGHT*sizeof(Pixel)); // Allocate memory for the image
    generate_fractal(MAX_ITER, 1, 0, 0, image); // Generate the fractal
    FILE *fp;
    fp = fopen("fractal.ppm", "wb"); // Open a file to write the image data
    fprintf(fp, "P6\n%d %d\n255\n", WIDTH, HEIGHT);
    fwrite(image, sizeof(Pixel), WIDTH*HEIGHT, fp); // Write the image data to the file
    fclose(fp); // Close the file
    free(image); // Free the memory allocated for the image
    return 0;
}