//Falcon2-11B DATASET v1.0 Category: Image Steganography ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IMAGE_BYTE_COUNT (1024 * 1024)

void hideData(const char *imgFileName, const unsigned char *data, int dataLen, const unsigned char *secretKey, unsigned char *imageBuffer) {
    FILE *imgFile = fopen(imgFileName, "rb");
    if (imgFile == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    fseek(imgFile, 0, SEEK_END);
    long imgFileSize = ftell(imgFile);
    rewind(imgFile);

    unsigned char imgBuffer[IMAGE_BYTE_COUNT];
    fread(imgBuffer, 1, IMAGE_BYTE_COUNT, imgFile);

    int offset = 0;
    int numBytesToHide = dataLen / 8;
    while (offset < imgFileSize) {
        unsigned char byte = imgBuffer[offset];
        unsigned char hiddenByte = (byte & 0x80)? secretKey[offset % 8] : byte;
        imageBuffer[offset - 1] = hiddenByte;
        offset++;
    }

    offset = 0;
    numBytesToHide = dataLen % 8;
    while (offset < numBytesToHide) {
        unsigned char byte = data[offset + numBytesToHide - 1];
        unsigned char hiddenByte = (byte & 0x80)? secretKey[offset % 8] : byte;
        imageBuffer[offset + numBytesToHide - 1] = hiddenByte;
        offset++;
    }

    fseek(imgFile, 0, SEEK_SET);
    fwrite(imageBuffer, 1, IMAGE_BYTE_COUNT, imgFile);

    fclose(imgFile);
}

void extractData(const char *imgFileName, const unsigned char *secretKey, unsigned char *buffer) {
    FILE *imgFile = fopen(imgFileName, "rb");
    if (imgFile == NULL) {
        printf("Error opening image file\n");
        exit(1);
    }

    fseek(imgFile, 0, SEEK_END);
    long imgFileSize = ftell(imgFile);
    rewind(imgFile);

    unsigned char imgBuffer[IMAGE_BYTE_COUNT];
    fread(imgBuffer, 1, IMAGE_BYTE_COUNT, imgFile);

    int offset = 0;
    while (offset < imgFileSize) {
        unsigned char byte = imgBuffer[offset];
        unsigned char hiddenByte = (byte & 0x80)? secretKey[offset % 8] : byte;
        buffer[offset - 1] = hiddenByte;
        offset++;
    }

    fclose(imgFile);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s imageFile secretKey outputFile\n", argv[0]);
        exit(1);
    }

    const unsigned char *data = (unsigned char *)argv[1];
    const unsigned char *secretKey = (unsigned char *)argv[2];
    unsigned char outputBuffer[IMAGE_BYTE_COUNT];
    hideData(argv[1], data, strlen(data), secretKey, outputBuffer);
    extractData(argv[1], secretKey, outputBuffer);
    FILE *outputFile = fopen(argv[3], "wb");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        exit(1);
    }
    fwrite(outputBuffer, 1, IMAGE_BYTE_COUNT, outputFile);
    fclose(outputFile);

    return 0;
}