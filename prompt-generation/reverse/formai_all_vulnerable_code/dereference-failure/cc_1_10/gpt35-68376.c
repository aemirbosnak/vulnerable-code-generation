//FormAI DATASET v1.0 Category: Image Steganography ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// function to get the binary form of a number
void decimalToBinary(int num, int* binary) {
    int i = 7;
    while(num > 0) {
        binary[i] = num % 2;
        num /= 2;
        i--;
    }
}

// function to embed a binary pixel value into a RGB pixel value
void embedPixel(unsigned char * pixel, int binaryPixel) {
    if(binaryPixel == 0) {
        if(pixel[0] % 2 == 1) {
            pixel[0]--;
        }
        if(pixel[1] % 2 == 1) {
            pixel[1]--;
        }
        if(pixel[2] % 2 == 1) {
            pixel[2]--;
        }
    } else {
        if(pixel[0] % 2 == 0) {
            pixel[0]++;
        }
        if(pixel[1] % 2 == 0) {
            pixel[1]++;
        }
        if(pixel[2] % 2 == 0) {
            pixel[2]++;
        }
    }
}

// recursive function to embed the binary message into the image
void embedMessage(unsigned char * image, int * binaryMessage, int messageIndex, int imageIndex) {
    if(messageIndex > 7) {
        return;
    }

    int pixelIndex = imageIndex + (messageIndex % 3);
    unsigned char pixelValue = image[pixelIndex];
    embedPixel(&pixelValue, binaryMessage[messageIndex]);
    image[pixelIndex] = pixelValue;

    embedMessage(image, binaryMessage, messageIndex+1, imageIndex);

    return;
}

int main() {
    FILE *fp;
    fp = fopen("image.bmp", "rb+");

    if(fp == NULL) {
        printf("Error opening the image\n");
        return 0;
    }

    fseek(fp, 0, SEEK_END);
    long fileSize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *image = (unsigned char *)malloc(fileSize * sizeof(unsigned char));
    int bytesRead = fread(image, sizeof(unsigned char), fileSize, fp);

    int messageLength = 11; // example message
    int binaryMessage[messageLength*8]; // to hold the binary form of the message
    decimalToBinary(messageLength, &binaryMessage[0]);

    for(int i = 0; i < messageLength; i++) {
        decimalToBinary("Hello World"[i], &binaryMessage[(i+1)*8]);
    }

    embedMessage(image, binaryMessage, 0, 54);

    // write the modified image to a new file
    FILE *out;
    out = fopen("image-modified.bmp", "wb+");
    fwrite(image, sizeof(unsigned char), bytesRead, out);

    fclose(fp);
    fclose(out);

    return 0;
}