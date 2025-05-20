//Falcon-180B DATASET v1.0 Category: Pixel Art Generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define WIDTH 800
#define HEIGHT 600
#define PIXEL_SIZE 5

int main() {
    // Initialize random seed
    srand(time(NULL));

    // Create image buffer
    unsigned char* image_buffer = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Clear image buffer
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image_buffer[i] = 0;
    }

    // Generate pixel art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            // Calculate pixel color based on position
            int r = sin(x * M_PI / WIDTH) * cos(y * M_PI / HEIGHT);
            int g = cos(x * M_PI / WIDTH) * cos(y * M_PI / HEIGHT);
            int b = cos(x * M_PI / WIDTH) * sin(y * M_PI / HEIGHT);

            // Set pixel color
            int index = (y * WIDTH + x) * sizeof(unsigned char);
            image_buffer[index] = r;
            image_buffer[index + 1] = g;
            image_buffer[index + 2] = b;
        }
    }

    // Save image to file
    FILE* fp = fopen("pixel_art.png", "wb");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }

    fwrite(image_buffer, WIDTH * HEIGHT * sizeof(unsigned char), 1, fp);
    fclose(fp);

    printf("Pixel art generated and saved to file.\n");

    return 0;
}