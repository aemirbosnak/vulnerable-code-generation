//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to flip an image horizontally
void FlipHorizontal(unsigned char* imgData, int width, int height) {
    int lineSize = width * 3;
    unsigned char* tmpLine = (unsigned char*) malloc(lineSize);
    int halfHeight = height / 2;
    for (int y = 0; y < halfHeight; y++) {
        int lineIndex1 = y * lineSize;
        int lineIndex2 = (height - y - 1) * lineSize;
        memcpy(tmpLine, &imgData[lineIndex1], lineSize);
        memcpy(&imgData[lineIndex1], &imgData[lineIndex2], lineSize);
        memcpy(&imgData[lineIndex2], tmpLine, lineSize);
    }
    free(tmpLine);
}

// Function to adjust brightness and contrast of an image
void BrightnessContrast(unsigned char* imgData, int width, int height, int brightness, int contrast) {
    float factor = (float) (259 * (contrast + 255)) / (float) (255 * (259 - contrast));
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int index = (y * width + x) * 3;
            int b = imgData[index];
            int g = imgData[index + 1];
            int r = imgData[index + 2];
            // Adjust brightness
            b += brightness;
            g += brightness;
            r += brightness;
            // Adjust contrast
            b = factor * (b - 128) + 128;
            g = factor * (g - 128) + 128;
            r = factor * (r - 128) + 128;
            // Clamp values between 0-255
            b = (b < 0) ? 0 : ((b > 255) ? 255 : b);
            g = (g < 0) ? 0 : ((g > 255) ? 255 : g);
            r = (r < 0) ? 0 : ((r > 255) ? 255 : r);
            // Save modified pixel values
            imgData[index] = (unsigned char) b;
            imgData[index + 1] = (unsigned char) g;
            imgData[index + 2] = (unsigned char) r;
        }
    }
}

int main() {
    // Load image data from file
    FILE* file = fopen("image.raw", "rb");
    int width = 640;
    int height = 480;
    int bufferSize = width * height * 3;
    unsigned char* imgData = (unsigned char*) malloc(bufferSize);
    fread(imgData, 1, bufferSize, file);
    fclose(file);
	
    // Flip image horizontally
    FlipHorizontal(imgData, width, height);

    // Adjust brightness and contrast
    int brightness = 50;
    int contrast = 20;
    BrightnessContrast(imgData, width, height, brightness, contrast);

    // Save modified image data to file
    file = fopen("output.raw", "wb");
    fwrite(imgData, 1, bufferSize, file);
    fclose(file);

    // Free image data buffer
    free(imgData);

    return 0;
}