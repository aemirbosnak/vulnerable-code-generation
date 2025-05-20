//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

void load_image(const char *filename, image_t *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    image->data = malloc(size);
    if (image->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(1);
    }

    fread(image->data, 1, size, fp);
    fclose(fp);

    image->width = *(int *)image->data;
    image->height = *(int *)(image->data + 4);
}

void free_image(image_t *image) {
    free(image->data);
}

void print_ascii_art(const image_t *image) {
    int x, y;
    for (y = 0; y < image->height; ++y) {
        for (x = 0; x < image->width; ++x) {
            int value = *(int *)(image->data + y * image->width + x);
            int brightness = (value >> 16) & 0xff;
            printf("%c", ".-+!*#@"[brightness]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    image_t image;
    load_image(argv[1], &image);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", output_filename);
        exit(1);
    }

    print_ascii_art(&image);

    fclose(fp);
    free_image(&image);

    return 0;
}