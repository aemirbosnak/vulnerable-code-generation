//Falcon-180B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define WIDTH 512
#define HEIGHT 512

int main() {
    srand(time(NULL));

    // Initialize image with random values
    int *image = calloc(WIDTH * HEIGHT, sizeof(int));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        image[i] = rand() % 256;
    }

    // Flip image horizontally
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH / 2; j++) {
            int temp = image[i * WIDTH + j];
            image[i * WIDTH + j] = image[i * WIDTH + WIDTH - j - 1];
            image[i * WIDTH + WIDTH - j - 1] = temp;
        }
    }

    // Change brightness and contrast
    int brightness = rand() % 256;
    int contrast = rand() % 256;
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int value = image[i * WIDTH + j];
            value = (value * contrast) >> 8;
            value += brightness;
            value = value < 0? 0 : value > 255? 255 : value;
            image[i * WIDTH + j] = value;
        }
    }

    // Save image to file
    FILE *fp = fopen("image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        exit(1);
    }
    fwrite(image, sizeof(int), WIDTH * HEIGHT, fp);
    fclose(fp);

    printf("Image processing completed successfully.\n");

    return 0;
}