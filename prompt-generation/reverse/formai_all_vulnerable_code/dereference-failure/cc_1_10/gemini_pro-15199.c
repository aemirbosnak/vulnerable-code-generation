//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
    int channels;
} Image;

Image *read_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("Error allocating memory");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    fread(&image->channels, sizeof(int), 1, file);

    image->data = malloc(image->width * image->height * image->channels);
    if (!image->data) {
        perror("Error allocating memory");
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, image->width * image->height * image->channels, 1, file);

    fclose(file);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(&image->channels, sizeof(int), 1, file);
    fwrite(image->data, image->width * image->height * image->channels, 1, file);

    fclose(file);
}

void embed_watermark(Image *image, const char *watermark) {
    int watermark_length = strlen(watermark);
    int watermark_index = 0;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                if (watermark_index < watermark_length) {
                    // Embed watermark bit by modifying the least significant bit of the pixel value
                    int bit = (watermark[watermark_index] >> (7 - watermark_index % 8)) & 1;
                    int mask = (1 << bit) - 1;
                    image->data[(y * image->width + x) * image->channels + c] ^= mask;
                }
            }
        }
    }
}

char *extract_watermark(const Image *image) {
    char *watermark = malloc(image->width * image->height * image->channels / 8 + 1);
    int watermark_length = 0;

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            for (int c = 0; c < image->channels; c++) {
                // Extract watermark bit from the least significant bit of the pixel value
                int bit = image->data[(y * image->width + x) * image->channels + c] & 1;
                watermark[watermark_length] |= (bit << (7 - watermark_length % 8));
                if (watermark_length % 8 == 7) {
                    watermark_length++;
                }
            }
        }
    }

    watermark[watermark_length] = '\0';

    return watermark;
}

int main(int argc, char **argv) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <watermark> <output_image>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Embed watermark in the image
    embed_watermark(image, argv[2]);

    // Write watermarked image to file
    write_image(image, argv[3]);

    // Extract watermark from the image
    char *watermark = extract_watermark(image);
    printf("Extracted watermark: %s\n", watermark);

    free(image->data);
    free(image);
    free(watermark);

    return 0;
}