//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 512
#define HEIGHT 512
#define MAX 255

// Function to flip the image horizontally
void flipHorizontally(unsigned char* img) {
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < (WIDTH/2); x++) {
            unsigned char temp = img[y * WIDTH + x];
            img[y * WIDTH + x] = img[y * WIDTH + (WIDTH-1-x)];
            img[y * WIDTH + (WIDTH-1-x)] = temp;
        }
    }
}

// Function to adjust the brightness and contrast of the image
void adjustBrightnessContrast(unsigned char* img, int brightness, int contrast) {
    int x, y;
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int val = img[y * WIDTH + x];
            val = (int)((factor * (val - 128)) + 128 + brightness);
            img[y * WIDTH + x] = (unsigned char)fmin(fmax(val, 0), MAX);
        }
    }
}

int main() {
    unsigned char* img = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    FILE* file = fopen("image.raw", "rb");
    fread(img, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);

    flipHorizontally(img);
    adjustBrightnessContrast(img, 50, 100);

    file = fopen("output.raw", "wb");
    fwrite(img, sizeof(unsigned char), WIDTH * HEIGHT, file);
    fclose(file);

    free(img);
    return 0;
}