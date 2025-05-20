//FormAI DATASET v1.0 Category: Image Editor ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Declarations
void inFileValidation(FILE *inFile);
void outFileValidation(FILE *outFile);
void printMenu();
void grayScale(unsigned char *imageData, int imgWidth, int imgHeight);
void invertColors(unsigned char *imageData, int imgWidth, int imgHeight);
void swapRedAndGreen(unsigned char *imageData, int imgWidth, int imgHeight);
void swapRedAndBlue(unsigned char *imageData, int imgWidth, int imgHeight);

int main(int argc, char *argv[]) {
    // Variable Declarations
    FILE *inFile, *outFile;
    char inFileName[50], outFileName[50];
    unsigned char *imageData;
    int imgWidth, imgHeight, imgBitDepth, imgSize, userChoice;

    // Check for valid command line arguments
    if (argc != 2) {
        printf("Usage: %s <input_file_name>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Copy the input file name to a variable and append .bmp extension
    strcpy(inFileName, argv[1]);
    strcat(inFileName, ".bmp");

    // Open the input file for reading
    inFile = fopen(inFileName, "rb");
    inFileValidation(inFile);

    // Read the BMP file header
    fseek(inFile, 18, SEEK_SET);
    fread(&imgWidth, sizeof(int), 1, inFile);
    fread(&imgHeight, sizeof(int), 1, inFile);
    fseek(inFile, 2, SEEK_CUR);
    fread(&imgBitDepth, sizeof(short), 1, inFile);
    fseek(inFile, 24, SEEK_SET);
    fread(&imgSize, sizeof(int), 1, inFile);

    // Allocate memory for the image data
    imageData = (unsigned char*)malloc(imgSize);

    // Read the image data into memory
    fseek(inFile, 54, SEEK_SET);
    fread(imageData, sizeof(unsigned char), imgSize, inFile);

    // Close the input file
    fclose(inFile);

    // Print the menu of options
    do {
        printMenu();
        scanf("%d", &userChoice);
        switch(userChoice) {
            case 1:
                grayScale(imageData, imgWidth, imgHeight);
                break;
            case 2:
                invertColors(imageData, imgWidth, imgHeight);
                break;
            case 3:
                swapRedAndGreen(imageData, imgWidth, imgHeight);
                break;
            case 4:
                swapRedAndBlue(imageData, imgWidth, imgHeight);
                break;
            case 5:
                printf("Enter output file name: ");
                scanf("%s", outFileName);
                outFile = fopen(outFileName, "wb");
                outFileValidation(outFile);
                fseek(outFile, 0, SEEK_SET);
                fwrite(imageData, sizeof(unsigned char), imgSize, outFile);
                fclose(outFile);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while(userChoice != 6);

    // Free the memory used for the image data
    free(imageData);

    return 0;
}

// Function Definitions

void inFileValidation(FILE *inFile) {
    // Check if input file has opened successfully
    if (inFile == NULL) {
        printf("Error opening input file.\n");
        exit(EXIT_FAILURE);
    }
}

void outFileValidation(FILE *outFile) {
    // Check if output file has opened successfully
    if (outFile == NULL) {
        printf("Error opening output file.\n");
        exit(EXIT_FAILURE);
    }
}

void printMenu() {
    printf("\nMENU\n");
    printf("1. Convert to Gray Scale\n");
    printf("2. Invert Colors\n");
    printf("3. Swap Red and Green Channels\n");
    printf("4. Swap Red and Blue Channels\n");
    printf("5. Save Output\n");
    printf("6. Exit\n");
    printf("Enter choice: ");
}

void grayScale(unsigned char *imageData, int imgWidth, int imgHeight) {
    int i, j, grayVal, pixelPos;
    unsigned char r, g, b;
    for (i = 0; i < imgHeight; i++) {
        for (j = 0; j < imgWidth; j++) {
            pixelPos = (i * imgWidth + j) * 3;
            r = imageData[pixelPos];
            g = imageData[pixelPos + 1];
            b = imageData[pixelPos + 2];
            grayVal = 0.21 * r + 0.72 * g + 0.07 * b;
            imageData[pixelPos] = grayVal;
            imageData[pixelPos + 1] = grayVal;
            imageData[pixelPos + 2] = grayVal;
        }
    }
    printf("Image converted to gray scale.\n");
}

void invertColors(unsigned char *imageData, int imgWidth, int imgHeight) {
    int i, j, pixelPos;
    unsigned char r, g, b;
    for (i = 0; i < imgHeight; i++) {
        for (j = 0; j < imgWidth; j++) {
            pixelPos = (i * imgWidth + j) * 3;
            r = 255 - imageData[pixelPos];
            g = 255 - imageData[pixelPos + 1];
            b = 255 - imageData[pixelPos + 2];
            imageData[pixelPos] = r;
            imageData[pixelPos + 1] = g;
            imageData[pixelPos + 2] = b;
        }
    }
    printf("Colors inverted.\n");
}

void swapRedAndGreen(unsigned char *imageData, int imgWidth, int imgHeight) {
    int i, j, pixelPos;
    unsigned char r, g, b;
    for (i = 0; i < imgHeight; i++) {
        for (j = 0; j < imgWidth; j++) {
            pixelPos = (i * imgWidth + j) * 3;
            r = imageData[pixelPos];
            g = imageData[pixelPos + 1];
            b = imageData[pixelPos + 2];
            imageData[pixelPos] = g;
            imageData[pixelPos + 1] = r;
            imageData[pixelPos + 2] = b;
        }
    }
    printf("Red and green channels swapped.\n");
}

void swapRedAndBlue(unsigned char *imageData, int imgWidth, int imgHeight) {
    int i, j, pixelPos;
    unsigned char r, g, b;
    for (i = 0; i < imgHeight; i++) {
        for (j = 0; j < imgWidth; j++) {
            pixelPos = (i * imgWidth + j) * 3;
            r = imageData[pixelPos];
            g = imageData[pixelPos + 1];
            b = imageData[pixelPos + 2];
            imageData[pixelPos] = b;
            imageData[pixelPos + 1] = g;
            imageData[pixelPos + 2] = r;
        }
    }
    printf("Red and blue channels swapped.\n");
}