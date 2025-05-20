//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80 // Width of the ASCII art
#define HEIGHT 60 // Height of the ASCII art
#define CHAR_SET ".:-=+*#@" // Character set used for ASCII art

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    // Load the image file
    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Cannot open image file.\n");
        exit(1);
    }

    // Get the size of the image file
    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    rewind(fp);

    // Allocate memory for the image data
    unsigned char *image_data = (unsigned char *) malloc(file_size);
    if (image_data == NULL) {
        printf("Error: Cannot allocate memory.\n");
        exit(1);
    }

    // Read the image data from the file
    fread(image_data, file_size, 1, fp);
    fclose(fp);

    // Convert the image to ASCII art
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            int value = (int) image_data[(y * WIDTH + x) * 3]; // Get the average value of RGB
            int index = value % 8; // Get the index of the character set
            printf("%c", CHAR_SET[index]);
        }
        printf("\n");
    }

    free(image_data);
    return 0;
}