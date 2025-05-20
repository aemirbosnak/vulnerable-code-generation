//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Image dimensions
#define WIDTH 512
#define HEIGHT 512

// RGB color components
typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
} pixel;

// Image data structure
typedef struct {
    pixel data[WIDTH][HEIGHT];
} image;

// Load an image from a file
image* load_image(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    // Read the header
    unsigned char header[54];
    fread(header, 54, 1, file);

    // Check if the file is a valid BMP file
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: file is not a valid BMP file\n");
        fclose(file);
        return NULL;
    }

    // Read the image dimensions
    unsigned int offset = *(unsigned int*)(header + 10);
    unsigned int width = *(unsigned int*)(header + 18);
    unsigned int height = *(unsigned int*)(header + 22);

    // Check if the image dimensions are valid
    if (width != WIDTH || height != HEIGHT) {
        fprintf(stderr, "Error: image dimensions are not valid\n");
        fclose(file);
        return NULL;
    }

    // Read the image data
    image* img = malloc(sizeof(image));
    fread(img->data, sizeof(pixel), WIDTH * HEIGHT, file);

    fclose(file);

    return img;
}

// Save an image to a file
void save_image(const char* filename, image* img) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    *(unsigned int*)(header + 2) = sizeof(header) + sizeof(pixel) * WIDTH * HEIGHT;
    *(unsigned int*)(header + 10) = sizeof(header);
    *(unsigned int*)(header + 18) = WIDTH;
    *(unsigned int*)(header + 22) = HEIGHT;
    *(unsigned short*)(header + 26) = 1;
    *(unsigned short*)(header + 28) = 24;
    *(unsigned int*)(header + 34) = sizeof(pixel) * WIDTH * HEIGHT;

    fwrite(header, 54, 1, file);

    // Write the image data
    fwrite(img->data, sizeof(pixel), WIDTH * HEIGHT, file);

    fclose(file);
}

// Flip an image horizontally
void flip_horizontal(image* img) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH / 2; x++) {
            pixel temp = img->data[y][x];
            img->data[y][x] = img->data[y][WIDTH - 1 - x];
            img->data[y][WIDTH - 1 - x] = temp;
        }
    }
}

// Flip an image vertically
void flip_vertical(image* img) {
    for (int y = 0; y < HEIGHT / 2; y++) {
        for (int x = 0; x < WIDTH; x++) {
            pixel temp = img->data[y][x];
            img->data[y][x] = img->data[HEIGHT - 1 - y][x];
            img->data[HEIGHT - 1 - y][x] = temp;
        }
    }
}

// Change the brightness and contrast of an image
void change_brightness_contrast(image* img, double brightness, double contrast) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            int r = img->data[y][x].r * contrast + brightness;
            int g = img->data[y][x].g * contrast + brightness;
            int b = img->data[y][x].b * contrast + brightness;

            // Clamp the values to the range [0, 255]
            img->data[y][x].r = (unsigned char)fmin(fmax(r, 0), 255);
            img->data[y][x].g = (unsigned char)fmin(fmax(g, 0), 255);
            img->data[y][x].b = (unsigned char)fmin(fmax(b, 0), 255);
        }
    }
}

int main() {
    // Load the image
    image* img = load_image("image.bmp");
    if (img == NULL) {
        return 1;
    }

    // Flip the image horizontally
    flip_horizontal(img);

    // Flip the image vertically
    flip_vertical(img);

    // Change the brightness and contrast of the image
    change_brightness_contrast(img, 50, 1.2);

    // Save the image
    save_image("output.bmp", img);

    // Free the image
    free(img);

    return 0;
}