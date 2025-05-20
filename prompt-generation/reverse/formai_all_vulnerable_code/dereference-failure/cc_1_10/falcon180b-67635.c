//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define WIDTH 80
#define HEIGHT 50

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(filesize);
    if (data == NULL) {
        fprintf(stderr, "Error: could not allocate memory for image data\n");
        exit(EXIT_FAILURE);
    }

    if (fread(data, filesize, 1, fp)!= 1) {
        fprintf(stderr, "Error: could not read image data from file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    Image image = {
       .data = data,
       .width = 0,
       .height = 0
    };

    return image;
}

void free_image(Image *image) {
    free(image->data);
}

void print_ascii_art(const Image *image) {
    for (int y = 0; y < image->height; ++y) {
        for (int x = 0; x < image->width; ++x) {
            int brightness = image->data[y * image->width + x] / 16;

            switch (brightness) {
                case 0:
                    printf("  ");
                    break;
                case 1:
                    printf(". ");
                    break;
                case 2:
                    printf("+ ");
                    break;
                case 3:
                    printf("* ");
                    break;
                default:
                    printf("? ");
                    break;
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <image_file>\n", argv[0]);
        return 1;
    }

    Image image = load_image(argv[1]);

    if (image.width == 0 || image.height == 0) {
        fprintf(stderr, "Error: could not determine image dimensions\n");
        return 1;
    }

    printf("ASCII Art:\n");
    print_ascii_art(&image);

    free_image(&image);

    return 0;
}