//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;

typedef struct {
    int width, height;
    byte *data;
} Image;

Image *loadPPM(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(1);
    }

    Image *img = malloc(sizeof(Image));

    char header[3];
    fscanf(file, "%2s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Unsupported PPM format\n");
        exit(1);
    }

    fscanf(file, "%d %d", &img->width, &img->height);
    int maxval;
    fscanf(file, "%d", &maxval);
    fgetc(file); // consume newline

    img->data = malloc(img->width * img->height * 3 * sizeof(byte));
    fread(img->data, sizeof(byte), img->width * img->height * 3, file);
    fclose(file);

    return img;
}

void savePPM(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Failed to open file %s for writing\n", filename);
        exit(1);
    }

    fprintf(file, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(byte), img->width * img->height * 3, file);
    fclose(file);
}

void flipImage(Image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            int idx1 = (y * img->width + x) * 3;
            int idx2 = (y * img->width + (img->width - 1 - x)) * 3;

            // Swap pixels
            for (int c = 0; c < 3; c++) {
                byte temp = img->data[idx1 + c];
                img->data[idx1 + c] = img->data[idx2 + c];
                img->data[idx2 + c] = temp;
            }
        }
    }
}

void changeBrightnessContrast(Image *img, int brightness, float contrast) {
    for (int i = 0; i < img->width * img->height * 3; i++) {
        int newValue = (int)(contrast * (img->data[i] - 128) + 128 + brightness);
        img->data[i] = (byte)(newValue < 0 ? 0 : (newValue > 255 ? 255 : newValue));
    }
}

void freeImage(Image *img) {
    free(img->data);
    free(img);
}

int main() {
    printf("🎉 Welcome to the Amazing Image Processor! 🎨\n");

    const char *inputFile = "input.ppm";
    const char *outputFileFlip = "output_flipped.ppm";
    const char *outputFileBright = "output_bright.ppm";

    Image *img = loadPPM(inputFile);
    printf("Loaded image: %dx%d\n", img->width, img->height);

    printf("Flipping the image... 🌀\n");
    flipImage(img);
    savePPM(outputFileFlip, img);
    printf("Flipped image saved as %s! 😃\n", outputFileFlip);

    // Adjust brightness and contrast
    int brightness = 30;  // Brightens the image
    float contrast = 1.2; // Increases contrast
    printf("Changing brightness by %d and contrast by %.2f... 🎈\n", brightness, contrast);
    changeBrightnessContrast(img, brightness, contrast);
    savePPM(outputFileBright, img);
    printf("Brightened and contrasted image saved as %s! 🎉\n", outputFileBright);

    freeImage(img);
    printf("🎊 All done! Enjoy your images! 🖼️\n");
    
    return 0;
}