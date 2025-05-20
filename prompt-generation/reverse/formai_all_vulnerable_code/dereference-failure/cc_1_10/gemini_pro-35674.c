//GEMINI-pro DATASET v1.0 Category: Image Editor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

// Image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Error handling macro
#define CHECK(expr)                                 \
    do {                                            \
        if (!(expr)) {                              \
            fprintf(stderr, "Error at %s:%d: %s\n", __FILE__, __LINE__, #expr); \
            exit(EXIT_FAILURE);                    \
        }                                           \
    } while (0)

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    CHECK(file != NULL);

    Image *image = malloc(sizeof(Image));
    CHECK(image != NULL);

    fscanf(file, "%d %d\n", &image->width, &image->height);
    image->data = malloc(image->width * image->height);
    CHECK(image->data != NULL);

    fread(image->data, 1, image->width * image->height, file);
    fclose(file);

    return image;
}

// Save an image to a file
void save_image(const Image *image, const char *filename) {
    FILE *file = fopen(filename, "wb");
    CHECK(file != NULL);

    fprintf(file, "%d %d\n", image->width, image->height);
    fwrite(image->data, 1, image->width * image->height, file);
    fclose(file);
}

// Invert the colors of an image
void invert_image(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i] = 255 - image->data[i];
    }
}

// Apply a filter to an image
void filter_image(Image *image, float filter[3][3]) {
    Image *new_image = malloc(sizeof(Image));
    CHECK(new_image != NULL);

    new_image->width = image->width;
    new_image->height = image->height;
    new_image->data = malloc(new_image->width * new_image->height);
    CHECK(new_image->data != NULL);

    for (int i = 1; i < image->width - 1; i++) {
        for (int j = 1; j < image->height - 1; j++) {
            float new_value = 0.0f;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    new_value += image->data[(i + k) * image->width + (j + l)] * filter[k + 1][l + 1];
                }
            }
            new_image->data[i * new_image->width + j] = (unsigned char)new_value;
        }
    }

    free(image->data);
    *image = *new_image;
    free(new_image);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input.ppm output.ppm\n", argv[0]);
        return EXIT_FAILURE;
    }

    Image *image = load_image(argv[1]);
    invert_image(image);
    save_image(image, argv[2]);

    printf("Surprise! Your image is now inverted.\n");

    return EXIT_SUCCESS;
}