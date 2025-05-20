//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ASCII characters used to represent the pixels
const char PIXELS[] = {' ', '.', ':', 'o', '&', '8', '#', '@'};

// Function to read the image file
int** read_image(char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }
    fscanf(file, "%d %d", width, height);
    int** image = (int**) malloc((*height) * sizeof(int*));
    for (int i = 0; i < *height; i++) {
        image[i] = (int*) malloc((*width) * sizeof(int));
        for (int j = 0; j < *width; j++) {
            fscanf(file, "%d", &image[i][j]);
        }
    }
    fclose(file);
    return image;
}

// Function to convert the image to ASCII art
char** convert_image(int** image, int width, int height) {
    char** ascii = (char**) malloc((height) * sizeof(char*));
    for (int i = 0; i < height; i++) {
        ascii[i] = (char*) malloc((width + 1) * sizeof(char));
        for (int j = 0; j < width; j++) {
            int index = (int) ((image[i][j] / 255.0) * 7);
            ascii[i][j] = PIXELS[index];
        }
        ascii[i][width] = '\0';
    }
    return ascii;
}

int main() {
    char* filename = "image.txt";

    // Read the image
    int width, height;
    int** image = read_image(filename, &width, &height);

    // Convert the image to ASCII art
    char** ascii = convert_image(image, width, height);

    // Print the ASCII art
    for (int i = 0; i < height; i++) {
        printf("%s\n", ascii[i]);
    }

    // Free the memory
    for (int i = 0; i < height; i++) {
        free(ascii[i]);
        free(image[i]);
    }
    free(ascii);
    free(image);
    return 0;
}