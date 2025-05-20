//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define MAX_FILENAME 100
#define WATERMARK_SIZE 64

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    uint32_t width, height;
    Pixel *pixels;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, const Image *image);
void embed_watermark(Image *image, const char *watermark);
void extract_watermark(const Image *image, char *watermark);
void free_image(Image *image);

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input_image> <watermark> <output_image>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_image_filename = argv[1];
    const char *watermark = argv[2];
    const char *output_image_filename = argv[3];

    Image *image = load_image(input_image_filename);
    if (!image) {
        fprintf(stderr, "Error loading image %s\n", input_image_filename);
        return EXIT_FAILURE;
    }

    embed_watermark(image, watermark);
    save_image(output_image_filename, image);

    char extracted_watermark[WATERMARK_SIZE + 1] = {0};
    extract_watermark(image, extracted_watermark);
    printf("Extracted Watermark: %s\n", extracted_watermark);

    free_image(image);
    return EXIT_SUCCESS;
}

Image* load_image(const char *filename) {
    // Dummy function to create a simple image
    // Here we would normally load an image file into a Pixel array
    
    Image *img = malloc(sizeof(Image));
    if (!img) return NULL;

    img->width = 100; // Example width
    img->height = 100; // Example height
    img->pixels = malloc(img->width * img->height * sizeof(Pixel));
    
    // Fill image with some color data
    for (uint32_t i = 0; i < img->width * img->height; ++i) {
        img->pixels[i].r = 255;
        img->pixels[i].g = 255;
        img->pixels[i].b = 255; // Create a white image
    }
    
    return img;
}

void save_image(const char *filename, const Image *image) {
    // Dummy function to save an image
    // Here we would normally write the Pixel data back to an image file

    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error saving image %s\n", filename);
        return;
    }
    
    // Write image data (dummy)
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void embed_watermark(Image *image, const char *watermark) {
    size_t watermark_length = strlen(watermark);
    if (watermark_length > WATERMARK_SIZE) {
        fprintf(stderr, "Watermark too large. Max size is %d characters\n", WATERMARK_SIZE);
        return;
    }

    for (size_t i = 0; i < watermark_length; ++i) {
        for (int j = 0; j < 8; ++j) {
            if ((watermark[i] >> (7 - j)) & 1) {
                image->pixels[i * 8 + j].r |= 1; // Embed in red channel
            } else {
                image->pixels[i * 8 + j].r &= ~1; // Clear the LSB
            }
        }
    }
}

void extract_watermark(const Image *image, char *watermark) {
    for (size_t i = 0; i < WATERMARK_SIZE; ++i) {
        watermark[i] = 0;
        for (int j = 0; j < 8; ++j) {
            watermark[i] <<= 1;
            watermark[i] |= (image->pixels[i * 8 + j].r & 1);
        }
    }
    watermark[WATERMARK_SIZE] = '\0'; // Null terminate the string
}

void free_image(Image *image) {
    free(image->pixels);
    free(image);
}