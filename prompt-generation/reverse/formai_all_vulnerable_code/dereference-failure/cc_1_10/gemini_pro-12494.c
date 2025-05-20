//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    unsigned char r, g, b;
} pixel;

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <image> <message> <output>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *image = fopen(argv[1], "rb");
    if (!image) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *message = fopen(argv[2], "rb");
    if (!message) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    FILE *output = fopen(argv[3], "wb");
    if (!output) {
        perror("fopen");
        return EXIT_FAILURE;
    }

    // Read the image header
    unsigned char header[54];
    fread(header, 1, 54, image);
    fwrite(header, 1, 54, output);

    // Read the image data
    pixel *data = malloc(sizeof(pixel) * 512 * 512);
    fread(data, sizeof(pixel), 512 * 512, image);

    // Read the message
    char *msg = malloc(sizeof(char) * 1024);
    fread(msg, 1, 1024, message);

    // Embed the message in the image
    int i = 0;
    int j = 0;
    for (i = 0; i < 1024; i++) {
        for (j = 0; j < 8; j++) {
            if (msg[i] & (1 << j)) {
                data[i * 8 + j].r |= 1;
            } else {
                data[i * 8 + j].r &= ~1;
            }
        }
    }

    // Write the image data
    fwrite(data, sizeof(pixel), 512 * 512, output);

    // Free the memory
    free(data);
    free(msg);

    // Close the files
    fclose(image);
    fclose(message);
    fclose(output);

    return EXIT_SUCCESS;
}