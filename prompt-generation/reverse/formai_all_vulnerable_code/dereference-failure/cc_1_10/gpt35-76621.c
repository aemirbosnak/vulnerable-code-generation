//FormAI DATASET v1.0 Category: Image Editor ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILE_NAME_LEN 100
#define MAX_PIXEL_VALUE 255

// Function to read the input file and create an image matrix
unsigned char** read_image(char* file_name, int* rows, int* cols) {
    FILE* image_file = fopen(file_name, "rb");

    if (!image_file) {
        printf("Error: Failed to read the file\n");
        return NULL;
    }

    // Read the magic number and number of rows and columns
    char buffer[5];
    fgets(buffer, 5, image_file);
    fgets(buffer, 5, image_file);
    *cols = atoi(strtok(buffer, " "));
    *rows = atoi(strtok(NULL, " "));
    fgets(buffer, 5, image_file);

    // Create the image matrix
    unsigned char** image = (unsigned char**)malloc(*rows * sizeof(unsigned char*));
    for (int i = 0; i < *rows; i++) {
        image[i] = (unsigned char*)malloc(*cols * sizeof(unsigned char));
        fread(image[i], sizeof(unsigned char), *cols, image_file);
    }

    fclose(image_file);
    return image;
}

// Function to write the output file
bool write_image(unsigned char** image, char* file_name, int rows, int cols) {
    FILE* image_file = fopen(file_name, "wb");

    if (!image_file) {
        printf("Error: Failed to create the file\n");
        return false;
    }

    // Write the magic number and number of rows and columns
    fprintf(image_file, "P5\n%d %d\n%d\n", cols, rows, MAX_PIXEL_VALUE);

    // Write the image matrix
    for (int i = 0; i < rows; i++) {
        fwrite(image[i], sizeof(unsigned char), cols, image_file);
    }

    fclose(image_file);
    return true;
}

// Function to invert the colors of the image
void invert_colors(unsigned char** image, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            image[i][j] = MAX_PIXEL_VALUE - image[i][j];
        }
    }
}

// Function to blend two images with equal weight
unsigned char** blend_images(unsigned char** image1, unsigned char** image2, int rows, int cols) {
    unsigned char** blended_image = (unsigned char**)malloc(rows * sizeof(unsigned char*));

    for (int i = 0; i < rows; i++) {
        blended_image[i] = (unsigned char*)malloc(cols * sizeof(unsigned char));

        for (int j = 0; j < cols; j++) {
            blended_image[i][j] = (image1[i][j] + image2[i][j]) / 2;
        }
    }

    return blended_image;
}

int main() {
    char file_name[MAX_FILE_NAME_LEN];
    printf("Enter the name of the image file: ");
    scanf("%s", file_name);

    int rows, cols;
    unsigned char** image = read_image(file_name, &rows, &cols);
    if (!image) {
        return 0;
    }

    // Invert the colors of the image
    invert_colors(image, rows, cols);
    write_image(image, "output_invert.pgm", rows, cols);

    // Blend the image with a copy of itself
    unsigned char** blended_image = blend_images(image, image, rows, cols);
    write_image(blended_image, "output_blend.pgm", rows, cols);

    // Free the memory
    for (int i = 0; i < rows; i++) {
        free(image[i]);
        free(blended_image[i]);
    }
    free(image);
    free(blended_image);

    return 0;
}