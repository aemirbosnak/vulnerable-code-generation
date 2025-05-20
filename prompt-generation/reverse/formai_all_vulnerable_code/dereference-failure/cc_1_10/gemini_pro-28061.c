//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: romantic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main() {
    // Open the cover image
    FILE *cover = fopen("cover.bmp", "rb");
    if (!cover) {
        printf("Error opening cover image\n");
        return 1;
    }

    // Read the cover image header
    unsigned char header[54];
    fread(header, 54, 1, cover);

    // Get the width and height of the cover image
    int width = *(int *)&header[18];
    int height = *(int *)&header[22];

    // Create a buffer to store the cover image data
    unsigned char *cover_data = malloc(width * height * 3);
    fread(cover_data, width * height * 3, 1, cover);

    // Close the cover image
    fclose(cover);

    // Open the secret message file
    FILE *secret = fopen("secret.txt", "rb");
    if (!secret) {
        printf("Error opening secret message file\n");
        return 1;
    }

    // Read the secret message
    char *secret_message = malloc(100);
    fread(secret_message, 100, 1, secret);

    // Close the secret message file
    fclose(secret);

    // Embed the secret message in the cover image
    int secret_index = 0;
    for (int i = 0; i < width * height * 3; i += 3) {
        // Get the current pixel
        pixel *current_pixel = (pixel *)&cover_data[i];

        // Embed the next character of the secret message in the least significant bit of each color channel
        current_pixel->r &= 0xFE;
        current_pixel->r |= (secret_message[secret_index] >> 6) & 1;
        current_pixel->g &= 0xFE;
        current_pixel->g |= (secret_message[secret_index] >> 4) & 1;
        current_pixel->b &= 0xFE;
        current_pixel->b |= (secret_message[secret_index] >> 2) & 1;

        // Increment the secret message index
        secret_index++;

        // If we have embedded the entire secret message, break out of the loop
        if (secret_index == strlen(secret_message)) {
            break;
        }
    }

    // Open the stego image file
    FILE *stego = fopen("stego.bmp", "wb");
    if (!stego) {
        printf("Error opening stego image file\n");
        return 1;
    }

    // Write the stego image header
    fwrite(header, 54, 1, stego);

    // Write the stego image data
    fwrite(cover_data, width * height * 3, 1, stego);

    // Close the stego image file
    fclose(stego);

    // Free the allocated memory
    free(cover_data);
    free(secret_message);

    printf("The secret message has been successfully embedded in the cover image.\n");

    return 0;
}