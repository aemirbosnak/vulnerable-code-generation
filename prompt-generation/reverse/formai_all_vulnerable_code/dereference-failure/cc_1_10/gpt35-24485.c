//FormAI DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_IMAGE_SIZE 1000000

// Function to load image file
char* load_image(char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        printf("Error opening file.\n");
        exit(1);
    }
    char* image = (char*)malloc(MAX_IMAGE_SIZE);
    size_t bytesRead = fread(image, 1, MAX_IMAGE_SIZE, file);
    fclose(file);
    printf("Image loaded successfully.\n");
    return image;
}

// Function to save image file
void save_image(char* filename, char* image, int size) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        printf("Error saving file.\n");
        exit(1);
    }
    fwrite(image, 1, size, file);
    fclose(file);
    printf("Image saved successfully.\n");
}

// Function to perform grayscale conversion
void grayscale(char* image, int width, int height) {
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width * 3; j += 3) {
            int r = image[i * width * 3 + j];
            int g = image[i * width * 3 + j + 1];
            int b = image[i * width * 3 + j + 2];
            int avg = (r + g + b) / 3;
            image[i * width * 3 + j] = avg;
            image[i * width * 3 + j + 1] = avg;
            image[i * width * 3 + j + 2] = avg;
        }
    }
    printf("Grayscale conversion successful.\n");
}

// Function to perform invert transformation
void invert(char* image, int size) {
    for (int i = 0; i < size; i++) {
        image[i] = 255 - image[i];
    }
    printf("Invert transformation successful.\n");
}

// Function to perform blur effect
void blur(char* image, int width, int height) {
    char* temp = (char*)malloc(width * height * 3);
    memcpy(temp, image, width * height * 3);
    for (int i = 1; i < height - 1; i++) {
        for (int j = 3; j < (width - 1) * 3; j += 3) {
            int r = (temp[(i - 1) * width * 3 + j - 3] + temp[(i - 1) * width * 3 + j] + temp[(i - 1) * width * 3 + j + 3]
                     + temp[i * width * 3 + j - 3] + temp[i * width * 3 + j] + temp[i * width * 3 + j + 3]
                     + temp[(i + 1) * width * 3 + j - 3] + temp[(i + 1) * width * 3 + j] + temp[(i + 1) * width * 3 + j + 3]) / 9;
            int g = (temp[(i - 1) * width * 3 + j - 2] + temp[(i - 1) * width * 3 + j + 1] + temp[(i - 1) * width * 3 + j + 4]
                     + temp[i * width * 3 + j - 2] + temp[i * width * 3 + j + 1] + temp[i * width * 3 + j + 4]
                     + temp[(i + 1) * width * 3 + j - 2] + temp[(i + 1) * width * 3 + j + 1] + temp[(i + 1) * width * 3 + j + 4]) / 9;
            int b = (temp[(i - 1) * width * 3 + j - 1] + temp[(i - 1) * width * 3 + j + 2] + temp[(i - 1) * width * 3 + j + 5]
                     + temp[i * width * 3 + j - 1] + temp[i * width * 3 + j + 2] + temp[i * width * 3 + j + 5]
                     + temp[(i + 1) * width * 3 + j - 1] + temp[(i + 1) * width * 3 + j + 2] + temp[(i + 1) * width * 3 + j + 5]) / 9;
            image[i * width * 3 + j] = r;
            image[i * width * 3 + j + 1] = g;
            image[i * width * 3 + j + 2] = b;
        }
    }
    free(temp);
    printf("Blur effect applied successfully.\n");
}

int main() {
    printf("Welcome to the C Image Editor!\n");
    srand(time(NULL));
    char filename[100];
    printf("Enter the name of the image file: ");
    scanf("%s", filename);

    // Load the image
    char* image = load_image(filename);
    int size = strlen(image);
    int width, height;
    printf("Enter the width and height of the image (separated by a space): ");
    scanf("%d %d", &width, &height);
    printf("Image dimensions: %dx%d\n", width, height);

    // Apply a random transformation
    int choice = rand() % 3;
    switch (choice) {
        case 0:
            grayscale(image, width, height);
            break;
        case 1:
            invert(image, size);
            break;
        case 2:
            blur(image, width, height);
            break;
    }

    // Save the image
    char new_filename[100];
    printf("Enter a name for the new image file: ");
    scanf("%s", new_filename);
    save_image(new_filename, image, size);

    free(image);
    printf("Thank you for using the C Image Editor!\n");
    return 0;
}