//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 25

void print_matrix(char matrix[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char header[54];
    fread(header, 1, 54, fp);

    int width, height, channels;
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fread(&channels, 2, 1, fp);

    char *data = malloc(width * height * channels);
    fread(data, 1, width * height * channels, fp);

    fclose(fp);

    int max_value = 0;
    for (int i = 0; i < width * height * channels; i++) {
        if (data[i] > max_value) {
            max_value = data[i];
        }
    }

    char matrix[HEIGHT][WIDTH];
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int index = (i * width + j) * channels;
            int value = data[index] * HEIGHT / max_value;
            matrix[i][j] = (char)value;
        }
    }

    print_matrix(matrix);

    free(data);
    return 0;
}