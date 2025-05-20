//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char *data;
    int width, height;
} Image;

Image *read_image(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return NULL;
    }

    Image *image = malloc(sizeof(Image));
    if (!image) {
        fprintf(stderr, "Error allocating memory for image\n");
        return NULL;
    }

    // Read the header
    unsigned char header[18];
    if (fread(header, 1, 18, fp) != 18) {
        fprintf(stderr, "Error reading header from file %s\n", filename);
        free(image);
        return NULL;
    }

    // Check the header
    if (memcmp(header, "BM", 2) != 0) {
        fprintf(stderr, "Error: file %s is not a valid BMP file\n", filename);
        free(image);
        return NULL;
    }

    // Get the image dimensions
    image->width = *(int *)(header + 18);
    image->height = *(int *)(header + 22);

    // Allocate memory for the image data
    image->data = malloc(image->width * image->height * 3);
    if (!image->data) {
        fprintf(stderr, "Error allocating memory for image data\n");
        free(image);
        return NULL;
    }

    // Read the image data
    if (fread(image->data, 1, image->width * image->height * 3, fp) != image->width * image->height * 3) {
        fprintf(stderr, "Error reading image data from file %s\n", filename);
        free(image->data);
        free(image);
        return NULL;
    }

    fclose(fp);

    return image;
}

void write_image(const Image *image, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Error opening file %s\n", filename);
        return;
    }

    // Write the header
    unsigned char header[18];
    memcpy(header, "BM", 2);
    *(int *)(header + 18) = image->width;
    *(int *)(header + 22) = image->height;
    if (fwrite(header, 1, 18, fp) != 18) {
        fprintf(stderr, "Error writing header to file %s\n", filename);
        fclose(fp);
        return;
    }

    // Write the image data
    if (fwrite(image->data, 1, image->width * image->height * 3, fp) != image->width * image->height * 3) {
        fprintf(stderr, "Error writing image data to file %s\n", filename);
        fclose(fp);
        return;
    }

    fclose(fp);
}

void flip_image(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            // Swap the pixels
            unsigned char temp = image->data[i * image->width + j];
            image->data[i * image->width + j] = image->data[(image->height - i - 1) * image->width + j];
            image->data[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

void change_brightness_contrast(Image *image, double brightness, double contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            // Adjust the brightness
            image->data[i * image->width + j] = (unsigned char) (image->data[i * image->width + j] * brightness);

            // Adjust the contrast
            image->data[i * image->width + j] = (unsigned char) ((image->data[i * image->width + j] - 128) * contrast + 128);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <input file> <output file>\n", argv[0]);
        return 1;
    }

    // Read the input image
    Image *image = read_image(argv[1]);
    if (!image) {
        return 1;
    }

    // Flip the image
    flip_image(image);

    // Change the brightness and contrast
    change_brightness_contrast(image, 1.2, 1.5);

    // Write the output image
    write_image(image, argv[2]);

    // Free the memory allocated for the image
    free(image->data);
    free(image);

    return 0;
}