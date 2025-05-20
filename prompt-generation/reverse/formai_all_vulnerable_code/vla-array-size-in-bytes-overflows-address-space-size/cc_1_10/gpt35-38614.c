//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: romantic
#include <stdio.h>

// A function to convert RGB to grayscale
char grayscale(int r, int g, int b) {
    return (char) ((0.2126 * r) + (0.7152 * g) + (0.0722 * b));
}

// A function to convert an image to ASCII art
void imageToAscii(char *imageName) {
    int width, height;
    char asciiArray[500][500];
 
    // Open the image file
    FILE *imageFile = fopen(imageName, "rb");
 
    // Read the header to get width and height of the image
    char header[54];
    fread(header, sizeof(char), 54, imageFile);
    width = *(int *) &header[18];
    height = *(int *) &header[22];
 
    // Read the pixel data
    unsigned char pixelData[height][width][3];
    fread(pixelData, sizeof(char), height * width * 3, imageFile);
    fclose(imageFile);
 
    // Convert each pixel to ASCII character
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char asciiChar = grayscale(pixelData[i][j][0], pixelData[i][j][1], pixelData[i][j][2]);
            asciiArray[i][j] = asciiChar;
        }
    }
 
    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Choose appropriate ASCII character based on the grayscale value
            if (asciiArray[i][j] >= 220) {
                printf(" ");
            } else if (asciiArray[i][j] >= 192) {
                printf(".");
            } else if (asciiArray[i][j] >= 164) {
                printf(",");
            } else if (asciiArray[i][j] >= 136) {
                printf(":");
            } else if (asciiArray[i][j] >= 108) {
                printf(";");
            } else if (asciiArray[i][j] >= 80) {
                printf("o");
            } else if (asciiArray[i][j] >= 52) {
                printf("O");
            } else if (asciiArray[i][j] >= 24) {
                printf("0");
            } else {
                printf("@");
            }
        }
        printf("\n");
    }
}

// The main function
int main() {
    char imageName[] = "romantic_night.jpg";
    // Convert the image to ASCII art
    imageToAscii(imageName);
    return 0;
}