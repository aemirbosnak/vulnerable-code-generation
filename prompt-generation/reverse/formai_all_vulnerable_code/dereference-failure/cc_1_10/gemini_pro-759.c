//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    // Define the image file and message to be hidden
    const char *image_file = "image.bmp";
    const char *message = "This is a secret message";

    // Open the image file
    FILE *image = fopen(image_file, "rb");
    if (image == NULL) {
        perror("Error opening image file");
        return EXIT_FAILURE;
    }

    // Get the image size
    fseek(image, 2, SEEK_SET);
    uint32_t image_size;
    fread(&image_size, sizeof(uint32_t), 1, image);
    fseek(image, 0, SEEK_SET);

    // Allocate a buffer to store the image data
    uint8_t *image_data = malloc(image_size);
    if (image_data == NULL) {
        perror("Error allocating memory for image data");
        fclose(image);
        return EXIT_FAILURE;
    }

    // Read the image data
    fread(image_data, image_size, 1, image);
    fclose(image);

    // Hide the message in the image data
    int message_length = strlen(message);
    for (int i = 0; i < message_length; i++) {
        uint8_t message_byte = message[i];
        for (int j = 0; j < 8; j++) {
            uint8_t bit = (message_byte >> j) & 1;
            image_data[i * 8 + j] = (image_data[i * 8 + j] & ~1) | bit;
        }
    }

    // Open a new file to store the steganographed image
    FILE *stego_image = fopen("stego_image.bmp", "wb");
    if (stego_image == NULL) {
        perror("Error opening stego image file");
        free(image_data);
        return EXIT_FAILURE;
    }

    // Write the steganographed image data to the file
    fwrite(image_data, image_size, 1, stego_image);
    fclose(stego_image);

    // Clean up
    free(image_data);

    printf("Message successfully hidden in image\n");
    return EXIT_SUCCESS;
}