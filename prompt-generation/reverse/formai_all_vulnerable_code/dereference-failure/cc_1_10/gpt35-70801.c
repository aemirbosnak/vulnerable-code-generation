//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

// Function to convert an image to ASCII art
void img_to_ascii(char *img_path) {
    // Open the Image file
    FILE *img_file = fopen(img_path, "rb");

    if (!img_file) {
        printf("ERROR: Could not open file '%s'\n", img_path);
        return;
    }

    // Allocate memory to store the image data
    unsigned char *image_data = (unsigned char*)malloc(WIDTH * HEIGHT * 3);

    // Read the image data into the memory
    fread(image_data, 1, WIDTH * HEIGHT * 3, img_file);

    // Close the image file
    fclose(img_file);

    // Calculate the brightness value of each pixel and convert it to ASCII character
    char ascii_art[WIDTH * HEIGHT];
    int k = 0;
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            int index = (i * WIDTH + j) * 3;
            int brightness = (int)(0.299 * image_data[index] + 0.587 * image_data[index + 1] + 0.114 * image_data[index + 2]);
            ascii_art[k++] = ((brightness >= 230) ? ' ' : ((brightness >= 200) ? '-' : ((brightness >= 180) ? '=' : ((brightness >= 160) ? '+' : ((brightness >= 130) ? '*' : ((brightness >= 100) ? '#' : 'M'))))));
        }
        ascii_art[k++] = '\n';
    }

    // Print the ASCII art
    printf("%s\n", ascii_art);

    // Free the memory
    free(image_data);
}

// Main function
int main() {
    char *img_path = "image.jpg";

    img_to_ascii(img_path);

    return 0;
}