//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

// function to flip an image
void flipImage(char *inputFile, char *outputFile, int width, int height) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    unsigned char *row = (unsigned char*)malloc(sizeof(char) * width * 3);

    for(int i = 0; i < height; i++) {
        fseek(input, width*3*(height - i - 1), SEEK_SET);
        fread(row, sizeof(char), width*3, input);
        fwrite(row, sizeof(char), width*3, output);
    }

    free(row);
    fclose(input);
    fclose(output);
}

// function to adjust brightness of an image
void adjustBrightness(char *inputFile, char *outputFile, int width, int height, int brightness) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    unsigned char *row = (unsigned char*)malloc(sizeof(char) * width * 3);

    for(int i = 0; i < height; i++) {
        fread(row, sizeof(char), width*3, input);
        for(int j = 0; j < width*3; j++) {
            int value = row[j] + brightness;
            if(value < 0) value = 0;
            if(value > 255) value = 255;
            row[j] = (unsigned char)value;
        }
        fwrite(row, sizeof(char), width*3, output);
    }

    free(row);
    fclose(input);
    fclose(output);
}

// function to adjust contrast of an image
void adjustContrast(char *inputFile, char *outputFile, int width, int height, float contrast) {
    FILE *input = fopen(inputFile, "rb");
    FILE *output = fopen(outputFile, "wb");
    unsigned char *row = (unsigned char*)malloc(sizeof(char) * width * 3);

    for(int i = 0; i < height; i++) {
        fread(row, sizeof(char), width*3, input);
        for(int j = 0; j < width*3; j++) {
            float value = (float)row[j] / 255.0;
            value -= 0.5;
            value *= contrast;
            value += 0.5;
            value *= 255.0;
            if(value < 0) value = 0;
            if(value > 255) value = 255;
            row[j] = (unsigned char)value;
        }
        fwrite(row, sizeof(char), width*3, output);
    }

    free(row);
    fclose(input);
    fclose(output);
}

int main() {
    char inputFile[] = "image.bmp"; // input image file name
    char outputFile[] = "output.bmp"; // output image file name
    int width = 640; // width of the image
    int height = 480; // height of the image

    // flip the image
    flipImage(inputFile, "flip.bmp", width, height);

    // adjust brightness of the image
    adjustBrightness(inputFile, "brightness.bmp", width, height, 50);

    // adjust contrast of the image
    adjustContrast(inputFile, "contrast.bmp", width, height, 1.5);

    return 0;
}