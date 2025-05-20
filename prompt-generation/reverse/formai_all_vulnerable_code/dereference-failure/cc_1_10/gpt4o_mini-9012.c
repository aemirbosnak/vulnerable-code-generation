//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: introspective
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *pixels;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, const Image *image);
void free_image(Image *image);
void flip_image(Image *image);
void adjust_brightness(Image *image, int adjustment);
void adjust_contrast(Image *image, float factor);
void print_image_info(const Image *image);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <image_file> <out_file> <operation> [args]\n", argv[0]);
        printf("Operations:\n");
        printf("  flip\n");
        printf("  brightness <value>\n");
        printf("  contrast <factor>\n");
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    const char *operation = argv[3];

    Image *image = load_image(input_file);
    if (!image) {
        printf("Error loading image.\n");
        return 1;
    }

    print_image_info(image);

    if (strcmp(operation, "flip") == 0) {
        flip_image(image);
    } else if (strcmp(operation, "brightness") == 0) {
        if (argc != 5) {
            printf("Usage: %s <image_file> <out_file> brightness <value>\n", argv[0]);
            free_image(image);
            return 1;
        }
        int brightness_adjustment = atoi(argv[4]);
        adjust_brightness(image, brightness_adjustment);
    } else if (strcmp(operation, "contrast") == 0) {
        if (argc != 5) {
            printf("Usage: %s <image_file> <out_file> contrast <factor>\n", argv[0]);
            free_image(image);
            return 1;
        }
        float contrast_factor = atof(argv[4]);
        adjust_contrast(image, contrast_factor);
    } else {
        printf("Unknown operation: %s\n", operation);
        free_image(image);
        return 1;
    }

    save_image(output_file, image);

    free_image(image);
    return 0;
}

Image* load_image(const char *filename) {
    // Dummy implementation just for structure purposes
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = 100; // Let's assume a 100x100 image for simplicity
    image->height = 100;
    image->pixels = (Pixel *)malloc(image->width * image->height * sizeof(Pixel));

    // Example initialization (in a real program, you would read from a file)
    for (int i = 0; i < image->width * image->height; i++) {
        image->pixels[i].r = rand() % 256;
        image->pixels[i].g = rand() % 256;
        image->pixels[i].b = rand() % 256;
    }
    
    return image;
}

void save_image(const char *filename, const Image *image) {
    // Dummy implementation just for structure purposes
    printf("Saving image to %s: (%d x %d) pixels\n", filename, image->width, image->height);
}

void free_image(Image *image) {
    if(image) {
        free(image->pixels);
        free(image);
    }
}

void flip_image(Image *image) {
    int width = image->width;
    int height = image->height;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width / 2; x++) {
            int opposite_x = width - x - 1;
            Pixel temp = image->pixels[y * width + x];
            image->pixels[y * width + x] = image->pixels[y * width + opposite_x];
            image->pixels[y * width + opposite_x] = temp;
        }
    }
    printf("Image flipped horizontally.\n");
}

void adjust_brightness(Image *image, int adjustment) {
    int width = image->width;
    int height = image->height;
    for (int i = 0; i < width * height; i++) {
        image->pixels[i].r = (unsigned char)(fmin(fmax(image->pixels[i].r + adjustment, 0), 255));
        image->pixels[i].g = (unsigned char)(fmin(fmax(image->pixels[i].g + adjustment, 0), 255));
        image->pixels[i].b = (unsigned char)(fmin(fmax(image->pixels[i].b + adjustment, 0), 255));
    }
    printf("Brightness adjusted by %d.\n", adjustment);
}

void adjust_contrast(Image *image, float factor) {
    int width = image->width;
    int height = image->height;
    for (int i = 0; i < width * height; i++) {
        image->pixels[i].r = (unsigned char)(fmin(fmax(((image->pixels[i].r - 128) * factor + 128), 0), 255));
        image->pixels[i].g = (unsigned char)(fmin(fmax(((image->pixels[i].g - 128) * factor + 128), 0), 255));
        image->pixels[i].b = (unsigned char)(fmin(fmax(((image->pixels[i].b - 128) * factor + 128), 0), 255));
    }
    printf("Contrast factor applied: %.2f.\n", factor);
}

void print_image_info(const Image *image) {
    printf("Image info: width = %d, height = %d\n", image->width, image->height);
}