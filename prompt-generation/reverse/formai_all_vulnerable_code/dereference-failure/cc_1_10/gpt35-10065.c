//FormAI DATASET v1.0 Category: Image Editor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_IMAGE_SIZE 1024*1024 // 1MB

//function declarations
void menu();
void readFile(char *fileName);
void writeFile(char *fileName);
void invertColors();
void rotate90Degrees();
void flipHorizontally();
void flipVertically();

//global variables
unsigned char* imagePixels = NULL;
int imageSize = 0;
int imageWidth = 0;
int imageHeight = 0;
int bytesPerPixel = 0;

int main() {
    char fileName[MAX_FILE_NAME_SIZE];

    printf("Welcome to C Image Editor!\n");
    printf("Please enter the name of the image file: ");
    scanf("%s", fileName);

    readFile(fileName);

    int choice = -1;
    while (choice != 0) {
        menu();
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("Goodbye!\n");
                break;
            case 1:
                writeFile(fileName);
                break;
            case 2:
                invertColors();
                break;
            case 3:
                rotate90Degrees();
                break;
            case 4:
                flipHorizontally();
                break;
            case 5:
                flipVertically();
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    }

    if (imagePixels != NULL) {
        free(imagePixels);
        imagePixels = NULL;
    }

    return 0;
}

void menu() {
    printf("\nPlease choose an option:\n");
    printf("0. Quit\n");
    printf("1. Save the image\n");
    printf("2. Invert colors\n");
    printf("3. Rotate 90 degrees\n");
    printf("4. Flip horizontally\n");
    printf("5. Flip vertically\n");
    printf("Your choice: ");
}

void readFile(char *fileName) {
    FILE *file;
    file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    int fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    if (fileSize > MAX_IMAGE_SIZE) {
        printf("Error: image is too big (%d bytes)\n", fileSize);
        exit(1);
    }

    unsigned char header[54];
    int read = fread(header, 1, 54, file);
    if (read != 54) {
        printf("Error: invalid file format\n");
        exit(1);
    }

    if (header[0] != 'B' || header[1] != 'M') {
        printf("Error: invalid file format\n");
        exit(1);
    }

    int pixelOffset = *(int*)&header[10];
    bytesPerPixel = *(int*)&header[28] / 8;
    imageWidth = *(int*)&header[18];
    imageHeight = *(int*)&header[22];
    imageSize = imageWidth * imageHeight * bytesPerPixel;

    imagePixels = (unsigned char*) malloc(imageSize);
    if (imagePixels == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    fseek(file, pixelOffset, SEEK_SET);
    read = fread(imagePixels, 1, imageSize, file);
    if (read != imageSize) {
        printf("Error: invalid file format\n");
        exit(1);
    }

    fclose(file);
}

void writeFile(char *fileName) {
    FILE *file;
    file = fopen(fileName, "wb");
    if (file == NULL) {
        printf("Error opening file %s\n", fileName);
        exit(1);
    }

    unsigned char header[54];
    memset(header, 0, 54);
    header[0] = 'B';
    header[1] = 'M';
    *(int*)&header[2] = 54 + imageSize;
    *(int*)&header[10] = 54;
    *(int*)&header[14] = 40;
    *(int*)&header[18] = imageWidth;
    *(int*)&header[22] = imageHeight;
    *(int*)&header[26] = 1;
    *(int*)&header[28] = bytesPerPixel * 8;

    fwrite(header, 1, 54, file);
    fwrite(imagePixels, 1, imageSize, file);

    printf("Image saved as %s\n", fileName);
    fclose(file);
}

void invertColors() {
    for (int i = 0; i < imageSize; i++) {
        imagePixels[i] = 255 - imagePixels[i];
    }

    printf("Colors inverted!\n");
}

void rotate90Degrees() {
    int newWidth = imageHeight;
    int newHeight = imageWidth;
    unsigned char* newPixels = (unsigned char*) malloc(imageSize);
    if (newPixels == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    int pixelIndex = 0;
    int newIndex = 0;
    for (int y = imageHeight - 1; y >= 0; y--) {
        for (int x = 0; x < imageWidth; x++) {
            pixelIndex = (y * imageWidth + x) * bytesPerPixel;
            newIndex = (x * newWidth + y) * bytesPerPixel;
            for (int b = 0; b < bytesPerPixel; b++) {
                newPixels[newIndex + b] = imagePixels[pixelIndex + b];
            }
        }
    }

    free(imagePixels);
    imagePixels = newPixels;
    imageSize = newWidth * newHeight * bytesPerPixel;
    imageWidth = newWidth;
    imageHeight = newHeight;

    printf("Image rotated 90 degrees!\n");
}

void flipHorizontally() {
    unsigned char tmp;
    int i1, i2;

    for (int y = 0; y < imageHeight; y++) {
        for (int x = 0; x < imageWidth / 2; x++) {
            i1 = (y * imageWidth + x) * bytesPerPixel;
            i2 = (y * imageWidth + imageWidth - 1 - x) * bytesPerPixel;
            for (int b = 0; b < bytesPerPixel; b++) {
                tmp = imagePixels[i1 + b];
                imagePixels[i1 + b] = imagePixels[i2 + b];
                imagePixels[i2 + b] = tmp;
            }
        }
    }

    printf("Image flipped horizontally!\n");
}

void flipVertically() {
    unsigned char tmp;
    int i1, i2;

    for (int y = 0; y < imageHeight / 2; y++) {
        for (int x = 0; x < imageWidth; x++) {
            i1 = (y * imageWidth + x) * bytesPerPixel;
            i2 = ((imageHeight - 1 - y) * imageWidth + x) * bytesPerPixel;
            for (int b = 0; b < bytesPerPixel; b++) {
                tmp = imagePixels[i1 + b];
                imagePixels[i1 + b] = imagePixels[i2 + b];
                imagePixels[i2 + b] = tmp;
            }
        }
    }

    printf("Image flipped vertically!\n");
}