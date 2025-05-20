//FormAI DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: portable
// C Basic Image Processing: Flipping an image, Changing Brightness/Contrast example program

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

typedef struct {
    int width;
    int height;
    pixel *data;
} image;

// Function to load image from file
image *load_image(char *filename) {
    FILE *fp = fopen(filename, "rb");
    if(!fp) {
        printf("Error: Could not open file %s\n", filename);
        return NULL;
    }

    // Read image header
    char magic[2];
    int width, height, max_val;
    fscanf(fp, "%s\n%d %d\n%d\n", magic, &width, &height, &max_val);

    if(strcmp(magic, "P6") != 0) {
        printf("Error: Invalid file format. Expected P6\n");
        return NULL;
    }

    if(max_val > 255) {
        printf("Error: Unsupported max value. Max value must be less than or equal to 255\n");
        return NULL;
    }

    // Read image data
    pixel *data = malloc(sizeof(pixel) * width * height);
    fread(data, sizeof(pixel), width * height, fp);

    // Create image structure and return
    image *img = malloc(sizeof(image));
    img->width = width;
    img->height = height;
    img->data = data;
    fclose(fp);

    return img;
}

// Function to save image to file
void save_image(image *img, char *filename) {
    FILE *fp = fopen(filename, "wb");
    if(!fp) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }

    // Write image header
    fprintf(fp, "P6\n%d %d\n%d\n", img->width, img->height, 255);

    // Write image data
    fwrite(img->data, sizeof(pixel), img->width * img->height, fp);

    fclose(fp);
}

// Function to flip image horizontally
void flip_horizontally(image *img) {
    pixel temp;
    for(int y = 0; y < img->height; y++) {
        for(int x = 0; x < img->width / 2; x++) {
            temp = img->data[y * img->width + x];
            img->data[y * img->width + x] = img->data[y * img->width + (img->width - x - 1)];
            img->data[y * img->width + (img->width - x - 1)] = temp;
        }
    }
}

// Function to adjust brightness and contrast of image
void adjust_brightness_contrast(image *img, int brightness, int contrast) {
    float factor = (259 * (contrast + 255)) / (255 * (259 - contrast));
    for(int y = 0; y < img->height; y++) {
        for(int x = 0; x < img->width; x++) {
            pixel *p = &img->data[y * img->width + x];
            p->r = factor * (p->r - 128) + 128 + brightness;
            p->g = factor * (p->g - 128) + 128 + brightness;
            p->b = factor * (p->b - 128) + 128 + brightness;
        }
    }
}

int main() {
    // Load image from file
    image *img = load_image("image.ppm");
    if(!img) {
        return 1;
    }

    // Flip image horizontally
    flip_horizontally(img);

    // Adjust brightness and contrast
    adjust_brightness_contrast(img, 50, 30);

    // Save modified image to file
    save_image(img, "modified_image.ppm");

    // Free memory allocated for image
    free(img->data);
    free(img);

    return 0;
}