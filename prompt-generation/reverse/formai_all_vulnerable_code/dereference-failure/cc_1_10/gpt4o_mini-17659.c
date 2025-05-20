//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>

#define MAX_CHARS 256
#define MAX_WIDTH 1000
#define MAX_HEIGHT 1000

typedef struct {
    uint8_t r, g, b;
} RGB;

typedef struct {
    RGB *data;
    int width;
    int height;
} Image;

const char* ASCII_CHARS = "@%#*+=-:. "; // Characters from dark to light

Image* loadPPM(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s: %s\n", filename, strerror(errno));
        return NULL;
    }
    
    char format[3];
    int width, height, maxval;

    fscanf(file, "%2s", format);
    if (strcmp(format, "P6") != 0) {
        fprintf(stderr, "Error: Unsupported image format: %s\n", format);
        fclose(file);
        return NULL;
    }

    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // consume the newline

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(RGB));

    fread(img->data, sizeof(RGB), width * height, file);
    fclose(file);
    
    return img;
}

void freeImage(Image* img) {
    free(img->data);
    free(img);
}

char convertToAscii(RGB pixel) {
    // Calculate brightness using luminosity method
    float brightness = 0.2126f * pixel.r + 0.7152f * pixel.g + 0.0722f * pixel.b;
    int index = (int)(brightness / 255.0f * (strlen(ASCII_CHARS) - 1));
    return ASCII_CHARS[index];
}

void printAsciiImage(Image* img, int newWidth) {
    int newHeight = (newWidth * img->height) / img->width;
    float x_ratio = img->width / (float)newWidth;
    float y_ratio = img->height / (float)newHeight;

    for (int y = 0; y < newHeight; y++) {
        for (int x = 0; x < newWidth; x++) {
            int srcX = (int)(x * x_ratio);
            int srcY = (int)(y * y_ratio);
            RGB pixel = img->data[srcY * img->width + srcX];
            putchar(convertToAscii(pixel));
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image* img = loadPPM(argv[1]);
    if (!img) {
        return EXIT_FAILURE;
    }

    int newWidth = 80; // Set your desired width here
    printAsciiImage(img, newWidth);

    freeImage(img);
    return EXIT_SUCCESS;
}