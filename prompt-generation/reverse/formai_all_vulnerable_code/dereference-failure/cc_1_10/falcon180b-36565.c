//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 25
#define MAX_CHARS (MAX_WIDTH * MAX_HEIGHT)

typedef struct {
    char *filename;
    int width;
    int height;
    char *data;
} Image;

void read_image(Image *img) {
    FILE *fp = fopen(img->filename, "rb");
    if (fp == NULL) {
        printf("Error opening file: %s\n", img->filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    rewind(fp);

    img->data = malloc(size);
    fread(img->data, size, 1, fp);
    fclose(fp);

    int pos = 0;
    while (pos < size) {
        if (img->data[pos] == 0xff && img->data[pos+1] == 0xd8) {
            img->width = *(int *)(img->data + pos + 6);
            img->height = *(int *)(img->data + pos + 8);
            break;
        }
        pos++;
    }
}

void write_ascii_art(Image *img) {
    int chars_printed = 0;
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel_index = y * img->width + x;
            int value = img->data[pixel_index * 3];

            if (value < 128) {
                printf(" ");
            } else if (value < 192) {
                printf(". ");
            } else {
                printf("*");
            }

            if (++chars_printed == MAX_CHARS) {
                printf("\n");
                chars_printed = 0;
            }
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img;
    img.filename = argv[1];
    img.width = 0;
    img.height = 0;
    img.data = NULL;

    read_image(&img);
    write_ascii_art(&img);

    return 0;
}