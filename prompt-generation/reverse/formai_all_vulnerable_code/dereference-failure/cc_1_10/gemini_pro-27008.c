//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Define the image structure
typedef struct {
    int width;
    int height;
    unsigned char *data;
} Image;

// Load an image from a file
Image *load_image(const char *filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    // Read the image header
    unsigned char header[14];
    fread(header, sizeof(header), 1, file);

    // Check if the file is a BMP image
    if (header[0] != 'B' || header[1] != 'M') {
        fprintf(stderr, "Error: File is not a BMP image\n");
        fclose(file);
        return NULL;
    }

    // Read the image dimensions
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the image data
    unsigned char *data = malloc(width * height * 3);
    fread(data, width * height * 3, 1, file);

    // Close the file
    fclose(file);

    // Create the image object
    Image *image = malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = data;

    return image;
}

// Save an image to a file
void save_image(const char *filename, Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return;
    }

    // Write the image header
    unsigned char header[14] = {
        'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0
    };
    fwrite(header, sizeof(header), 1, file);

    // Write the image dimensions
    int width = image->width;
    int height = image->height;
    fwrite(&width, sizeof(width), 1, file);
    fwrite(&height, sizeof(height), 1, file);

    // Write the image data
    fwrite(image->data, width * height * 3, 1, file);

    // Close the file
    fclose(file);
}

int main() {
    const char *filename = "image.bmp";
    Image *image = load_image(filename);
    if (!image) {
        return 1;
    }
   unsigned char *pixels;
  pixels = image->data;
    // Flip the image horizontally
    
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = pixels[i * image->width + j];
            pixels[i * image->width + j] = pixels[i * image->width + image->width - j - 1];
            pixels[i * image->width + image->width - j - 1] = temp;
        }
    }

    // Save the image to a file
    save_image("flipped_image.bmp", image);

    // Free the image object
    free(image->data);
    free(image);

    return 0;
}