//GPT-4o-mini DATASET v1.0 Category: Digital Watermarking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struct to represent a pixel in an RGB format
typedef struct {
    unsigned char r, g, b;
} Pixel;

// Struct for PPM image
typedef struct {
    char magic[3];
    int width;
    int height;
    int max_color_value;
    Pixel *pixels;
} PPMImage;

// Function to load a PPM image
PPMImage* loadPPMImage(const char *filename) {
    PPMImage *image = malloc(sizeof(PPMImage));
    if (!image) {
        printf("Memory allocation failed.\n");
        return NULL;
    }

    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Failed to open file: %s\n", filename);
        free(image);
        return NULL;
    }
    
    fscanf(file, "%s", image->magic);
    fscanf(file, "%d %d", &image->width, &image->height);
    fscanf(file, "%d", &image->max_color_value);
    
    image->pixels = malloc(sizeof(Pixel) * image->width * image->height);
    fread(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
    
    return image;
}

// Function to save a PPM image
void savePPMImage(const char *filename, PPMImage *image) {
    FILE *file = fopen(filename, "wb");
    fprintf(file, "%s\n%d %d\n%d\n", image->magic, image->width, image->height, image->max_color_value);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to encode watermark into the image
void embedWatermark(PPMImage *image, const char *watermark) {
    int watermark_length = strlen(watermark);
    int index = 0;

    for (int i = 0; i < image->height && index < watermark_length; i++) {
        for (int j = 0; j < image->width && index < watermark_length; j++) {
            // Embed the watermark character into the least significant bit of the red pixel value
            image->pixels[i * image->width + j].r = (image->pixels[i * image->width + j].r & 0xFE) | ((watermark[index] >> (7 - (j % 8))) & 0x01);
            index++;
        }
    }
}

// Function to extract watermark from the image
void extractWatermark(PPMImage *image, char *watermark, int max_length) {
    int index = 0;
    for (int i = 0; i < image->height && index < max_length; i++) {
        for (int j = 0; j < image->width && index < max_length; j++) {
            if (index % 8 == 0) {
                watermark[index / 8] = 0; // Start a new character
            }
            // Retrieve the LSB from the red pixel value
            watermark[index / 8] |= (image->pixels[i * image->width + j].r & 0x01) << (7 - (index % 8));
            index++;
        }
    }
    watermark[index / 8] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input_image.ppm> <watermark> <output_image.ppm>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_image_file = argv[1];
    const char *watermark = argv[2];
    const char *output_image_file = argv[3];

    // Load the input image
    PPMImage *image = loadPPMImage(input_image_file);
    if (!image) return EXIT_FAILURE;

    // Embed the watermark
    embedWatermark(image, watermark);

    // Save the image with the embedded watermark
    savePPMImage(output_image_file, image);
    printf("Watermark embedded successfully!\n");

    // Extract the watermark for verification
    char extracted_watermark[64];
    extractWatermark(image, extracted_watermark, sizeof(extracted_watermark) - 1);
    printf("Extracted Watermark: %s\n", extracted_watermark);

    // Cleanup
    free(image->pixels);
    free(image);

    return EXIT_SUCCESS;
}