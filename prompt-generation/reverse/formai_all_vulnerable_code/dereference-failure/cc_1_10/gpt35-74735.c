//FormAI DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 80

char *ASCII_CHARS = " .:-=+*#%@";

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Please specify an image file.\n");
        return 1;
    }

    char *filename = argv[1];
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Unable to open file.\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    int file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *image_data = malloc(file_size);
    fread(image_data, file_size, 1, file);
    fclose(file);

    int image_width = (image_data[18] << 8) + image_data[19];
    int image_height = (image_data[22] << 8) + image_data[23];
    unsigned char *image_pixels = image_data + (image_data[10] << 8) + image_data[11];

    char ascii_image[MAX_HEIGHT][MAX_WIDTH];
    memset(ascii_image, '\0', sizeof(ascii_image));

    double brightness[MAX_HEIGHT][MAX_WIDTH];
    memset(brightness, 0, sizeof(brightness));

    double max_brightness = 0;
    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            int pixel_index = (i * image_width + j) * 3;
            int r = image_pixels[pixel_index];
            int g = image_pixels[pixel_index + 1];
            int b = image_pixels[pixel_index + 2];
            brightness[i][j] = sqrt(0.299 * r * r + 0.587 * g * g + 0.114 * b * b);
            if (brightness[i][j] > max_brightness) {
                max_brightness = brightness[i][j];
            }
        }
    }

    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            int brightness_index = (int)floor((brightness[i][j] / max_brightness) * (strlen(ASCII_CHARS) - 1));
            ascii_image[i][j] = ASCII_CHARS[brightness_index];
        }
    }

    for (int i = 0; i < image_height; i++) {
        for (int j = 0; j < image_width; j++) {
            printf("%c", ascii_image[i][j]);
        }
        printf("\n");
    }

    free(image_data);

    return 0;
}