//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 100
#define HEIGHT 50

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open image file.\n");
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0, SEEK_END);
    long size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    unsigned char *data = malloc(size);
    if (data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image data.\n");
        exit(EXIT_FAILURE);
    }

    if (fread(data, 1, size, fp)!= size) {
        fprintf(stderr, "Error: Could not read image data.\n");
        exit(EXIT_FAILURE);
    }

    fclose(fp);

    return (Image) {
       .data = data,
       .width = WIDTH,
       .height = HEIGHT
    };
}

void free_image(Image image) {
    free(image.data);
}

void print_image(const Image image) {
    for (int y = 0; y < image.height; ++y) {
        for (int x = 0; x < image.width; ++x) {
            int index = (y * image.width + x) * 3;
            int value = image.data[index];

            printf("%s", value < 128? " " : "*");
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <input_image> <output_ascii_art>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    Image input_image = load_image(argv[1]);
    if (input_image.width!= WIDTH || input_image.height!= HEIGHT) {
        fprintf(stderr, "Error: Input image must be %dx%d pixels.\n", WIDTH, HEIGHT);
        exit(EXIT_FAILURE);
    }

    FILE *output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open output file.\n");
        exit(EXIT_FAILURE);
    }

    print_image(input_image);

    fclose(output_file);

    free_image(input_image);

    return 0;
}