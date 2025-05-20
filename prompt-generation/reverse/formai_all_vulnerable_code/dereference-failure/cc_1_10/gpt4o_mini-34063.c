//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(fp, "%2s", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Error: Not a valid PPM file\n");
        fclose(fp);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
    int max_colors;
    fscanf(fp, "%d", &max_colors);
    fgetc(fp); // Eat the newline after max colors

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error: Unable to open file %s\n", filename);
        return;
    }

    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

void flip_image_horizontal(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void change_brightness(Image *img, int delta) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + delta > 255) ? 255 : (img->data[i].r + delta < 0) ? 0 : img->data[i].r + delta;
        img->data[i].g = (img->data[i].g + delta > 255) ? 255 : (img->data[i].g + delta < 0) ? 0 : img->data[i].g + delta;
        img->data[i].b = (img->data[i].b + delta > 255) ? 255 : (img->data[i].b + delta < 0) ? 0 : img->data[i].b + delta;
    }
}

void change_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (factor * (img->data[i].r - 128) + 128);
        img->data[i].g = (factor * (img->data[i].g - 128) + 128);
        img->data[i].b = (factor * (img->data[i].b - 128) + 128);
        
        img->data[i].r = (img->data[i].r > 255) ? 255 : (img->data[i].r < 0) ? 0 : img->data[i].r;
        img->data[i].g = (img->data[i].g > 255) ? 255 : (img->data[i].g < 0) ? 0 : img->data[i].g;
        img->data[i].b = (img->data[i].b > 255) ? 255 : (img->data[i].b < 0) ? 0 : img->data[i].b;
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <brightness_delta> <contrast_factor>\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int brightness_delta = atoi(argv[3]);
    float contrast_factor = atof(argv[4]);

    Image *img = load_ppm(input_file);
    if (!img) return 1;

    flip_image_horizontal(img);
    change_brightness(img, brightness_delta);
    change_contrast(img, contrast_factor);

    save_ppm(output_file, img);
    free_image(img);

    return 0;
}