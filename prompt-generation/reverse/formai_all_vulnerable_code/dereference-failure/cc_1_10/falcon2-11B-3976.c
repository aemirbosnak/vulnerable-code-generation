//Falcon2-11B DATASET v1.0 Category: Basic Image Processing: Simple tasks like flipping an image, changing brightness/contrast ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the size of the image
#define WIDTH 640
#define HEIGHT 480

int main() {
    // Create a buffer to hold the image data
    unsigned char* imageData = (unsigned char*)malloc(WIDTH * HEIGHT * sizeof(unsigned char));

    // Read image data from a file
    FILE* imageFile = fopen("input.jpg", "rb");
    if (imageFile == NULL) {
        printf("Error: Could not open image file.\n");
        return 1;
    }

    fseek(imageFile, 0, SEEK_END);
    long imageSize = ftell(imageFile);
    fseek(imageFile, 0, SEEK_SET);

    unsigned char* buffer = (unsigned char*)malloc(imageSize);
    fread(buffer, imageSize, 1, imageFile);
    fclose(imageFile);

    // Perform image processing operations
    unsigned char* buffer2 = (unsigned char*)malloc(imageSize);

    // Flip the image horizontally
    for (int i = 0; i < WIDTH / 2; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            unsigned char temp = buffer[i * HEIGHT * 3 + j * 3];
            buffer2[i * HEIGHT * 3 + j * 3] = buffer[(WIDTH / 2 - i) * HEIGHT * 3 + j * 3];
            buffer2[(WIDTH / 2 - i) * HEIGHT * 3 + j * 3] = temp;
        }
    }

    // Change brightness of the image
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        unsigned char brightness = (unsigned char)((buffer[i] + buffer2[i]) / 2);
        buffer2[i] = brightness;
    }

    // Change contrast of the image
    for (int i = 0; i < WIDTH * HEIGHT * 3; i++) {
        unsigned char contrast = (unsigned char)((buffer[i] + buffer2[i]) / 2);
        buffer2[i] = contrast * (1 - (buffer2[i] - 128) / 255);
    }

    // Write the processed image back to a file
    FILE* outputFile = fopen("output.jpg", "wb");
    if (outputFile == NULL) {
        printf("Error: Could not open output file.\n");
        return 1;
    }

    fwrite(buffer2, imageSize, 1, outputFile);
    fclose(outputFile);

    free(imageData);
    free(buffer);
    free(buffer2);

    printf("Image processing completed successfully.\n");

    return 0;
}