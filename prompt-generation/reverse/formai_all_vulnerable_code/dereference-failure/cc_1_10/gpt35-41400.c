//FormAI DATASET v1.0 Category: Image Steganography ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BMP_HEADER_SIZE 54

/* Function to get the size of a file */
long int getFileSize(FILE *file) {
    long int size;
    fseek(file, 0, SEEK_END);
    size = ftell(file);
    fseek(file, 0, SEEK_SET);
    return size;
}

/* Function to read a BMP image */
unsigned char* readBMPImage(char *filename, long int *size) {
    FILE *file;
    unsigned char *buffer;

    file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    *size = getFileSize(file);
    buffer = (unsigned char*) malloc(*size);

    fread(buffer, *size, 1, file);

    fclose(file);

    return buffer;
}

/* Function to write a BMP image */
void writeBMPImage(char *filename, unsigned char *buffer, long int size) {
    FILE *file;

    file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fwrite(buffer, size, 1, file);

    fclose(file);
}

/* Function to hide data in the least significant bits of an image */
unsigned char* hideData(unsigned char *image, long int size, char *data, long int dataSize) {
    unsigned char *newImage;
    long int i, j, bitIndex, byteIndex, dataByteIndex, dataBitIndex;

    newImage = (unsigned char*) malloc(size);

    memcpy(newImage, image, BMP_HEADER_SIZE);

    dataByteIndex = 0;
    dataBitIndex = 0;

    for (i = BMP_HEADER_SIZE; i < size && dataByteIndex < dataSize; i++) {
        byteIndex = i - BMP_HEADER_SIZE;
        bitIndex = byteIndex % 8;

        if (bitIndex == 0) {
            newImage[i] = image[i] & 0xfe;
        }

        if (data[dataByteIndex] & (1 << dataBitIndex)) {
            newImage[i]++;
        }

        dataBitIndex++;

        if (dataBitIndex >= 8) {
            dataByteIndex++;
            dataBitIndex = 0;
        }
    }

    return newImage;
}

/* Function to retrieve hidden data from the least significant bits of an image */
char* retrieveData(unsigned char *image, long int size) {
    char *data;
    long int i, j, bitIndex, byteIndex, dataSize;

    dataSize = (size - BMP_HEADER_SIZE) / 8;
    data = (char*) malloc(dataSize + 1);

    byteIndex = 0;
    bitIndex = 0;

    for (i = BMP_HEADER_SIZE, j = 0; i < size && j < dataSize; i++) {
        byteIndex = i - BMP_HEADER_SIZE;
        bitIndex = byteIndex % 8;

        if (bitIndex == 0) {
            data[j] = 0;
        }

        if (image[i] & 1) {
            data[j] |= 1 << bitIndex;
        }

        if (bitIndex == 7) {
            j++;
        }
    }

    data[dataSize] = '\0';

    return data;
}

/* Main function */
int main() {
    long int imageSize, dataSize;
    char *data, *retrievedData;
    unsigned char *image, *newImage;

    /* Read the image */
    image = readBMPImage("image.bmp", &imageSize);

    /* Hide some data in the image */
    data = "Hello, world!";
    dataSize = strlen(data);
    newImage = hideData(image, imageSize, data, dataSize);

    /* Write the new image with the hidden data */
    writeBMPImage("newimage.bmp", newImage, imageSize);

    /* Free memory */
    free(image);
    free(newImage);

    /* Read the new image with the hidden data */
    newImage = readBMPImage("newimage.bmp", &imageSize);

    /* Retrieve the hidden data */
    retrievedData = retrieveData(newImage, imageSize);
    printf("Retrieved data: %s\n", retrievedData);

    /* Free memory */
    free(newImage);
    free(retrievedData);

    return 0;
}