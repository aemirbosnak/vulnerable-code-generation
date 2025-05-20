//Falcon-180B DATASET v1.0 Category: Image Editor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <math.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    int width;
    int height;
    char *data;
} Image;

void image_init(Image *img, int width, int height) {
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(char));
    memset(img->data, 0, width * height * sizeof(char));
}

void image_free(Image *img) {
    free(img->data);
}

void image_print(Image *img) {
    int i, j;
    for (i = 0; i < img->height; i++) {
        for (j = 0; j < img->width; j++) {
            printf("%c", img->data[i * img->width + j]);
        }
        printf("\n");
    }
}

void image_save(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return;
    }
    fwrite(img->data, 1, img->width * img->height, fp);
    fclose(fp);
}

int main() {
    Image img;
    image_init(&img, 256, 256);
    image_print(&img);
    image_save(&img, "image.txt");
    return 0;
}