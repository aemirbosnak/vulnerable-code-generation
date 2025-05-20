//GPT-4o-mini DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Pixel;

typedef struct {
    Pixel *data;
    int width, height;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
void invert_image(Image *image);
void grayscale_image(Image *image);
void free_image(Image *image);
void print_usage();

int main(int argc, char *argv[]) {
    if (argc < 3) {
        print_usage();
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    Image *image = load_image(input_file);

    if (!image) {
        fprintf(stderr, "Error loading image: %s\n", input_file);
        return 1;
    }

    printf("Applying transformations...\n");

    if (argc == 4) {
        if (strcmp(argv[3], "invert") == 0) {
            invert_image(image);
            printf("Inverted colors of the image.\n");
        } else if (strcmp(argv[3], "grayscale") == 0) {
            grayscale_image(image);
            printf("Converted the image to grayscale.\n");
        } else {
            fprintf(stderr, "Unknown transformation: %s\n", argv[3]);
            free_image(image);
            return 1;
        }
    }

    save_image(output_file, image);
    printf("Saved transformed image to: %s\n", output_file);

    free_image(image);
    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) return NULL;

    int width, height;
    fscanf(file, "P6\n%d %d\n255\n", &width, &height);
    
    Image *image = malloc(sizeof(Image));
    image->data = malloc(width * height * sizeof(Pixel));
    image->width = width;
    image->height = height;

    fread(image->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) return;

    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = 255 - image->data[i].r;
        image->data[i].g = 255 - image->data[i].g;
        image->data[i].b = 255 - image->data[i].b;
    }
}

void grayscale_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        uint8_t gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

void free_image(Image *image) {
    free(image->data);
    free(image);
}

void print_usage() {
    printf("Usage: image_editor <input_file> <output_file> [invert|grayscale]\n");
    printf("Example: image_editor input.ppm output.ppm invert\n");
}