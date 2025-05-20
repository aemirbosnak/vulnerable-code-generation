//FormAI DATASET v1.0 Category: Image compression ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// function to compress an image using run-length encoding
void compress_image(unsigned char *image, int width, int height) {
    // allocate memory for the compressed image
    int size = width * height;
    unsigned char *compressed_image = malloc(sizeof(unsigned char) * size);

    // initialize variables for run-length encoding
    int count = 1, index = 0;
    unsigned char current_pixel = image[0];

    // traverse the image and compress the pixels
    for (int i = 1; i < size; i++) {
        unsigned char pixel = image[i];
        if (pixel != current_pixel || count == 255) {
            // store the count and pixel value in the compressed image
            compressed_image[index++] = count;
            compressed_image[index++] = current_pixel;

            // reset variables for the next run
            count = 1;
            current_pixel = pixel;
        } else {
            count++;
        }
    }

    // store the final run in the compressed image
    compressed_image[index++] = count;
    compressed_image[index++] = current_pixel;

    // print the compressed image
    printf("Compressed image: ");
    for (int i = 0; i < index; i++) {
        printf("%u ", compressed_image[i]);
    }
    printf("\n");

    // free memory allocated for the compressed image
    free(compressed_image);
}

int main() {
    // create a sample image
    unsigned char image[] = {255, 255, 255, 255, 255,
                             0, 0, 0, 0, 0,
                             255, 255, 255, 255, 255,
                             0, 0, 0, 0, 0,
                             255, 255, 255, 255, 255};

    // compress the image using run-length encoding
    int width = 5, height = 5;
    compress_image(image, width, height);

    return 0;
}