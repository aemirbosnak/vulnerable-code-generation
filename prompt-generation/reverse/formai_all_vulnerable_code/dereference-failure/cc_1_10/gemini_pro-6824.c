//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Hide a message in an image using least significant bit steganography
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 4) {
        printf("Usage: %s <image> <message> <output>\n", argv[0]);
        return 1;
    }

    // Read the image
    FILE *image = fopen(argv[1], "rb");
    if (image == NULL) {
        printf("Error opening image\n");
        return 1;
    }

    // Get the image size
    int width, height;
    fread(&width, sizeof(int), 1, image);
    fread(&height, sizeof(int), 1, image);

    // Read the message
    FILE *message = fopen(argv[2], "r");
    if (message == NULL) {
        printf("Error opening message\n");
        return 1;
    }

    // Get the message size
    int message_size;
    fseek(message, 0, SEEK_END);
    message_size = ftell(message);
    fseek(message, 0, SEEK_SET);

    // Check if the message is too large
    if (message_size > width * height * 3) {
        printf("Error: message is too large\n");
        return 1;
    }

    // Encode the message in the image
    unsigned char *data = malloc(width * height * 3);
    fread(data, 1, width * height * 3, image);
    for (int i = 0; i < message_size; i++) {
        int byte = fgetc(message);
        for (int j = 0; j < 8; j++) {
            int bit = (byte >> j) & 1;
            data[i * 8 + j] = (data[i * 8 + j] & 0xFE) | bit;
        }
    }

    // Write the output image
    FILE *output = fopen(argv[3], "wb");
    if (output == NULL) {
        printf("Error opening output image\n");
        return 1;
    }
    fwrite(&width, sizeof(int), 1, output);
    fwrite(&height, sizeof(int), 1, output);
    fwrite(data, 1, width * height * 3, output);

    // Free memory
    fclose(image);
    fclose(message);
    fclose(output);
    free(data);

    printf("Message hidden successfully!\n");
    return 0;
}