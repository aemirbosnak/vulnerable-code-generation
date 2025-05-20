//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to flip the image horizontally
void flipHorizontal(unsigned char *image, int width, int height) {
    unsigned char tempPixel, *start, *end;
    for (int y = 0; y < height; y++) {
        start = image + y * width * 3;
        end = start + (width - 1) * 3;
        for (int x = 0; x < width / 2; x++) {
            for (int i = 0; i < 3; i++) {
                tempPixel = *(start + i);
                *(start + i) = *(end - i);
                *(end - i) = tempPixel;
            }
            start += 3;
            end -= 3;
        }
    }
}

// Function to adjust the brightness and contrast of the image
void adjustBrightnessAndContrast(unsigned char *image, int width, int height, int brightness, float contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    if (brightness > 0) {
        for (int i = 0; i < width * height * 3; i++) {
            int pixelValue = *(image + i) + brightness;
            *(image + i) = pixelValue > 255 ? 255 : pixelValue;
        }
    } else if (brightness < 0) {
        for (int i = 0; i < width * height * 3; i++) {
            int pixelValue = *(image + i) + brightness;
            *(image + i) = pixelValue < 0 ? 0 : pixelValue;
        }
    }
    for (int i = 0; i < width * height * 3; i++) {
        float pixelValue = *(image + i);
        pixelValue = factor * (pixelValue - 128) + 128;
        *(image + i) = pixelValue > 255 ? 255 : (pixelValue < 0 ? 0 : pixelValue);
    }
}

int main() {
    int width = 512;
    int height = 512;
    unsigned char *image = (unsigned char *)malloc(width * height * 3 * sizeof(unsigned char));

    // Initialize example image
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            *(image + ((y * width + x) * 3 + 0)) = 255 * (x / (float)width); // red
            *(image + ((y * width + x) * 3 + 1)) = 255 * (y / (float)height); // green
            *(image + ((y * width + x) * 3 + 2)) = 255 * (1 - ((x / (float)width) + (y / (float)height)) / 2); // blue
        }
    }

    // Flip the image horizontally
    flipHorizontal(image, width, height);

    // Adjust the brightness and contrast of the image
    adjustBrightnessAndContrast(image, width, height, -100, 1.5);

    // Save the image to a file (PPM format)
    FILE *f = fopen("output.ppm", "wb");
    fprintf(f, "P6\n%d %d\n255\n", width, height);
    fwrite(image, sizeof(unsigned char), width * height * 3, f);
    fclose(f);

    free(image);
    return 0;
}