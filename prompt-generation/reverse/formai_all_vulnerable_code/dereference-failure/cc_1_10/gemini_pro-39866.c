//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// RGB pixel struct
typedef struct {
    unsigned char r, g, b;
} pixel;

// Image struct
typedef struct {
    int width, height;
    pixel *data;
} image;

// Function to flip an image horizontally
void flip_horizontal(image *img) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width / 2; x++) {
            pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + img->width - x - 1];
            img->data[y * img->width + img->width - x - 1] = temp;
        }
    }
}

// Function to flip an image vertically
void flip_vertical(image *img) {
    for (int x = 0; x < img->width; x++) {
        for (int y = 0; y < img->height / 2; y++) {
            pixel temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[(img->height - y - 1) * img->width + x];
            img->data[(img->height - y - 1) * img->width + x] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(image *img, int brightness) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int new_r = img->data[y * img->width + x].r + brightness;
            int new_g = img->data[y * img->width + x].g + brightness;
            int new_b = img->data[y * img->width + x].b + brightness;
            // Clamp the values to 0-255
            if (new_r > 255) new_r = 255;
            if (new_g > 255) new_g = 255;
            if (new_b > 255) new_b = 255;
            img->data[y * img->width + x].r = new_r;
            img->data[y * img->width + x].g = new_g;
            img->data[y * img->width + x].b = new_b;
        }
    }
}

// Function to change the contrast of an image
void change_contrast(image *img, double contrast) {
    for (int y = 0; y < img->height; y++) {
        for (int x = 0; x < img->width; x++) {
            int new_r = img->data[y * img->width + x].r * contrast;
            int new_g = img->data[y * img->width + x].g * contrast;
            int new_b = img->data[y * img->width + x].b * contrast;
            // Clamp the values to 0-255
            if (new_r > 255) new_r = 255;
            if (new_g > 255) new_g = 255;
            if (new_b > 255) new_b = 255;
            img->data[y * img->width + x].r = new_r;
            img->data[y * img->width + x].g = new_g;
            img->data[y * img->width + x].b = new_b;
        }
    }
}

// Function to save an image to a PPM file
void save_ppm(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    fprintf(fp, "P6\n%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);
    fclose(fp);
}

// Function to load an image from a PPM file
image *load_ppm(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error: could not open file %s\n", filename);
        return NULL;
    }
    char line[1024];
    fgets(line, 1024, fp); // Skip the header
    int width, height;
    fscanf(fp, "%d %d\n", &width, &height);
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = malloc(sizeof(pixel) * width * height);
    fread(img->data, sizeof(pixel), width * height, fp);
    fclose(fp);
    return img;
}

int main() {
    // Load an image from a file
    image *img = load_ppm("test.ppm");
    if (!img) {
        fprintf(stderr, "Error: could not load image\n");
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(img);

    // Change the brightness of the image
    change_brightness(img, 30);

    // Change the contrast of the image
    change_contrast(img, 1.5);

    // Save the image to a file
    save_ppm(img, "output.ppm");

    // Free the image data
    free(img->data);
    free(img);

    return 0;
}