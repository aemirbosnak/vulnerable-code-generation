//FormAI DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define image dimensions
#define WIDTH 64 
#define HEIGHT 64 
#define DEPTH 3 

// Define color constants
#define BLACK 0
#define WHITE 255
#define RED 100
#define GREEN 150
#define BLUE 200

// Define configurable filter constants
#define COLOR_THRESHOLD 75
#define BRIGHTNESS_THRESHOLD 150

// Define function to set an individual pixel's color values
void set_pixel_color(unsigned char *image, int x, int y, int r, int g, int b) {
    int index = (y * WIDTH + x) * DEPTH;
    image[index] = r;
    image[index + 1] = g;
    image[index + 2] = b;
}

int main() {
    // Dynamically allocate space for the image array
    unsigned char *image = (unsigned char*)malloc(WIDTH * HEIGHT * DEPTH);
    
    // Set all pixels to white
    for (int i = 0; i < WIDTH * HEIGHT * DEPTH; i++) {
        image[i] = WHITE;
    }
    
    // Draw a black border around the edges
    for (int x = 0; x < WIDTH; x++) {
        set_pixel_color(image, x, 0, BLACK, BLACK, BLACK);
        set_pixel_color(image, x, HEIGHT - 1, BLACK, BLACK, BLACK);
    }
    for (int y = 0; y < HEIGHT; y++) {
        set_pixel_color(image, 0, y, BLACK, BLACK, BLACK);
        set_pixel_color(image, WIDTH - 1, y, BLACK, BLACK, BLACK);
    }
    
    // Generate random pixels within the border
    for (int x = 1; x < WIDTH - 1; x++) {
        for (int y = 1; y < HEIGHT - 1; y++) {
            int r = rand() % 256;
            int g = rand() % 256;
            int b = rand() % 256;
            set_pixel_color(image, x, y, r, g, b);
        }
    }
    
    // Apply configurable color filter
    for (int x = 1; x < WIDTH - 1; x++) {
        for (int y = 1; y < HEIGHT - 1; y++) {
            int index = (y * WIDTH + x) * DEPTH;
            int r = image[index];
            int g = image[index + 1];
            int b = image[index + 2];
            if (r < COLOR_THRESHOLD && g < COLOR_THRESHOLD && b < COLOR_THRESHOLD) {
                r += RED;
                g += GREEN;
                b += BLUE;
                set_pixel_color(image, x, y, r, g, b);
            }
        }
    }
    
    // Apply configurable brightness filter
    for (int x = 1; x < WIDTH - 1; x++) {
        for (int y = 1; y < HEIGHT - 1; y++) {
            int index = (y * WIDTH + x) * DEPTH;
            int r = image[index];
            int g = image[index + 1];
            int b = image[index + 2];
            if ((r + g + b) / 3 > BRIGHTNESS_THRESHOLD) {
                r -= RED;
                g -= GREEN;
                b -= BLUE;
                set_pixel_color(image, x, y, r, g, b);
            }
        }
    }
    
    // Output the final image to a file
    FILE *output_file = fopen("output_image.ppm", "wb");
    fprintf(output_file, "P6\n%d %d\n%d\n", WIDTH, HEIGHT, 255);
    fwrite(image, 1, WIDTH * HEIGHT * DEPTH, output_file);
    fclose(output_file);
    
    free(image); // Free the dynamically allocated memory
    return 0;
}