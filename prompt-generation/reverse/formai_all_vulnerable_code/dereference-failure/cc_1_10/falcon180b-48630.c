//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 24

char ascii_art[WIDTH * HEIGHT];

void generate_ascii_art(char *image_data, int width, int height) {
    int i, j, k, l;
    int pixel_value;
    int max_value = 0;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = image_data[(i * width + j) * 3];
            if (pixel_value > max_value) {
                max_value = pixel_value;
            }
        }
    }

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            pixel_value = image_data[(i * width + j) * 3];
            k = pixel_value * HEIGHT / max_value;
            l = k * WIDTH / width;
            ascii_art[(i * WIDTH + j) * 2] = '@';
            ascii_art[(i * WIDTH + j) * 2 + 1] = '@';
        }
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    char header[4];
    int width, height;

    if (argc!= 2) {
        printf("Usage: %s <image>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    fread(header, 1, 4, fp);
    if (header[0]!= 'B' || header[1]!= 'M') {
        printf("Error: Invalid image format.\n");
        fclose(fp);
        return 1;
    }

    fseek(fp, 18, SEEK_SET);
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);

    ascii_art[0] = '\0';
    generate_ascii_art(header + 10, width, height);

    fclose(fp);

    printf("ASCII art:\n%s\n", ascii_art);

    return 0;
}