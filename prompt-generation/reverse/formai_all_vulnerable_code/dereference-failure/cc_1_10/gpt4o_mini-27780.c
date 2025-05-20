//GPT-4o-mini DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b; // Red, Green, Blue color components
} Pixel;

typedef struct {
    int width, height;
    Pixel *data; // Array of pixels
} Image;

// Function to load PPM image
Image* loadPPM(const char* filename) {
    FILE *file = fopen(filename, "rb");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        return NULL;
    }

    // Read PPM header
    char header[3];
    fscanf(file, "%s", header);
    if (header[0] != 'P' || header[1] != '6') {
        fprintf(stderr, "Invalid PPM file format\n");
        fclose(file);
        return NULL;
    }

    int width, height, maxval;
    fscanf(file, "%d %d %d", &width, &height, &maxval);
    fgetc(file); // Read the newline after maxval

    // Allocate memory for image
    Image *image = (Image *)malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->data = (Pixel *)malloc(width * height * sizeof(Pixel));

    fread(image->data, sizeof(Pixel), width * height, file);
    fclose(file);
    return image;
}

// Function to save PPM image
void savePPM(const char* filename, const Image *image) {
    FILE *file = fopen(filename, "wb");
    if (!file) {
        fprintf(stderr, "Could not open file %s for writing\n", filename);
        return;
    }

    // Write PPM header
    fprintf(file, "P6\n%d %d\n255\n", image->width, image->height);
    fwrite(image->data, sizeof(Pixel), image->width * image->height, file);
    fclose(file);
}

// Function to flip the image horizontally
void flipImageHorizontally(Image *image) {
    for (int y = 0; y < image->height; y++) {
        for (int x = 0; x < image->width / 2; x++) {
            // Swap pixels
            Pixel temp = image->data[y * image->width + x];
            image->data[y * image->width + x] = image->data[y * image->width + (image->width - 1 - x)];
            image->data[y * image->width + (image->width - 1 - x)] = temp;
        }
    }
}

// Function to adjust brightness
void adjustBrightness(Image *image, int value) {
    for (int i = 0; i < image->width * image->height; i++) {
        image->data[i].r = (image->data[i].r + value > 255) ? 255 : (image->data[i].r + value < 0 ? 0 : image->data[i].r + value);
        image->data[i].g = (image->data[i].g + value > 255) ? 255 : (image->data[i].g + value < 0 ? 0 : image->data[i].g + value);
        image->data[i].b = (image->data[i].b + value > 255) ? 255 : (image->data[i].b + value < 0 ? 0 : image->data[i].b + value);
    }
}

// Function to adjust contrast
void adjustContrast(Image *image, float factor) {
    for (int i = 0; i < image->width * image->height; i++) {
        // Normalizing the color values
        image->data[i].r = (unsigned char) fmin(fmax((image->data[i].r - 128) * factor + 128, 0), 255);
        image->data[i].g = (unsigned char) fmin(fmax((image->data[i].g - 128) * factor + 128, 0), 255);
        image->data[i].b = (unsigned char) fmin(fmax((image->data[i].b - 128) * factor + 128, 0), 255);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 5) {
        fprintf(stderr, "Usage: %s <input.ppm> <output_flipped.ppm> <output_brightness.ppm> <output_contrast.ppm>\n", argv[0]);
        return 1;
    }

    const char *inputFile = argv[1];
    const char *outputFlipped = argv[2];
    const char *outputBrightness = argv[3];
    const char *outputContrast = argv[4];

    Image *image = loadPPM(inputFile);
    if (!image) {
        return 1;
    }

    // Flip the image and save it
    flipImageHorizontally(image);
    savePPM(outputFlipped, image);

    // Adjust brightness and save
    adjustBrightness(image, 50); // Increase brightness by 50
    savePPM(outputBrightness, image);

    // Adjust contrast and save
    adjustContrast(image, 1.5); // Increase contrast by a factor of 1.5
    savePPM(outputContrast, image);

    // Free the image memory
    free(image->data);
    free(image);
    return 0;
}