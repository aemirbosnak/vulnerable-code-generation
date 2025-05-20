//FormAI DATASET v1.0 Category: Image Steganography ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING 1000
#define MAX_SIZE 10000

// function to convert decimal to binary
int* decimalToBinary(int decimal) {
    static int binary[8];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    return binary;
}

// function to convert binary to decimal
int binaryToDecimal(int* binary) {
    int decimal = 0, base = 1;

    for (int i = 7; i >= 0; i--) {
        decimal = decimal + binary[i] * base;
        base = base * 2;
    }
    return decimal;
}

// function to get a random pixel position
int getRandomPixelPosition(int* usedPixels, int usedPixelsCount, int imageSize) {
    int randNum;
    while (1) {
        randNum = rand() % imageSize;
        int used = 0;
        for (int i = 0; i < usedPixelsCount; i++) {
            if (usedPixels[i] == randNum) {
                used = 1;
                break;
            }
        }
        if (!used) {
            usedPixels[usedPixelsCount] = randNum;
            return randNum;
        }
    }
}

int main() {
    srand(time(NULL));

    char inputText[MAX_STRING];
    printf("Enter the text you want to hide in the image: ");
    fgets(inputText, MAX_STRING, stdin);

    // read the image file
    FILE* imageFile;
    unsigned char imageData[MAX_SIZE];
    int imageSize;
    imageFile = fopen("image.jpg", "rb");
    if (imageFile == NULL) {
        printf("Failed to open image file.");
        return 1;
    }
    imageSize = fread(imageData, 1, MAX_SIZE, imageFile);
    fclose(imageFile);

    // convert input text to binary
    int inputTextLength = strlen(inputText);
    int* inputTextBinary = (int*)malloc(inputTextLength * 8 * sizeof(int));
    int inputTextBinaryIndex = 0;
    for (int i = 0; i < inputTextLength; i++) {
        int* binary = decimalToBinary(inputText[i]);
        for (int j = 7; j >= 0; j--) {
            inputTextBinary[inputTextBinaryIndex] = binary[j];
            inputTextBinaryIndex++;
        }
    }

    // randomly choose pixels to hide the text bits
    int usedPixels[MAX_SIZE] = { 0 };
    int usedPixelsCount = 0;

    for (int i = 0; i < inputTextBinaryIndex; i++) {
        int randomPixelPosition = getRandomPixelPosition(usedPixels, usedPixelsCount, imageSize);
        usedPixelsCount++;

        // convert pixel value to binary
        int pixelValueBinary[8];
        int pixelValue = imageData[randomPixelPosition];
        for (int j = 0; j < 8; j++) {
            pixelValueBinary[j] = pixelValue % 2;
            pixelValue = pixelValue / 2;
        }

        // hide the text bit in the pixel
        pixelValueBinary[7] = inputTextBinary[i];

        // convert binary back to decimal and save in image data
        imageData[randomPixelPosition] = binaryToDecimal(pixelValueBinary);
    }

    // write the new image data to file
    FILE* outputFile = fopen("output.jpg", "wb");
    fwrite(imageData, 1, imageSize, outputFile);
    fclose(outputFile);

    printf("Text hidden successfully!\n");
    return 0;
}