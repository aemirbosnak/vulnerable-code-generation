//GPT-4o-mini DATASET v1.0 Category: Image to ASCII art converter ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 60

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

const char *ASCII_CHARS = "@#%*+=-:. "; // Characters used for ASCII representation

Image *load_image(const char *filename);
void free_image(Image *img);
void convert_to_ascii(const Image *img);
char pixel_to_ascii(uint8_t r, uint8_t g, uint8_t b);
void print_ascii(const char *ascii_art);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = load_image(argv[1]);
    if (img == NULL) {
        fprintf(stderr, "Failed to load image %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    convert_to_ascii(img);
    free_image(img);

    return EXIT_SUCCESS;
}

Image *load_image(const char *filename) {
    // Dummy implementation for loading image
    // This function should actually read an image from file
    Image *img = malloc(sizeof(Image));
    img->width = WIDTH;
    img->height = HEIGHT;
    img->data = malloc(img->width * img->height * sizeof(Pixel));

    // Filling with random grayscale pixels as a placeholder
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t)(rand() % 256);
        img->data[i].g = (uint8_t)(rand() % 256);
        img->data[i].b = (uint8_t)(rand() % 256);
    }

    return img;
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

char pixel_to_ascii(uint8_t r, uint8_t g, uint8_t b) {
    // Simple luminance calculation
    uint8_t gray = (uint8_t)(0.299 * r + 0.587 * g + 0.114 * b);
    int index = gray * (strlen(ASCII_CHARS) - 1) / 255;
    return ASCII_CHARS[index];
}

void convert_to_ascii(const Image *img) {
    char ascii_buffer[HEIGHT][WIDTH + 1]; // +1 for null terminator

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            Pixel *pixel = &img->data[y * img->width + x];
            ascii_buffer[y][x] = pixel_to_ascii(pixel->r, pixel->g, pixel->b);
        }
        ascii_buffer[y][img->width] = '\0'; // null-terminate each line
    }

    print_ascii((const char *)ascii_buffer);
}

void print_ascii(const char *ascii_art) {
    for (int y = 0; y < HEIGHT; y++) {
        printf("%s\n", ascii_art[y]);
    }
}