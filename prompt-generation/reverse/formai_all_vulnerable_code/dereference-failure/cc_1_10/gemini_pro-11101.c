//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(fp);
        return NULL;
    }

    // Read header
    fread(&image->width, sizeof(unsigned int), 1, fp);
    fread(&image->height, sizeof(unsigned int), 1, fp);

    // Read data
    image->data = malloc(image->width * image->height);
    if (!image->data) {
        fclose(fp);
        free(image);
        return NULL;
    }
    fread(image->data, 1, image->width * image->height, fp);

    fclose(fp);

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        return;
    }

    // Write header
    fwrite(&image->width, sizeof(unsigned int), 1, fp);
    fwrite(&image->height, sizeof(unsigned int), 1, fp);

    // Write data
    fwrite(image->data, 1, image->width * image->height, fp);

    fclose(fp);
}

void watermark_image(Image *image, const char *watermark) {
    unsigned int watermark_length = strlen(watermark);
    unsigned int watermark_index = 0;

    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            // Get pixel value
            unsigned char pixel = image->data[y * image->width + x];

            // Embed watermark bit
            if (watermark_index < watermark_length) {
                unsigned char bit = (watermark[watermark_index] >> (7 - (x % 8))) & 1;
                pixel = (pixel & ~1) | (bit << 0);
                watermark_index++;
            }

            // Set pixel value
            image->data[y * image->width + x] = pixel;
        }
    }
}

char *extract_watermark(Image *image) {
    unsigned int watermark_length = 0;
    unsigned char watermark[256] = {0};
    unsigned int watermark_index = 0;

    for (unsigned int y = 0; y < image->height; y++) {
        for (unsigned int x = 0; x < image->width; x++) {
            // Get pixel value
            unsigned char pixel = image->data[y * image->width + x];

            // Extract watermark bit
            if (watermark_index < watermark_length) {
                unsigned char bit = pixel & 1;
                watermark[watermark_index] |= (bit << (7 - (x % 8)));
                watermark_index++;
            }
        }
    }

    return strdup(watermark);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        printf("Usage: %s <input image> <watermark> <output image>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        printf("Error loading input image\n");
        return 1;
    }

    watermark_image(image, argv[2]);

    save_image(argv[3], image);

    char *watermark = extract_watermark(image);
    printf("Extracted watermark: %s\n", watermark);

    free(watermark);
    free(image->data);
    free(image);

    return 0;
}