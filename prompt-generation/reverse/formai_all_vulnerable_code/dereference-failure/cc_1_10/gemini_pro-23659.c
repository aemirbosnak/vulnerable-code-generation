//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENCRYPT 1
#define DECRYPT 0

// XOR encryption function
void xor_encrypt(char *text, int length, char *key) {
    int key_index = 0;
    for (int i = 0; i < length; i++) {
        text[i] ^= key[key_index];
        key_index = (key_index + 1) % strlen(key);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Usage: %s <input file> <output file> <key> <mode (0 for decrypt, 1 for encrypt)>\n", argv[0]);
        return -1;
    }

    // Get command-line arguments
    char *input_file = argv[1];
    char *output_file = argv[2];
    char *key = argv[3];
    int mode = atoi(argv[4]);

    // Validate mode
    if (mode != ENCRYPT && mode != DECRYPT) {
        printf("Invalid mode. Please enter 0 for decrypt or 1 for encrypt.\n");
        return -1;
    }

    // Open input file
    FILE *input_stream = fopen(input_file, "rb");
    if (input_stream == NULL) {
        printf("Error opening input file: %s\n", input_file);
        return -1;
    }

    // Get input file size
    fseek(input_stream, 0, SEEK_END);
    long file_size = ftell(input_stream);
    rewind(input_stream);

    // Allocate memory for input data
    char *input_data = malloc(file_size);
    if (input_data == NULL) {
        printf("Memory allocation failed.\n");
        fclose(input_stream);
        return -1;
    }

    // Read input file data
    size_t bytes_read = fread(input_data, 1, file_size, input_stream);
    if (bytes_read != file_size) {
        printf("Error reading input file.\n");
        free(input_data);
        fclose(input_stream);
        return -1;
    }

    // Close input file
    fclose(input_stream);

    // Perform encryption or decryption
    if (mode == ENCRYPT) {
        xor_encrypt(input_data, file_size, key);
    } else {
        xor_encrypt(input_data, file_size, key);
    }

    // Open output file
    FILE *output_stream = fopen(output_file, "wb");
    if (output_stream == NULL) {
        printf("Error opening output file: %s\n", output_file);
        free(input_data);
        return -1;
    }

    // Write encrypted/decrypted data to output file
    fwrite(input_data, 1, file_size, output_stream);

    // Close output file
    fclose(output_stream);

    // Free memory
    free(input_data);

    return 0;
}