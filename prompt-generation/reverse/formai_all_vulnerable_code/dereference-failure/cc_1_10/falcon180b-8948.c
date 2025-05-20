//Falcon-180B DATASET v1.0 Category: Image to ASCII art converter ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define WIDTH 80
#define HEIGHT 24

typedef struct {
    char *data;
    int width;
    int height;
} Image;

Image load_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    long filesize = ftell(fp);
    rewind(fp);

    char *data = malloc(filesize);
    if (data == NULL) {
        fprintf(stderr, "Error: Could not allocate memory for image data\n");
        exit(1);
    }

    fread(data, filesize, 1, fp);
    fclose(fp);

    return (Image) {.data = data,.width = WIDTH,.height = HEIGHT };
}

void free_image(Image img) {
    free(img.data);
}

void print_ascii_art(const Image *img) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            char c = img->data[y * img->width + x];
            printf("%c", c);
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
    if (img.width!= WIDTH || img.height!= HEIGHT) {
        fprintf(stderr, "Error: Input image must be %dx%d pixels\n", WIDTH, HEIGHT);
        free_image(img);
        return 1;
    }

    print_ascii_art(&img);

    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        fprintf(stderr, "Error: Could not open file '%s' for writing\n", argv[2]);
        free_image(img);
        return 1;
    }

    fwrite(img.data, img.width * img.height, 1, fp);
    fclose(fp);

    free_image(img);
    return 0;
}