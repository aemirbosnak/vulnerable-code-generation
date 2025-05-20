//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100
#define MAX_PIXELS 100000

// Function to read image file
void read_image(char *filename, int **pixels, int *width, int *height) {
    FILE *fp;
    int i, j;

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: File not found.\n");
        exit(1);
    }

    fseek(fp, 18, SEEK_SET); // Skip header
    fread(&*width, sizeof(int), 1, fp);
    fread(&*height, sizeof(int), 1, fp);

    if (*width <= 0 || *height <= 0) {
        printf("Error: Invalid image dimensions.\n");
        exit(1);
    }

    *pixels = (int *)malloc(*width * *height * sizeof(int));
    for (i = 0; i < *height; i++) {
        for (j = 0; j < *width; j++) {
            fread(&(*pixels)[i * *width + j], sizeof(int), 1, fp);
        }
    }

    fclose(fp);
}

// Function to print ASCII art
void print_ascii_art(int *pixels, int width, int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            printf("%c", pixels[i * width + j] < 128? pixels[i * width + j] : '.');
        }
        printf("\n");
    }
}

// Main function
int main(int argc, char *argv[]) {
    int *pixels;
    int width, height;

    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    read_image(argv[1], &pixels, &width, &height);
    print_ascii_art(pixels, width, height);

    free(pixels);

    return 0;
}