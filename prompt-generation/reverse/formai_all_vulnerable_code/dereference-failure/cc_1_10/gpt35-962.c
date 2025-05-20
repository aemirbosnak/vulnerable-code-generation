//FormAI DATASET v1.0 Category: Image Steganography ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME 256
#define MAX_MESSAGE 1024
#define MAX_BUFFER 1024

struct Pixel {
    unsigned char r, g, b;
};

int main() {
    // Get file name
    char filename[MAX_FILENAME];
    printf("Enter image file name: ");
    scanf("%s", filename);

    // Open the input file and load the image pixels
    FILE *in = fopen(filename, "rb");
    if(in == NULL) {
        printf("Error: Could not open image file\n");
        exit(EXIT_FAILURE);
    }

    fseek(in, 0, SEEK_END);
    long int file_size = ftell(in);
    fseek(in, 0, SEEK_SET);

    struct Pixel *pixels = malloc(file_size);

    fread(pixels, sizeof(struct Pixel), file_size, in);

    // Get the message from user
    char message[MAX_MESSAGE];
    printf("Enter message to hide: ");
    scanf(" %[^\n]s", message);

    // Calculate message length, in bits
    int message_length = strlen(message) * 8;

    // Check if image can hold the message
    if (message_length > (file_size * 3)) {
        printf("Error: Message too large for image\n");
        exit(EXIT_FAILURE);
    }

    // Create bitstream of message
    unsigned char *bitstream = malloc(message_length + 1);

    for (int i = 0; i < strlen(message); i++) {
        char c = message[i];

        for (int j = 0; j < 8; j++) {
            *(bitstream + (i * 8) + j) = (c >> (7 - j)) & 0x01;
        }
    }

    // Set the least significant bit of each color channel to the next bit in the bitstream
    int i = 0;
    for (int j = 0; j < message_length; j++) {
        struct Pixel *pixel = &pixels[j];

        pixel->r &= 0xFE;
        pixel->g &= 0xFE;
        pixel->b &= 0xFE;

        pixel->r |= *(bitstream + j);
        pixel->g |= *(bitstream + j + 1);
        pixel->b |= *(bitstream + j + 2);

        i += 3;
    }

    // Save the modified image
    FILE *out = fopen("encoded.bmp", "wb");
    if(out == NULL) {
        printf("Error: Could not open output file\n");
        exit(EXIT_FAILURE);
    }

    fwrite(pixels, sizeof(struct Pixel), file_size, out);

    // Cleanup
    fclose(in);
    fclose(out);
    free(pixels);
    free(bitstream);

    printf("Message hidden successfully!\n");

    return 0;
}