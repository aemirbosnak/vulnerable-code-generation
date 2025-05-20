//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define WIDTH 800
#define HEIGHT 600

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel pixels[HEIGHT][WIDTH];
} Image;

// Function prototypes
void load_image(const char *filename, Image *img);
void save_image(const char *filename, const Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int adjustment);
void adjust_contrast(Image *img, float factor);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_file> <output_file> <flip (0/1)> <brightness_adjustment> <contrast_factor>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int flip = atoi(argv[3]);
    int brightness_adjustment = atoi(argv[4]);
    float contrast_factor = atof(argv[5]);

    Image img;
    load_image(input_file, &img);

    if (flip) {
        flip_image(&img);
    }

    adjust_brightness(&img, brightness_adjustment);
    adjust_contrast(&img, contrast_factor);

    save_image(output_file, &img);

    printf("Processing complete. Image saved to: %s\n", output_file);
    return EXIT_SUCCESS;
}

void load_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open input file");
        exit(EXIT_FAILURE);
    }
    
    // Here we simulate loading an image. In reality, you should implement actual image loading logic.
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[y][x].r = rand() % 256;
            img->pixels[y][x].g = rand() % 256;
            img->pixels[y][x].b = rand() % 256;
        }
    }

    fclose(file);
}

void save_image(const char *filename, const Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open output file");
        exit(EXIT_FAILURE);
    }

    // Here we simulate saving an image. In reality, you should implement actual image saving logic.
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            fwrite(&img->pixels[y][x], sizeof(Pixel), 1, file);
        }
    }
    
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            Pixel temp = img->pixels[y][x];
            img->pixels[y][x] = img->pixels[y][WIDTH - 1 - x];
            img->pixels[y][WIDTH - 1 - x] = temp;
        }
    }
}

void adjust_brightness(Image *img, int adjustment) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[y][x].r = (img->pixels[y][x].r + adjustment > 255) ? 255 : (img->pixels[y][x].r + adjustment < 0) ? 0 : img->pixels[y][x].r + adjustment;
            img->pixels[y][x].g = (img->pixels[y][x].g + adjustment > 255) ? 255 : (img->pixels[y][x].g + adjustment < 0) ? 0 : img->pixels[y][x].g + adjustment;
            img->pixels[y][x].b = (img->pixels[y][x].b + adjustment > 255) ? 255 : (img->pixels[y][x].b + adjustment < 0) ? 0 : img->pixels[y][x].b + adjustment;
        }
    }
}

void adjust_contrast(Image *img, float factor) {
    float f = (factor + 1); // Example factor for brightness adjustment
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            img->pixels[y][x].r = (img->pixels[y][x].r - 128) * f + 128;
            img->pixels[y][x].g = (img->pixels[y][x].g - 128) * f + 128;
            img->pixels[y][x].b = (img->pixels[y][x].b - 128) * f + 128;

            img->pixels[y][x].r = img->pixels[y][x].r < 0 ? 0 : (img->pixels[y][x].r > 255 ? 255 : img->pixels[y][x].r);
            img->pixels[y][x].g = img->pixels[y][x].g < 0 ? 0 : (img->pixels[y][x].g > 255 ? 255 : img->pixels[y][x].g);
            img->pixels[y][x].b = img->pixels[y][x].b < 0 ? 0 : (img->pixels[y][x].b > 255 ? 255 : img->pixels[y][x].b);
        }
    }
}