//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 50
#define CHAR_SET_SIZE 256

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./program image.bmp\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "rb");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fseek(fp, 0, SEEK_END);
    long file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(file_size);
    if (data == NULL) {
        printf("Error allocating memory.\n");
        fclose(fp);
        return 1;
    }

    fread(data, file_size, 1, fp);
    fclose(fp);

    int width = *(int *)data;
    int height = *(int *)(data + 4);
    int offset = *(int *)(data + 8);

    unsigned char *pixels = data + offset;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int index = y * width + x;

            int r = pixels[index * 3] >> 4;
            int g = pixels[index * 3 + 1] >> 4;
            int b = pixels[index * 3 + 2] >> 4;

            int closest_color_index = 0;
            int closest_color_distance = 1000;

            for (int i = 0; i < CHAR_SET_SIZE; ++i) {
                int c_r = (i >> 4) & 0xF;
                int c_g = (i >> 8) & 0xF;
                int c_b = (i >> 12) & 0xF;

                int color_distance = abs(r - c_r) + abs(g - c_g) + abs(b - c_b);

                if (color_distance < closest_color_distance) {
                    closest_color_index = i;
                    closest_color_distance = color_distance;
                }
            }

            printf("%c", closest_color_index);
        }
        printf("\n");
    }

    free(data);
    return 0;
}