//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} pixel_t;

typedef struct {
    pixel_t *pixels;
    uint32_t width;
    uint32_t height;
} image_t;

// This function allocates memory for a new image
void init_image(image_t *img, uint32_t width, uint32_t height) {
    img->pixels = (pixel_t*) malloc(sizeof(pixel_t) * width * height);
    img->width = width;
    img->height = height;
}

// This function loads an image from a file
int load_image(image_t *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return -1;
    }

    uint32_t width, height;
    fread(&width, sizeof(uint32_t), 1, fp);
    fread(&height, sizeof(uint32_t), 1, fp);
    init_image(img, width, height);

    fread(img->pixels, sizeof(pixel_t), width * height, fp);
    fclose(fp);

    return 0;
}

// This function saves an image to a file
int save_image(const image_t *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return -1;
    }

    fwrite(&img->width, sizeof(uint32_t), 1, fp);
    fwrite(&img->height, sizeof(uint32_t), 1, fp);
    fwrite(img->pixels, sizeof(pixel_t), img->width * img->height, fp);
    fclose(fp);

    return 0;
}

// This function flips the image horizontally
void flip_image(image_t *img) {
    pixel_t temp;
    for (uint32_t y = 0; y < img->height; y++) {
        for (uint32_t x = 0; x < img->width / 2; x++) {
            temp = img->pixels[y * img->width + x];
            img->pixels[y * img->width + x] = img->pixels[y * img->width + img->width - x - 1];
            img->pixels[y * img->width + img->width - x - 1] = temp;
        }
    }
}

// This function adjusts the brightness and contrast of the image
void adjust_brightness_contrast(image_t *img, int16_t brightness, int16_t contrast) {
    for (uint32_t i = 0; i < img->width * img->height; i++) {
        int16_t r = img->pixels[i].r + brightness;
        int16_t g = img->pixels[i].g + brightness;
        int16_t b = img->pixels[i].b + brightness;

        r = (r * (contrast + 255)) / 255 - contrast;
        g = (g * (contrast + 255)) / 255 - contrast;
        b = (b * (contrast + 255)) / 255 - contrast;

        img->pixels[i].r = (uint8_t) (r < 0 ? 0 : (r > 255 ? 255 : r));
        img->pixels[i].g = (uint8_t) (g < 0 ? 0 : (g > 255 ? 255 : g));
        img->pixels[i].b = (uint8_t) (b < 0 ? 0 : (b > 255 ? 255 : b));
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <input> [<output>]\n", argv[0]);
        return 0;
    }

    image_t img;
    if (load_image(&img, argv[1]) != 0) {
        printf("Error: Could not load %s\n", argv[1]);
        return 0;
    }

    flip_image(&img);
    adjust_brightness_contrast(&img, 10, 50);

    if (argc == 2) {
        printf("Saving output to output.img...\n");
        save_image(&img, "output.img");
    } else {
        save_image(&img, argv[2]);
    }

    free(img.pixels);
    return 0;
}