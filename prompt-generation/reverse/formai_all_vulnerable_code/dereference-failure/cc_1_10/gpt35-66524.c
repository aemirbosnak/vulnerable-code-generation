//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 120
#define MAX_HEIGHT 60

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_path>\n", argv[0]);
        return 1;
    }

    char *image_path = argv[1];
    FILE *file = fopen(image_path, "rb");

    if (!file) {
        printf("Error: Could not open file\n");
        return 1;
    }

    // Get the file size
    fseek(file, 0L, SEEK_END);
    long int file_size = ftell(file);
    fseek(file, 0L, SEEK_SET);

    // Allocate memory for the image buffer
    char *image_buffer = malloc(sizeof(char) * file_size);

    if (!image_buffer) {
        printf("Error: Could not allocate memory\n");
        return 1;
    }

    // Read the image into the buffer
    fread(image_buffer, sizeof(char), file_size, file);
    fclose(file);

    // Parse the header to get the dimensions
    char *dimensions_str = strtok(image_buffer, "\n"); // format: "WIDTH HEIGHT"
    int width = atoi(strtok(dimensions_str, " "));
    int height = atoi(strtok(NULL, " "));

    if (width > MAX_WIDTH || height > MAX_HEIGHT) {
        printf("Error: Image is too large\n");
        return 1;
    }

    // Calculate the size of the pixel array
    int pixels_size = width * height;
    unsigned char *pixels = malloc(sizeof(unsigned char) * pixels_size);

    if (!pixels) {
        printf("Error: Could not allocate memory\n");
        return 1;
    }

    // Copy the pixel data to the new array
    memcpy(pixels, image_buffer + (strlen(dimensions_str) + 1), pixels_size);

    // Convert the pixels to ASCII art
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int i = (y * width) + x;
            int intensity = (int)(pixels[i] / 255.0 * 9.0);
            printf("%c", ascii_chars[intensity]);
        }
        printf("\n");
    }

    free(image_buffer);
    free(pixels);

    return 0;
}