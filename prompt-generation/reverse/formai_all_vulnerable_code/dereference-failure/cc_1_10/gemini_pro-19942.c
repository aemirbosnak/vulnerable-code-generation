//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char *data;
    int width;
    int height;
} Image;

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int new_value = image->data[i * image->width + j] + brightness;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[i * image->width + j] = new_value;
        }
    }
}

void change_contrast(Image *image, int contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            int new_value = (image->data[i * image->width + j] - 128) * contrast + 128;
            if (new_value < 0) {
                new_value = 0;
            } else if (new_value > 255) {
                new_value = 255;
            }
            image->data[i * image->width + j] = new_value;
        }
    }
}

int main() {
    Image image;

    // Read image from file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Read image header
    fread(&image.width, sizeof(int), 1, file);
    fread(&image.height, sizeof(int), 1, file);

    // Allocate memory for image data
    image.data = malloc(image.width * image.height * sizeof(unsigned char));
    if (image.data == NULL) {
        perror("Error allocating memory");
        fclose(file);
        return EXIT_FAILURE;
    }

    // Read image data
    fread(image.data, image.width * image.height, 1, file);

    // Close file
    fclose(file);

    // Flip image
    flip_image(&image);

    // Change brightness
    change_brightness(&image, 50);

    // Change contrast
    change_contrast(&image, 150);

    // Write image to file
    file = fopen("new_image.bmp", "wb");
    if (file == NULL) {
        perror("Error opening file");
        free(image.data);
        return EXIT_FAILURE;
    }

    // Write image header
    fwrite(&image.width, sizeof(int), 1, file);
    fwrite(&image.height, sizeof(int), 1, file);

    // Write image data
    fwrite(image.data, image.width * image.height, 1, file);

    // Close file
    fclose(file);

    // Free memory
    free(image.data);

    return EXIT_SUCCESS;
}