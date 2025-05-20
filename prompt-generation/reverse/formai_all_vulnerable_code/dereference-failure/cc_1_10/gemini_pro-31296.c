//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 1024

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (image == NULL) {
        fprintf(stderr, "Error allocating memory for image\n");
        fclose(fp);
        return NULL;
    }

    // Read the header information
    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height);
    if (image->data == NULL) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        fclose(fp);
        return NULL;
    }

    // Read the image data
    fread(image->data, image->width * image->height, 1, fp);

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Write the header information
    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);

    // Write the image data
    fwrite(image->data, image->width * image->height, 1, fp);

    fclose(fp);
}

void embed_watermark(Image *image, const char *watermark) {
    int i, j, k;
    int watermark_length = strlen(watermark);

    for (i = 0; i < watermark_length; i++) {
        for (j = 0; j < 8; j++) {
            // Get the bit value
            int bit = (watermark[i] >> j) & 1;

            // Embed the bit in the image data
            int pixel_index = i * 8 + j;
            image->data[pixel_index] = (image->data[pixel_index] & ~1) | bit;
        }
    }
}

char *extract_watermark(const Image *image) {
    int i, j, k;
    int watermark_length = (image->width * image->height) / 8;
    char *watermark = malloc(watermark_length + 1);
    if (watermark == NULL) {
        fprintf(stderr, "Error allocating memory for watermark\n");
        return NULL;
    }

    for (i = 0; i < watermark_length; i++) {
        for (j = 0; j < 8; j++) {
            // Get the bit value
            int bit = image->data[i * 8 + j] & 1;

            // Add the bit to the watermark
            watermark[i] |= (bit << j);
        }
    }

    watermark[watermark_length] = '\0';

    return watermark;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <image file> <watermark>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Read the image
    Image *image = read_image(argv[1]);
    if (image == NULL) {
        return EXIT_FAILURE;
    }

    // Embed the watermark in the image
    embed_watermark(image, argv[2]);

    // Save the watermarked image
    write_image(image, "watermarked.bmp");

    // Extract the watermark from the image
    char *watermark = extract_watermark(image);
    if (watermark == NULL) {
        return EXIT_FAILURE;
    }

    // Print the extracted watermark
    printf("Extracted watermark: %s\n", watermark);

    // Free the memory
    free(image->data);
    free(image);
    free(watermark);

    return EXIT_SUCCESS;
}