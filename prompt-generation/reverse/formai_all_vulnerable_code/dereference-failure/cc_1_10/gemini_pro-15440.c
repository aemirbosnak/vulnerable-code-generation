//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define LSB_MASK 0x01

typedef struct Pixel {
    uint8_t r;
    uint8_t g;
    uint8_t b;
    uint8_t a;
} Pixel;

typedef struct Image {
    Pixel **data;
    int width;
    int height;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(height * sizeof(Pixel *));
    for (int i = 0; i < height; i++) {
        image->data[i] = malloc(width * sizeof(Pixel));
    }
    return image;
}

void free_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        free(image->data[i]);
    }
    free(image->data);
    free(image);
}

int main() {
    Image *image = create_image(640, 480);

    // Load the image from a file
    FILE *file = fopen("image.bmp", "rb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fread(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);

    // Hide a message in the image
    char *message = "Hello world";
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (message[i] >> j) & LSB_MASK;
            image->data[i][j].r &= ~LSB_MASK;
            image->data[i][j].r |= bit;
        }
    }

    // Save the image to a file
    file = fopen("output.bmp", "wb");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);

    free_image(image);
    return 0;
}