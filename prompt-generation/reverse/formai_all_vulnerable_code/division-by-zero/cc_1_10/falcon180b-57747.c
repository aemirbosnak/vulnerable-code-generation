//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#define ROWS 40
#define COLS 80
#define BLACK "  "
#define WHITE " *"

typedef struct {
    int row, col;
} Point;

void draw_pixel(int row, int col, char *image, int width, int height) {
    if (row < 0 || row >= height || col < 0 || col >= width)
        return;

    if (image[row * width + col] == 0) {
        printf(" ");
        return;
    }

    printf("%c", image[row * width + col] == 1? WHITE : BLACK);
}

void draw_image(char *image, int width, int height) {
    int i, j;

    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            draw_pixel(i, j, image, width, height);
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    FILE *fp;
    char filename[100];
    int width, height, i, j, value;
    char *image = NULL;

    printf("Enter the filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    width = ftell(fp) / 3;
    height = ftell(fp) / width / 3;

    rewind(fp);
    image = malloc(height * width);
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            fread(&value, 1, 1, fp);
            image[i * width + j] = value;
        }
    }

    draw_image(image, width, height);

    free(image);
    fclose(fp);

    return 0;
}