//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

char asciiChars[] = {'@', '#', '%', '.', '*', '+', '=', '-', ':', ' '}; // Characters to represent the varying shades of gray

// Function to convert the pixel value to ASCII character
char pixelToAscii(int pixelValue, int range, char* asciiChars) {
    int asciiVal = pixelValue / range;
    return asciiChars[asciiVal];
}

// Function to calculate the average brightness of an area of pixels
int getAreaBrightness(int* pixelArray, int width, int areaHeight, int areaWidth, int startX, int startY) {
    int totalBrightness = 0;
    for(int i=startY; i<startY+areaHeight; i++) {
        for(int j=startX; j<startX+areaWidth; j++) {
            int pixelIndex = i * width + j;
            totalBrightness += pixelArray[pixelIndex];
        }
    }
    return totalBrightness / (areaHeight * areaWidth);
}

// Function to covert an image to ASCII art
char* imageToAscii(int* pixelArray, int width, int height, int asciiWidth, int asciiHeight, char* asciiChars) {
    int areaWidth = width / asciiWidth; // Width of the area from which average brightness will be calculated
    int areaHeight = height / asciiHeight; // Height of the area from which average brightness will be calculated
    int numOfChars = asciiWidth * asciiHeight; // Total number of ASCII characters required
    int range = 255 / (sizeof(asciiChars) / sizeof(asciiChars[0]) - 1); // Range of values for each ASCII character
    char* asciiArray = (char*)malloc(numOfChars); // Allocate memory for the ASCII character array
    int pixelIndex = 0, charIndex = 0;
    for(int i=0; i<asciiHeight; i++) {
        for(int j=0; j<asciiWidth; j++) {
            int startX = j * areaWidth;
            int startY = i * areaHeight;
            int averageBrightness = getAreaBrightness(pixelArray, width, areaHeight, areaWidth, startX, startY);
            asciiArray[charIndex++] = pixelToAscii(averageBrightness, range, asciiChars);
        }
    }
    asciiArray[numOfChars] = '\0'; // Null terminate the ASCII character array
    return asciiArray;
}

int main() {
    FILE* imageFile = fopen("image.png", "rb"); // Open the image file
    if(!imageFile) {
        printf("Could not open image file!");
        return 1;
    }
    fseek(imageFile, 0, SEEK_END); // Move the file pointer to the end of the file
    long fileSize = ftell(imageFile); // Get the file size
    rewind(imageFile); // Move the file pointer back to the beginning of the file
    char* imageBuffer = (char*)malloc(fileSize); // Allocate memory for the image buffer
    fread(imageBuffer, 1, fileSize, imageFile); // Read the image file into the buffer
    fclose(imageFile); // Close the image file
    int width = 100, height = 100; // Set the width and height of the image
    int* pixelArray = (int*)malloc(width * height * sizeof(int)); // Allocate memory for the pixel array
    for(int i=0; i<width*height; i++) {
        pixelArray[i] = imageBuffer[i*4]; // Copy the blue value of each pixel to the pixel array
    }
    char* asciiArray = imageToAscii(pixelArray, width, height, 50, 50, asciiChars); // Convert the image to ASCII art
    printf("%s", asciiArray); // Print the ASCII art to the console
    free(imageBuffer); // Free the memory allocated for the image buffer
    free(pixelArray); // Free the memory allocated for the pixel array
    free(asciiArray); // Free the memory allocated for the ASCII array
    return 0;
}