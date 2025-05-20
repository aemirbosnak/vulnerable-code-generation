//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 30
#define HEIGHT 10
#define BMP_SIZE (WIDTH * HEIGHT * 3)

char *colors[] = {
    " .:!*oe&#%@",
    " +:;:!*:%&@$",
    " =:;:!*:%&+@",
    " -:;:!*:%&*@",
    " _:;:!*:%&*#",
    " `:;:!*:%&*##",
    " ':;:!*:%&*###",
    " :;:!*:%&*####",
    " :;:!*:%&&####",
    " :;:!*:&&&&####"
};

typedef struct {
    unsigned char blue;
    unsigned char green;
    unsigned char red;
} RGB;

RGB get_color(int intensity) {
    RGB color;
    int index = intensity / 32;
    int rem = intensity % 32;

    color.red = colors[index][rem];
    color.green = colors[index][rem + 1];
    color.blue = colors[index][rem + 2];

    return color;
}

void bmp_to_ascii(unsigned char *bmp_data, int width, int height) {
    int i, j, intensity;
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            intensity = bmp_data[i * width * 3 + j * 3];
            printf("%c", get_color(intensity).red);
            putchar(get_color(intensity).green);
            putchar(get_color(intensity).blue);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    unsigned char bmp_data[BMP_SIZE];
    FILE *fp;
    int i;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <path_to_bmp_file>\n", argv[0]);
        return 1;
    }

    if ((fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    fread(bmp_data, 1, BMP_SIZE, fp);
    fclose(fp);

    printf("----------------------------------------\n");
    bmp_to_ascii(bmp_data, WIDTH, HEIGHT);
    printf("----------------------------------------\n");

    free(bmp_data);
    return 0;
}