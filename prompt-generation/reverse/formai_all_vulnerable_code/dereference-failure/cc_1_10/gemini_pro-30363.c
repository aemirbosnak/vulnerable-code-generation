//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WIDTH 1024
#define MAX_HEIGHT 1024

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

typedef struct {
    unsigned int width;
    unsigned int height;
    pixel *data;
} image;

image *create_image(unsigned int width, unsigned int height) {
    image *img = malloc(sizeof(image));
    if (img == NULL) {
        return NULL;
    }

    img->width = width;
    img->height = height;
    img->data = malloc(width * height * sizeof(pixel));
    if (img->data == NULL) {
        free(img);
        return NULL;
    }

    return img;
}

void destroy_image(image *img) {
    free(img->data);
    free(img);
}

int load_image(image *img, const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        return -1;
    }

    // Read the header
    unsigned char header[14];
    fread(header, 1, 14, fp);

    // Check the header
    if (header[0] != 'B' || header[1] != 'M') {
        return -2;
    }

    // Read the image data
    unsigned int data_size = *(unsigned int *)&header[2];
    fread(img->data, 1, data_size, fp);

    // Close the file
    fclose(fp);

    return 0;
}

int save_image(image *img, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        return -1;
    }

    // Write the header
    unsigned char header[14] = {
        'B', 'M',
        0, 0, 0, 0,
        0, 0,
        0, 0,
        24, 0,
        0, 0
    };

    *(unsigned int *)&header[2] = img->width * img->height * 3 + 54;
    *(unsigned int *)&header[10] = img->width;
    *(unsigned int *)&header[14] = img->height;

    fwrite(header, 1, 14, fp);

    // Write the image data
    fwrite(img->data, 1, img->width * img->height * 3, fp);

    // Close the file
    fclose(fp);

    return 0;
}

void invert_colors(image *img) {
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        img->data[i].red = 255 - img->data[i].red;
        img->data[i].green = 255 - img->data[i].green;
        img->data[i].blue = 255 - img->data[i].blue;
    }
}

void grayscale(image *img) {
    for (unsigned int i = 0; i < img->width * img->height; i++) {
        unsigned char gray = (img->data[i].red + img->data[i].green + img->data[i].blue) / 3;
        img->data[i].red = gray;
        img->data[i].green = gray;
        img->data[i].blue = gray;
    }
}

void blur(image *img) {
    image *blurred = create_image(img->width, img->height);
    if (blurred == NULL) {
        return;
    }

    for (unsigned int x = 0; x < img->width; x++) {
        for (unsigned int y = 0; y < img->height; y++) {
            unsigned int red = 0, green = 0, blue = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (x + i >= 0 && x + i < img->width && y + j >= 0 && y + j < img->height) {
                        red += img->data[(y + j) * img->width + (x + i)].red;
                        green += img->data[(y + j) * img->width + (x + i)].green;
                        blue += img->data[(y + j) * img->width + (x + i)].blue;
                    }
                }
            }
            blurred->data[y * img->width + x].red = red / 9;
            blurred->data[y * img->width + x].green = green / 9;
            blurred->data[y * img->width + x].blue = blue / 9;
        }
    }

    memcpy(img->data, blurred->data, img->width * img->height * sizeof(pixel));
    destroy_image(blurred);
}

void sharpen(image *img) {
    image *sharpened = create_image(img->width, img->height);
    if (sharpened == NULL) {
        return;
    }

    for (unsigned int x = 0; x < img->width; x++) {
        for (unsigned int y = 0; y < img->height; y++) {
            int red = 0, green = 0, blue = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (x + i >= 0 && x + i < img->width && y + j >= 0 && y + j < img->height) {
                        red += img->data[(y + j) * img->width + (x + i)].red;
                        green += img->data[(y + j) * img->width + (x + i)].green;
                        blue += img->data[(y + j) * img->width + (x + i)].blue;
                    }
                }
            }
            red -= 8 * img->data[y * img->width + x].red;
            green -= 8 * img->data[y * img->width + x].green;
            blue -= 8 * img->data[y * img->width + x].blue;
            sharpened->data[y * img->width + x].red = red;
            sharpened->data[y * img->width + x].green = green;
            sharpened->data[y * img->width + x].blue = blue;
        }
    }

    memcpy(img->data, sharpened->data, img->width * img->height * sizeof(pixel));
    destroy_image(sharpened);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input image> <output image>\n", argv[0]);
        return 1;
    }

    image *img = create_image(MAX_WIDTH, MAX_HEIGHT);
    if (img == NULL) {
        printf("Error: Could not create image.\n");
        return 1;
    }

    if (load_image(img, argv[1]) != 0) {
        printf("Error: Could not load image.\n");
        destroy_image(img);
        return 1;
    }

    // Apply the image processing filters
    invert_colors(img);
    grayscale(img);
    blur(img);
    sharpen(img);

    if (save_image(img, argv[2]) != 0) {
        printf("Error: Could not save image.\n");
        destroy_image(img);
        return 1;
    }

    destroy_image(img);
    return 0;
}