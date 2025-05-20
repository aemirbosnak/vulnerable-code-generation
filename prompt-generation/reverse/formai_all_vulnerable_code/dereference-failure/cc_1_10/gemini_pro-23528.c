//GEMINI-pro DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

//Sherlock Holmes-Inspired Image Processing

// Function to flip an image horizontally
void flip_horizontal(unsigned char *image, int width, int height) {
    int i, j;
    unsigned char temp;

    // Iterate over each row
    for (i = 0; i < height; i++) {
        // Iterate over half of the columns
        for (j = 0; j < width / 2; j++) {
            // Swap the pixels at (i, j) and (i, width - j - 1)
            temp = image[i * width + j];
            image[i * width + j] = image[i * width + width - j - 1];
            image[i * width + width - j - 1] = temp;
        }
    }
}

// Function to change the brightness of an image
void change_brightness(unsigned char *image, int width, int height, int brightness) {
    int i, j;

    // Iterate over each pixel
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Add the brightness value to the pixel
            image[i * width + j] += brightness;

            // Clamp the pixel value to [0, 255]
            if (image[i * width + j] > 255) {
                image[i * width + j] = 255;
            } else if (image[i * width + j] < 0) {
                image[i * width + j] = 0;
            }
        }
    }
}

// Function to change the contrast of an image
void change_contrast(unsigned char *image, int width, int height, int contrast) {
    int i, j;
    float factor;

    // Calculate the factor to apply to the contrast
    factor = (259 * (contrast + 255)) / (255 * (259 - contrast));

    // Iterate over each pixel
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            // Apply the factor to the pixel
            image[i * width + j] = factor * (image[i * width + j] - 128) + 128;

            // Clamp the pixel value to [0, 255]
            if (image[i * width + j] > 255) {
                image[i * width + j] = 255;
            } else if (image[i * width + j] < 0) {
                image[i * width + j] = 0;
            }
        }
    }
}

// Main function
int main() {
    // Read the image from a file
    FILE *fp = fopen("image.bmp", "rb");
    if (fp == NULL) {
        printf("Error: could not open image file\n");
        return EXIT_FAILURE;
    }
    
    //Read the file headers
    int width, height;
    fread(&width, 4, 1, fp);
    fread(&height, 4, 1, fp);
    fseek(fp, 54, 0);

    // Allocate memory for the image data
    unsigned char *image = malloc(width * height * 3);
    if (image == NULL) {
        printf("Error: could not allocate memory for image\n");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the image data from the file
    fread(image, width * height * 3, 1, fp);
    fclose(fp);

    // Flip the image horizontally
    flip_horizontal(image, width, height);

    // Change the brightness of the image
    change_brightness(image, width, height, 50);

    // Change the contrast of the image
    change_contrast(image, width, height, 20);

    // Write the modified image to a file
    fp = fopen("modified_image.bmp", "wb");
    if (fp == NULL) {
        printf("Error: could not open output file\n");
        free(image);
        return EXIT_FAILURE;
    }
    
    fwrite(&width, 4, 1, fp);
    fwrite(&height, 4, 1, fp);
    fseek(fp, 54, 0);

    // Write the image data to the file
    fwrite(image, width * height * 3, 1, fp);
    fclose(fp);

    // Free the memory allocated for the image data
    free(image);

    printf("Image processing complete. Results saved to modified_image.bmp.\n");

    // Exit successfully
    return EXIT_SUCCESS;
}