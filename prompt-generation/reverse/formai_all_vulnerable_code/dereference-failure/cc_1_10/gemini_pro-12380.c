//GEMINI-pro DATASET v1.0 Category: Image to ASCII art converter ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define WIDTH 80
#define HEIGHT 25
#define MAX_BRIGHTNESS 255
#define NUM_ASCII_CHARS 256
#define BRIGHTNESS_STEP 25

char *ASCII_CHARS = " .,-~:;!@#$%^&*+=_-`  ";

void image_to_ascii(unsigned char *image, int width, int height, char *output) {
    int i, j, k, l;
    double brightness;
    int index;
    char *p;

    p = output;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            brightness = 0;
            for (k = 0; k < 3; k++) {
                brightness += image[(i * width + j) * 3 + k];
            }
            brightness /= 3;
            index = brightness / BRIGHTNESS_STEP;
            if (index >= NUM_ASCII_CHARS) {
                index = NUM_ASCII_CHARS - 1;
            }
            *p++ = ASCII_CHARS[index];
        }
        *p++ = '\n';
    }
    *p++ = '\0';
}

int main(int argc, char **argv) {
    FILE *fp;
    unsigned char *image;
    int width, height;
    char *output;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.bmp>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    if (fread(&width, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "fread: width\n");
        return 1;
    }

    if (fread(&height, sizeof(int), 1, fp) != 1) {
        fprintf(stderr, "fread: height\n");
        return 1;
    }

    image = malloc(width * height * 3);
    if (image == NULL) {
        perror("malloc");
        return 1;
    }

    if (fread(image, width * height * 3, 1, fp) != 1) {
        fprintf(stderr, "fread: image data\n");
        return 1;
    }

    output = malloc(width * height + WIDTH + 1);
    if (output == NULL) {
        perror("malloc");
        return 1;
    }

    image_to_ascii(image, width, height, output);

    printf("%s", output);

    free(output);
    free(image);
    fclose(fp);

    return 0;
}