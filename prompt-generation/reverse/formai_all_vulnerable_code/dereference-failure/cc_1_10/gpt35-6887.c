//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define custom image size
#define WIDTH 50
#define HEIGHT 50

// Function to load image from file
void load_image(char *filename, int **image) {
    FILE *fp;
    fp = fopen(filename, "rb");
    if(fp == NULL) {
        printf("Error: could not open file.");
        exit(1);
    }
    unsigned char buffer[WIDTH];
    int row, col;
    for(row = 0; row < HEIGHT; ++row) {
        fread(buffer, sizeof(unsigned char), WIDTH, fp);
        for(col = 0; col < WIDTH; ++col) {
            image[row][col] = buffer[col];
        }
    }
    fclose(fp);
}

// Function to convert image to ASCII art
void convert_to_ASCII(int **image, char **output) {
    int row, col;
    for(row = 0; row < HEIGHT; ++row) {
        for(col = 0; col < WIDTH; ++col) {
            int pixel_value = image[row][col];
            if(pixel_value < 50) {
                output[row][col] = '#';
            } else if(pixel_value < 100) {
                output[row][col] = '&';
            } else if(pixel_value < 150) {
                output[row][col] = '$';
            } else if(pixel_value < 200) {
                output[row][col] = '*';
            } else {
                output[row][col] = ' ';
            }
        }
    }
}

int main() {
    int **image;
    image = (int **) malloc(HEIGHT * sizeof(int *));
    int row;
    for(row = 0; row < HEIGHT; ++row) {
        image[row] = (int *) malloc(WIDTH * sizeof(int));
    }

    char **output;
    output = (char **) malloc(HEIGHT * sizeof(char *));
    for(row = 0; row < HEIGHT; ++row) {
        output[row] = (char *) malloc(WIDTH * sizeof(char));
    }

    printf("Enter image filename: ");
    char filename[100];
    scanf("%s", filename);

    load_image(filename, image);
    convert_to_ASCII(image, output);

    printf("ASCII art representation of %s:\n\n", filename);
    for(row = 0; row < HEIGHT; ++row) {
        printf("%s\n", output[row]);
    }

    for(row = 0; row < HEIGHT; ++row) {
        free(image[row]);
        free(output[row]);
    }
    free(image);
    free(output);

    return 0;
}