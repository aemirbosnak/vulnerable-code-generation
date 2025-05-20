//GEMINI-pro DATASET v1.0 Category: Browser Plugin ; Style: immersive
// Immerse yourself in the vast digital ocean, where your browser becomes your vessel and our plugin your compass.

#include <stdio.h>
#include <stdlib.h>

// Unveil the secrets of the web, one pixel at a time.
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Embark on a grand adventure, where pixels dance to your commands.
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fclose(file);
        return NULL;
    }

    fread(&image->width, sizeof(int), 1, file);
    fread(&image->height, sizeof(int), 1, file);

    image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (!image->data) {
        fclose(file);
        free(image);
        return NULL;
    }

    fread(image->data, sizeof(unsigned char), image->width * image->height, file);
    fclose(file);

    return image;
}

// Transform the mundane into the magnificent, one stroke at a time.
Image *process_image(Image *image) {
    Image *processed_image = malloc(sizeof(Image));
    if (!processed_image) {
        return NULL;
    }

    processed_image->width = image->width;
    processed_image->height = image->height;

    processed_image->data = malloc(image->width * image->height * sizeof(unsigned char));
    if (!processed_image->data) {
        free(processed_image);
        return NULL;
    }

    for (int i = 0; i < image->width * image->height; i++) {
        processed_image->data[i] = 255 - image->data[i];
    }

    return processed_image;
}

// Witness the birth of a masterpiece, as pixels find their rightful place.
void display_image(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            printf("%c", image->data[i * image->width + j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Set sail, brave explorer, and let your imagination soar.
int main() {
    Image *image = load_image("image.bmp");
    if (!image) {
        printf("Failed to load image.\n");
        return 1;
    }

    Image *processed_image = process_image(image);
    if (!processed_image) {
        printf("Failed to process image.\n");
        return 1;
    }

    display_image(processed_image);

    free(image->data);
    free(image);
    free(processed_image->data);
    free(processed_image);

    return 0;
}