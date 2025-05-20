//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_SIZE 1000000

typedef struct {
    unsigned char *data;
    unsigned int size;
} Image;

typedef struct {
    unsigned char *watermark;
    unsigned int size;
} Watermark;

// Read an image from a file
Image* read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    assert(fp != NULL);

    Image *image = malloc(sizeof(Image));
    assert(image != NULL);

    fseek(fp, 0, SEEK_END);
    image->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(image->size);
    assert(image->data != NULL);

    fread(image->data, 1, image->size, fp);

    fclose(fp);

    return image;
}

// Write an image to a file
void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    assert(fp != NULL);

    fwrite(image->data, 1, image->size, fp);

    fclose(fp);
}

// Read a watermark from a file
Watermark* read_watermark(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    assert(fp != NULL);

    Watermark *watermark = malloc(sizeof(Watermark));
    assert(watermark != NULL);

    fseek(fp, 0, SEEK_END);
    watermark->size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    watermark->watermark = malloc(watermark->size);
    assert(watermark->watermark != NULL);

    fread(watermark->watermark, 1, watermark->size, fp);

    fclose(fp);

    return watermark;
}

// Write a watermark to a file
void write_watermark(const char *filename, Watermark *watermark) {
    FILE *fp = fopen(filename, "wb");
    assert(fp != NULL);

    fwrite(watermark->watermark, 1, watermark->size, fp);

    fclose(fp);
}

// Embed a watermark in an image
void embed_watermark(Image *image, Watermark *watermark) {
    assert(image->size >= watermark->size);

    for (unsigned int i = 0; i < watermark->size; i++) {
        image->data[i] ^= watermark->watermark[i];
    }
}

// Extract a watermark from an image
void extract_watermark(Image *image, Watermark *watermark) {
    assert(image->size >= watermark->size);

    for (unsigned int i = 0; i < watermark->size; i++) {
        watermark->watermark[i] = image->data[i] ^ watermark->watermark[i];
    }
}

// Compare two watermarks
int compare_watermarks(Watermark *watermark1, Watermark *watermark2) {
    assert(watermark1->size == watermark2->size);

    for (unsigned int i = 0; i < watermark1->size; i++) {
        if (watermark1->watermark[i] != watermark2->watermark[i]) {
            return 0;
        }
    }

    return 1;
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <image> <watermark> <watermarked> <extracted>\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    Watermark *watermark = read_watermark(argv[2]);

    embed_watermark(image, watermark);

    write_image(argv[3], image);

    Image *watermarked_image = read_image(argv[3]);
    Watermark *extracted_watermark = malloc(sizeof(Watermark));
    extracted_watermark->size = watermark->size;
    extracted_watermark->watermark = malloc(watermark->size);

    extract_watermark(watermarked_image, extracted_watermark);

    int match = compare_watermarks(watermark, extracted_watermark);

    if (match) {
        printf("Watermark successfully extracted.\n");
    } else {
        printf("Watermark not found.\n");
    }

    free(image->data);
    free(image);
    free(watermark->watermark);
    free(watermark);
    free(watermarked_image->data);
    free(watermarked_image);
    free(extracted_watermark->watermark);
    free(extracted_watermark);

    return 0;
}