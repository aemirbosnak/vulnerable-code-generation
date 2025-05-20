//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define ASCII_CHARS ".,-~:;=!*#@"

typedef struct {
    int width;
    int height;
    unsigned char *data;
} image_t;

image_t *load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    unsigned char *data = malloc(filesize);
    fread(data, filesize, 1, fp);
    fclose(fp);

    image_t *img = malloc(sizeof(image_t));
    img->width = *(int *)data;
    img->height = *(int *)(data + 4);
    img->data = data + 8;

    return img;
}

void free_image(image_t *img) {
    free(img->data);
    free(img);
}

void draw_ascii_art(const image_t *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = *(img->data + y * img->width + x) / 16;
            printf("%c", ASCII_CHARS[pixel]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s input.bmp output.txt\n", argv[0]);
        exit(1);
    }

    image_t *img = load_image(argv[1]);
    char *output_filename = argv[2];

    FILE *fp = fopen(output_filename, "w");
    if (!fp) {
        fprintf(stderr, "Error: could not open file '%s' for writing\n", output_filename);
        exit(1);
    }

    draw_ascii_art(img);

    fclose(fp);
    free_image(img);

    return 0;
}