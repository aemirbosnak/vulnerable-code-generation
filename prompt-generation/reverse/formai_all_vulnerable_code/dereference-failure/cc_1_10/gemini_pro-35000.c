//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 512

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_image> <output_image> <secret_message>\n", argv[0]);
        return 1;
    }

    FILE *input_image = fopen(argv[1], "rb");
    if (input_image == NULL) {
        printf("Error opening input image file\n");
        return 1;
    }

    FILE *output_image = fopen(argv[2], "wb");
    if (output_image == NULL) {
        printf("Error opening output image file\n");
        return 1;
    }

    // Read the input image into a buffer
    unsigned char *buffer = malloc(MAX_SIZE * MAX_SIZE * 3);
    if (buffer == NULL) {
        printf("Error allocating memory for input image buffer\n");
        return 1;
    }
    fread(buffer, 1, MAX_SIZE * MAX_SIZE * 3, input_image);

    // Get the size of the secret message
    int message_size = strlen(argv[3]);

    // Encode the secret message into the LSBs of the image pixels
    for (int i = 0; i < message_size; i++) {
        for (int j = 0; j < 8; j++) {
            int bit = (argv[3][i] >> j) & 1;
            buffer[i * 8 + j] = (buffer[i * 8 + j] & 0xFE) | bit;
        }
    }

    // Write the steganographed image to the output file
    fwrite(buffer, 1, MAX_SIZE * MAX_SIZE * 3, output_image);

    // Free the allocated memory
    free(buffer);

    // Close the files
    fclose(input_image);
    fclose(output_image);

    return 0;
}