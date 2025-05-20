//FormAI DATASET v1.0 Category: Image Steganography ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BYTES_TO_BITS 8

void binaryToChar(char *str, int length, int *arr) {
    int i, j, sum;
    for(i=0; i<length; i++) {
        sum=0;
        for(j=0; j<BYTES_TO_BITS; j++)
            sum += arr[i*BYTES_TO_BITS + j] * (1 << (BYTES_TO_BITS-1-j));
        str[i] = sum;
    }
    str[i] = '\0';
}

void hideMessage(FILE *fp, char *message) {
    char imageHeader[54], *binary, *newMessage;
    int imageSize, imageWidth, imageHeight, bitsPerPix;

    fread(imageHeader, sizeof(char), 54, fp);
    imageSize = *(int*)&imageHeader[2];
    imageWidth = *(int*)&imageHeader[18];
    imageHeight = *(int*)&imageHeader[22];
    bitsPerPix = *(short int*)&imageHeader[28];

    int imageSizeInBytes = imageSize - 54;
    unsigned char imageBuffer[imageSizeInBytes];
    fread(imageBuffer, sizeof(unsigned char), imageSizeInBytes, fp);

    binary = (char *)malloc(sizeof(char) * imageSizeInBytes * BYTES_TO_BITS);
    for(int i=0; i<imageSizeInBytes; i++) {
        for(int j=0; j<BYTES_TO_BITS; j++) {
            binary[i*BYTES_TO_BITS+j] = (imageBuffer[i] >> (BYTES_TO_BITS-1-j)) & 1;
        }
    }
    binaryToChar(newMessage, strlen(message), binary);

    int newMessageLength = strlen(newMessage) * BYTES_TO_BITS;
    if(newMessageLength > imageSizeInBytes) {
        printf("Message too long to be hidden in the image.\n");
        return;
    }
    for(int i=0; i<newMessageLength; i++) {
        imageBuffer[i] &= ~(1);
        imageBuffer[i] |= (newMessage[i/8] >> (BYTES_TO_BITS-1-(i%BYTES_TO_BITS))) & 1;
    }

    FILE *output = fopen("output.bmp", "wb");

    fwrite(imageHeader, sizeof(unsigned char), 54, output);
    fwrite(imageBuffer, sizeof(unsigned char), imageSizeInBytes, output);

    fclose(output);
    printf("Image saved to output.bmp successfully with hidden message.\n");
}

void showMessage(FILE *fp) {
    char imageHeader[54], *binary, message[255];
    int imageSize, imageWidth, imageHeight, bitsPerPix;

    fread(imageHeader, sizeof(char), 54, fp);
    imageSize = *(int*)&imageHeader[2];
    imageWidth = *(int*)&imageHeader[18];
    imageHeight = *(int*)&imageHeader[22];
    bitsPerPix = *(short int*)&imageHeader[28];

    int imageSizeInBytes = imageSize - 54;
    unsigned char imageBuffer[imageSizeInBytes];
    fread(imageBuffer, sizeof(unsigned char), imageSizeInBytes, fp);

    binary = (char*)malloc(sizeof(char) * imageSizeInBytes * BYTES_TO_BITS);
    for(int i=0; i<imageSizeInBytes; i++) {
        for(int j=0; j<BYTES_TO_BITS; j++) {
            binary[i*BYTES_TO_BITS+j] = (imageBuffer[i] >> (BYTES_TO_BITS-1-j)) & 1;
        }
    }
    binaryToChar(message, sizeof(message), binary);
    printf("Hidden message in the image is: %s\n", message);
}

void help() {
    printf("*********Image Steganography Example Program*********\n");
    printf("1. To hide message into image, use command:\n\t./steganography -e <image_file> '<message>'\n");
    printf("2. To show hidden message from the image, use command:\n\t./steganography -s <image_file>\n");
}

int main(int argc, char *argv[]) {    
    if(argc == 4 && strcmp(argv[1], "-e") == 0) {
        FILE *fp = fopen(argv[2], "rb");
        if(fp == NULL) {
            printf("Failed to open the image file.\n");
            return 1;
        }
        hideMessage(fp, argv[3]);
        fclose(fp);
    } else if(argc == 3 && strcmp(argv[1], "-s") == 0) {
        FILE *fp = fopen(argv[2], "rb");
        if(fp == NULL) {
            printf("Failed to open the image file.\n");
            return 1;
        }
        showMessage(fp);
        fclose(fp);
    } else {
        help();
    }

    return 0;
}