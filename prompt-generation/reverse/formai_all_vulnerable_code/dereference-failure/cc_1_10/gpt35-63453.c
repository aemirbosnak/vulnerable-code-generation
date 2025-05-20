//FormAI DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to read an image from a file and return as a 2D array
int** read_image(char* file_name, int* width, int* height) {
    FILE* fp = fopen(file_name, "r");
    if(fp == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        exit(1);
    }

    fscanf(fp, "%d %d", width, height);

    int** image = (int **) malloc(*height * sizeof(int*));
    for(int i=0; i<*height; i++)
        image[i] = (int *) malloc(*width * sizeof(int));

    for(int i=0; i<*height; i++) {
        for(int j=0; j<*width; j++) {
            fscanf(fp, "%d", &image[i][j]);
        }
    }
    fclose(fp);
    return image;
}

// Function to write an image to a file
void write_image(char* file_name, int** image, int width, int height) {
    FILE* fp = fopen(file_name, "w");
    if(fp == NULL) {
        printf("Error: Unable to open file %s\n", file_name);
        exit(1);
    }

    fprintf(fp, "%d %d\n", width, height);

    for(int i=0; i<height; i++) {
        for(int j=0; j<width; j++) {
            if(j == width-1)
                fprintf(fp, "%d", image[i][j]);
            else
                fprintf(fp, "%d ", image[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}

// Function to flip an image horizontally
void flip_horizontal(int** image, int width, int height) {
    for(int i=0; i<height; i++) {
        for(int j=0; j<width/2; j++) {
            int temp = image[i][j];
            image[i][j] = image[i][width-j-1];
            image[i][width-j-1] = temp;
        }
    }
}

// Function to rotate an image 90 degrees clockwise
void rotate_clockwise(int** image, int* width, int* height) {
    int new_width = *height;
    int new_height = *width;

    int** new_image = (int **) malloc(new_height * sizeof(int*));
    for(int i=0; i<new_height; i++)
        new_image[i] = (int *) malloc(new_width * sizeof(int));

    for(int i=0; i<*height; i++) {
        for(int j=0; j<*width; j++) {
            new_image[j][*height-1-i] = image[i][j];
        }
    }

    // Free the old image and replace with the new image
    for(int i=0; i<*height; i++)
        free(image[i]);
    free(image);

    // Update the width and height to the new values
    *width = new_width;
    *height = new_height;

    image = new_image;
}

// Main function
int main() {
    int width, height;
    int** image = read_image("input_image.txt", &width, &height);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Rotate the image 90 degrees clockwise
    rotate_clockwise(image, &width, &height);

    // Write the edited image to a file
    write_image("output_image.txt", image, width, height);

    // Free the memory allocated for the image
    for(int i=0; i<height; i++)
        free(image[i]);
    free(image);

    return 0;
}