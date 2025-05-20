//Falcon2-11B DATASET v1.0 Category: Image Editor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Function to open an image file and display it
void openAndDisplayImage(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(fileSize);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return;
    }

    fread(buffer, fileSize, 1, file);
    fclose(file);

    int width = 0;
    int height = 0;
    int red = 0, green = 0, blue = 0;

    for (int i = 0; i < fileSize; i++) {
        int r = buffer[i];
        int g = buffer[i + 1];
        int b = buffer[i + 2];

        width = width * 3 + 1;
        height = height * 3 + 1;

        red = red * height + r;
        green = green * height + g;
        blue = blue * height + b;
    }

    printf("Displaying image with dimensions %d x %d.\n", width, height);
    printf("Image data:\n");

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (red + y * 3 * width) % 256;
            int g = (green + y * 3 * width) % 256;
            int b = (blue + y * 3 * width) % 256;

            printf("(%d, %d, %d)\n", r, g, b);
        }
    }

    free(buffer);
}

// Function to resize an image
void resizeImage(const char* filename, int newWidth, int newHeight) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(fileSize);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return;
    }

    fread(buffer, fileSize, 1, file);
    fclose(file);

    int width = 0;
    int height = 0;
    int red = 0, green = 0, blue = 0;

    for (int i = 0; i < fileSize; i++) {
        int r = buffer[i];
        int g = buffer[i + 1];
        int b = buffer[i + 2];

        width = width * 3 + 1;
        height = height * 3 + 1;

        red = red * height + r;
        green = green * height + g;
        blue = blue * height + b;
    }

    printf("Resizing image from dimensions %d x %d to %d x %d.\n", width, height, newWidth, newHeight);

    int widthRatio = newWidth / width;
    int heightRatio = newHeight / height;

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            int r = (red + y * 3 * widthRatio) % 256;
            int g = (green + y * 3 * widthRatio) % 256;
            int b = (blue + y * 3 * widthRatio) % 256;

            int index = (y * widthRatio + x) * 3;
            buffer[index] = r;
            buffer[index + 1] = g;
            buffer[index + 2] = b;
        }
    }

    FILE* newFile = fopen("resized.bmp", "wb");
    if (newFile == NULL) {
        printf("Error opening new file'resized.bmp'.\n");
        return;
    }

    fwrite(buffer, fileSize, 1, newFile);
    fclose(newFile);
    free(buffer);
}

// Function to rotate an image
void rotateImage(const char* filename, int angle) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", filename);
        return;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(fileSize);
    if (buffer == NULL) {
        printf("Error allocating memory.\n");
        fclose(file);
        return;
    }

    fread(buffer, fileSize, 1, file);
    fclose(file);

    int width = 0;
    int height = 0;
    int red = 0, green = 0, blue = 0;

    for (int i = 0; i < fileSize; i++) {
        int r = buffer[i];
        int g = buffer[i + 1];
        int b = buffer[i + 2];

        width = width * 3 + 1;
        height = height * 3 + 1;

        red = red * height + r;
        green = green * height + g;
        blue = blue * height + b;
    }

    printf("Rotating image by %d degrees.\n", angle);

    int newWidth = width;
    int newHeight = height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int r = (red + y * 3 * width) % 256;
            int g = (green + y * 3 * width) % 256;
            int b = (blue + y * 3 * width) % 256;

            int index = (x + y * width) * 3;
            buffer[index] = r;
            buffer[index + 1] = g;
            buffer[index + 2] = b;
        }
    }

    FILE* newFile = fopen("rotated.bmp", "wb");
    if (newFile == NULL) {
        printf("Error opening new file 'rotated.bmp'.\n");
        return;
    }

    fwrite(buffer, fileSize, 1, newFile);
    fclose(newFile);
    free(buffer);
}

int main() {
    // Example usage
    openAndDisplayImage("image.bmp");
    resizeImage("image.bmp", 400, 300);
    rotateImage("image.bmp", 90);

    return 0;
}