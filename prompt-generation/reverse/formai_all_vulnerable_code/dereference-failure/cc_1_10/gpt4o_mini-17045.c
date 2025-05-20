//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, const Image *img);
void free_image(Image *img);
Image* convert_to_grayscale(const Image *img);
void print_usage(const char *prog_name);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    Image *gray_img = convert_to_grayscale(img);
    if (!gray_img) {
        fprintf(stderr, "Error converting image to grayscale.\n");
        free_image(img);
        return 1;
    }

    save_image(argv[2], gray_img);

    free_image(img);
    free_image(gray_img);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;

    char header[3];
    fscanf(f, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fclose(f);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(f, "%d %d\n255\n", &img->width, &img->height);

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, f);
    fclose(f);

    return img;
}

void save_image(const char *filename, const Image *img) {
    FILE *f = fopen(filename, "wb");
    if (!f) return;

    fprintf(f, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, f);
    fclose(f);
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

Image* convert_to_grayscale(const Image *img) {
    Image *gray_img = malloc(sizeof(Image));
    gray_img->width = img->width;
    gray_img->height = img->height;
    gray_img->data = malloc(gray_img->width * gray_img->height * sizeof(Pixel));

    for (int i = 0; i < gray_img->width * gray_img->height; i++) {
        unsigned char gray = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        gray_img->data[i].r = gray;
        gray_img->data[i].g = gray;
        gray_img->data[i].b = gray;
    }

    return gray_img;
}

void print_usage(const char *prog_name) {
    fprintf(stderr, "Usage: %s <input.ppm> <output.ppm>\n", prog_name);
}