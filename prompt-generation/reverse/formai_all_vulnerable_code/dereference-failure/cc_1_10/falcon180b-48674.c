//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000000 // Maximum size of the image
#define MAX_PIXELS (MAX_SIZE * 3) // Maximum number of pixels in the image
#define HIDDEN_SIZE 100 // Size of the hidden message

// Function to convert a character to its ASCII value
int charToAscii(char c) {
    return (int)c;
}

// Function to convert an ASCII value to a character
char asciiToChar(int ascii) {
    return (char)ascii;
}

// Function to read the image file and store it in a 2D array
void readImage(char* filename, int** image) {
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int filesize = ftell(fp);
    rewind(fp);

    *image = (int*)malloc(MAX_PIXELS * sizeof(int));

    int count = 0;
    while (count < filesize) {
        int pixel = fgetc(fp);
        if (pixel == EOF) {
            break;
        }
        (*image)[count] = pixel;
        count++;
    }

    fclose(fp);
}

// Function to hide a message in the image
void hideMessage(int** image, char* message) {
    int messageSize = strlen(message);
    int hiddenSize = HIDDEN_SIZE;
    int i, j;

    for (i = 0; i < messageSize; i++) {
        message[i] = toupper(message[i]);
    }

    for (i = 0; i < hiddenSize; i++) {
        int index = rand() % MAX_PIXELS;
        (*image)[index] ^= message[i % messageSize];
    }
}

// Function to write the modified image to a file
void writeImage(char* filename, int** image) {
    FILE* fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        exit(1);
    }

    int count = 0;
    while (count < MAX_PIXELS) {
        fputc((*image)[count], fp);
        count++;
    }

    fclose(fp);
}

// Function to extract the hidden message from the image
char* extractMessage(int** image) {
    int messageSize = strlen("Hello, World!");
    char* message = (char*)malloc(messageSize + 1);

    int i, j;
    for (i = 0; i < messageSize; i++) {
        message[i] = '\0';
    }

    for (i = 0; i < messageSize; i++) {
        int index = rand() % MAX_PIXELS;
        message[i] = asciiToChar((*image)[index] ^ i);
    }

    return message;
}

int main() {
    int** image;
    readImage("image.bmp", &image);
    hideMessage(image, "Secret Message");
    writeImage("modified_image.bmp", image);

    char* extractedMessage = extractMessage(image);
    printf("Extracted message: %s\n", extractedMessage);

    free(extractedMessage);
    free(image[0]);
    free(image);

    return 0;
}