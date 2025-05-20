//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 100
#define HEIGHT 50
#define ASCII_CHARS " .:-=+*%@#"

void grayscale(float r, float g, float b, float *gray) {
    *gray = 0.299 * r + 0.587 * g + 0.114 * b;
}

char get_ascii_char(float gray) {
    int index = (int)(gray / 255.0 * (strlen(ASCII_CHARS) - 1));
    return ASCII_CHARS[index];
}

void convert_image_to_ascii(const char *filename) {
    FILE *file;
    unsigned char *image_data;
    int width, height;

    // Read the PPM image file
    if ((file = fopen(filename, "rb")) == NULL) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return;
    }

    // Read header
    char header[3];
    fscanf(file, "%s %d %d %*d", header, &width, &height);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Invalid PPM file format\n");
        fclose(file);
        return;
    }

    // Allocate memory for image data
    image_data = (unsigned char *)malloc(width * height * 3);
    fread(image_data, sizeof(unsigned char), width * height * 3, file);
    fclose(file);

    // Prepare ASCII art representation
    char ascii_art[HEIGHT][WIDTH + 1];

    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int pixel_x = x * width / WIDTH;
            int pixel_y = y * height / HEIGHT;
            int pixel_index = (pixel_y * width + pixel_x) * 3;

            // Get RGB values
            float r = image_data[pixel_index];
            float g = image_data[pixel_index + 1];
            float b = image_data[pixel_index + 2];
            
            // Convert to grayscale
            float gray;
            grayscale(r, g, b, &gray);
            
            // Map to ASCII character
            ascii_art[y][x] = get_ascii_char(gray);
        }
        ascii_art[y][WIDTH] = '\0';  // Null-terminate the string
    }

    // Free image data
    free(image_data);

    // Print ASCII art
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", ascii_art[y]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return 1;
    }

    convert_image_to_ascii(argv[1]);
    return 0;
}