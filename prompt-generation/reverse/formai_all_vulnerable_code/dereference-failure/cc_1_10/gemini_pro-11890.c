//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
} pixel;

int main() {
    // Open the carrier image
    FILE *carrier_image_file = fopen("carrier.bmp", "rb");
    if (carrier_image_file == NULL) {
        printf("Error opening carrier image file\n");
        return EXIT_FAILURE;
    }

    // Read the header of the carrier image
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, carrier_image_file);

    // Get the width and height of the carrier image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Read the pixel data of the carrier image
    pixel *carrier_image = malloc(width * height * sizeof(pixel));
    fread(carrier_image, sizeof(pixel), width * height, carrier_image_file);
    fclose(carrier_image_file);

    // Open the secret message file
    FILE *secret_message_file = fopen("secret.txt", "rb");
    if (secret_message_file == NULL) {
        printf("Error opening secret message file\n");
        return EXIT_FAILURE;
    }

    // Read the secret message
    char *secret_message = malloc(1000);
    fread(secret_message, sizeof(char), 1000, secret_message_file);
    fclose(secret_message_file);

    // Embed the secret message in the carrier image
    int index = 0;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            // Get the current pixel
            pixel *pixel = &carrier_image[i * width + j];

            // Embed the next character of the secret message in the least significant bit of the red channel of the pixel
            pixel->red = (pixel->red & ~1) | ((secret_message[index] >> 7) & 1);

            // Increment the index of the secret message
            index++;

            // If the index of the secret message exceeds the length of the message, break out of the loop
            if (index >= strlen(secret_message)) {
                break;
            }
        }
    }

    // Save the stego image
    FILE *stego_image_file = fopen("stego.bmp", "wb");
    if (stego_image_file == NULL) {
        printf("Error opening stego image file\n");
        return EXIT_FAILURE;
    }

    // Write the header of the carrier image to the stego image file
    fwrite(header, sizeof(unsigned char), 54, stego_image_file);

    // Write the pixel data of the stego image to the stego image file
    fwrite(carrier_image, sizeof(pixel), width * height, stego_image_file);
    fclose(stego_image_file);

    // Free the memory allocated for the carrier image and the secret message
    free(carrier_image);
    free(secret_message);

    return EXIT_SUCCESS;
}