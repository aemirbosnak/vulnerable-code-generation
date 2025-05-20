//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: active
// C Basic Image Processing: Simple Tasks Like Flipping an Image, Changing Brightness/Contrast

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Image data structure
typedef struct {
    int width;
    int height;
    unsigned char *pixels;
} Image;

// Load an image from a file
Image load_image(char *filename) {
    Image image;

    // Open the file
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Read the header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, file);

    // Get the image dimensions
    image.width = header[18] | (header[19] << 8) | (header[20] << 16) | (header[21] << 24);
    image.height = header[22] | (header[23] << 8) | (header[24] << 16) | (header[25] << 24);

    // Allocate memory for the pixels
    image.pixels = (unsigned char *)malloc(image.width * image.height * sizeof(unsigned char));
    if (image.pixels == NULL) {
        printf("Error: could not allocate memory for pixels\n");
        exit(1);
    }

    // Read the pixels
    fread(image.pixels, sizeof(unsigned char), image.width * image.height, file);

    // Close the file
    fclose(file);

    return image;
}

// Save an image to a file
void save_image(Image image, char *filename) {
    // Open the file
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    // Write the header
    unsigned char header[54];
    header[0] = 'B';
    header[1] = 'M';
    header[2] = (unsigned char)(image.width * image.height * 3 + 54);
    header[3] = 0;
    header[4] = 0;
    header[5] = 0;
    header[6] = 0;
    header[7] = 0;
    header[8] = 40;
    header[9] = 0;
    header[10] = 0;
    header[11] = 0;
    header[12] = (unsigned char)(image.width);
    header[13] = 0;
    header[14] = 0;
    header[15] = 0;
    header[16] = (unsigned char)(image.height);
    header[17] = 0;
    header[18] = 0;
    header[19] = 0;
    header[20] = 1;
    header[21] = 0;
    header[22] = 24;
    header[23] = 0;
    header[24] = 0;
    header[25] = 0;
    header[26] = 0;
    header[27] = 0;
    header[28] = 0;
    header[29] = 0;
    header[30] = 0;
    header[31] = 0;
    fwrite(header, sizeof(unsigned char), 54, file);

    // Write the pixels
    fwrite(image.pixels, sizeof(unsigned char), image.width * image.height, file);

    // Close the file
    fclose(file);
}

// Flip an image horizontally
void flip_image_horizontally(Image *image) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width / 2; j++) {
            unsigned char temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[i * image->width + image->width - j - 1];
            image->pixels[i * image->width + image->width - j - 1] = temp;
        }
    }
}

// Flip an image vertically
void flip_image_vertically(Image *image) {
    for (int i = 0; i < image->height / 2; i++) {
        for (int j = 0; j < image->width; j++) {
            unsigned char temp = image->pixels[i * image->width + j];
            image->pixels[i * image->width + j] = image->pixels[(image->height - i - 1) * image->width + j];
            image->pixels[(image->height - i - 1) * image->width + j] = temp;
        }
    }
}

// Change the brightness of an image
void change_brightness(Image *image, int brightness) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] = (unsigned char)fmin(255, fmax(0, image->pixels[i * image->width + j] + brightness));
        }
    }
}

// Change the contrast of an image
void change_contrast(Image *image, float contrast) {
    for (int i = 0; i < image->height; i++) {
        for (int j = 0; j < image->width; j++) {
            image->pixels[i * image->width + j] = (unsigned char)fmin(255, fmax(0, 128 + contrast * (image->pixels[i * image->width + j] - 128)));
        }
    }
}

// Main function
int main() {
    // Load the input image
    Image image = load_image("input.bmp");

    // Flip the image horizontally
    flip_image_horizontally(&image);

    // Flip the image vertically
    flip_image_vertically(&image);

    // Change the brightness of the image
    change_brightness(&image, 50);

    // Change the contrast of the image
    change_contrast(&image, 1.5);

    // Save the output image
    save_image(image, "output.bmp");

    return 0;
}