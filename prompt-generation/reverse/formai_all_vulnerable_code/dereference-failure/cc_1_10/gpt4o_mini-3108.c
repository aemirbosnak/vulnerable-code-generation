//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: automated
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} Pixel;

typedef struct {
    int width, height;
    Pixel *data;
} Image;

Image* load_image(const char* filename);
void save_image(const char* filename, Image *img);
void flip_image(Image *img);
void change_brightness(Image *img, int delta);
void change_contrast(Image *img, float factor);
void free_image(Image *img);

int main(int argc, char *argv[]) {
    if (argc < 5) {
        printf("Usage: %s <input_image> <output_image> <operation> [parameters]\n", argv[0]);
        printf("Operations:\n");
        printf("  flip\n");
        printf("  brightness <delta>\n");
        printf("  contrast <factor>\n");
        return 1;
    }

    const char *input_filename = argv[1];
    const char *output_filename = argv[2];
    const char *operation = argv[3];
    
    Image *img = load_image(input_filename);
    if (!img) {
        printf("Error loading image.\n");
        return 1;
    }

    if (strcmp(operation, "flip") == 0) {
        flip_image(img);
    } else if (strcmp(operation, "brightness") == 0) {
        if (argc < 5) {
            printf("Missing parameter for brightness.\n");
            free_image(img);
            return 1;
        }
        int delta = atoi(argv[4]);
        change_brightness(img, delta);
    } else if (strcmp(operation, "contrast") == 0) {
        if (argc < 5) {
            printf("Missing parameter for contrast.\n");
            free_image(img);
            return 1;
        }
        float factor = atof(argv[4]);
        change_contrast(img, factor);
    } else {
        printf("Unknown operation: %s\n", operation);
        free_image(img);
        return 1;
    }

    save_image(output_filename, img);
    free_image(img);
    return 0;
}

Image* load_image(const char* filename) {
    // Load a BMP or a PPM image
    // This is a placeholder function
    // In a real application, you would include code to read image files
    // Here, we'll create a simple placeholder image for demonstration
    Image *img = (Image*)malloc(sizeof(Image));
    img->width = 100;
    img->height = 100;
    img->data = (Pixel*)malloc(img->width * img->height * sizeof(Pixel));
    
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = rand() % 256;
        img->data[i].g = rand() % 256;
        img->data[i].b = rand() % 256;
    }
    return img;
}

void save_image(const char* filename, Image *img) {
    // Save a BMP or a PPM image
    // This is a placeholder function
    // In a real application, you would include code to save image files
    printf("Image saved to %s (Width: %d, Height: %d)\n", filename, img->width, img->height);
}

void flip_image(Image *img) {
    int width = img->width;
    int height = img->height;
    Pixel *flipped_data = (Pixel*)malloc(width * height * sizeof(Pixel));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            flipped_data[y * width + x] = img->data[y * width + (width - x - 1)];
        }
    }

    free(img->data);
    img->data = flipped_data;
    printf("Image flipped horizontally.\n");
}

void change_brightness(Image *img, int delta) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (img->data[i].r + delta > 255) ? 255 : (img->data[i].r + delta < 0) ? 0 : img->data[i].r + delta;
        img->data[i].g = (img->data[i].g + delta > 255) ? 255 : (img->data[i].g + delta < 0) ? 0 : img->data[i].g + delta;
        img->data[i].b = (img->data[i].b + delta > 255) ? 255 : (img->data[i].b + delta < 0) ? 0 : img->data[i].b + delta;
    }
    printf("Brightness changed by %d.\n", delta);
}

void change_contrast(Image *img, float factor) {
    for (int i = 0; i < img->width * img->height; i++) {
        img->data[i].r = (factor * (img->data[i].r - 128) + 128);
        img->data[i].g = (factor * (img->data[i].g - 128) + 128);
        img->data[i].b = (factor * (img->data[i].b - 128) + 128);

        if (img->data[i].r > 255) img->data[i].r = 255;
        if (img->data[i].r < 0) img->data[i].r = 0;
        if (img->data[i].g > 255) img->data[i].g = 255;
        if (img->data[i].g < 0) img->data[i].g = 0;
        if (img->data[i].b > 255) img->data[i].b = 255;
        if (img->data[i].b < 0) img->data[i].b = 0;
    }
    printf("Contrast changed by factor %.2f.\n", factor);
}

void free_image(Image *img) {
    free(img->data);
    free(img);
}