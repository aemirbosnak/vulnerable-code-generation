//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 40
#define MAX_PIXEL_VALUE 255

// Function to load image data from a file
void load_image_data(const char *filename, unsigned char *image_data, int size) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open image file");
        exit(EXIT_FAILURE);
    }
    fread(image_data, sizeof(unsigned char), size, file);
    fclose(file);
}

// Function to convert the pixel value to ASCII character
char pixel_to_ascii(unsigned char value) {
    char ascii_chars[] = " .,:;ox%#@";
    int num_chars = strlen(ascii_chars);
    int index = (int)(((float)value / MAX_PIXEL_VALUE) * num_chars);
    if (index >= num_chars) {
        index = num_chars - 1;
    }
    return ascii_chars[index];
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Load image data from file
    int image_size = WIDTH * HEIGHT;
    unsigned char *image_data = malloc(image_size);
    if (!image_data) {
        perror("Unable to allocate memory");
        exit(EXIT_FAILURE);
    }
    load_image_data(argv[1], image_data, image_size);

    // Convert image data to ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            unsigned char value = image_data[y * WIDTH + x];
            char ascii_char = pixel_to_ascii(value);
            printf("%c", ascii_char);
        }
        printf("\n");
    }

    free(image_data);
    exit(EXIT_SUCCESS);
}