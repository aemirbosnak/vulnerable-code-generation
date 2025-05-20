//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_VALUE 255
#define MIN_VALUE 0

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel* pixels;
} Image;

// Function to load BMP image
Image load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    // BMP Header
    fseek(file, 18, SEEK_SET);
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    fseek(file, 54, SEEK_SET); // Move to pixel array
    Pixel* pixels = (Pixel*)malloc(width * height * sizeof(Pixel));

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fread(&pixels[i * width + j], sizeof(Pixel), 1, file);
        }
    }

    fclose(file);
    return (Image){width, height, pixels};
}

// Function to flip the image vertically
void flip_image(Image* img) {
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            Pixel temp = img->pixels[i * img->width + j];
            img->pixels[i * img->width + j] = img->pixels[(img->height - i - 1) * img->width + j];
            img->pixels[(img->height - i - 1) * img->width + j] = temp;
        }
    }
}

// Function to change brightness of the image
void change_brightness(Image* img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = img->pixels[i].r + value;
        int g = img->pixels[i].g + value;
        int b = img->pixels[i].b + value;

        img->pixels[i].r = r < MIN_VALUE ? MIN_VALUE : (r > MAX_VALUE ? MAX_VALUE : r);
        img->pixels[i].g = g < MIN_VALUE ? MIN_VALUE : (g > MAX_VALUE ? MAX_VALUE : g);
        img->pixels[i].b = b < MIN_VALUE ? MIN_VALUE : (b > MAX_VALUE ? MAX_VALUE : b);
    }
}

// Function to change contrast of the image
void change_contrast(Image* img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        int r = (int)(factor * (img->pixels[i].r - 128) + 128);
        int g = (int)(factor * (img->pixels[i].g - 128) + 128);
        int b = (int)(factor * (img->pixels[i].b - 128) + 128);

        img->pixels[i].r = r < MIN_VALUE ? MIN_VALUE : (r > MAX_VALUE ? MAX_VALUE : r);
        img->pixels[i].g = g < MIN_VALUE ? MIN_VALUE : (g > MAX_VALUE ? MAX_VALUE : g);
        img->pixels[i].b = b < MIN_VALUE ? MIN_VALUE : (b > MAX_VALUE ? MAX_VALUE : b);
    }
}

// Function to save BMP image
void save_image(const char* filename, const Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Error saving file");
        exit(EXIT_FAILURE);
    }

    // BMP Header
    fputs("BM", file);
    int filesize = 54 + 3 * img->width * img->height;
    fwrite(&filesize, sizeof(int), 1, file);
    fwrite("\0\0\0\0", 4, 1, file); // Reserved fields
    int offset = 54;
    fwrite(&offset, sizeof(int), 1, file);
    
    int info_header_size = 40;
    fwrite(&info_header_size, sizeof(int), 1, file);
    fwrite(&img->width, sizeof(int), 1, file);
    fwrite(&img->height, sizeof(int), 1, file);
    short planes = 1;
    fwrite(&planes, sizeof(short), 1, file);
    short bpp = 24;
    fwrite(&bpp, sizeof(short), 1, file);
    fwrite("\0\0\0\0", 4, 1, file); // Compression
    fwrite("\0\0\0\0", 4, 1, file); // Image size (invalid for uncompressed)
    fwrite("\0\0\0\0", 4, 1, file); // H resolution
    fwrite("\0\0\0\0", 4, 1, file); // V resolution
    fwrite("\0\0\0\0", 4, 1, file); // Palette size
    fwrite("\0\0\0\0", 4, 1, file); // Important colors

    // Writing pixel data
    for (int i = 0; i < img->height; i++) {
        for (int j = 0; j < img->width; j++) {
            fwrite(&img->pixels[i * img->width + j], sizeof(Pixel), 1, file);
        }
    }

    fclose(file);
}

void free_image(Image* img) {
    free(img->pixels);
    img->pixels = NULL;
}

// Main function
int main(int argc, char* argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp> <brightness_change> <contrast_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image img = load_image(argv[1]);
    int brightness_change = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);

    printf("Darkness is creeping over our skies now...\n");
    printf("Flipping the image over, revealing forgotten truths...\n");
    flip_image(&img);

    printf("Adjusting brightness, illuminating the shadows...\n");
    change_brightness(&img, brightness_change);

    printf("Shaping the contrast... As the remnants of color fight for existence...\n");
    change_contrast(&img, contrast_factor);

    save_image(argv[2], &img);
    printf("The image has been saved, a glimpse of a world fading away...\n");

    free_image(&img);
    return EXIT_SUCCESS;
}