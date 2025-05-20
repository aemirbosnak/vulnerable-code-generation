//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80 // maximum width of the ASCII art
#define MAX_HEIGHT 25 // maximum height of the ASCII art

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    int size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    void *data = malloc(size);
    if (data == NULL) {
        printf("Error: could not allocate memory\n");
        exit(1);
    }

    if (fread(data, size, 1, fp)!= 1) {
        printf("Error: could not read file '%s'\n", filename);
        exit(1);
    }

    fclose(fp);

    return (Image *)data;
}

void free_image(Image *image) {
    free(image);
}

void print_ascii_art(const Image *image, int x, int y) {
    const char *data = image->data;
    int width = image->width;
    int height = image->height;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            char c = data[(i * width + j) * 3];
            if (c < 128) {
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        exit(1);
    }

    Image *image = load_image(argv[1]);

    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        printf("Error: could not open file '%s'\n", argv[2]);
        exit(1);
    }

    print_ascii_art(image, 0, 0);

    fclose(fp);

    free_image(image);

    return 0;
}