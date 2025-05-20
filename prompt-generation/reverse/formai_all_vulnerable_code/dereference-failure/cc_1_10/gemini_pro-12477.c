//GEMINI-pro DATASET v1.0 Category: Image Steganography ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

typedef struct {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Pixel;

void encode_bit(Pixel *pixel, int bit) {
    pixel->a &= ~1;  // Clear the least significant bit
    pixel->a |= bit;  // Set the least significant bit to the value of `bit`
}

int decode_bit(Pixel *pixel) {
    return pixel->a & 1;  // Return the least significant bit
}

void encode(const char *in_file, const char *out_file, const char *message) {
    FILE *in = fopen(in_file, "rb");
    if (!in) {
        perror("fopen(in_file)");
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(out_file, "wb");
    if (!out) {
        perror("fopen(out_file)");
        exit(EXIT_FAILURE);
    }

    // Read the header from the input file
    uint32_t width, height;
    fread(&width, sizeof(width), 1, in);
    fread(&height, sizeof(height), 1, in);

    // Write the header to the output file
    fwrite(&width, sizeof(width), 1, out);
    fwrite(&height, sizeof(height), 1, out);

    // Read the pixels from the input file
    Pixel *pixels = malloc(width * height * sizeof(Pixel));
    if (!pixels) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(pixels, sizeof(Pixel), width * height, in);

    // Encode the message into the pixels
    int bit_index = 0;
    for (int i = 0; message[i] != '\0'; i++) {
        for (int j = 0; j < 8; j++) {
            encode_bit(&pixels[bit_index++], message[i] >> j & 1);
        }
    }

    // Write the pixels to the output file
    fwrite(pixels, sizeof(Pixel), width * height, out);

    // Free the memory
    free(pixels);

    // Close the files
    fclose(in);
    fclose(out);
}

void decode(const char *in_file, const char *out_file) {
    FILE *in = fopen(in_file, "rb");
    if (!in) {
        perror("fopen(in_file)");
        exit(EXIT_FAILURE);
    }

    FILE *out = fopen(out_file, "w");
    if (!out) {
        perror("fopen(out_file)");
        exit(EXIT_FAILURE);
    }

    // Read the header from the input file
    uint32_t width, height;
    fread(&width, sizeof(width), 1, in);
    fread(&height, sizeof(height), 1, in);

    // Read the pixels from the input file
    Pixel *pixels = malloc(width * height * sizeof(Pixel));
    if (!pixels) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    fread(pixels, sizeof(Pixel), width * height, in);

    // Decode the message from the pixels
    int bit_index = 0;
    char message[width * height * 8];
    int message_length = 0;
    while (bit_index < width * height * 8) {
        for (int i = 0; i < 8; i++) {
            message[message_length++] = decode_bit(&pixels[bit_index++]) << i;
        }
        if (message[message_length - 1] == '\0') {
            break;
        }
    }

    // Write the message to the output file
    fprintf(out, "%s", message);

    // Free the memory
    free(pixels);

    // Close the files
    fclose(in);
    fclose(out);
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <in_file> <out_file> [message]\n", argv[0]);
        return 1;
    }

    if (argc == 3) {
        decode(argv[1], argv[2]);
    } else {
        encode(argv[1], argv[2], argv[3]);
    }

    return 0;
}