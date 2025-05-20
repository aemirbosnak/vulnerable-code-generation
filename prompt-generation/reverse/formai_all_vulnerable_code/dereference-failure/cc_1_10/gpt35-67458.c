//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define WIDTH 256
#define HEIGHT 256

// Flips the image by reversing the pixel order
void flipImage(unsigned char* im) {
    unsigned char temp;

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH / 2; ++x) {
            temp = im[y * WIDTH + x];
            im[y * WIDTH + x] = im[y * WIDTH + WIDTH - 1 - x];
            im[y * WIDTH + WIDTH - 1 - x] = temp;
        }
    }
}

// Changes the brightness of the image
void adjustBrightness(unsigned char* im, int delta) {
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        int pix = (int) im[i] + delta;
        im[i] = (pix > 255) ? 255 : (pix < 0) ? 0 : (unsigned char) pix;
    }
}

// Changes the contrast of the image
void adjustContrast(unsigned char* im, float delta) {
    float factor = (259.0 * (delta + 255.0)) / (255.0 * (259.0 - delta));
    for (int i = 0; i < WIDTH * HEIGHT; ++i) {
        int pix = (int) (factor * ((int) im[i] - 128) + 128);
        im[i] = (pix > 255) ? 255 : (pix < 0) ? 0 : (unsigned char) pix;
    }
}

// Entry point of the program
int main() {
    // Load the image into memory
    unsigned char* im = (unsigned char*) malloc(WIDTH * HEIGHT * sizeof(unsigned char));
    FILE* fp = fopen("image.raw", "rb");
    fread(im, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Flip the image and save it
    flipImage(im);
    fp = fopen("flipped.raw", "wb+");
    fwrite(im, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Reset the image and adjust its brightness
    fp = fopen("image.raw", "rb");
    fread(im, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
    adjustBrightness(im, 50);
    fp = fopen("brightness.raw", "wb+");
    fwrite(im, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Reset the image and adjust its contrast
    fp = fopen("image.raw", "rb");
    fread(im, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);
    adjustContrast(im, 30.0);
    fp = fopen("contrast.raw", "wb+");
    fwrite(im, sizeof(unsigned char), WIDTH * HEIGHT, fp);
    fclose(fp);

    // Clean up memory
    free(im);
    return 0;
}