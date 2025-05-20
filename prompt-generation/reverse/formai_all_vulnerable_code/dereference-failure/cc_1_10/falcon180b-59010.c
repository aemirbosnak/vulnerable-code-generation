//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 100
#define MAX_HEIGHT 100

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image loadImage(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    char *data = malloc(size);
    if (!data) {
        fprintf(stderr, "Error: out of memory\n");
        exit(1);
    }

    if (fread(data, 1, size, fp)!= size) {
        fprintf(stderr, "Error: could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    return (Image) {
       .width = 0,
       .height = 0,
       .data = data
    };
}

void freeImage(Image img) {
    free(img.data);
}

void printAsciiArt(const Image *img) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            int value = *(img->data + y * img->width + x) / 16;
            putchar(value % 10 + '0');
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img = loadImage(argv[1]);

    char *output_filename = argv[2];
    FILE *fp = fopen(output_filename, "w");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", output_filename);
        exit(1);
    }

    printAsciiArt(&img);

    fclose(fp);

    freeImage(img);

    return 0;
}