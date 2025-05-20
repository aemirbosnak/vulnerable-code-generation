//LLAMA2-13B DATASET v1.0 Category: Image Editor ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

#define WIDTH 640
#define HEIGHT 480
#define BITS_PER_PIXEL 32
#define MAX_IMAGE_SIZE (WIDTH * HEIGHT * BITS_PER_PIXEL / 8)

typedef struct {
    unsigned char *data;
    size_t width, height;
} image_t;

image_t *load_image(const char *filename) {
    size_t size = MAX_IMAGE_SIZE;
    image_t *img = malloc(sizeof(image_t));
    img->data = malloc(size);
    img->width = WIDTH;
    img->height = HEIGHT;

    // Load the image from file
    FILE *file = fopen(filename, "rb");
    fseek(file, 0, SEEK_END);
    size_t file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    // Read the image data
    size_t bytes_read = fread(img->data, 1, size, file);
    if (bytes_read != size) {
        fprintf(stderr, "Error reading image file: %s\n", filename);
        return NULL;
    }

    fclose(file);
    return img;
}

void save_image(const char *filename, image_t *img) {
    // Open the output file
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening output file: %s\n", filename);
        return;
    }

    // Write the image data
    size_t bytes_written = fwrite(img->data, 1, img->width * img->height * BITS_PER_PIXEL / 8, file);
    if (bytes_written != img->width * img->height * BITS_PER_PIXEL / 8) {
        fprintf(stderr, "Error writing image file: %s\n", filename);
        fclose(file);
        return;
    }

    // Flush the buffer
    fflush(file);

    // Close the file
    fclose(file);
}

void edit_image(image_t *img, int x, int y, int width, int height) {
    // Get the address of the pixel at (x, y)
    unsigned char *pixel = img->data + (y * img->width * BITS_PER_PIXEL / 8) + (x * BITS_PER_PIXEL / 8);

    // Get the current value of the pixel
    unsigned int value = *pixel;

    // If the pixel is transparent, set it to the new value
    if (value == 0) {
        *pixel = value = width & 0xFF;
    }

    // If the pixel is not transparent, set it to the new value
    // and make it transparent
    else {
        *pixel = (value & 0xFF) | (width << 24);
    }
}

int main(int argc, char **argv) {
    // Check the number of command-line arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <image_file> <x> <y> <width> <height>\n", argv[0]);
        return 1;
    }

    // Load the image
    image_t *img = load_image(argv[1]);
    if (!img) {
        fprintf(stderr, "Error loading image file: %s\n", argv[1]);
        return 1;
    }

    // Get the coordinates and dimensions from the command-line arguments
    int x = atoi(argv[2]);
    int y = atoi(argv[3]);
    int width = atoi(argv[4]);
    int height = atoi(argv[5]);

    // Edit the image
    edit_image(img, x, y, width, height);

    // Save the modified image
    save_image(argv[1], img);

    // Free the memory
    free(img->data);
    free(img);

    return 0;
}