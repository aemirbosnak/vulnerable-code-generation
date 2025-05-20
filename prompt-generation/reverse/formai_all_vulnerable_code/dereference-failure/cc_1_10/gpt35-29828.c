//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 60

char ascii_chars[] = {' ', '.', ':', '-', '=', '+', '*', '#', '%', '@'};

int get_intensity(unsigned char *image_data, int x, int y, int width) {
    int intensity = 0;
    int num_channels = 3;

    for (int i = 0; i < num_channels; i++) {
        intensity += image_data[(x + y * width) * num_channels + i];
    }

    return (intensity / num_channels);
}

char get_ascii_char(int intensity) {
    int num_ascii_chars = sizeof(ascii_chars) / sizeof(ascii_chars[0]);

    return ascii_chars[(intensity * num_ascii_chars) / 256];
}

void convert_image_to_ascii(unsigned char *image_data, int width, int height) {
    int current_char;
    char ascii_char;
    int intensity;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            intensity = get_intensity(image_data, x, y, width);
            ascii_char = get_ascii_char(intensity);
            printf("%c", ascii_char);
        }
        printf("\n");
    }
}

int main() {
    unsigned char *image_data = malloc(WIDTH * HEIGHT * 3 * sizeof(unsigned char));
    char file_name[256];
    FILE *file;
    int index = 0;
    int width;
    int height;

    printf("Enter the name of the image file: ");
    scanf("%s", file_name);

    file = fopen(file_name, "rb");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    // Read the image header
    fseek(file, 0x12, SEEK_SET);
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Read the image data
    fseek(file, 54, SEEK_SET);
    fread(image_data, sizeof(unsigned char), WIDTH * HEIGHT * 3, file);

    // Convert the image to ASCII
    convert_image_to_ascii(image_data, WIDTH, HEIGHT);

    // Cleanup
    fclose(file);
    free(image_data);

    return 0;
}