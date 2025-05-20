//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL_VALUE 255

typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

Image* load_image(const char *filename);
void save_image(const char *filename, Image *image);
Image* flip_image(Image *image);
void adjust_brightness(Image *image, int adjustment);
void free_image(Image *image);

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <input.pgm> <output.pgm> <brightness adjustment> [flip]\n", argv[0]);
        return 1;
    }

    const char *input_file = argv[1];
    const char *output_file = argv[2];
    int brightness_adjustment = atoi(argv[3]);
    int flip_image_flag = argc > 4 && strcmp(argv[4], "flip") == 0;

    Image *image = load_image(input_file);
    if (image == NULL) {
        fprintf(stderr, "Error loading image.\n");
        return 1;
    }

    if (flip_image_flag) {
        Image *flipped_image = flip_image(image);
        free_image(image);
        image = flipped_image;
    }

    adjust_brightness(image, brightness_adjustment);
    save_image(output_file, image);
    free_image(image);

    return 0;
}

Image* load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        perror("Unable to open file");
        return NULL;
    }

    char buffer[16];
    if (!fgets(buffer, sizeof(buffer), file)) {
        perror("Invalid PGM file");
        fclose(file);
        return NULL;
    }
    
    if (buffer[0] != 'P' || buffer[1] != '5') {
        fprintf(stderr, "Unsupported PGM format (must be 'P5').\n");
        fclose(file);
        return NULL;
    }

    // Continue reading the header
    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // read the newline after maxval

    unsigned char *data = (unsigned char *)malloc(width * height);
    fread(data, 1, width * height, file);
    fclose(file);

    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        perror("Unable to open file for writing");
        return;
    }

    fprintf(file, "P5\n%d %d\n%d\n", image->width, image->height, MAX_PIXEL_VALUE);
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

Image* flip_image(Image *image) {
    Image *flipped_image = (Image *)malloc(sizeof(Image));
    flipped_image->width = image->width;
    flipped_image->height = image->height;
    flipped_image->data = (unsigned char *)malloc(image->width * image->height);

    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            flipped_image->data[y * image->width + (image->width - 1 - x)] =
                image->data[y * image->width + x];
        }
    }

    return flipped_image;
}

void adjust_brightness(Image *image, int adjustment) {
    for (int i = 0; i < image->width * image->height; i++) {
        int new_value = image->data[i] + adjustment;
        if (new_value > MAX_PIXEL_VALUE) new_value = MAX_PIXEL_VALUE;
        if (new_value < 0) new_value = 0;
        image->data[i] = new_value;
    }
}

void free_image(Image *image) {
    if (image) {
        free(image->data);
        free(image);
    }
}