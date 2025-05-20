//FormAI DATASET v1.0 Category: Image Steganography ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMPHEADER 54
#define MAXSIZE 1000000

// function to get bit at a specific position
int getBit(unsigned char* byte, int position) {
    return ((*byte) >> position) & 1;
}

// function to set the bit at a specific position to 1
void setBit1(unsigned char* byte, int position) {
    (*byte) |= (1 << position);
}

// function to set the bit at a specific position to 0
void setBit0(unsigned char* byte, int position) {
    (*byte) &= ~(1 << position);
}

// function to hide a message in an image
// takes the path of original image, the path of the output image, and the message as input
void hideMessageInImage(char* inputImagePath, char* outputImagePath, char* message) {
    FILE* inputFile = fopen(inputImagePath, "rb");
    FILE* outputFile = fopen(outputImagePath, "wb");
    if (!inputFile || !outputFile) {
        printf("Error: Could not read input/output file.\n");
        return;
    }
    
    // read bmp header info
    unsigned char header[BMPHEADER];
    fread(header, sizeof(unsigned char), BMPHEADER, inputFile);
    
    // read image data
    unsigned char* data = (unsigned char*) malloc(MAXSIZE);
    int dataSize = fread(data, sizeof(unsigned char), MAXSIZE, inputFile);
    
    // calculate message length
    int messageLen = strlen(message);
    if (messageLen * 8 >= dataSize) {
        printf("Error: Message too long to hide in image.\n");
        return;
    }
    
    // loop through message and hide in image
    int dataIndex = 0;
    for (int i = 0; i < messageLen; i++) {
        for (int j = 0; j < 8; j++) {
            char bit = (message[i] >> j) & 1;
            if (dataIndex >= dataSize) {
                printf("Error: Image does not have enough space to hide message.\n");
                return;
            }
            if (bit == 1) {
                setBit1(&data[dataIndex], 0);
            } else {
                setBit0(&data[dataIndex], 0);
            }
            dataIndex++;
        }
    }
    
    // write the new bmp header and data to the output file
    fwrite(header, sizeof(unsigned char), BMPHEADER, outputFile);
    fwrite(data, sizeof(unsigned char), dataSize, outputFile);
    
    printf("Message hidden in image successfully!\n");
}

// function to extract the hidden message from an image
// takes the path of image as input
void extractMessageFromImage(char* imagePath) {
    FILE* imageFile = fopen(imagePath, "rb");
    if (!imageFile) {
        printf("Error: Could not read input file.\n");
        return;
    }
    
    // read bmp header info
    unsigned char header[BMPHEADER];
    fread(header, sizeof(unsigned char), BMPHEADER, imageFile);
    
    // read image data
    unsigned char* data = (unsigned char*) malloc(MAXSIZE);
    int dataSize = fread(data, sizeof(unsigned char), MAXSIZE, imageFile);
    
    // loop through data and extract the message
    char message[MAXSIZE/8];
    int messageIndex = 0;
    for (int i = 0; i < dataSize; i++) {
        char bit = getBit(&data[i], 0);
        message[messageIndex/8] |= bit << (messageIndex % 8);
        messageIndex++;
    }
    
    printf("Hidden message: %s\n", message);
}

int main() {
    char* inputImagePath = "original_image.bmp";
    char* outputImagePath = "output_image.bmp";
    char* message = "This is a secret message.";

    hideMessageInImage(inputImagePath, outputImagePath, message);
    extractMessageFromImage(outputImagePath);

    return 0;
}