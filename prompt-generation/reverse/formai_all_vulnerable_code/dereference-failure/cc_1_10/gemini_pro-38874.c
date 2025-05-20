//GEMINI-pro DATASET v1.0 Category: Digital Watermarking ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

// Embeds a secret message into an image.
int main(int argc, char** argv) {
    if (argc != 4) {
        printf("Usage: %s <image> <message> <output>\n", argv[0]);
        return 1;
    }

    // Open the image file.
    FILE* image = fopen(argv[1], "rb");
    if (image == NULL) {
        printf("Error opening image file.\n");
        return 1;
    }

    // Read the image data into a buffer.
    fseek(image, 0, SEEK_END);
    long size = ftell(image);
    fseek(image, 0, SEEK_SET);
    unsigned char* data = malloc(size);
    if (data == NULL) {
        printf("Error allocating memory for image data.\n");
        return 1;
    }
    fread(data, 1, size, image);
    fclose(image);

    // Convert the secret message to binary.
    unsigned char* message = malloc(strlen(argv[2]) + 1);
    if (message == NULL) {
        printf("Error allocating memory for secret message.\n");
        return 1;
    }
    strcpy(message, argv[2]);
    for (int i = 0; i < strlen(message); i++) {
        message[i] = message[i] & 0x01;
    }

    // Embed the secret message into the image data.
    for (int i = 0; i < strlen(message); i++) {
        data[i + size / 2] = data[i + size / 2] | message[i];
    }

    // Save the watermarked image to a file.
    FILE* output = fopen(argv[3], "wb");
    if (output == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }
    fwrite(data, 1, size, output);
    fclose(output);

    printf("Secret message embedded into image.\n");

    return 0;
}