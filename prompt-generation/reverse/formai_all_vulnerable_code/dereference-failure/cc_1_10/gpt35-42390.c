//FormAI DATASET v1.0 Category: Image Editor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 100
#define MAX_MENU_ITEM_LENGTH 30
#define MAX_MENU_ITEMS 5

void printMainMenu();
void applyInvertFilter(unsigned char *imgData, int imgSize);
void applyGrayscaleFilter(unsigned char *imgData, int imgSize);
void applyFlipFilter(unsigned char *imgData, int imgWidth, int imgHeight);

int main() {
    char imgFileName[MAX_FILENAME_LENGTH];
    char userInput[MAX_MENU_ITEM_LENGTH];

    printf("Enter image filename: ");
    scanf("%s", imgFileName);

    FILE *imgFile = fopen(imgFileName, "rb");
    if (!imgFile) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Read image data
    fseek(imgFile, 0, SEEK_END);
    int imgSize = ftell(imgFile);
    fseek(imgFile, 0, SEEK_SET);

    unsigned char *imgData = malloc(imgSize);
    fread(imgData, 1, imgSize, imgFile);
    fclose(imgFile);

    // Display main menu
    printMainMenu();

    // Apply user-selected filters
    while (1) {
        printf("\nEnter your choice: ");
        scanf("%s", userInput);

        if (strcmp(userInput, "1") == 0) {
            applyInvertFilter(imgData, imgSize);
            printf("Invert filter applied.\n");
        } else if (strcmp(userInput, "2") == 0) {
            applyGrayscaleFilter(imgData, imgSize);
            printf("Grayscale filter applied.\n");
        } else if (strcmp(userInput, "3") == 0) {
            int imgWidth = *(short *)(imgData + 0x12);
            int imgHeight = *(short *)(imgData + 0x16);
            applyFlipFilter(imgData, imgWidth, imgHeight);
            printf("Flip filter applied.\n");
        } else if (strcmp(userInput, "4") == 0) {
            // Save image to file
            printf("Enter output filename: ");
            scanf("%s", imgFileName);

            FILE *outputFile = fopen(imgFileName, "wb");
            if (!outputFile) {
                printf("Error: Could not create file\n");
                return 1;
            }

            fwrite(imgData, 1, imgSize, outputFile);
            fclose(outputFile);
            printf("Image saved to %s.\n", imgFileName);
            break;
        } else if (strcmp(userInput, "5") == 0) {
            printf("Exiting program...\n");
            break;
        } else {
            printf("Invalid option. Please try again.\n");
        }
    }

    free(imgData);
    return 0;
}

// Prints the main menu options
void printMainMenu() {
    printf("\n======== IMAGE EDITOR ========\n");
    printf("1. Apply Invert Filter\n");
    printf("2. Apply Grayscale Filter\n");
    printf("3. Apply Flip Filter\n");
    printf("4. Save Image\n");
    printf("5. Exit\n");
}

// Applies an invert filter to the image data
void applyInvertFilter(unsigned char *imgData, int imgSize) {
    int i;
    for (i = 0; i < imgSize; i++) {
        imgData[i] = 255 - imgData[i];
    }
}

// Applies a grayscale filter to the image data
void applyGrayscaleFilter(unsigned char *imgData, int imgSize) {
    int i;
    for (i = 0; i < imgSize; i += 3) {
        unsigned char r = imgData[i];
        unsigned char g = imgData[i+1];
        unsigned char b = imgData[i+2];
        unsigned char gray = (r + g + b) / 3;
        imgData[i] = gray;
        imgData[i+1] = gray;
        imgData[i+2] = gray;
    }
}

// Applies a flip filter to the image data
void applyFlipFilter(unsigned char *imgData, int imgWidth, int imgHeight) {
    int i, j;
    unsigned char tempPixel[3];
    for (i = 0; i < imgHeight / 2; i++) {
        for (j = 0; j < imgWidth * 3; j += 3) {
            int topIndex = i * imgWidth * 3 + j;
            int bottomIndex = (imgHeight - i - 1) * imgWidth * 3 + j;

            memcpy(tempPixel, imgData + topIndex, 3);
            memcpy(imgData + topIndex, imgData + bottomIndex, 3);
            memcpy(imgData + bottomIndex, tempPixel, 3);
        }
    }
}