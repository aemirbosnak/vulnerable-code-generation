//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

typedef struct {
    unsigned int width, height;
    pixel *data;
} image;

image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) return NULL;

    char header[3];
    fread(header, 3, 1, fp);
    if (strncmp(header, "P6", 3) != 0) return NULL;

    unsigned int width, height, maxval;
    fscanf(fp, "%u %u %u", &width, &height, &maxval);

    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));

    fread(img->data, sizeof(pixel), width * height, fp);
    fclose(fp);

    return img;
}

void write_image(const char *filename, const image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) return;

    fprintf(fp, "P6\n%u %u 255\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

void invert(image *img) {
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = 255 - img->data[i].r;
        img->data[i].g = 255 - img->data[i].g;
        img->data[i].b = 255 - img->data[i].b;
    }
}

void grayscale(image *img) {
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        unsigned char avg = (img->data[i].r + img->data[i].g + img->data[i].b) / 3;
        img->data[i].r = avg;
        img->data[i].g = avg;
        img->data[i].b = avg;
    }
}

void blur(image *img, unsigned int radius) {
    if (radius < 1) return;

    unsigned int width = img->width;
    unsigned int height = img->height;

    pixel *tmp = malloc(width * height * sizeof(pixel));
    memcpy(tmp, img->data, width * height * sizeof(pixel));

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            unsigned int r = 0, g = 0, b = 0;
            unsigned int count = 0;

            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        r += tmp[ny * width + nx].r;
                        g += tmp[ny * width + nx].g;
                        b += tmp[ny * width + nx].b;
                        count++;
                    }
                }
            }

            img->data[y * width + x].r = r / count;
            img->data[y * width + x].g = g / count;
            img->data[y * width + x].b = b / count;
        }
    }

    free(tmp);
}

void sharpen(image *img, unsigned int radius) {
    if (radius < 1) return;

    unsigned int width = img->width;
    unsigned int height = img->height;

    pixel *tmp = malloc(width * height * sizeof(pixel));
    memcpy(tmp, img->data, width * height * sizeof(pixel));

    for (unsigned int y = 0; y < height; y++) {
        for (unsigned int x = 0; x < width; x++) {
            int r = 0, g = 0, b = 0;

            for (int dy = -radius; dy <= radius; dy++) {
                for (int dx = -radius; dx <= radius; dx++) {
                    int nx = x + dx;
                    int ny = y + dy;

                    if (nx >= 0 && nx < width && ny >= 0 && ny < height) {
                        r += tmp[ny * width + nx].r;
                        g += tmp[ny * width + nx].g;
                        b += tmp[ny * width + nx].b;
                    }
                }
            }

            r = r / (2 * radius + 1) * (2 * radius + 1) - tmp[y * width + x].r;
            g = g / (2 * radius + 1) * (2 * radius + 1) - tmp[y * width + x].g;
            b = b / (2 * radius + 1) * (2 * radius + 1) - tmp[y * width + x].b;

            img->data[y * width + x].r = r;
            img->data[y * width + x].g = g;
            img->data[y * width + x].b = b;
        }
    }

    free(tmp);
}

int main(int argc, char **argv) {
    if (argc < 4) {
        fprintf(stderr, "Usage: %s <image> <operation> <output>\n", argv[0]);
        fprintf(stderr, "Operations: invert, grayscale, blur, sharpen\n");
        return 1;
    }

    const char *input = argv[1];
    const char *operation = argv[2];
    const char *output = argv[3];

    image *img = read_image(input);
    if (!img) {
        fprintf(stderr, "Error: could not read image '%s'\n", input);
        return 1;
    }

    if (strcmp(operation, "invert") == 0) {
        invert(img);
    } else if (strcmp(operation, "grayscale") == 0) {
        grayscale(img);
    } else if (strcmp(operation, "blur") == 0) {
        unsigned int radius = 3;
        if (argc >= 5) radius = atoi(argv[4]);
        blur(img, radius);
    } else if (strcmp(operation, "sharpen") == 0) {
        unsigned int radius = 3;
        if (argc >= 5) radius = atoi(argv[4]);
        sharpen(img, radius);
    } else {
        fprintf(stderr, "Error: unknown operation '%s'\n", operation);
        return 1;
    }

    write_image(output, img);
    free(img->data);
    free(img);

    return 0;
}