//FormAI DATASET v1.0 Category: Fractal Generation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

// Number of iterations
#define ITERATIONS 5000

// Image width and height
#define WIDTH 800
#define HEIGHT 800

// Image brightness
#define BRIGHTNESS 255

// Coordinates of the center of the image
#define CENTER_X -0.5
#define CENTER_Y 0.0

// Zoom level
#define ZOOM 1

// The complex plane
typedef struct {
    double re;
    double im;
} Complex;

// Map a pixel to a point in the complex plane
void map_pixel(int x, int y, double zoom, Complex *point)
{
    point->re = CENTER_X - WIDTH/2.0/zoom + x/zoom;
    point->im = CENTER_Y - HEIGHT/2.0/zoom + y/zoom;
}

// Check if a point is in the Mandelbrot set
bool in_mandelbrot_set(Complex *c)
{
    Complex z = {0.0, 0.0};
    for (int i = 0; i < ITERATIONS; i++) {
        Complex z_new = {
            z.re*z.re - z.im*z.im + c->re,
            2*z.re*z.im + c->im
        };
        if (sqrt(z_new.re*z_new.re + z_new.im*z_new.im) > 2.0) {
            return false;
        }
        z = z_new;
    }
    return true;
}

// Generate the Mandelbrot fractal
void generate_fractal(unsigned char *image, double zoom)
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            Complex point;
            map_pixel(x, y, zoom, &point);
            bool in_set = in_mandelbrot_set(&point);
            int index = (y*WIDTH + x)*3;
            if (in_set) {
                image[index] = BRIGHTNESS;
                image[index+1] = BRIGHTNESS;
                image[index+2] = BRIGHTNESS;
            } else {
                image[index] = 0;
                image[index+1] = 0;
                image[index+2] = 0;
            }
        }
    }
}

int main()
{
    // Allocate memory for the image
    unsigned char *image = (unsigned char *)malloc(WIDTH*HEIGHT*3);

    // Generate the Mandelbrot fractal
    generate_fractal(image, ZOOM);

    // Write the image to a file
    FILE *image_file = fopen("mandelbrot.bmp", "wb");
    unsigned char bmp_header[] = {
        0x42, 0x4D, 0x36, 0x92, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x36, 0x00, 0x00, 0x00, 0x28, 0x00,
        0x00, 0x00, 0x20, 0x03, 0x00, 0x00, 0x20, 0x03,
        0x00, 0x00, 0x01, 0x00, 0x18, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x92, 0x00, 0x00, 0x12, 0x0B,
        0x00, 0x00, 0x12, 0x0B, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
    fwrite(bmp_header, 1, sizeof(bmp_header), image_file);
    fwrite(image, 1, WIDTH*HEIGHT*3, image_file);
    fclose(image_file);

    // Free memory
    free(image);

    return 0;
}