//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_ppm(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        return NULL;
    }

    char header[3];
    fscanf(file, "%s\n", header);
    if (header[0] != 'P' || header[1] != '6') {
        printf("Unsupported image format\n");
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d\n255\n", &img->width, &img->height);
    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
    
    return img;
}

void save_ppm(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        printf("Unable to open file %s\n", filename);
        return;
    }
    
    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int opposite_x = img->width - x - 1;
            Pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + opposite_x];
            img->data[y * img->width + opposite_x] = temp;
        }
    }
    printf("Image flipped horizontally!\n");
}

void adjust_brightness(Image *img, int brightness) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + brightness > 255) ? 255 : 
                         (img->data[i].r + brightness < 0) ? 0 : 
                         img->data[i].r + brightness;

        img->data[i].g = (img->data[i].g + brightness > 255) ? 255 : 
                         (img->data[i].g + brightness < 0) ? 0 : 
                         img->data[i].g + brightness;

        img->data[i].b = (img->data[i].b + brightness > 255) ? 255 : 
                         (img->data[i].b + brightness < 0) ? 0 : 
                         img->data[i].b + brightness;
    }
    printf("Brightness adjusted by %d!\n", brightness);
}

void adjust_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r - 128) * factor + 128;
        img->data[i].g = (img->data[i].g - 128) * factor + 128;
        img->data[i].b = (img->data[i].b - 128) * factor + 128;

        // Clamping values
        if (img->data[i].r < 0) img->data[i].r = 0;
        if (img->data[i].r > 255) img->data[i].r = 255;
        if (img->data[i].g < 0) img->data[i].g = 0;
        if (img->data[i].g > 255) img->data[i].g = 255;
        if (img->data[i].b < 0) img->data[i].b = 0;
        if (img->data[i].b > 255) img->data[i].b = 255;
    }
    printf("Contrast adjusted by a factor of %.2f!\n", factor);
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}

int main() {
    const char *input_file = "input.ppm";
    const char *output_file = "output.ppm";

    Image *img = load_ppm(input_file);
    if (!img) return 1;

    flip_image(img);
    adjust_brightness(img, 30); // Increase brightness
    adjust_contrast(img, 1.2f); // Increase contrast

    save_ppm(output_file, img);
    
    free_image(img);
    printf("Image processing completed! Check output.ppm for results.\n");
    return 0;
}