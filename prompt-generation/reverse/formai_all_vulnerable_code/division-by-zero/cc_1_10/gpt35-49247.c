//FormAI DATASET v1.0 Category: Image Steganography ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1000

void hideData(char* inputImagePath, char* outputImagePath, char* secretDataFilename) {
    FILE* inputImageFile = fopen(inputImagePath, "rb");
    FILE* outputImageFile = fopen(outputImagePath, "wb");
    FILE* secretDataFile = fopen(secretDataFilename, "r");
    
    if (inputImageFile == NULL || outputImageFile == NULL || secretDataFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Read input image header
    unsigned char header[BUFFER_SIZE];
    fread(header, sizeof(unsigned char), BUFFER_SIZE, inputImageFile);
    fwrite(header, sizeof(unsigned char), BUFFER_SIZE, outputImageFile);
    
    // Get input image size
    int size;
    fseek(inputImageFile, 0, SEEK_END);
    size = ftell(inputImageFile) - BUFFER_SIZE; // remove header size
    fseek(inputImageFile, BUFFER_SIZE, SEEK_SET);
    
    // Read secret data from file
    char secretData[BUFFER_SIZE];
    fgets(secretData, BUFFER_SIZE, secretDataFile);
    
    if (strlen(secretData) > size / 8) {
        printf("Error: Input image not large enough to hide data.\n");
        return;
    }
    
    // Encode secret data in input image
    int i, j, bit;
    unsigned char pixel;
    char* data = secretData;
    
    for (i = 0; i < size; i++) {
        fread(&pixel, sizeof(unsigned char), 1, inputImageFile);
        for (j = 0; j < 8; j++) {
            fseek(outputImageFile, 0, SEEK_CUR); // keep writing to same position
            bit = data[j % strlen(data)] >> j / 8 & 0x1;
            pixel = (pixel & 0xFE) | bit;
            fwrite(&pixel, sizeof(unsigned char), 1, outputImageFile);
        }
        data += 8;
    }
    
    fclose(inputImageFile);
    fclose(outputImageFile);
    fclose(secretDataFile);
}

void extractData(char* inputImagePath, char* secretDataFilename) {
    FILE* inputImageFile = fopen(inputImagePath, "rb");
    FILE* secretDataFile = fopen(secretDataFilename, "w");
    
    if (inputImageFile == NULL || secretDataFile == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    
    // Read input image header
    unsigned char header[BUFFER_SIZE];
    fread(header, sizeof(unsigned char), BUFFER_SIZE, inputImageFile);
    
    // Get input image size
    int size;
    fseek(inputImageFile, 0, SEEK_END);
    size = ftell(inputImageFile) - BUFFER_SIZE; // remove header size
    fseek(inputImageFile, BUFFER_SIZE, SEEK_SET);
    
    // Decode secret data from input image
    int i, j, bit;
    unsigned char pixel;
    char outputData[BUFFER_SIZE];
    memset(outputData, 0, sizeof(outputData));
    char* data = outputData;
    
    for (i = 0; i < size; i++) {
        fread(&pixel, sizeof(unsigned char), 1, inputImageFile);
        for (j = 0; j < 8; j++) {
            bit = pixel >> j & 0x1;
            *data |= bit << j % 8;
            if (j % 8 == 7) {
                data++;
            }
        }
    }
    
    fprintf(secretDataFile, "%s", outputData);
    
    fclose(inputImageFile);
    fclose(secretDataFile);
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        printf("Usage: ./steganography <input image> <output image> <secret data>\n");
        return 0;
    }
    
    char* inputImagePath = argv[1];
    char* outputImagePath = argv[2];
    char* secretDataFilename = argv[3];
    
    hideData(inputImagePath, outputImagePath, secretDataFilename);
    extractData(outputImagePath, secretDataFilename);
    
    return 0;
}