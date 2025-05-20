//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* loadPPM(const char *filename);
void savePPM(const char *filename, Image *img);
Image* flipImage(Image *img);
void adjustBrightnessContrast(Image *img, int brightness, float contrast);
void freeImage(Image *img);

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output_flipped.ppm> <output_adjusted.ppm> <brightness> <contrast>\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *img = loadPPM(argv[1]);
    if (!img) {
        fprintf(stderr, "Failed to load image %s.\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Flip the image
    Image *flippedImage = flipImage(img);
    savePPM(argv[2], flippedImage);
    freeImage(flippedImage);

    // Adjust brightness and contrast
    int brightness = atoi(argv[4]);
    float contrast = atof(argv[5]);
    adjustBrightnessContrast(img, brightness, contrast);
    savePPM(argv[3], img);
    
    freeImage(img);
    return EXIT_SUCCESS;
}

Image* loadPPM(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        return NULL;
    }

    char header[3];
    fscanf(fp, "%2s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fclose(fp);
        return NULL;
    }

    Image *img = malloc(sizeof(Image));
    fscanf(fp, "%d %d", &img->width, &img->height);
    int max;
    fscanf(fp, "%d", &max); // Read max color value
    fgetc(fp); // Consume the newline

    img->data = malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);

    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, fp);
    fclose(fp);
}

Image* flipImage(Image *img) {
    Image *flipped = malloc(sizeof(Image));
    flipped->width = img->width;
    flipped->height = img->height;
    flipped->data = malloc(img->width * img->height * sizeof(Pixel));

    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            flipped->data[y * img->width + x] = img->data[y * img->width + (img->width - 1 - x)];
        }
    }

    return flipped;
}

void adjustBrightnessContrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height; i++) {
        Pixel *p = &img->data[i];
        
        // Adjust brightness
        int r = p->r + brightness;
        int g = p->g + brightness;
        int b = p->b + brightness;

        // Adjust contrast
        r = ((r - 128) * contrast + 128);
        g = ((g - 128) * contrast + 128);
        b = ((b - 128) * contrast + 128);
        
        // Clamp values
        p->r = (r < 0) ? 0 : (r > 255) ? 255 : r;
        p->g = (g < 0) ? 0 : (g > 255) ? 255 : g;
        p->b = (b < 0) ? 0 : (b > 255) ? 255 : b;
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}