//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 60

/* This function converts a pixel value (grayscale) to a character */
char pixel_to_char(uint8_t pixel) {
    char characters[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};
    int num_chars = sizeof(characters) / sizeof(characters[0]);
    int index = pixel * num_chars / 256;
    return characters[index];
}

/* This function reads a grayscale PGM image file and returns the image data */
uint8_t* read_image(char* filename, int* width, int* height) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        return NULL;
    }

    char header[64];
    fgets(header, sizeof(header), file);
    if (header[0] != 'P' || header[1] != '5') {
        printf("Error: not a valid PGM file\n");
        fclose(file);
        return NULL;
    }

    int max_val;
    fscanf(file, "%d %d %d\n", width, height, &max_val);
    if (max_val > 255) {
        printf("Error: image has more than 8 bits per pixel\n");
        fclose(file);
        return NULL;
    }

    uint8_t* image = (uint8_t*) malloc((*width) * (*height) * sizeof(uint8_t));
    fread(image, sizeof(char), (*width) * (*height), file);
    fclose(file);

    return image;
}

/* This function prints the ASCII art representation of an image */
void print_ascii(uint8_t* image, int width, int height) {
    int new_width = width * 2;
    int new_height = height;

    /* Ensure that the output width and height are within the maximum limits */
    if (new_width > MAX_WIDTH) {
        new_height = new_height * MAX_WIDTH / new_width;
        new_width = MAX_WIDTH;
    }
    if (new_height > MAX_HEIGHT) {
        new_width = new_width * MAX_HEIGHT / new_height;
        new_height = MAX_HEIGHT;
    }

    /* Create a new image with the correct aspect ratio */
    uint8_t* new_image = (uint8_t*) malloc(new_width * new_height * sizeof(uint8_t));
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            int old_x = x * width / new_width;
            int old_y = y * height / new_height;
            new_image[x + y * new_width] = image[old_x + old_y * width];
        }
    }

    /* Print the ASCII art */
    for (int y = 0; y < new_height; y++) {
        for (int x = 0; x < new_width; x++) {
            uint8_t pixel = new_image[x + y * new_width];
            char ascii_char = pixel_to_char(pixel);
            putchar(ascii_char);
            putchar(ascii_char);
        }
        putchar('\n');
    }

    /* Free the memory */
    free(new_image);
}

int main(int argc, char* argv[]) {
    /* Check the command line arguments */
    if (argc != 2) {
        printf("Usage: %s <image file>\n", argv[0]);
        return 1;
    }

    /* Read the image data */
    int width, height;
    uint8_t* image = read_image(argv[1], &width, &height);
    if (image == NULL) {
        return 1;
    }

    /* Print the ASCII art */
    print_ascii(image, width, height);

    /* Free the memory */
    free(image);

    return 0;
}