//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} Pixel;

typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Image;

Image* read_ppm(const char* filename);
void write_ppm(const char* filename, Image* img);
void flip_image(Image* img);
void adjust_brightness_contrast(Image* img, int brightness, float contrast);
void free_image(Image* img);

int main(int argc, char* argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input.ppm> <output.ppm> <brightness> <contrast>\n", argv[0]);
        return 1;
    }

    const char* input_filename = argv[1];
    const char* output_filename = argv[2];
    int brightness = atoi(argv[3]);
    float contrast = atof(argv[4]);

    Image* img = read_ppm(input_filename);
    if (!img) {
        fprintf(stderr, "Error reading image.\n");
        return 1;
    }

    flip_image(img);
    adjust_brightness_contrast(img, brightness, contrast);
    
    write_ppm(output_filename, img);
    free_image(img);
  
    printf("Image processing completed successfully.\n");
    return 0;
}

Image* read_ppm(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }
    
    char header[3];
    fscanf(file, "%s\n", header);
    if (strcmp(header, "P6") != 0) {
        fprintf(stderr, "Unsupported PPM format. Only P6 is supported.\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d\n%d\n", &width, &height, &maxval);

    Image* img = malloc(sizeof(Image));
    img->width = width;
    img->height = height;
    img->pixels = malloc(sizeof(Pixel) * width * height);
    
    fread(img->pixels, sizeof(Pixel), width * height, file);
    fclose(file);
    return img;
}

void write_ppm(const char* filename, Image* img) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->pixels, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image* img) {
    int width = img->width;
    int height = img->height;
    
    for (int y = 0; y < height / 2; ++y) {
        for (int x = 0; x < width; ++x) {
            Pixel temp = img->pixels[y * width + x];
            img->pixels[y * width + x] = img->pixels[(height - 1 - y) * width + x];
            img->pixels[(height - 1 - y) * width + x] = temp;
        }
    }
}

void adjust_brightness_contrast(Image* img, int brightness, float contrast) {
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            Pixel* p = &img->pixels[y * img->width + x];

            int r = (int)(p->r * contrast + brightness);
            int g = (int)(p->g * contrast + brightness);
            int b = (int)(p->b * contrast + brightness);

            p->r = r < 0 ? 0 : (r > 255 ? 255 : r);
            p->g = g < 0 ? 0 : (g > 255 ? 255 : g);
            p->b = b < 0 ? 0 : (b > 255 ? 255 : b);
        }
    }
}

void free_image(Image* img) {
    if (img) {
        free(img->pixels);
        free(img);
    }
}