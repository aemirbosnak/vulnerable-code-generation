//FormAI DATASET v1.0 Category: Image Steganography ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// function to check if the given bit is set or not
bool checkBit(unsigned char byte, int pos) {
    return (byte >> pos) & 1;
}

// function to set the given bit to 1
void setBit(unsigned char *byte, int pos) {
    *byte = *byte | (1 << pos);
}

// function to calculate the maximum message length that can be embedded in the image
int getMaxMessageLength(int imageWidth, int imageHeight) {
    // since each pixel has 3 bytes (RGB), we can only use one byte for message (8 bits)
    // so we can embed (imageWidth * imageHeight * 3) / 8 bytes of message
    return (imageWidth * imageHeight * 3) / 8;
}

// function to embed a message in the given image
void embedMessage(unsigned char *imageData, int imageWidth, int imageHeight, unsigned char *message, int messageLength) {
    int maxMessageLength = getMaxMessageLength(imageWidth, imageHeight);

    if (messageLength > maxMessageLength) {
        printf("Error: Message is too long to embed in the given image.\n");
        exit(EXIT_FAILURE);
    }

    // initialize variables
    int imageDataIndex = 0;
    int bitIndex = 0;

    // loop through each message byte and embed it
    for (int i = 0; i < messageLength; i++) {
        unsigned char messageByte = message[i];

        // loop through each bit of the message byte
        for (int j = 0; j < 8; j++) {
            // get the current pixel
            unsigned char red = imageData[imageDataIndex];
            unsigned char green = imageData[imageDataIndex + 1];
            unsigned char blue = imageData[imageDataIndex + 2];

            // embed the bit in the red pixel
            if (checkBit(messageByte, bitIndex)) {
                setBit(&red, 0);
            } else {
                setBit(&red, 0);
                setBit(&red, 1);
            }

            // update the imageData array
            imageData[imageDataIndex] = red;
            imageData[imageDataIndex + 1] = green;
            imageData[imageDataIndex + 2] = blue;

            // increment indices
            imageDataIndex += 3; // move to the next pixel
            bitIndex++; // move to the next bit

            if (bitIndex == 8) {
                bitIndex = 0; // start from the first bit of the next message byte
            }
        }
    }
}

// function to extract the message from the given image
unsigned char *extractMessage(unsigned char *imageData, int imageWidth, int imageHeight, int messageLength) {
    int maxMessageLength = getMaxMessageLength(imageWidth, imageHeight);

    if (messageLength > maxMessageLength) {
        printf("Error: Message is too long to be extracted from the given image.\n");
        exit(EXIT_FAILURE);
    }

    // initialize variables
    int imageDataIndex = 0;
    int bitIndex = 0;
    unsigned char *message = malloc(messageLength);

    // loop through each message byte and extract it
    for (int i = 0; i < messageLength; i++) {
        unsigned char messageByte = 0;

        // loop through each bit of the message byte
        for (int j = 0; j < 8; j++) {
            // get the current pixel
            unsigned char red = imageData[imageDataIndex];
            unsigned char green = imageData[imageDataIndex + 1];
            unsigned char blue = imageData[imageDataIndex + 2];

            // extract the bit from the red pixel
            if (checkBit(red, 0)) {
                messageByte = messageByte | (1 << bitIndex);
            }

            // increment indices
            imageDataIndex += 3; // move to the next pixel
            bitIndex++; // move to the next bit

            if (bitIndex == 8) {
                bitIndex = 0; // start from the first bit of the next message byte
            }
        }

        message[i] = messageByte;
    }

    return message;
}

int main() {
    // read the image file
    FILE *imageFile = fopen("image.bmp", "rb");

    if (!imageFile) {
        printf("Error: Cannot read image file.\n");
        exit(EXIT_FAILURE);
    }

    // read the image header
    unsigned char header[54];

    if (fread(header, sizeof(unsigned char), 54, imageFile) != 54) {
        printf("Error: Invalid image file.\n");
        exit(EXIT_FAILURE);
    }

    // check if the image format is BMP
    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: Invalid image file format.\n");
        exit(EXIT_FAILURE);
    }

    // read the image properties
    int imageWidth = *(int *)&header[18];
    int imageHeight = *(int *)&header[22];
    int imageSize = *(int *)&header[34];

    // allocate memory for the image data
    unsigned char *imageData = malloc(imageSize * sizeof(unsigned char));

    // read the image data
    fread(imageData, sizeof(unsigned char), imageSize, imageFile);

    // close the image file
    fclose(imageFile);

    // embed the message in the image
    unsigned char *message = "This is a secret message.";
    int messageLength = sizeof(message) / sizeof(unsigned char);
    embedMessage(imageData, imageWidth, imageHeight, message, messageLength);

    // write the modified image data to a new file
    FILE *modifiedImageFile = fopen("modified_image.bmp", "wb");

    if (!modifiedImageFile) {
        printf("Error: Cannot write image file.\n");
        exit(EXIT_FAILURE);
    }

    // write the header
    fwrite(header, sizeof(unsigned char), 54, modifiedImageFile);

    // write the modified image data
    fwrite(imageData, sizeof(unsigned char), imageSize, modifiedImageFile);

    // close the modified image file
    fclose(modifiedImageFile);

    // extract the message from the modified image
    unsigned char *extractedMessage = extractMessage(imageData, imageWidth, imageHeight, messageLength);

    // print the extracted message
    printf("Extracted Message: ");
    for (int i = 0; i < messageLength; i++) {
        printf("%c", extractedMessage[i]);
    }
    printf("\n");

    // free memory
    free(imageData);
    free(extractedMessage);

    return 0;
}