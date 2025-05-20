//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Pixel {
    unsigned char r, g, b;
} Pixel;

typedef struct Image {
    int width, height;
    Pixel *pixels;
} Image;

Image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        perror("Error opening file");
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        perror("Error allocating memory for image");
        fclose(fp);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, fp);
    fread(&image->height, sizeof(int), 1, fp);

    image->pixels = malloc(image->width * image->height * sizeof(Pixel));
    if (!image->pixels) {
        perror("Error allocating memory for image pixels");
        free(image);
        fclose(fp);
        return NULL;
    }

    fread(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);

    return image;
}

void save_image(Image *image, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Error opening file");
        return;
    }

    fwrite(&image->width, sizeof(int), 1, fp);
    fwrite(&image->height, sizeof(int), 1, fp);
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, fp);
    fclose(fp);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height / 2; j++) {
            Pixel temp = image->pixels[i * image->height + j];
            image->pixels[i * image->height + j] = image->pixels[i * image->height + image->height - j - 1];
            image->pixels[i * image->height + image->height - j - 1] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, float brightness, float contrast) {
    for (int i = 0; i < image->width; i++) {
        for (int j = 0; j < image->height; j++) {
            Pixel *pixel = &image->pixels[i * image->height + j];

            // Change brightness
            pixel->r = (unsigned char) (pixel->r * brightness);
            pixel->g = (unsigned char) (pixel->g * brightness);
            pixel->b = (unsigned char) (pixel->b * brightness);

            // Change contrast
            pixel->r = (unsigned char) ((pixel->r - 128) * contrast + 128);
            pixel->g = (unsigned char) ((pixel->g - 128) * contrast + 128);
            pixel->b = (unsigned char) ((pixel->b - 128) * contrast + 128);
        }
    }
}

int main() {
    Image *image = load_image("image.bmp");
    if (!image) {
        return -1;
    }

    // Flip the image
    flip_image(image);

    // Change the brightness and contrast
    change_brightness_contrast(image, 1.2, 1.5);

    // Save the image
    save_image(image, "new_image.bmp");

    free(image->pixels);
    free(image);

    return 0;
}