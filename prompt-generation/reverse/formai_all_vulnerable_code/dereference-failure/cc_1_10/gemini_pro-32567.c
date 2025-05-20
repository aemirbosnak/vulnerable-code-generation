//GEMINI-pro DATASET v1.0 Category: Pixel Art Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} bitmap_t;

bitmap_t *bitmap_create(int width, int height) {
    bitmap_t *bitmap = malloc(sizeof(bitmap_t));
    bitmap->width = width;
    bitmap->height = height;
    bitmap->data = malloc(width * height);
    return bitmap;
}

void bitmap_destroy(bitmap_t *bitmap) {
    free(bitmap->data);
    free(bitmap);
}

void bitmap_set_pixel(bitmap_t *bitmap, int x, int y, char value) {
    if (x < 0 || x >= bitmap->width || y < 0 || y >= bitmap->height) {
        return;
    }
    bitmap->data[y * bitmap->width + x] = value;
}

char bitmap_get_pixel(bitmap_t *bitmap, int x, int y) {
    if (x < 0 || x >= bitmap->width || y < 0 || y >= bitmap->height) {
        return 0;
    }
    return bitmap->data[y * bitmap->width + x];
}

void bitmap_save(bitmap_t *bitmap, const char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }
    fprintf(file, "P1\n%d %d\n", bitmap->width, bitmap->height);
    for (int y = 0; y < bitmap->height; y++) {
        for (int x = 0; x < bitmap->width; x++) {
            fprintf(file, "%d ", bitmap_get_pixel(bitmap, x, y));
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s width height filename\n", argv[0]);
        return 1;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);
    const char *filename = argv[3];

    bitmap_t *bitmap = bitmap_create(width, height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            bitmap_set_pixel(bitmap, x, y, (x + y) % 2);
        }
    }
    bitmap_save(bitmap, filename);
    bitmap_destroy(bitmap);

    return 0;
}