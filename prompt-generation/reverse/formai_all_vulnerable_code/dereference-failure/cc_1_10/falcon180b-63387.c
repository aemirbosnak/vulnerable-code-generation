//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

void load_image(Image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        printf("Error: cannot open image file %s\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    img->data = (char *) malloc(filesize);
    fread(img->data, filesize, 1, fp);

    fclose(fp);

    int header_size = 54;
    char *header = (char *) malloc(header_size);
    memcpy(header, img->data, header_size);

    int width = *(int *) (header + 18);
    int height = *(int *) (header + 22);

    img->width = width;
    img->height = height;
}

void free_image(Image *img) {
    free(img->data);
}

void print_ascii_art(const Image *img) {
    int x, y;
    for (y = 0; y < img->height; y++) {
        for (x = 0; x < img->width; x++) {
            int pixel_index = (y * img->width + x) * 3;
            int r = img->data[pixel_index];
            int g = img->data[pixel_index + 1];
            int b = img->data[pixel_index + 2];

            int brightness = (r + g + b) / 3;

            if (brightness < 0) {
                brightness = 0;
            } else if (brightness > 7) {
                brightness = 7;
            }

            printf("%c", ".:-=+*#@"[brightness]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <image_file>\n", argv[0]);
        exit(1);
    }

    Image img;
    load_image(&img, argv[1]);

    printf("Original image:\n");
    print_ascii_art(&img);

    free_image(&img);

    return 0;
}