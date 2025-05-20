//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_PIXEL_VALUE 255
#define ASCII_CHARS "@#&$%*o!;:,. "

char* convertPixelToAscii(int pixelValue){
    int numChars = strlen(ASCII_CHARS);
    int stepSize = ceil(MAX_PIXEL_VALUE/(numChars-1));
    int asciiIndex = pixelValue/stepSize;
    char* asciiChar = (char*) malloc(sizeof(char));
    asciiChar[0] = ASCII_CHARS[asciiIndex];
    return asciiChar;
}

void convertImageToAscii(char* imagePath, int width, int height){
    FILE* filePtr;
    unsigned char* imageData;
    unsigned char* grayImageData;
    char* asciiImageData;
    filePtr = fopen(imagePath,"rb");

    if(filePtr==NULL){
        printf("File not found!\n");
        exit(-1);
    }

    imageData = (unsigned char*) malloc(width*height*3);
    grayImageData = (unsigned char*) malloc(width*height);
    asciiImageData = (char*) malloc(width*height*sizeof(char));

    fread(imageData, sizeof(unsigned char), width*height*3, filePtr);

    for(int i=0; i<width*height; i++){
        unsigned char redValue = imageData[i*3];
        unsigned char greenValue = imageData[i*3+1];
        unsigned char blueValue = imageData[i*3+2];
        grayImageData[i] = 0.21*redValue + 0.72*greenValue + 0.07*blueValue;
    }

    for(int i=0; i<width*height; i++){
        asciiImageData[i] = convertPixelToAscii(grayImageData[i])[0];
    }

    int charIndex = 0;
    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            printf("%c ",asciiImageData[charIndex++]);
        }
        printf("\n");
    }

    fclose(filePtr);
    free(imageData);
    free(grayImageData);
    free(asciiImageData);
}

int main(){
    char* imagePath = "test.jpg";
    int width = 50, height = 50;
    convertImageToAscii(imagePath, width, height);
    return 0;
}