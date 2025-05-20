//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_CHARS "@%#*+=-:. "
#define ASCII_LEN (sizeof(ASCII_CHARS) - 1)

void print_ascii_image(const char *image_path, int width, int height) {
    FILE *fp = fopen(image_path, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Could not open image file.\n");
        exit(EXIT_FAILURE);
    }

    // Read the image file header (for PGM format - P5)
    char magic_number[3];
    int max_value;
    fscanf(fp, "%2s", magic_number);
    if (strcmp(magic_number, "P5") != 0) {
        fprintf(stderr, "Error: Not a valid PGM file.\n");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    fscanf(fp, "%d %d %d", &width, &height, &max_value);
    fgetc(fp); // consume newline

    // Read pixel data
    unsigned char *pixels = malloc(width * height);
    fread(pixels, 1, width * height, fp);
    fclose(fp);

    // Convert pixels to ASCII
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            int pixel_value = pixels[y * width + x]; // Access pixel
            int ascii_index = pixel_value * ASCII_LEN / (max_value + 1); // Calculate ASCII index
            putchar(ASCII_CHARS[ascii_index]);
        }
        putchar('\n'); // New line after each row
    }

    free(pixels);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image.pgm> <width> <height>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *image_path = argv[1];
    int width = atoi(argv[2]);
    int height = atoi(argv[3]);

    printf("Converting image '%s' of size %dx%d to ASCII art...\n", image_path, width, height);
    print_ascii_image(image_path, width, height);

    printf("Conversion done! Enjoy your ASCII art!\n");
    return 0;
}