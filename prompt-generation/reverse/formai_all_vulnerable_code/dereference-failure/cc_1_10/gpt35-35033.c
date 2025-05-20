//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WIDTH 512
#define HEIGHT 512

void flipImage(unsigned char* image, int width, int height)
{
    unsigned char* temp = (unsigned char*)malloc(width * 3);
    int rowSize = width * 3;
    int num = height / 2;
    int index1 = 0;
    int index2 = 0;
    for (int i = 0; i < num; i++) {
        index1 = i * rowSize;
        index2 = (height - i - 1) * rowSize;
        memcpy(temp, image + index1, rowSize);
        memcpy(image + index1, image + index2, rowSize);
        memcpy(image + index2, temp, rowSize);
    }
    free(temp);
}

void adjustBrightness(unsigned char* image, int width, int height, int brightness)
{
    int pixelCount = width * height * 3;
    int pixelValue;
    for (int i = 0; i < pixelCount; i++) {
        pixelValue = image[i] + brightness;
        image[i] = (pixelValue > 255) ? 255 : (pixelValue < 0) ? 0 : pixelValue;
    }
}

void adjustContrast(unsigned char* image, int width, int height, int contrast)
{
    float factor = (259.0f * (contrast + 255.0f)) / (255.0f * (259.0f - contrast));
    int pixelCount = width * height * 3;
    int pixelValue;
    for (int i = 0; i < pixelCount; i++) {
        pixelValue = (int)(factor * (image[i] - 128) + 128);
        image[i] = (pixelValue > 255) ? 255 : (pixelValue < 0) ? 0 : pixelValue;
    }
}

int main()
{
    unsigned char image[WIDTH * HEIGHT * 3];   
    FILE* inputfile = fopen("input.raw", "rb");
    if (!inputfile) {
        printf("Error: Couldn't open input file");
        return 1;
    }
    fread(image, 1, WIDTH * HEIGHT * 3, inputfile);
    fclose(inputfile);
    
    flipImage(image, WIDTH, HEIGHT);
    
    adjustBrightness(image, WIDTH, HEIGHT, -50);
    
    adjustContrast(image, WIDTH, HEIGHT, 50);
    
    FILE* outputfile = fopen("output.raw", "wb");
    if (!outputfile) {
        printf("Error: Couldn't open output file");
        return 1;
    }
    fwrite(image, 1, WIDTH * HEIGHT * 3, outputfile);
    fclose(outputfile);
    
    return 0;
}