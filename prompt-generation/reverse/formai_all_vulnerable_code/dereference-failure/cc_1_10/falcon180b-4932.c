//Falcon-180B DATASET v1.0 Category: Image Steganography ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 500
#define HEIGHT 500

// Function to read in the image file
void readImage(char *filename, char **imageData) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    *imageData = malloc(fileSize + 1);
    if (!*imageData) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(*imageData, fileSize, 1, file);
    fclose(file);
}

// Function to write out the modified image data
void writeImage(char *filename, char *imageData) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        exit(1);
    }

    fwrite(imageData, strlen(imageData), 1, file);
    fclose(file);
}

// Function to embed the message into the image data
void embedMessage(char *message, char *imageData) {
    int messageLength = strlen(message);
    int imageDataLength = strlen(imageData);
    int capacity = imageDataLength - messageLength;
    int i = 0;

    for (i = 0; i < messageLength; i++) {
        int index = rand() % capacity;
        imageData[index + i] = message[i];
    }
}

// Function to extract the message from the image data
char *extractMessage(char *imageData) {
    int messageLength = strlen(imageData);
    char *message = malloc(messageLength + 1);
    if (!message) {
        fprintf(stderr, "Error: could not allocate memory for message\n");
        exit(1);
    }

    int i = 0;
    while (i < messageLength) {
        if (imageData[i] == '\0') {
            break;
        }
        message[i] = imageData[i];
        i++;
    }

    message[i] = '\0';
    return message;
}

// Function to display the image
void displayImage(char *imageData) {
    int i = 0;
    while (i < WIDTH * HEIGHT) {
        printf("%c", imageData[i]);
        i++;
    }
}

int main() {
    char *imageData;
    readImage("image.png", &imageData);

    char *message = "This is a secret message";
    embedMessage(message, imageData);

    writeImage("stego_image.png", imageData);

    char *extractedMessage = extractMessage(imageData);
    printf("Extracted message: %s\n", extractedMessage);

    free(imageData);
    free(extractedMessage);

    return 0;
}