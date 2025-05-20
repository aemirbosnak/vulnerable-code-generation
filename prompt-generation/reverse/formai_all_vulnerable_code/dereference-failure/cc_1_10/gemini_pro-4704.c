//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned int width;
    unsigned int height;
    unsigned char *data;
} Image;

Image *create_image(unsigned int width, unsigned int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height * sizeof(unsigned char));
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

int main() {
    Image *image = create_image(256, 256);

    // Load the image data from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }
    fread(image->data, image->width * image->height, sizeof(unsigned char), file);
    fclose(file);

    // Embed the watermark in the image
    unsigned char *watermark = "Watermark";
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] += watermark[i % strlen(watermark)];
    }

    // Save the watermarked image to a file
    file = fopen("watermarked_image.bmp", "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }
    fwrite(image->data, image->width * image->height, sizeof(unsigned char), file);
    fclose(file);

    // Destroy the image
    destroy_image(image);

    return EXIT_SUCCESS;
}