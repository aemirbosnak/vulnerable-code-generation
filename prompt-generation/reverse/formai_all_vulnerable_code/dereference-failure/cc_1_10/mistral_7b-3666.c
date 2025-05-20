//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t blue;
    uint8_t green;
    uint8_t red;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel *data;
} Bitmap;

Bitmap *load_bitmap(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    Bitmap *bitmap = malloc(sizeof(Bitmap));
    if (!bitmap) {
        fclose(fp);
        perror("Error allocating memory");
        return NULL;
    }

    fread(&bitmap->width, sizeof(int), 1, fp);
    fread(&bitmap->height, sizeof(int), 1, fp);

    bitmap->data = malloc(bitmap->width * bitmap->height * sizeof(Pixel));
    if (!bitmap->data) {
        free(bitmap);
        fclose(fp);
        perror("Error allocating memory for data");
        return NULL;
    }

    fread(bitmap->data, sizeof(Pixel), bitmap->width * bitmap->height, fp);
    fclose(fp);

    return bitmap;
}

void generate_irregular_pixel_art(Bitmap *bitmap) {
    for (int y = 0; y < bitmap->height; y++) {
        for (int x = 0; x < bitmap->width; x++) {
            Pixel *pixel = &bitmap->data[y * bitmap->width + x];
            int random_value = rand() % 256;

            pixel->red = random_value;
            pixel->green = random_value + (rand() % 128);
            pixel->blue = random_value + (rand() % 128);

            // Apply some irregularities
            if (x % 3 == 0 && y % 2 == 0) {
                pixel->red += 50;
                pixel->green -= 50;
                pixel->blue += 50;
            }
            if (x % 5 == 0 && y % 3 == 0) {
                pixel->red -= 50;
                pixel->green += 50;
                pixel->blue -= 50;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <bitmap_filename>\n", argv[0]);
        return 1;
    }

    Bitmap *bitmap = load_bitmap(argv[1]);
    if (!bitmap) {
        return 1;
    }

    generate_irregular_pixel_art(bitmap);

    // Save the generated pixel art back to a file
    FILE *fp = fopen("output.bmp", "wb");
    if (!fp) {
        perror("Error opening file for writing");
        free(bitmap->data);
        free(bitmap);
        return 1;
    }

    fwrite(&bitmap->width, sizeof(int), 1, fp);
    fwrite(&bitmap->height, sizeof(int), 1, fp);

    fwrite(bitmap->data, sizeof(Pixel), bitmap->width * bitmap->height, fp);
    fclose(fp);

    free(bitmap->data);
    free(bitmap);

    return 0;
}