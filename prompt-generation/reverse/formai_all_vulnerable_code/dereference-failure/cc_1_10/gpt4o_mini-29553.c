//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *img);
void flip_image(Image *img);
void adjust_brightness(Image *img, int value);
void adjust_contrast(Image *img, double factor);
void free_image(Image *img);
void print_image_details(Image *img);

int main(int argc, char **argv) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input_image> <output_image> <flip (0 or 1)> <brightness_adjustment> <contrast_factor>\n", argv[0]);
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    int flip = atoi(argv[3]);
    int brightness_adjustment = atoi(argv[4]);
    double contrast_factor = atof(argv[5]);

    // Load the input image
    Image *img = load_image(input_filename);
    if (!img) {
        fprintf(stderr, "Error: Could not load image.\n");
        return 1;
    }

    // Print image details
    print_image_details(img);

    // Flip the image if requested
    if (flip) {
        flip_image(img);
        printf("Image flipped.\n");
    }

    // Adjust brightness
    if (brightness_adjustment != 0) {
        adjust_brightness(img, brightness_adjustment);
        printf("Brightness adjusted by %d.\n", brightness_adjustment);
    }

    // Adjust contrast
    if (contrast_factor != 1.0) {
        adjust_contrast(img, contrast_factor);
        printf("Contrast adjusted by factor of %.2f.\n", contrast_factor);
    }

    // Save the processed image
    save_image(output_filename, img);
    printf("Processed image saved as %s\n", output_filename);

    // Free allocated memory
    free_image(img);

    return 0;
}

Image* load_image(const char *filename) {
    // For simplicity, let's assume a very basic PPM (P6) format loading
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    char buf[16];
    fgets(buf, sizeof(buf), file);
    if (buf[0] != 'P' || buf[1] != '6') {
        fclose(file);
        return NULL;
    }

    Image *img = (Image *)malloc(sizeof(Image));
    fscanf(file, "%d %d", &img->width, &img->height);
    int max_val;
    fscanf(file, "%d", &max_val);
    fgetc(file); // skip the newline after the max value

    img->data = (Pixel *)malloc(img->width * img->height * sizeof(Pixel));
    fread(img->data, sizeof(Pixel), img->width * img->height, file);

    fclose(file);
    return img;
}

void save_image(const char *filename, Image *img) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P6\n");
    fprintf(file, "%d %d\n255\n", img->width, img->height);
    fwrite(img->data, sizeof(Pixel), img->width * img->height, file);
    fclose(file);
}

void flip_image(Image *img) {
    int row_size = img->width * sizeof(Pixel);
    for (int i = 0; i < img->height / 2; i++) {
        for (int j = 0; j < img->width; j++) {
            Pixel temp = img->data[i * img->width + j];
            img->data[i * img->width + j] = img->data[(img->height - 1 - i) * img->width + j];
            img->data[(img->height - 1 - i) * img->width + j] = temp;
        }
    }
}

void adjust_brightness(Image *img, int value) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t) fmin(255, fmax(0, img->data[i].r + value));
        img->data[i].g = (uint8_t) fmin(255, fmax(0, img->data[i].g + value));
        img->data[i].b = (uint8_t) fmin(255, fmax(0, img->data[i].b + value));
    }
}

void adjust_contrast(Image *img, double factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (uint8_t) fmin(255, fmax(0, (int)((img->data[i].r - 128) * factor + 128)));
        img->data[i].g = (uint8_t) fmin(255, fmax(0, (int)((img->data[i].g - 128) * factor + 128)));
        img->data[i].b = (uint8_t) fmin(255, fmax(0, (int)((img->data[i].b - 128) * factor + 128)));
    }
}

void free_image(Image *img) {
    if (img) {
        free(img->data);
        free(img);
    }
}

void print_image_details(Image *img) {
    if (img) {
        printf("Image details: Width = %d, Height = %d\n", img->width, img->height);
    }
}