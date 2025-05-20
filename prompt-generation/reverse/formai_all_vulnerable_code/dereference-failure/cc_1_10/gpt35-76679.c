//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function prototypes
int readImage(char *fileName, unsigned char *imageData, int imageSize);
void convertToASCII(unsigned char *imageData, int imageSize, int width, int height);
char getASCIIChar(int pixelValue);

int main(int argc, char *argv[]) {
    // check if the correct number of arguments have been passed
    if(argc != 2) {
        printf("Usage: %s [path to image]\n", argv[0]);
        return 0;
    }

    // read the image data
    unsigned char *imageData;
    int imageSize = readImage(argv[1], imageData, 0);
    if(imageSize == 0) {
        printf("Error reading the image\n");
        return 0;
    }

    // get the width and height of the image
    int width = sqrt(imageSize);
    int height = sqrt(imageSize);

    // call the function to convert the image to ASCII art
    convertToASCII(imageData, imageSize, width, height);

    // free the dynamically allocated memory
    free(imageData);

    return 0;
}

// function to read the image data from file
int readImage(char *fileName, unsigned char *imageData, int imageSize) {
    FILE *fp = fopen(fileName, "rb");

    if(fp == NULL) {
        return 0;
    }

    // add the size of the file to the imageSize variable
    fseek(fp, 0L, SEEK_END);
    imageSize += ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    // dynamically allocate memory for the image data
    imageData = (unsigned char*)malloc(sizeof(unsigned char) * imageSize);

    // read the image data from file
    fread(imageData, sizeof(unsigned char), imageSize, fp);

    // close the file pointer
    fclose(fp);

    return imageSize;
}

// function to convert the image to ASCII art
void convertToASCII(unsigned char *imageData, int imageSize, int width, int height) {
    // loop through the image data and get the average pixel value of each 3x3 area
    for(int i = 0; i < height; i += 3) {
        for(int j = 0; j < width; j += 3) {
            int sum = 0;
            for(int k = i; k < i + 3; k++) {
                for(int l = j; l < j + 3; l++) {
                    sum += imageData[k * width + l];
                }
            }
            int avg = sum / 9;

            // get the corresponding ASCII character for the pixel value
            char asciiChar = getASCIIChar(avg);

            // print the character to the console
            printf("%c", asciiChar);
        }
        printf("\n");
    }
}

// helper function to map pixel values to ASCII characters
char getASCIIChar(int pixelValue) {
    char asciiChar;
    if(pixelValue >= 0 && pixelValue <= 25) {
        asciiChar = '@';
    }
    else if(pixelValue >= 26 && pixelValue <= 50) {
        asciiChar = '#';
    }
    else if(pixelValue >= 51 && pixelValue <= 75) {
        asciiChar = '&';
    }
    else if(pixelValue >= 76 && pixelValue <= 100) {
        asciiChar = '$';
    }
    else if(pixelValue >= 101 && pixelValue <= 125) {
        asciiChar = '%';
    }
    else if(pixelValue >= 126 && pixelValue <= 150) {
        asciiChar = '*';
    }
    else if(pixelValue >= 151 && pixelValue <= 175) {
        asciiChar = '+';
    }
    else if(pixelValue >= 176 && pixelValue <= 200) {
        asciiChar = '-';
    }
    else if(pixelValue >= 201 && pixelValue <= 225) {
        asciiChar = ';';
    }
    else if(pixelValue >= 226 && pixelValue <= 255) {
        asciiChar = '.';
    }

    return asciiChar;
}