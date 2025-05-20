//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_CHARS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    int width;
    int height;
    char *data;
} Image;

int load_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    image->data = malloc(filesize);
    if (image->data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        fclose(fp);
        return 1;
    }

    if (fread(image->data, 1, filesize, fp)!= filesize) {
        fprintf(stderr, "Error: could not read image data from file '%s'\n", filename);
        free(image->data);
        fclose(fp);
        return 1;
    }

    fclose(fp);

    image->width = *(int *)image->data;
    image->height = *(int *)(image->data + 4);

    return 0;
}

int save_ascii_art(const char *filename, const char *ascii_art) {
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", filename);
        return 1;
    }

    fprintf(fp, "%s", ascii_art);

    fclose(fp);

    return 0;
}

void free_image(Image *image) {
    free(image->data);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image image;
    if (load_image(argv[1], &image)) {
        return 1;
    }

    char *ascii_art = malloc(MAX_CHARS);
    if (ascii_art == NULL) {
        fprintf(stderr, "Error: could not allocate memory for ASCII art\n");
        free_image(&image);
        return 1;
    }

    int x, y, c;
    for (y = 0; y < image.height; ++y) {
        for (x = 0; x < image.width; ++x) {
            c = *(int *)(image.data + y * image.width + x) >> 16 & 0xFF;
            ascii_art[y * MAX_WIDTH + x] = (c < 32 || c > 126)? '.' : (char)c;
        }
    }

    save_ascii_art(argv[2], ascii_art);

    free(ascii_art);
    free_image(&image);

    return 0;
}