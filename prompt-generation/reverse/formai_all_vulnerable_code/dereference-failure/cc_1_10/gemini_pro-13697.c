//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *image;
    int width;
    int height;
} Image;

typedef struct {
    unsigned char *watermark;
    int width;
    int height;
} Watermark;

Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error: could not allocate memory for image\n");
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);
    image->image = malloc(image->width * image->height * sizeof(unsigned char));
    if (!image->image) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        free(image);
        fclose(file);
        return NULL;
    }

    fread(image->image, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

Watermark *load_watermark(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }

    Watermark *watermark = malloc(sizeof(Watermark));
    if (!watermark) {
        fprintf(stderr, "Error: could not allocate memory for watermark\n");
        fclose(file);
        return NULL;
    }

    fread(&watermark->width, sizeof(int), 1, file);
    fread(&watermark->height, sizeof(int), 1, file);
    watermark->watermark = malloc(watermark->width * watermark->height * sizeof(unsigned char));
    if (!watermark->watermark) {
        fprintf(stderr, "Error: could not allocate memory for watermark data\n");
        free(watermark);
        fclose(file);
        return NULL;
    }

    fread(watermark->watermark, sizeof(unsigned char), watermark->width * watermark->height, file);
    fclose(file);

    return watermark;
}

void embed_watermark(Image *image, Watermark *watermark, int x, int y) {
    if (x + watermark->width > image->width || y + watermark->height > image->height) {
        fprintf(stderr, "Error: watermark is too large for image\n");
        return;
    }

    for (int i = 0; i < watermark->height; i++) {
        for (int j = 0; j < watermark->width; j++) {
            image->image[(y + i) * image->width + (x + j)] = (image->image[(y + i) * image->width + (x + j)] & 0xf0) | (watermark->watermark[i * watermark->width + j] & 0x0f);
        }
    }
}

Image *extract_watermark(Image *image, Watermark *watermark, int x, int y) {
    Image *extracted_watermark = malloc(sizeof(Image));
    if (!extracted_watermark) {
        fprintf(stderr, "Error: could not allocate memory for extracted watermark\n");
        return NULL;
    }

    extracted_watermark->width = watermark->width;
    extracted_watermark->height = watermark->height;
    extracted_watermark->image = malloc(extracted_watermark->width * extracted_watermark->height * sizeof(unsigned char));
    if (!extracted_watermark->image) {
        fprintf(stderr, "Error: could not allocate memory for extracted watermark data\n");
        free(extracted_watermark);
        return NULL;
    }

    for (int i = 0; i < watermark->height; i++) {
        for (int j = 0; j < watermark->width; j++) {
            extracted_watermark->image[i * watermark->width + j] = image->image[(y + i) * image->width + (x + j)] & 0x0f;
        }
    }

    return extracted_watermark;
}

void save_image(Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return;
    }

    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);
    fwrite(image->image, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <image> <watermark> <x> <y>\n", argv[0]);
        return 1;
    }

    Image *image = load_image(argv[1]);
    if (!image) {
        return 1;
    }

    Watermark *watermark = load_watermark(argv[2]);
    if (!watermark) {
        free(image);
        return 1;
    }

    int x = atoi(argv[3]);
    int y = atoi(argv[4]);

    embed_watermark(image, watermark, x, y);

    Image *extracted_watermark = extract_watermark(image, watermark, x, y);
    if (!extracted_watermark) {
        free(image);
        free(watermark);
        return 1;
    }

    save_image(extracted_watermark, "extracted_watermark.bmp");

    free(image);
    free(watermark);
    free(extracted_watermark);

    return 0;
}