//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IMAGE_SIZE 1000000

unsigned char *image;
int imageSize;
char *secretMessage;
int secretMessageLength;
int secretMessageIndex;

void encodeSecretMessage() {
    int i;
    for (i = 0; i < secretMessageLength; i++) {
        int currentByte = secretMessage[i];
        int currentBit = 0;
        while (currentBit < 8) {
            int bitToSet = (currentByte >> currentBit) & 1;
            int imagePixelIndex = imageSize * (secretMessageIndex % (int) sqrt(imageSize));
            image[imagePixelIndex] &= ~(1 << currentBit);
            image[imagePixelIndex] |= (bitToSet << currentBit);
            currentBit++;
            secretMessageIndex++;
        }
    }
}

void decodeSecretMessage() {
    int i, j, k;
    int secretMessageLength = 0;
    char secretMessage[MAX_IMAGE_SIZE];
    for (i = 0; i < imageSize; i++) {
        for (j = 0; j < 8; j++) {
            int bitToGet = (image[i] >> j) & 1;
            secretMessage[secretMessageLength++] = bitToGet;
        }
    }
    for (k = 0; k < secretMessageLength; k++) {
        int currentByte = 0;
        int currentBit = 0;
        while (currentBit < 8) {
            currentByte |= (secretMessage[k++] << currentBit);
            currentBit++;
        }
        putchar(currentByte);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s [image file] [secret message] [encode/decode]\n", argv[0]);
        return 1;
    }
    FILE *imageFile = fopen(argv[1], "rb");
    if (imageFile == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }
    fseek(imageFile, 0, SEEK_END);
    imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);
    image = malloc(imageSize);
    if (image == NULL) {
        printf("Error allocating memory for image.\n");
        return 1;
    }
    fread(image, 1, imageSize, imageFile);
    fclose(imageFile);
    secretMessage = argv[2];
    secretMessageLength = strlen(secretMessage);
    secretMessageIndex = 0;
    if (strcmp(argv[3], "encode") == 0) {
        encodeSecretMessage();
    } else if (strcmp(argv[3], "decode") == 0) {
        decodeSecretMessage();
    } else {
        printf("Invalid operation. Must be either \"encode\" or \"decode\".\n");
        return 1;
    }
    free(image);
    return 0;
}