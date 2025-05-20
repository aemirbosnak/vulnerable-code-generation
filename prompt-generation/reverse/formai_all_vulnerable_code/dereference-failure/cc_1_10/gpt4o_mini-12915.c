//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int amount);
void adjust_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output.ppm> <flip(1/0)> <brightness_offset> <contrast_factor>\n", argv[0]);
        return 1;
    }

    int flip = atoi(argv[3]);
    int brightness_offset = atoi(argv[4]);
    float contrast_factor = atof(argv[5]);

    Image *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image: %s\n", argv[1]);
        return 1;
    }

    if (flip) {
        flip_image(img);
    }
    
    adjust_brightness(img, brightness_offset);
    adjust_contrast(img, contrast_factor);
    
    save_image(argv[2], img);
    free_image(img);
    
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char buff[16];
    if (!fgets(buff, sizeof(buff), file)) return NULL;
    if (buff[0] != 'P' || buff[1] != '6') {
        fprintf(stderr, "Not a valid PPM file.\n");
        fclose(file);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_color_value;
    fscanf(file, "%d", &max_color_value);
    fgetc(file); // Read the newline character

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
            img->data[y * img->width + (img->width - 1 - x)] = temp;
        }
    }
}

void adjust_brightness(Image *img, int amount) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + amount > 255) ? 255 : (img->data[i].r + amount < 0) ? 0 : img->data[i].r + amount;
        img->data[i].g = (img->data[i].g + amount > 255) ? 255 : (img->data[i].g + amount < 0) ? 0 : img->data[i].g + amount;
        img->data[i].b = (img->data[i].b + amount > 255) ? 255 : (img->data[i].b + amount < 0) ? 0 : img->data[i].b + amount;
    }
}

void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r - 128) * factor + 128;
        img->data[i].g = (img->data[i].g - 128) * factor + 128;
        img->data[i].b = (img->data[i].b - 128) * factor + 128;
        
        if (img->data[i].r > 255) img->data[i].r = 255;
        if (img->data[i].g > 255) img->data[i].g = 255;
        if (img->data[i].b > 255) img->data[i].b = 255;
        if (img->data[i].r < 0) img->data[i].r = 0;
        if (img->data[i].g < 0) img->data[i].g = 0;
        if (img->data[i].b < 0) img->data[i].b = 0;
    }
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}