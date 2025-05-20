//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: Cryptic
#define _CRYPTIC_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10

typedef struct { int r, g, b; } pixel_t;

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void read_pgm(const char *filename, unsigned char **data, int *width, int *height) {
    FILE *fp = fopen(filename, "rb");
    char magic[3];
    unsigned char header[5];

    if (!fp) die("Can't open file");

    fgets(magic, sizeof(magic), fp);
    magic[strlen(magic) - 1] = '\0';

    fread(header, sizeof(header), 1, fp);

    *width = atoi(strtok(strchr(magic, ' '), " "));
    *height = atoi(strtok(NULL, " "));

    *data = calloc(*width, *height);
    if (!*data) die("Out of memory");

    fread(*data, *width * *height, 1, fp);
    fclose(fp);
}

void write_pgm(const char *filename, const unsigned char *data, int width, int height) {
    FILE *fp = fopen(filename, "wb");
    char magic[10];
    unsigned char header[12];

    sprintf(magic, "P5\n%d %d\n255\n", width, height);
    fputs(magic, fp);

    header[0] = 59; header[1] = 50; header[2] = 51;
    header[3] = 'P'; header[4] = '5';

    fwrite(header, sizeof(header), 1, fp);
    fwrite(data, width * height, 1, fp);
    fclose(fp);
}

void image_to_ascii(const pixel_t *image, int width, int height, int ascii_chars) {
    int x, y, i, j, index;
    const char *ascii_map = " .:!*oe%$#@";

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++) {
            index = (image[y * width + x].r * 30 / 255 +
                     image[y * width + x].g * 30 / 255 +
                     image[y * width + x].b * 30 / 255) % ascii_chars;

            for (i = y * HEIGHT; i < y * HEIGHT + HEIGHT && i < height; i++) {
                for (j = x * WIDTH; j < x * WIDTH + WIDTH && j < width; j++) {
                    putchar(ascii_map[image[i * width + j].r * ascii_chars / 255]);
                }
                putchar('\n');
            }

            putchar(ascii_map[index]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
#ifndef _CRYPTIC_
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <pgm-image>\n", argv[0]);
        exit(1);
    }
#endif

    unsigned char *image_data;
    int image_width, image_height;

    read_pgm(argv[1], &image_data, &image_width, &image_height);

    pixel_t *image = malloc(image_width * image_height * sizeof(pixel_t));

    for (int i = 0; i < image_width * image_height; i++) {
        image[i].r = image_data[i];
        image[i].g = image_data[i + image_width];
        image[i].b = image_data[i + image_width * 2];
    }

    image_to_ascii(image, image_width, image_height, 32);

    free(image);
    free(image_data);
    write_pgm(argv[1], image_data, image_width, image_height);

    return 0;
}