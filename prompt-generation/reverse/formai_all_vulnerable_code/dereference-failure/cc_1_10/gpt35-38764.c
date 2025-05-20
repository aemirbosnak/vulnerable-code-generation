//FormAI DATASET v1.0 Category: Image Steganography ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

#define BYTES_PER_PIXEL 3
#define BITS_PER_BYTE 8

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <input_file> <output_file> <secret_message>\n", argv[0]);
        exit(1);
    }

    char *input_file = argv[1];
    char *output_file = argv[2];
    char *message = argv[3];

    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");

    if (in == NULL || out == NULL) {
        printf("Error: Unable to open files\n");
        exit(1);
    }

    // Get input file size
    fseek(in, 0, SEEK_END);
    long file_size = ftell(in);
    rewind(in);

    int message_len = strlen(message);
    int message_bits = message_len * BITS_PER_BYTE;

    if (message_bits > file_size * BYTES_PER_PIXEL) {
        printf("Error: Secret message is too long to fit in image\n");
        exit(1);
    }

    // Read input file header
    unsigned char header[54];
    fread(header, sizeof(unsigned char), 54, in);

    // Write header to output file
    fwrite(header, sizeof(unsigned char), 54, out);

    // Read image data
    unsigned char *image = (unsigned char*) malloc(file_size * sizeof(unsigned char));
    fread(image, sizeof(unsigned char), file_size, in);
    fclose(in);

    int message_index = 0;
    int bit_index = 0;

    for (int i = 54; i < file_size; i += BYTES_PER_PIXEL) {
        if (message_index >= message_len) {
            break;
        }

        unsigned char *pixel = image + i;

        for (int j = 0; j < BYTES_PER_PIXEL; j++) {
            if (bit_index >= BITS_PER_BYTE) {
                bit_index = 0;
                message_index++;
            }

            if (message_index >= message_len) {
                break;
            }

            unsigned char c = message[message_index];
            unsigned char bit = (c >> bit_index) & 0x01;

            pixel[j] = (pixel[j] & 0xFE) | bit; // Replace LSB with message bit

            bit_index++;
        }
    }

    fwrite(image, sizeof(unsigned char), file_size, out);
    fclose(out);
    free(image);

    printf("File encoded successfully\n");

    return 0;
}