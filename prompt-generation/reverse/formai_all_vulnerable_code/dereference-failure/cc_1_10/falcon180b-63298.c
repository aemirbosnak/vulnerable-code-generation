//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

// Function to print the ASCII art
void print_ascii_art(char *ascii_art) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH && ascii_art[i * WIDTH + j]!= '\0'; j++) {
            printf("%c", ascii_art[i * WIDTH + j]);
        }
        printf("\n");
    }
}

int main() {
    // Read the image file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    // Get the size of the image
    int width, height;
    fseek(fp, 18, SEEK_SET);
    fread(&width, sizeof(int), 1, fp);
    fread(&height, sizeof(int), 1, fp);

    // Allocate memory for the ASCII art
    char *ascii_art = (char *)malloc(height * width);
    if (ascii_art == NULL) {
        printf("Error: Could not allocate memory for ASCII art.\n");
        exit(1);
    }

    // Convert the image to ASCII art
    int x, y;
    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            int pixel = 0;
            fseek(fp, 54 + y * width + x, SEEK_SET);
            fread(&pixel, sizeof(int), 1, fp);
            ascii_art[y * width + x] = pixel % 10 + '0';
        }
    }

    // Print the ASCII art
    print_ascii_art(ascii_art);

    // Free the memory
    free(ascii_art);

    // Close the image file
    fclose(fp);

    return 0;
}