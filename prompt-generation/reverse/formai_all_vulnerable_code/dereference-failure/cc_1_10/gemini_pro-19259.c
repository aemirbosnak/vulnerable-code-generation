//GEMINI-pro DATASET v1.0 Category: Cryptography Implementation ; Style: complete
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ENCRYPT 1
#define DECRYPT 0

// Key for XOR encryption
unsigned char key[] = "mysecretkey";

// XOR encryption/decryption function
void xor_crypt(unsigned char *data, size_t data_len, unsigned char *key, size_t key_len, int mode)
{
    // Create a temporary buffer for the result
    unsigned char *result = malloc(data_len);
    if (!result) {
        fprintf(stderr, "Error: failed to allocate memory for result buffer\n");
        exit(1);
    }

    // XOR each byte of the data with the corresponding byte of the key
    for (size_t i = 0; i < data_len; i++) {
        if (mode == ENCRYPT) {
            result[i] = data[i] ^ key[i % key_len];
        } else if (mode == DECRYPT) {
            result[i] = data[i] ^ key[i % key_len];
        } else {
            fprintf(stderr, "Error: invalid mode specified\n");
            exit(1);
        }
    }

    // Copy the result back to the data buffer
    memcpy(data, result, data_len);

    // Free the temporary buffer
    free(result);
}

int main(int argc, char **argv)
{
    // Check if the correct number of arguments is provided
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <input file> <output file> <mode>\n", argv[0]);
        exit(1);
    }

    // Get the input and output file names
    char *input_file = argv[1];
    char *output_file = argv[2];

    // Get the mode (encrypt or decrypt)
    int mode = atoi(argv[3]);
    if (mode != ENCRYPT && mode != DECRYPT) {
        fprintf(stderr, "Error: invalid mode specified\n");
        exit(1);
    }

    // Open the input file
    FILE *input = fopen(input_file, "rb");
    if (!input) {
        fprintf(stderr, "Error: failed to open input file\n");
        exit(1);
    }

    // Determine the size of the input file
    fseek(input, 0, SEEK_END);
    size_t input_size = ftell(input);
    fseek(input, 0, SEEK_SET);

    // Read the input data into a buffer
    unsigned char *input_data = malloc(input_size);
    if (!input_data) {
        fprintf(stderr, "Error: failed to allocate memory for input buffer\n");
        exit(1);
    }
    fread(input_data, 1, input_size, input);
    fclose(input);

    // Determine the key length
    size_t key_len = strlen(key);

    // Encrypt or decrypt the data
    xor_crypt(input_data, input_size, key, key_len, mode);

    // Open the output file
    FILE *output = fopen(output_file, "wb");
    if (!output) {
        fprintf(stderr, "Error: failed to open output file\n");
        exit(1);
    }

    // Write the encrypted or decrypted data to the output file
    fwrite(input_data, 1, input_size, output);
    fclose(output);

    // Free the input data buffer
    free(input_data);

    // Print a success message
    printf("Data %s successfully!\n", mode == ENCRYPT ? "encrypted" : "decrypted");

    return 0;
}