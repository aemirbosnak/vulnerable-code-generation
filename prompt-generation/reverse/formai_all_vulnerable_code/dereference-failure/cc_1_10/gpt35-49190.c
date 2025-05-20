//FormAI DATASET v1.0 Category: Image Steganography ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to get file size */
int getFileSize(char *fileName) {
    FILE *fp;
    int size;

    fp = fopen(fileName, "rb");

    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    size = ftell(fp);
    fclose(fp);
    
    return size;
}

/* Function to read file data */
void readFileData(char *fileName, char *data) {
    FILE *fp;

    fp = fopen(fileName, "rb");
    
    if(fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    fread(data, sizeof(char), getFileSize(fileName), fp);
    fclose(fp);
}

/* Function to write data to file */
void writeFileData(char *fileName, char *data, int size) {
    FILE *fp;

    fp = fopen(fileName, "wb");
    
    if(fp == NULL) {
        printf("Error creating file!\n");
        exit(1);
    }

    fwrite(data, sizeof(char), size, fp);
    fclose(fp);
}

/* Function to hide data in image by modifying LSBs*/
void hideData(char *imageFile, char *dataFile) {
    char imageData[1024];
    char data[1024];
    int imageSize, dataSize, i, j;

    /* Read image data */
    readFileData(imageFile, imageData);

    /* Read data from file */
    readFileData(dataFile, data);
    dataSize = strlen(data);

    /* Get image size */
    imageSize = getFileSize(imageFile);

    /* Check if image size is greater than data size */
    if(imageSize <= dataSize + 54) {
        printf("Error: Image size is not sufficient to hide data!");
        exit(1);
    }

    /* Modify LSB of each pixel */
    for(i = 54, j = 0; j < dataSize; i += 3, j++) {
        imageData[i] = (imageData[i] & 0xfe) | ((data[j] >> 7) & 0x01);
        imageData[i+1] = (imageData[i+1] & 0xfe) | ((data[j] >> 6) & 0x01);
        imageData[i+2] = (imageData[i+2] & 0xfe) | ((data[j] >> 5) & 0x01);
        imageData[i+3] = (imageData[i+3] & 0xfe) | ((data[j] >> 4) & 0x01);
        imageData[i+4] = (imageData[i+4] & 0xfe) | ((data[j] >> 3) & 0x01);
        imageData[i+5] = (imageData[i+5] & 0xfe) | ((data[j] >> 2) & 0x01);
        imageData[i+6] = (imageData[i+6] & 0xfe) | ((data[j] >> 1) & 0x01);
        imageData[i+7] = (imageData[i+7] & 0xfe) | ((data[j] >> 0) & 0x01);
    }

    /* Write modified image data to file */
    writeFileData(imageFile, imageData, imageSize);
}

/* Function to extract data from image */
void extractData(char *imageFile, char *dataFile) {
    char imageData[1024];
    char data[1024];
    int imageSize, i, j;

    /* Read image data */
    readFileData(imageFile, imageData);

    /* Get image size */
    imageSize = getFileSize(imageFile);

    /* Extract data from LSB of each pixel */
    for(i = 54, j = 0; i < imageSize; i += 3, j++) {
        data[j] = 0;
        data[j] |= (imageData[i] & 0x01) << 7;
        data[j] |= (imageData[i+1] & 0x01) << 6;
        data[j] |= (imageData[i+2] & 0x01) << 5;
        data[j] |= (imageData[i+3] & 0x01) << 4;
        data[j] |= (imageData[i+4] & 0x01) << 3;
        data[j] |= (imageData[i+5] & 0x01) << 2;
        data[j] |= (imageData[i+6] & 0x01) << 1;
        data[j] |= (imageData[i+7] & 0x01) << 0;
    }

    /* Write extracted data to file */
    writeFileData(dataFile, data, j);
}

int main() {
    char imageFile[50], dataFile[50], choice;

    printf("Image Steganography Example Program\n");
    printf("-----------------------------------\n");

    printf("Enter image file name: ");
    scanf("%s", imageFile);

    printf(" 1. Hide data\n 2. Extract data\n");
    scanf(" %c", &choice);

    printf("Enter data file name: ");
    scanf("%s", dataFile);

    switch(choice) {
        case '1':
            hideData(imageFile, dataFile);
            printf("Data hidden successfully!\n");
            break;
        case '2':
            extractData(imageFile, dataFile);
            printf("Data extracted and written to file successfully!\n");
            break;
        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}