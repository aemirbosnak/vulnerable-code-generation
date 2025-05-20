//FormAI DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_FILE_SIZE 10000

void hideMessageInImage(char *filename, char *message) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    // read header of image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // calculate size of image
    int imageSize = width * height * 3; // 3 bytes per pixel
    unsigned char *imageData = (unsigned char*)malloc(imageSize);

    if (imageData == NULL) {
        printf("Error allocating memory!\n");
        return;
    }

    fread(imageData, sizeof(unsigned char), imageSize, fp);
    fclose(fp);

    // prepare message for encoding
    int messageLength = strlen(message);
    unsigned char *messageData = (unsigned char*)malloc(messageLength + 1);
    strcpy((char*)messageData, message);

    // encode message into image
    int i, j, k;
    int index = 0;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // skip first 54 bytes (header)
            if (i == 0 && j < 54 / 3) continue;

            // calculate index of current pixel in image data array
            int pixelIndex = (i * width + j) * 3;

            // modify least significant bit of each pixel's RGB values to encode message
            if (index < messageLength) {
                for (k = 0; k < 3; k++) {
                    if ((messageData[index] >> k) & 0x01) {
                        imageData[pixelIndex + k] |= 0x01; // set LSB to 1
                    } else {
                        imageData[pixelIndex + k] &= 0xFE; // set LSB to 0
                    }
                }
                index++;
            } else {
                break;
            }
        }
        if (index >= messageLength) break; // message encoding complete
    }

    // save image with encoded message
    fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fwrite(header, sizeof(unsigned char), 54, fp);
    fwrite(imageData, sizeof(unsigned char), imageSize, fp);
    fclose(fp);

    printf("Message hidden in image successfully.\n");

    free(imageData);
    free(messageData);
}

char* extractMessageFromImage(char *filename) {
    FILE *fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("Error opening file!\n");
        return "";
    }

    // read header of image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, fp);

    // get image dimensions
    int width = *(int*)&header[18];
    int height = *(int*)&header[22];

    // calculate size of image
    int imageSize = width * height * 3; // 3 bytes per pixel
    unsigned char *imageData = (unsigned char*)malloc(imageSize);

    if (imageData == NULL) {
        printf("Error allocating memory!\n");
        return "";
    }

    fread(imageData, sizeof(unsigned char), imageSize, fp);
    fclose(fp);

    // extract message from image
    char *message = (char*)malloc(MAX_FILE_SIZE);
    int i, j, k;
    int index = 0;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // skip first 54 bytes (header)
            if (i == 0 && j < 54 / 3) continue;

            // calculate index of current pixel in image data array
            int pixelIndex = (i * width + j) * 3;

            // extract LSB from each pixel's RGB values to decode message
            for (k = 0; k < 3; k++) {
                message[index] |= (imageData[pixelIndex + k] & 0x01) << k;
            }

            index++;

            if (index == MAX_FILE_SIZE) break;
        }
        if (index == MAX_FILE_SIZE) break;
    }

    printf("Message extracted from image: %s\n", message);

    free(imageData);

    return message;
}

int main() {
    char filename[MAX_FILENAME_LENGTH];
    char message[MAX_FILE_SIZE];
    char *extractedMessage;

    printf("Enter name of image file (including extension): ");
    scanf("%s", filename);

    printf("Enter message to hide in image: ");
    scanf("%s", message);

    hideMessageInImage(filename, message);

    extractedMessage = extractMessageFromImage(filename);

    printf("Extracted message: %s\n", extractedMessage);

    free(extractedMessage);

    return 0;
}