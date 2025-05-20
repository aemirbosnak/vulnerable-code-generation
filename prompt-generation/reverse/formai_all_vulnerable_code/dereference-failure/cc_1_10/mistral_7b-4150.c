//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define WIDTH 30
#define HEIGHT 15

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

void image_to_ascii(pixel image[WIDTH][HEIGHT], FILE *output) {
    int i, j, intensity;
    char symbol = ' ';

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            intensity = round(image[j][i].r * 0.3) + round(image[j][i].g * 0.57) + round(image[j][i].b * 0.13);
            if (intensity < 0) intensity = 0;
            if (intensity > 127) {
                symbol = '*';
                intensity -= 128;
            }
            putc(symbol, output);
            if (j < WIDTH - 1) putc(' ', output);
        }
        putc('\n', output);
    }
}

pixel load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    pixel image;
    int byte_count;

    if (file) {
        fread(&byte_count, sizeof(int), 1, file);
        fread(&image.r, sizeof(unsigned char), 3, file);
        fread(&image.g, sizeof(unsigned char), 3, file);
        fread(&image.b, sizeof(unsigned char), 3, file);
        fclose(file);
    }

    return image;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    pixel image = load_image(argv[1]);
    FILE *output = stdout;

    if (image.r == 0 && image.g == 0 && image.b == 0) {
        puts("Error: Invalid image file.\n");
        return 1;
    }

    pixel image_buffer[WIDTH][HEIGHT];
    memcpy(image_buffer, &image, sizeof(image_buffer));

    image_to_ascii(image_buffer, output);

    return 0;
}