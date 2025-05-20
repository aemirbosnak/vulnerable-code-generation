//FormAI DATASET v1.0 Category: Fractal Generation ; Style: Romeo and Juliet
/* Romeo and Juliet-inspired Fractal Generation program */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void generate_fractal(int, int, double, double, double, double);

int main()
{
    int width = 800; // width of the image
    int height = 800; // height of the image
    double x_min = -2.0; // minimum value of x
    double x_max = 2.0; // maximum value of x
    double y_min = -2.0; // minimum value of y
    double y_max = 2.0; // maximum value of y
    
    printf("Oh, how my heart churns with the desire to see a fractal bloom before my very eyes!\n");
    printf("Shall we embark on this journey, my dear Juliet?\n");
    printf("Yes, my love, let us witness the beauty of the Mandelbrot set together!\n");
    
    generate_fractal(width, height, x_min, x_max, y_min, y_max);
    
    printf("Oh, my Juliet, look at the wondrous pattern that has been revealed before us!\n");
    printf("Truly, nothing compares to the intricate details and the infinite possibilities of fractals.\n");
    printf("Thank you for sharing this moment with me, my love.\n");
    
    return 0;
}

void generate_fractal(int width, int height, double x_min, double x_max, double y_min, double y_max)
{
    // allocate memory for 2D array to store pixel values
    int **pixels = malloc(sizeof(int *) * height);
    for (int i = 0; i < height; i++)
        pixels[i] = malloc(sizeof(int) * width);
    
    // iterate over each pixel in the image
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // map pixel coordinates to complex plane coordinates
            double x_0 = x_min + ((double) j / width) * (x_max - x_min);
            double y_0 = y_min + ((double) i / height) * (y_max - y_min);
            double x = 0;
            double y = 0;
            int iteration = 0;
            
            // calculate the number of iterations until divergence using the Mandelbrot recurrence formula
            while (x*x + y*y <= 4 && iteration < 255)
            {
                double x_temp = x*x - y*y + x_0;
                y = 2*x*y + y_0;
                x = x_temp;
                iteration++;
            }
            
            // set the value of the pixel based on the number of iterations
            pixels[i][j] = iteration;
        }
    }
    
    // print the PPM image header
    printf("P3\n%d %d\n255\n", width, height);
    
    // print the pixel values in PPM format
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%d %d %d ", pixels[i][j], pixels[i][j], pixels[i][j]);
        }
        printf("\n");
    }
    
    // free memory
    for (int i = 0; i < height; i++)
        free(pixels[i]);
    free(pixels);
}