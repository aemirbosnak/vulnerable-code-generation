//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

// Define constants for the width and height of the image
#define WIDTH 800
#define HEIGHT 600

// Define a structure to hold the pixel data for the image
typedef struct {
    int r, g, b;
} pixel;

// Define a function to convert an integer to a string
char *int_to_str(int num) {
    static char str[11];
    sprintf(str, "%d", num);
    return str;
}

// Define a function to draw a pixel on the image
void draw_pixel(pixel *image, int x, int y, int r, int g, int b) {
    // Convert the pixel values to strings
    char r_str[11];
    char g_str[11];
    char b_str[11];
    sprintf(r_str, "%d", r);
    sprintf(g_str, "%d", g);
    sprintf(b_str, "%d", b);
    
    // Create a new string to hold the pixel data
    char pixel_str[20];
    sprintf(pixel_str, "R:%s G:%s B:%s", r_str, g_str, b_str);
    
    // Print the pixel string to the console
    printf("Drawing pixel at (%d, %d) with color %s\n", x, y, pixel_str);
    
    // Update the image data with the new pixel
    image[x + y * WIDTH].r = r;
    image[x + y * WIDTH].g = g;
    image[x + y * WIDTH].b = b;
}

// Define a function to print the image data to the console
void print_image(pixel *image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            printf("(%d, %d): %s\n", j, i, int_to_str(image[i + j * width].r));
        }
    }
}

int main() {
    // Allocate memory for the image data
    pixel *image = (pixel *)malloc(WIDTH * HEIGHT * sizeof(pixel));
    
    // Initialize the image data with default values
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            image[i + j * WIDTH].r = image[i + j * WIDTH].g = image[i + j * WIDTH].b = 0;
        }
    }
    
    // Draw a red square in the center of the image
    draw_pixel(image, WIDTH / 2, HEIGHT / 2, 255, 0, 0);
    
    // Print the image data to the console
    print_image(image, WIDTH, HEIGHT);
    
    // Free the memory allocated for the image data
    free(image);
    
    return 0;
}