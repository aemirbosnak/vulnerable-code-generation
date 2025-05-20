//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int width;
    int height;
    char *data;
} Image;

Image *create_image(int width, int height) {
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = malloc(width * height);
    return image;
}

void destroy_image(Image *image) {
    free(image->data);
    free(image);
}

void print_image(const Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            printf("%c", image->data[y * image->width + x]);
        }
        printf("\n");
    }
}

void invert_image(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width; x++) {
            image->data[y * image->width + x] = 255 - image->data[y * image->width + x];
        }
    }
}

void blur_image(Image *image) {
    int kernel[3][3] = {
        {0, 1, 0},
        {1, 2, 1},
        {0, 1, 0}
    };
    int sum;
    int count;
    for (int y = 0; y < image->height - 2; y++) {
        for (int x = 0; x < image->width - 2; x++) {
            sum = 0;
            count = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (kernel[i][j]) {
                        sum += image->data[(y + i) * image->width + (x + j)] * kernel[i][j];
                        count += kernel[i][j];
                    }
                }
            }
            image->data[y * image->width + x] = sum / count;
        }
    }
}

void sharpen_image(Image *image) {
    int kernel[3][3] = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}
    };
    int sum;
    int count;
    for (int y = 0; y < image->height - 2; y++) {
        for (int x = 0; x < image->width - 2; x++) {
            sum = 0;
            count = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    if (kernel[i][j]) {
                        sum += image->data[(y + i) * image->width + (x + j)] * kernel[i][j];
                        count += kernel[i][j];
                    }
                }
            }
            image->data[y * image->width + x] = sum / count;
        }
    }
}

int main() {
    Image *image = create_image(512, 512);

    // Read the image data from a file
    FILE *file = fopen("image.bin", "rb");
    fread(image->data, 1, image->width * image->height, file);
    fclose(file);

    // Process the image data
    invert_image(image);
    blur_image(image);
    sharpen_image(image);

    // Write the image data to a file
    file = fopen("image_processed.bin", "wb");
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);

    // Destroy the image
    destroy_image(image);

    return 0;
}