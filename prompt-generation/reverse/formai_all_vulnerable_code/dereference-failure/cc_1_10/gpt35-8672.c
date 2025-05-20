//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Function to convert grayscale value to corresponding ASCII character
char grayscaleToASCII(int grayValue) {
    char ASCIIChars[] = {' ', '.', '-', ':', '=', '+', '*', '#', '%', '@'};
    int charCount = sizeof(ASCIIChars)/sizeof(char);
    int idx = (grayValue * (charCount-1))/255; //Mapping grayscale value to character index
    return ASCIIChars[idx];
}

int main() {
    int height, width;

    printf("Enter the height of the image: \n");
    scanf("%d", &height);
    printf("Enter the width of the image: \n");
    scanf("%d", &width);

    //Dynamically allocate memory for the image pixel values
    int** image = (int**) malloc(height * sizeof(int*));
    for(int i=0; i<height; i++) {
        image[i] = (int*) malloc(width * sizeof(int));
    }

    //Read pixel values of the image from input
    printf("Enter the pixel values of the image: \n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            scanf("%d", &image[i][j]);
        }
    }

    //Convert image into ASCII art
    char** asciiImage = (char**) malloc(height * sizeof(char*));
    for(int i=0; i<height; i++) {
        asciiImage[i] = (char*) malloc(width * sizeof(char));
        for(int j=0; j<width; j++) {
            asciiImage[i][j] = grayscaleToASCII(image[i][j]);
        }
    }

    //Print the ASCII art
    printf("ASCII Art:\n");
    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            printf("%c", asciiImage[i][j]);
        }
        printf("\n"); //Move to new line for next row of ASCII characters
    }

    //Free dynamically allocated memory
    for(int i=0; i<height; i++) {
        free(image[i]);
        free(asciiImage[i]);
    }
    free(image);
    free(asciiImage);

    return 0;
}