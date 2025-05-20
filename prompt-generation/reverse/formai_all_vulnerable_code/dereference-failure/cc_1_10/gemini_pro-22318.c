//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 1024

void hideMessage(char *imageFile, char *message) {
    FILE *image, *messageFile;
    int imageSize, messageSize;
    char *imageBuffer, *messageBuffer;

    // Open the image
    image = fopen(imageFile, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the file size
    fseek(image, 0, SEEK_END);
    imageSize = ftell(image);
    fseek(image, 0, SEEK_SET);

    // Read the image into a buffer
    imageBuffer = malloc(imageSize);
    fread(imageBuffer, imageSize, 1, image);

    // Open the message
    messageFile = fopen(message, "rb");
    if (messageFile == NULL) {
        perror("Error opening message file");
        exit(1);
    }

    // Get the file size
    fseek(messageFile, 0, SEEK_END);
    messageSize = ftell(messageFile);
    fseek(messageFile, 0, SEEK_SET);

    // Read the message into a buffer
    messageBuffer = malloc(messageSize);
    fread(messageBuffer, messageSize, 1, messageFile);

    // Check if the message is too large
    if (messageSize > imageSize) {
        printf("Message is too large for image\n");
        exit(1);
    }

    // Hide the message in the image
    for (int i = 0; i < messageSize; i++) {
        imageBuffer[i] = imageBuffer[i] & 0b11111100 | messageBuffer[i] & 0b00000011;
    }

    // Write the modified image back to the file
    fseek(image, 0, SEEK_SET);
    fwrite(imageBuffer, imageSize, 1, image);
    fclose(image);

    // Close the message file
    fclose(messageFile);

    printf("Message hidden successfully\n");
}

void revealMessage(char *imageFile) {
    FILE *image;
    int imageSize;
    char *imageBuffer;
    char messageBuffer[MAX_MESSAGE_SIZE];

    // Open the image
    image = fopen(imageFile, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        exit(1);
    }

    // Get the file size
    fseek(image, 0, SEEK_END);
    imageSize = ftell(image);
    fseek(image, 0, SEEK_SET);

    // Read the image into a buffer
    imageBuffer = malloc(imageSize);
    fread(imageBuffer, imageSize, 1, image);

    // Read the message from the image
    for (int i = 0; i < imageSize; i++) {
        messageBuffer[i] = imageBuffer[i] & 0b00000011;
    }

    // Print the message
    printf("%s\n", messageBuffer);

    // Close the image file
    fclose(image);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [imagefile] [messagefile]\n", argv[0]);
        return 1;
    }

    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
        printf("Usage: %s [imagefile] [messagefile]\n", argv[0]);
        printf("\nHide a message in an image using steganography.\n");
        return 0;
    }

    if (strcmp(argv[1], "-e") == 0 || strcmp(argv[1], "--encode") == 0) {
        if (argc < 4) {
            printf("Usage: %s -e [imagefile] [messagefile]\n", argv[0]);
            return 1;
        }
        hideMessage(argv[2], argv[3]);
    } else if (strcmp(argv[1], "-d") == 0 || strcmp(argv[1], "--decode") == 0) {
        if (argc < 3) {
            printf("Usage: %s -d [imagefile]\n", argv[0]);
            return 1;
        }
        revealMessage(argv[2]);
    } else {
        printf("Unknown command: %s\n", argv[1]);
        return 1;
    }

    return 0;
}