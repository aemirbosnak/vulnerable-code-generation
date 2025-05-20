//MISTRAL-7B DATASET v1.0 Category: Image to ASCII art converter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 50
#define HEIGHT 5

typedef struct {
    unsigned char r, g, b;
} pixel;

char symbols[16][3] = {
    {'.', '.'}, {'#', ' '}, {'@', '.'}, {'&', '.'}, {'*', '.'},
    {'%', '.'}, {'+', '.'}, {'-', '.'}, {'|', '.'}, {'/', '.'},
    {'\\', '.'}, {'>', '.'}, {'<', '.'}, {'=', '.'}, {'_', '.'}
};

void image_to_ascii(pixel image[WIDTH][HEIGHT], int scale) {
    int i, j, index;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            index = (image[i][j].r >= 0.5 ? 0 : 1) * 3 +
                   (image[i][j].g >= 0.5 ? 0 : 1) * 2 +
                   (image[i][j].b >= 0.5 ? 0 : 1);
            putchar(symbols[index][scale]);
        }
        putchar('\n');
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    pixel image[WIDTH][HEIGHT];
    int i, j, r, g, b;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <image.pgm>\n", argv[0]);
        return 1;
    }

    fp = fopen(argv[1], "rb");
    if (!fp) {
        perror("Error opening file");
        return 1;
    }

    fgets(argv[1], sizeof(argv[1]), fp); // Skip magic number
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            fscanf(fp, "%d%d%d", &r, &g, &b);
            image[i][j].r = r / 255.0;
            image[i][j].g = g / 255.0;
            image[i][j].b = b / 255.0;
        }
    }

    fclose(fp);
    image_to_ascii(image, 0); // ASCII art
    image_to_ascii(image, 1); // Reversed ASCII art

    return 0;
}