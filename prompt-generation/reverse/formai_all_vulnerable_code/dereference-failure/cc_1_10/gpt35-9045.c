//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define red_val(pixel) (pixel & 0xFF)
#define green_val(pixel) ((pixel >> 8) & 0xFF)
#define blue_val(pixel) ((pixel >> 16) & 0xFF)

typedef unsigned int uint;

typedef struct {
    uint width;
    uint height;
    uint* pixels;
} Image;

Image load_image(char* filename) {
    Image img;
    FILE* fp = fopen(filename, "rb");
    if (!fp) {
        printf("Cannot open file!\n");
        exit(1);
    }
    char version[3];
    fgets(version, 3, fp);
    if (strcmp(version, "P6") != 0) {
        printf("Invalid file format!\n");
        exit(1);
    }
    int c = fgetc(fp);
    while (c == '#') {
        while (fgetc(fp) != '\n') {}
        c = fgetc(fp);
    }
    ungetc(c, fp);
    fscanf(fp, "%u %u", &img.width, &img.height);
    uint maxval;
    fscanf(fp, "%u", &maxval);
    if (maxval != 255) {
        printf("Only RGB 24-bit images are supported!\n");
        exit(1);
    }
    fgetc(fp);
    img.pixels = (uint*)malloc(sizeof(uint) * img.width * img.height);
    fread(img.pixels, sizeof(uint), img.width * img.height, fp);
    fclose(fp);
    return img;
}

void save_image(Image img, char* filename) {
    FILE* fp = fopen(filename, "wb");
    if (!fp) {
        printf("Cannot create output file!\n");
        exit(1);
    }
    fprintf(fp, "P6\n");
    fprintf(fp, "%d %d\n", img.width, img.height);
    fprintf(fp, "255\n");
    fwrite(img.pixels, sizeof(uint), img.width * img.height, fp);
    fclose(fp);
}

void flip_image(Image* img) {
    uint* temp = (uint*)malloc(sizeof(uint) * img->width);
    for (uint i = 0; i < img->height / 2; i++) {
        memcpy(temp, img->pixels + i * img->width, sizeof(uint) * img->width);
        memcpy(img->pixels + i * img->width, img->pixels + (img->height - i - 1) * img->width, sizeof(uint) * img->width);
        memcpy(img->pixels + (img->height - i - 1) * img->width, temp, sizeof(uint) * img->width);
    }
    free(temp);
}

void adjust_brightness(Image* img, int value) {
    for (uint i = 0; i < img->width * img->height; i++) {
        uint pixel = img->pixels[i];
        int red = red_val(pixel) + value;
        int green = green_val(pixel) + value;
        int blue = blue_val(pixel) + value;
        red = (red < 0) ? 0 : (red > 255) ? 255 : red;
        green = (green < 0) ? 0 : (green > 255) ? 255 : green;
        blue = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;
        img->pixels[i] = (red & 0xFF) | ((green & 0xFF) << 8) | ((blue & 0xFF) << 16);
    }
}

void adjust_contrast(Image* img, float value) {
    int intensity_sum = 0;
    for (uint i = 0; i < img->width * img->height; i++) {
        uint pixel = img->pixels[i];
        int red = red_val(pixel);
        int green = green_val(pixel);
        int blue = blue_val(pixel);
        intensity_sum += (red + green + blue) / 3;
    }
    float average_intensity = (float)intensity_sum / (float)(img->width * img->height);
    float factor = (259.0f * (value + 255.0f)) / (255.0f * (259.0f - value));
    for (uint i = 0; i < img->width * img->height; i++) {
        uint pixel = img->pixels[i];
        int red = red_val(pixel);
        int green = green_val(pixel);
        int blue = blue_val(pixel);
        red = (int)((factor * ((float)red - average_intensity)) + average_intensity);
        green = (int)((factor * ((float)green - average_intensity)) + average_intensity);
        blue = (int)((factor * ((float)blue - average_intensity)) + average_intensity);
        red = (red < 0) ? 0 : (red > 255) ? 255 : red;
        green = (green < 0) ? 0 : (green > 255) ? 255 : green;
        blue = (blue < 0) ? 0 : (blue > 255) ? 255 : blue;
        img->pixels[i] = (red & 0xFF) | ((green & 0xFF) << 8) | ((blue & 0xFF) << 16);
    }
}

int main() {
    Image img = load_image("input.ppm");
    flip_image(&img);
    adjust_brightness(&img, 20);
    adjust_contrast(&img, 1.5f);
    save_image(img, "output.ppm");
    free(img.pixels);
    return 0;
}