//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

Image *read_image(const char *filename) {
    Image *image = malloc(sizeof(Image));
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("fopen");
        return NULL;
    }

    // Read header
    unsigned char header[54];
    if (fread(header, 54, 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        free(image);
        return NULL;
    }

    // Check if it's a BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "%s is not a BMP file.\n", filename);
        fclose(fp);
        free(image);
        return NULL;
    }

    // Read width and height
    image->width = *(int *)&header[18];
    image->height = *(int *)&header[22];

    // Read data
    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        perror("malloc");
        fclose(fp);
        free(image);
        return NULL;
    }
    if (fread(image->data, image->width * image->height * 3, 1, fp) != 1) {
        perror("fread");
        fclose(fp);
        free(image->data);
        free(image);
        return NULL;
    }

    fclose(fp);
    return image;
}

void write_image(const char *filename, Image *image) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("fopen");
        return;
    }

    // Write header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(int *)&header[2] = 54 + image->width * image->height * 3;
    *(int *)&header[10] = 54;
    *(int *)&header[14] = 40;
    *(int *)&header[18] = image->width;
    *(int *)&header[22] = image->height;
    *(short *)&header[26] = 1;
    *(short *)&header[28] = 24;
    *(int *)&header[30] = 0;
    *(int *)&header[34] = image->width * image->height * 3;
    *(int *)&header[38] = 0;
    *(int *)&header[42] = 0;
    *(int *)&header[46] = 0;
    *(int *)&header[50] = 0;
    if (fwrite(header, 54, 1, fp) != 1) {
        perror("fwrite");
        fclose(fp);
        return;
    }

    // Write data
    if (fwrite(image->data, image->width * image->height * 3, 1, fp) != 1) {
        perror("fwrite");
        fclose(fp);
        return;
    }

    fclose(fp);
}

void flip_image_horizontal(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            for (int k = 0; k < 3; k++) {
                unsigned char temp = image->data[i * image->width * 3 + j * 3 + k];
                image->data[i * image->width * 3 + j * 3 + k] = image->data[i * image->width * 3 + (image->width - j - 1) * 3 + k];
                image->data[i * image->width * 3 + (image->width - j - 1) * 3 + k] = temp;
            }
        }
    }
}

void flip_image_vertical(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                unsigned char temp = image->data[i * image->width * 3 + j * 3 + k];
                image->data[i * image->width * 3 + j * 3 + k] = image->data[(image->height - i - 1) * image->width * 3 + j * 3 + k];
                image->data[(image->height - i - 1) * image->width * 3 + j * 3 + k] = temp;
            }
        }
    }
}

void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int value = image->data[i * image->width * 3 + j * 3 + k] + brightness;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = value;
            }
        }
    }
}

void change_contrast(Image *image, int contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            for (int k = 0; k < 3; k++) {
                int value = image->data[i * image->width * 3 + j * 3 + k] * contrast / 100;
                if (value < 0) {
                    value = 0;
                } else if (value > 255) {
                    value = 255;
                }
                image->data[i * image->width * 3 + j * 3 + k] = value;
            }
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input image> [<output image>]\n", argv[0]);
        return 1;
    }

    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip image horizontally
    flip_image_horizontal(image);

    // Change brightness
    change_brightness(image, 50);

    // Change contrast
    change_contrast(image, 120);

    // Write output image
    if (argc > 2) {
        write_image(argv[2], image);
    } else {
        write_image("output.bmp", image);
    }

    free(image->data);
    free(image);
    return 0;
}