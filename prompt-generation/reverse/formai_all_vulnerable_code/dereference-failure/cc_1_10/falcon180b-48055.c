//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80 // Maximum width of the ASCII art
#define MAX_HEIGHT 30 // Maximum height of the ASCII art

typedef struct {
    char *filename;
    int width;
    int height;
    unsigned char *data;
} Image;

void read_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: Could not open file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = malloc(filesize);
    fread(img->data, filesize, 1, fp);
    fclose(fp);

    img->width = atoi(strtok(filename, "."));
    img->height = atoi(strtok(NULL, "."));
}

void convert_to_ascii(Image *img) {
    int i, j;
    int total_pixels = img->width * img->height;
    int ascii_art_width = img->width / MAX_WIDTH;
    int ascii_art_height = img->height / MAX_HEIGHT;

    printf("+");
    for (i = 0; i < ascii_art_width; i++) {
        printf("-");
    }
    printf("\n");

    for (i = 0; i < ascii_art_height; i++) {
        for (j = 0; j < MAX_WIDTH; j++) {
            int pixel_index = (i * MAX_WIDTH + j) * 3;
            int r = img->data[pixel_index];
            int g = img->data[pixel_index + 1];
            int b = img->data[pixel_index + 2];

            int brightness = (r + g + b) / 3;

            if (brightness > 128) {
                printf("*");
            } else if (brightness > 64) {
                printf(":");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    Image img;
    img.filename = argv[1];
    read_image(&img, argv[1]);
    convert_to_ascii(&img);

    return 0;
}