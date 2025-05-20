//FormAI DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>

#define MAX_PIXELS 100000
#define MAX_MESSAGE 10000

/* Function to hide message into LSB of each pixel */
void hideMessage(int pixels[], char message[], int messageLength) {
    int pixelIndex = 0;
    int bitIndex = 0;
    int bitMask = 1;

    for (int i = 0; i < messageLength; i++) {
        char messageChar = message[i];
        for (int j = 0; j < 8; j++) {
            int currentPixel = pixels[pixelIndex];
            int currentBit = (messageChar & (bitMask << j)) >> j;
            int newPixel = (currentPixel & 0xFE) | currentBit;
            pixels[pixelIndex] = newPixel;
            pixelIndex++;
            if (pixelIndex >= MAX_PIXELS) {
                printf("Image file is too small to hide entire message.");
                exit(1);
            }
        }
    }

    /* Add null-termination character at the end of message */
    for (int j = 0; j < 8; j++) {
        int currentPixel = pixels[pixelIndex];
        int newPixel = (currentPixel & 0xFE) | ((j == 7) ? 1 : 0);
        pixels[pixelIndex] = newPixel;
        pixelIndex++;
        if (pixelIndex >= MAX_PIXELS) {
            printf("Image file is too small to hide entire message.");
            exit(1);
        }
    }
}

/* Function to retrieve message from LSB of each pixel */
char* retrieveMessage(int pixels[]) {
    char* message = (char*)malloc(MAX_MESSAGE*sizeof(char));
    int pixelIndex = 0;
    int messageIndex = 0;
    char currentChar = 0;
    int bitMask = 1;

    while (1) {
        int currentPixel = pixels[pixelIndex];
        int currentBit = currentPixel & 0x01;
        currentChar |= (currentBit << bitMask);
        bitMask++;
        if (bitMask >= 8) {
            if (currentChar == '\0') {
                message[messageIndex] = '\0';
                break;
            } else {
                message[messageIndex] = currentChar;
                messageIndex++;
                currentChar = 0;
                bitMask = 1;
            }
        }
        pixelIndex++;
        if (pixelIndex >= MAX_PIXELS) {
            message[messageIndex] = '\0';
            break;
        }
    }
    return message;
}

/* Main function for Image Steganography */
int main() {
    /* Read image as array of pixels (assume grayscale)*/
    int pixels[MAX_PIXELS];
    int numPixels = 0;
    FILE *imageFile = fopen("image.pgm", "r");
    char fileType[3];
    fscanf(imageFile, "%s", fileType);
    if (fileType[0] != 'P' || fileType[1] != '5') {
        printf("Image file is not in PGM format.");
        exit(1);
    }
    int width, height, maxVal;
    fscanf(imageFile, "%d %d %d\n", &width, &height, &maxVal);
    int pixel;
    while (fscanf(imageFile, "%d", &pixel) == 1) {
        pixels[numPixels] = pixel;
        numPixels++;
        if (numPixels >= MAX_PIXELS) {
            printf("Image file is too large.");
            exit(1);
        }
    }
    fclose(imageFile);

    /* Get message to hide */
    char message[MAX_MESSAGE];
    printf("Enter the message to hide: ");
    fgets(message, MAX_MESSAGE, stdin);

    /* Hide message */
    hideMessage(pixels, message, strlen(message));

    /* Save image with hidden message */
    FILE *outputImage = fopen("output.pgm", "w");
    fprintf(outputImage, "P5\n%d %d\n%d\n", width, height, maxVal);
    for (int i = 0; i < numPixels; i++) {
        fprintf(outputImage, "%d ", pixels[i]);
    }
    fclose(outputImage);

    /* Retrieve message from output image */
    int outputPixels[MAX_PIXELS];
    FILE *outputImageFile = fopen("output.pgm", "r");
    char outputFileType[3];
    fscanf(outputImageFile, "%s", outputFileType);
    if (outputFileType[0] != 'P' || outputFileType[1] != '5') {
        printf("Output image file is not in PGM format.");
        exit(1);
    }
    int outputWidth, outputHeight, outputMaxVal;
    fscanf(outputImageFile, "%d %d %d\n", &outputWidth, &outputHeight, &outputMaxVal);
    int outputPixel;
    for (int i = 0; i < numPixels; i++) {
        fscanf(outputImageFile, "%d", &outputPixel);
        outputPixels[i] = outputPixel;
    }
    fclose(outputImageFile);
    char* retrievedMessage = retrieveMessage(outputPixels);
    printf("Retrieved message: %s", retrievedMessage);
    free(retrievedMessage);

    return 0;
}