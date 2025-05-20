//FormAI DATASET v1.0 Category: Image Steganography ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_IMAGE_SIZE 1024*1024*3
#define BYTES_PER_PIXEL 3

unsigned char getImageByte(unsigned char *imageData, int width, int x, int y, int colorCode) {
    return imageData[(y*width*BYTES_PER_PIXEL)+(x*BYTES_PER_PIXEL)+colorCode];
}

void setImageByte(unsigned char *imageData, int width, int x, int y, int colorCode, unsigned char value) {
    imageData[(y*width*BYTES_PER_PIXEL)+(x*BYTES_PER_PIXEL)+colorCode] = value;
}

void hideMessageInImage(unsigned char *imageData, int width, int height, char *message) {
    int messageLength = strlen(message);
    int messageIndex = 0;
    int x = 0, y = 0, colorCode = 0;

    while (messageIndex < messageLength) {
        char currentChar = message[messageIndex];
        int bitIndex = 7;

        while (bitIndex >= 0 && messageIndex < messageLength) {
            unsigned char imageByte = getImageByte(imageData, width, x, y, colorCode);
            unsigned char bitValue = (currentChar >> bitIndex) & 0x01;
            unsigned char newValue = (imageByte & 0xFE) | bitValue;
            setImageByte(imageData, width, x, y, colorCode, newValue);

            bitIndex--;
            messageIndex++;

            if (colorCode < 2) {
                colorCode++;
            } else {
                colorCode = 0;
                x++;

                if (x >= width) {
                    x = 0;
                    y++;
                }
            }
        }
    }
}

void showMessageInImage(unsigned char *imageData, int width, int height, int messageLength) {
    int messageIndex = 0;
    int x = 0, y = 0, colorCode = 0;
    char resultString[MAX_IMAGE_SIZE];

    while (messageIndex < messageLength) {
        char currentChar = 0;

        for (int bitIndex = 7; bitIndex >= 0; bitIndex--) {
            unsigned char imageByte = getImageByte(imageData, width, x, y, colorCode);
            unsigned char bitValue = imageByte & 0x01;

            currentChar |= (bitValue << bitIndex);

            bitIndex--;
            messageIndex++;

            if (colorCode < 2) {
                colorCode++;
            } else {
                colorCode = 0;
                x++;

                if (x >= width) {
                    x = 0;
                    y++;
                }
            }
        }

        resultString[messageIndex] = currentChar;
    }

    printf("The hidden message is: %s\n", resultString);
}

int main() {
    FILE *imageFilePtr, *newImageFilePtr;
    unsigned char *imageData;
    int width, height, dataSize, messageLength;
    char message[MAX_IMAGE_SIZE];

    imageFilePtr = fopen("image.bmp", "rb");

    if (imageFilePtr == NULL) {
        printf("Error opening image file\n");
        return 1;
    }

    fseek(imageFilePtr, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, imageFilePtr);
    fread(&height, sizeof(int), 1, imageFilePtr);
    fseek(imageFilePtr, 0, SEEK_END);
    dataSize = ftell(imageFilePtr) - 54;

    rewind(imageFilePtr);
    imageData = malloc(sizeof(unsigned char) * dataSize);
    fread(imageData, sizeof(unsigned char), dataSize, imageFilePtr);
    fclose(imageFilePtr);

    printf("Enter your message to hide in the image:\n");
    fgets(message, MAX_IMAGE_SIZE, stdin);
    messageLength = strlen(message) - 1;

    hideMessageInImage(imageData, width, height, message);

    char newImageName[100];
    printf("Enter the new image file name:\n");
    scanf("%s", &newImageName);

    newImageFilePtr = fopen(newImageName, "wb");

    if (newImageFilePtr == NULL) {
        printf("Error creating new image file\n");
        return 1;
    }

    fwrite(imageData, sizeof(unsigned char), dataSize, newImageFilePtr);
    fclose(newImageFilePtr);

    printf("Message hidden successfully in %s\n", newImageName);

    printf("Do you want to extract the message from the image? (Y/N): ");
    char response;
    scanf(" %c", &response);

    if (response == 'Y' || response == 'y') {
        showMessageInImage(imageData, width, height, messageLength);
    }

    free(imageData);

    return 0;
}