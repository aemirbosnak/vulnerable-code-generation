//FormAI DATASET v1.0 Category: Image Editor ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PIXEL 255

#define RED 0
#define GREEN 1
#define BLUE 2

typedef struct Pixel {
    unsigned char r;     // red component
    unsigned char g;     // green component
    unsigned char b;     // blue component
} Pixel;

typedef struct Image {
    int width;           // width of image
    int height;          // height of image
    Pixel *data;         // array of pixels
} Image;

// allocate memory for an image of the given width and height
Image *create_image(int width, int height) {
    Image *image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (Pixel*) malloc(width * height * sizeof(Pixel));
    return image;
}

// free memory allocated for an image
void delete_image(Image *image) {
    free(image->data);
    free(image);
}

// read image data from a file
Image *read_image(const char *filename) {
    // open file for reading
    FILE *file = fopen(filename, "r");

    // check if file was opened successfully
    if (file == NULL) {
        printf("Error: could not open file '%s'\n", filename);
        return NULL;
    }

    // read image dimensions from file
    int width, height;
    fscanf(file, "%d %d", &width, &height);

    // create image object
    Image *image = create_image(width, height);

    // read pixel data from file
    for (int i = 0; i < width * height; i++) {
        fscanf(file, "%hhu %hhu %hhu", &image->data[i].r, &image->data[i].g, &image->data[i].b);
    }

    // close file
    fclose(file);

    return image;
}

// write image data to a file
void write_image(const char *filename, Image *image) {
    // open file for writing
    FILE *file = fopen(filename, "w");

    // write image dimensions to file
    fprintf(file, "%d %d\n", image->width, image->height);

    // write pixel data to file
    for (int i = 0; i < image->width * image->height; i++) {
        fprintf(file, "%hhu %hhu %hhu\n", image->data[i].r, image->data[i].g, image->data[i].b);
    }

    // close file
    fclose(file);
}

// flip image vertically
void flip_vertical(Image *image) {
    int half_height = image->height / 2;
    for (int y = 0; y < half_height; y++) {
        for (int x = 0; x < image->width; x++) {
            Pixel temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[(image->height - 1 - y) * image->width + x];
            image->data[(image->height - 1 - y) * image->width + x] = temp;
        }
    }
}

// apply grayscale filter to image
void grayscale_filter(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        unsigned char gray = (image->data[i].r + image->data[i].g + image->data[i].b) / 3;
        image->data[i].r = gray;
        image->data[i].g = gray;
        image->data[i].b = gray;
    }
}

// apply red filter to image
void red_filter(Image *image) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].g = 0;
        image->data[i].b = 0;
    }
}

int main() {
    // read image from file
    Image *image = read_image("input.ppm");

    // apply filters
    flip_vertical(image);
    grayscale_filter(image);
    red_filter(image);

    // write image to file
    write_image("output.ppm", image);

    // free memory allocated for image
    delete_image(image);

    // return success
    return 0;
}