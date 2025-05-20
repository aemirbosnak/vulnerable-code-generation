//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} Bitmap;

Bitmap *bitmap_create(int width, int height) {
    Bitmap *bitmap = malloc(sizeof(Bitmap));
    bitmap->width = width;
    bitmap->height = height;
    bitmap->data = malloc(width * height * sizeof(char));
    return bitmap;
}

void bitmap_destroy(Bitmap *bitmap) {
    free(bitmap->data);
    free(bitmap);
}

void bitmap_set_pixel(Bitmap *bitmap, int x, int y, char value) {
    if (x >= 0 && x < bitmap->width && y >= 0 && y < bitmap->height) {
        bitmap->data[y * bitmap->width + x] = value;
    }
}

char bitmap_get_pixel(Bitmap *bitmap, int x, int y) {
    if (x >= 0 && x < bitmap->width && y >= 0 && y < bitmap->height) {
        return bitmap->data[y * bitmap->width + x];
    }
    return 0;
}

void bitmap_save(Bitmap *bitmap, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }
    fprintf(file, "P1\n%d %d\n", bitmap->width, bitmap->height);
    for (int y = 0; y < bitmap->height; y++) {
        for (int x = 0; x < bitmap->width; x++) {
            fputc(bitmap_get_pixel(bitmap, x, y) ? '1' : '0', file);
        }
        fputc('\n', file);
    }
    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s width height filename\n", argv[0]);
        return 1;
    }
    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    char *filename = argv[3];
    Bitmap *bitmap = bitmap_create(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bitmap_set_pixel(bitmap, x, y, rand() % 2);
        }
    }
    bitmap_save(bitmap, filename);
    bitmap_destroy(bitmap);
    return 0;
}