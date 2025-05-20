//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WIDTH 80
#define MAX_HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'.\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (data == NULL) {
        fprintf(stderr, "Error: Failed to allocate memory for image data.\n");
        exit(1);
    }

    if (fread(data, 1, filesize, fp)!= filesize) {
        fprintf(stderr, "Error: Failed to read image data from file.\n");
        exit(1);
    }

    fclose(fp);

    int width, height;
    if (sscanf(filename, "%dx%d.bmp", &width, &height)!= 2 || width <= 0 || height <= 0) {
        fprintf(stderr, "Error: Invalid image dimensions.\n");
        exit(1);
    }

    return (Image) {
       .data = data,
       .width = width,
       .height = height
    };
}

void free_image(Image img) {
    free(img.data);
}

int get_pixel(const Image *img, int x, int y) {
    if (x < 0 || y < 0 || x >= img->width || y >= img->height) {
        return 0;
    }

    unsigned char *data = (unsigned char *)img->data;
    int offset = y * img->width + x;
    return data[offset];
}

void print_ascii_art(const Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int pixel = get_pixel(img, x, y);

            if (pixel == 0) {
                printf(" ");
            } else if (pixel == 255) {
                printf("#");
            } else {
                printf("%c", '@' + (pixel / 16));
            }
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        return 1;
    }

    Image img = load_image(argv[1]);
    char *output_filename = argv[2];

    FILE *fp = fopen(output_filename, "w");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s' for writing.\n", output_filename);
        exit(1);
    }

    print_ascii_art(&img);

    fclose(fp);

    free_image(img);

    return 0;
}