//FormAI DATASET v1.0 Category: Image Editor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function to print menu */
void printMenu() {
    printf("\nImage Editor - Main Menu");
    printf("\n------------------------");
    printf("\n1. Load Image");
    printf("\n2. Save Image");
    printf("\n3. Edit Image");
    printf("\n4. Exit");
    printf("\nPlease choose an option: ");
}

/* Function to load image */
void loadImage(char* filename, int* width, int* height, char** pixels) {
    FILE* fp = fopen(filename, "rb");

    if (fp == NULL) {
        printf("\nError: Failed to open file %s", filename);
        return;
    }

    /* Read width and height from file */
    fread(width, sizeof(int), 1, fp);  
    fread(height, sizeof(int), 1, fp);

    /* Allocate memory for pixel data */
    *pixels = (char*) malloc((*width) * (*height) * 3);

    /* Read pixel data from file */
    fread(*pixels, sizeof(char), (*width) * (*height) * 3, fp);

    /* Close file */
    fclose(fp);

    printf("\nImage loaded successfully!");
}

/* Function to save image */
void saveImage(char* filename, int width, int height, char* pixels) {
    FILE* fp = fopen(filename, "wb");

    if (fp == NULL) {
        printf("\nError: Failed to create file %s", filename);
        return;
    }

    /* Write width and height to file */
    fwrite(&width, sizeof(int), 1, fp);
    fwrite(&height, sizeof(int), 1, fp);

    /* Write pixel data to file */
    fwrite(pixels, sizeof(char), width * height * 3, fp);

    /* Close file */
    fclose(fp);

    printf("\nImage saved successfully!");
}

/* Function to edit image */
void editImage(int width, int height, char* pixels) {
    int choice, row, col;
    char color;

    do {
        printf("\n\nImage Editor - Edit Menu");
        printf("\n------------------------");
        printf("\n1. Set Pixel Color");
        printf("\n2. Flip Horizontally");
        printf("\n3. Flip Vertically");
        printf("\n4. Return to Main Menu");
        printf("\nPlease choose an option: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter row and column numbers (starting from 0): ");
                scanf("%d %d", &row, &col);
                printf("\nEnter pixel color (R G B): ");
                scanf("%hhd %hhd %hhd", &color, &color+1, &color+2);
                if (row >= 0 && row < height && col >= 0 && col < width) {
                    pixels[(row * width + col) * 3 + 0] = color;
                    pixels[(row * width + col) * 3 + 1] = color+1;
                    pixels[(row * width + col) * 3 + 2] = color+2;
                    printf("\nPixel color set successfully!");
                } else {
                    printf("\nError: Invalid row/column number!");
                }
                break;
            case 2:
                for (row = 0; row < height; row++) {
                    for (col = 0; col < width/2; col++) {
                        char tempR = pixels[(row * width + col) * 3 + 0];
                        char tempG = pixels[(row * width + col) * 3 + 1];
                        char tempB = pixels[(row * width + col) * 3 + 2];
                        pixels[(row * width + col) * 3 + 0] = pixels[(row * width + (width-col-1)) * 3 + 0];
                        pixels[(row * width + col) * 3 + 1] = pixels[(row * width + (width-col-1)) * 3 + 1];
                        pixels[(row * width + col) * 3 + 2] = pixels[(row * width + (width-col-1)) * 3 + 2];
                        pixels[(row * width + (width-col-1)) * 3 + 0] = tempR;
                        pixels[(row * width + (width-col-1)) * 3 + 1] = tempG;
                        pixels[(row * width + (width-col-1)) * 3 + 2] = tempB;
                    }
                }
                printf("\nImage flipped horizontally successfully!");
                break;
            case 3:
                for (col = 0; col < width; col++) {
                    for (row = 0; row < height/2; row++) {
                        char tempR = pixels[(row * width + col) * 3 + 0];
                        char tempG = pixels[(row * width + col) * 3 + 1];
                        char tempB = pixels[(row * width + col) * 3 + 2];
                        pixels[(row * width + col) * 3 + 0] = pixels[((height-row-1) * width + col) * 3 + 0];
                        pixels[(row * width + col) * 3 + 1] = pixels[((height-row-1) * width + col) * 3 + 1];
                        pixels[(row * width + col) * 3 + 2] = pixels[((height-row-1) * width + col) * 3 + 2];
                        pixels[((height-row-1) * width + col) * 3 + 0] = tempR;
                        pixels[((height-row-1) * width + col) * 3 + 1] = tempG;
                        pixels[((height-row-1) * width + col) * 3 + 2] = tempB;
                    }
                }
                printf("\nImage flipped vertically successfully!");
                break;
            case 4:
                printf("\nReturning to Main Menu...");
                break;
            default:
                printf("\nError: Invalid option!");
                break;
        }
    } while(choice != 4);
}

int main() {
    int width, height, choice;
    char* pixels = NULL;
    char filename[20];

    printf("Welcome to Image Editor!");

    do {
        printMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("\nEnter path to image file: ");
                scanf("%s", filename);
                loadImage(filename, &width, &height, &pixels);
                break;
            case 2:
                if (pixels == NULL) {
                    printf("\nError: No image loaded!");
                } else {
                    printf("\nEnter path to save image: ");
                    scanf("%s", filename);
                    saveImage(filename, width, height, pixels);
                }
                break;
            case 3:
                if (pixels == NULL) {
                    printf("\nError: No image loaded!");
                } else {
                    editImage(width, height, pixels);
                }
                break;
            case 4:
                printf("\nExiting...");
                break;
            default:
                printf("\nError: Invalid option!");
                break;
        }
    } while(choice != 4);

    /* Free memory allocated for pixel data */
    free(pixels);

    return 0;
}