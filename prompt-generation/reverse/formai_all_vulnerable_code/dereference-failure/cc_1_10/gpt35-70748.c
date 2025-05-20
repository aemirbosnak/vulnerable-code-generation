//FormAI DATASET v1.0 Category: Image Editor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH  1920
#define HEIGHT 1080
#define MAX_COLOR 255
#define SUCCESS 0
#define FAILURE -1

typedef struct {
    unsigned char r, g, b;
} pixel_t;

typedef struct {
    pixel_t *pixels;
    size_t width;
    size_t height;
} bitmap_t;

const char* FILE_NAME = "input.bmp";

int load_bmp(bitmap_t *bitmap, const char* filename) {
    size_t size;
    unsigned char* data;
    FILE* file = fopen(filename, "rb");
    if(file == NULL) return FAILURE;
    if(fread(&bitmap->width, sizeof(bitmap->width), 1, file) != 1) return FAILURE;
    if(fread(&bitmap->height, sizeof(bitmap->height), 1, file) != 1) return FAILURE;
    size = 3 * bitmap->width * bitmap->height;
    data = malloc(size);
    if(data == NULL) return FAILURE;
    if(fread(data, size, 1, file) != 1) return FAILURE;
    fclose(file);
    bitmap->pixels = malloc(bitmap->width * bitmap->height * sizeof(pixel_t));
    if(bitmap->pixels == NULL) {
        free(data);
        return FAILURE;
    }
    size_t x, y;
    for (y = 0; y < bitmap->height; ++y) {
        for (x = 0; x < bitmap->width; ++x) {
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].r = *(data + (3 * x) + (y * bitmap->width * 3) );
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].g = *(data + (3 * x) + (y * bitmap->width * 3) + 1);
            bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].b = *(data + (3 * x) + (y * bitmap->width * 3) + 2);
        }
    }
    free(data);
    return SUCCESS;
}

int save_bmp(bitmap_t* bitmap, const char* filename) {
    FILE* file;
    size_t x, y;
    unsigned char* data = NULL;
    int res = FAILURE;
    size_t size;
    size = 3 * bitmap->width * bitmap->height;
    data = malloc(size);
    if(data == NULL) return FAILURE;
    memset(data, 0, size);
    for(y = 0; y < bitmap->height; ++y) {
        for(x = 0; x < bitmap->width; ++x) {
            *(data + (3 * x) + (y * bitmap->width * 3) ) = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].r;
            *(data + (3 * x) + (y * bitmap->width * 3) + 1) = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].g;
            *(data + (3 * x) + (y * bitmap->width * 3) + 2) = bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x].b;
        }
    }
    file = fopen(filename, "wb");
    if(file == NULL) {
        goto free_and_exit;
    }
    if(fwrite(&bitmap->width, sizeof(bitmap->width), 1, file) != 1) {
        goto close_and_exit;
    }
    if(fwrite(&bitmap->height, sizeof(bitmap->height), 1, file) != 1) {
        goto close_and_exit;
    }
    if(fwrite(data, size, 1, file) != 1) {
        goto close_and_exit;
    }
    res = SUCCESS;
close_and_exit:
    fclose(file);
free_and_exit:
    free(data);
    return res;
}

void grayscale(bitmap_t* bitmap) {
    size_t x, y;
    for(y = 0; y < bitmap->height; ++y) {
        for(x = 0; x < bitmap->width; ++x) {
            pixel_t* pixel = &bitmap->pixels[(bitmap->height - 1 - y) * bitmap->width + x];
            unsigned char gray = (pixel->r + pixel->g + pixel->b) / 3;
            pixel->r = gray;
            pixel->g = gray;
            pixel->b = gray;
        }
    }
}

int main(int argc, char **argv) {
    bitmap_t bitmap;
    int rc = load_bmp(&bitmap, FILE_NAME);
    if(rc == FAILURE) {
        printf("Failed to read the file.");
        return rc;
    }
    grayscale(&bitmap);
    rc = save_bmp(&bitmap, "output.bmp");
    if(rc == FAILURE) {
        printf("Failed to save the file.");
    }
    return rc;
}