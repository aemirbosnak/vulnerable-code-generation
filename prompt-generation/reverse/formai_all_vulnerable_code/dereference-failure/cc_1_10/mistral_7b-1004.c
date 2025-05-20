//MISTRAL-7B DATASET v1.0 Category: Pixel Art Generator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WIDTH 10
#define HEIGHT 10

typedef struct {
    unsigned char r, g, b;
} pixel;

pixel palette[3] = {{255, 0, 0}, {0, 255, 0}, {0, 0, 255}};

void putpixel(FILE *fp, int x, int y, int color) {
    fseek(fp, (WIDTH * y + x) * 3, SEEK_SET);
    fwrite(&color, sizeof(int), 1, fp);
}

int main() {
    char filename[20];
    int i, j, color;

    printf("Enter image filename: ");
    scanf("%s", filename);

    pixel *image = malloc(WIDTH * HEIGHT * sizeof(pixel));

    printf("Enter pixels (R G B) or 'q' to quit:\n");

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        scanf("%d%d%d", &image[i].r, &image[i].g, &image[i].b);

        if (image[i].r == -1 && image[i].g == -1 && image[i].b == -1)
            break;
    }

    FILE *fp = fopen(filename, "wb");

    for (i = 0; i < WIDTH * HEIGHT; i++) {
        color = (image[i].r << 11) | (image[i].g << 5) | image[i].b;
        putpixel(fp, i % WIDTH, i / WIDTH, color);
    }

    free(image);
    fclose(fp);

    printf("Image saved as %s\n", filename);

    return 0;
}