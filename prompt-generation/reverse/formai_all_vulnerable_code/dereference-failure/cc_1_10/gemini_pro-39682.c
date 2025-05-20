//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the maximum number of pixels in an image
#define MAX_PIXELS 1000000

// Define the maximum number of bits to embed in an image
#define MAX_BITS 100000

// Define the maximum size of a watermark image
#define MAX_WATERMARK_SIZE 100

// Structure to represent a pixel
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} Pixel;

// Structure to represent an image
typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Image;

// Structure to represent a watermark
typedef struct {
    int width;
    int height;
    Pixel* pixels;
} Watermark;

// Function to load an image from a file
Image* load_image(char* filename) {
    // Open the image file
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read the image header
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Create an image structure
    Image* image = (Image*) malloc(sizeof(Image));
    image->width = width;
    image->height = height;
    image->pixels = (Pixel*) malloc(width * height * sizeof(Pixel));

    // Read the image data
    fread(image->pixels, sizeof(Pixel), width * height, file);

    // Close the image file
    fclose(file);

    // Return the image
    return image;
}

// Function to save an image to a file
void save_image(Image* image, char* filename) {
    // Open the image file
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        return;
    }

    // Write the image header
    fwrite(&image->width, sizeof(int), 1, file);
    fwrite(&image->height, sizeof(int), 1, file);

    // Write the image data
    fwrite(image->pixels, sizeof(Pixel), image->width * image->height, file);

    // Close the image file
    fclose(file);
}

// Function to load a watermark from a file
Watermark* load_watermark(char* filename) {
    // Open the watermark file
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        return NULL;
    }

    // Read the watermark header
    int width, height;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);

    // Create a watermark structure
    Watermark* watermark = (Watermark*) malloc(sizeof(Watermark));
    watermark->width = width;
    watermark->height = height;
    watermark->pixels = (Pixel*) malloc(width * height * sizeof(Pixel));

    // Read the watermark data
    fread(watermark->pixels, sizeof(Pixel), width * height, file);

    // Close the watermark file
    fclose(file);

    // Return the watermark
    return watermark;
}

// Function to embed a watermark in an image
void embed_watermark(Image* image, Watermark* watermark) {
    // Get the size of the image and watermark
    int image_width = image->width;
    int image_height = image->height;
    int watermark_width = watermark->width;
    int watermark_height = watermark->height;

    // Check if the watermark is too large for the image
    if (watermark_width > image_width || watermark_height > image_height) {
        return;
    }

    // Embed the watermark in the image
    for (int i = 0; i < watermark_width; i++) {
        for (int j = 0; j < watermark_height; j++) {
            // Get the pixel from the watermark
            Pixel watermark_pixel = watermark->pixels[i + j * watermark_width];

            // Get the pixel from the image
            Pixel image_pixel = image->pixels[(i + watermark_width / 2) + (j + watermark_height / 2) * image_width];

            // Embed the watermark pixel in the image pixel
            image_pixel.red = (image_pixel.red & 0xF0) | (watermark_pixel.red >> 4);
            image_pixel.green = (image_pixel.green & 0xF0) | (watermark_pixel.green >> 4);
            image_pixel.blue = (image_pixel.blue & 0xF0) | (watermark_pixel.blue >> 4);
        }
    }
}

// Function to extract a watermark from an image
Watermark* extract_watermark(Image* image) {
    // Get the size of the image
    int image_width = image->width;
    int image_height = image->height;

    // Create a watermark structure
    Watermark* watermark = (Watermark*) malloc(sizeof(Watermark));
    watermark->width = image_width / 2;
    watermark->height = image_height / 2;
    watermark->pixels = (Pixel*) malloc(watermark->width * watermark->height * sizeof(Pixel));

    // Extract the watermark from the image
    for (int i = 0; i < watermark->width; i++) {
        for (int j = 0; j < watermark->height; j++) {
            // Get the pixel from the image
            Pixel image_pixel = image->pixels[(i + watermark->width / 2) + (j + watermark->height / 2) * image_width];

            // Extract the watermark pixel from the image pixel
            watermark->pixels[i + j * watermark->width].red = (image_pixel.red & 0x0F) << 4;
            watermark->pixels[i + j * watermark->width].green = (image_pixel.green & 0x0F) << 4;
            watermark->pixels[i + j * watermark->width].blue = (image_pixel.blue & 0x0F) << 4;
        }
    }

    // Return the watermark
    return watermark;
}

// Main function
int main() {
    // Load the image
    Image* image = load_image("image.bmp");

    // Load the watermark
    Watermark* watermark = load_watermark("watermark.bmp");

    // Embed the watermark in the image
    embed_watermark(image, watermark);

    // Save the watermarked image
    save_image(image, "watermarked_image.bmp");

    // Extract the watermark from the watermarked image
    Watermark* extracted_watermark = extract_watermark(image);

    // Save the extracted watermark
    save_image(extracted_watermark, "extracted_watermark.bmp");

    // Free the memory allocated for the image and watermark
    free(image->pixels);
    free(image);
    free(watermark->pixels);
    free(watermark);
    free(extracted_watermark->pixels);
    free(extracted_watermark);

    return 0;
}