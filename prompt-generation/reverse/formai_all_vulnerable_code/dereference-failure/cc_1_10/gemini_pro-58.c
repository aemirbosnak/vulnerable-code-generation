//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Shift-rotate a byte by the specified number of bits
unsigned char shift_rotate(unsigned char byte, int bits) {
    return (byte >> (8 - bits)) | (byte << bits);
}

// Encrypt a file using a simple shift-rotate cipher
// Key is a string of up to 16 characters
void encrypt_file(const char *filename, const char *key) {
    // Open the input and output files
    FILE *input = fopen(filename, "rb");
    if (input == NULL) {
        perror("Error opening input file");
        return;
    }

    char output_filename[strlen(filename) + 5];
    sprintf(output_filename, "%s.enc", filename);
    FILE *output = fopen(output_filename, "wb");
    if (output == NULL) {
        perror("Error opening output file");
        fclose(input);
        return;
    }

    // Get the key length
    int key_len = strlen(key);
    if (key_len > 16) {
        fprintf(stderr, "Error: Key is too long (maximum 16 characters)\n");
        fclose(input);
        fclose(output);
        return;
    }

    // Read and encrypt the file
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] = shift_rotate(buffer[i], key[i % key_len]);
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the files
    fclose(input);
    fclose(output);
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <filename> <key>\n", argv[0]);
        return EXIT_FAILURE;
    }

    encrypt_file(argv[1], argv[2]);

    return EXIT_SUCCESS;
}