//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

// Function to convert image to ASCII art
void image_to_ascii(char* image_data, int image_size, char** ascii_art) {
    int i, j;
    int num_pixels = image_size / 3; // Each pixel is represented by 3 bytes (RGB)
    int max_value = 0;
    int min_value = 255;

    // Find the minimum and maximum values in the image data
    for (i = 0; i < num_pixels; i++) {
        int value = (image_data[i*3] + image_data[i*3+1] + image_data[i*3+2]) / 3;
        if (value < min_value) {
            min_value = value;
        }
        if (value > max_value) {
            max_value = value;
        }
    }

    // Calculate the ASCII character for each pixel
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int pixel_value = (i * num_pixels + j) * 3;
            int r = image_data[pixel_value] / 255.0;
            int g = image_data[pixel_value+1] / 255.0;
            int b = image_data[pixel_value+2] / 255.0;
            int ascii_value = (int) round(255 * (r + g + b) / 3.0);
            if (ascii_value < 0) {
                ascii_value = 0;
            } else if (ascii_value > 126) {
                ascii_value = 126;
            }
            ascii_art[i][j] = ascii_value;
        }
    }
}

int main() {
    FILE* image_file = fopen("image.bmp", "rb");
    if (image_file == NULL) {
        printf("Error: Could not open image file.\n");
        exit(1);
    }

    fseek(image_file, 0, SEEK_END);
    int image_size = ftell(image_file);
    fseek(image_file, 0, SEEK_SET);

    char* image_data = malloc(image_size);
    fread(image_data, image_size, 1, image_file);
    fclose(image_file);

    char ascii_art[HEIGHT][WIDTH];
    image_to_ascii(image_data, image_size, ascii_art);

    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", ascii_art[i][j]);
        }
        printf("\n");
    }

    free(image_data);
    return 0;
}