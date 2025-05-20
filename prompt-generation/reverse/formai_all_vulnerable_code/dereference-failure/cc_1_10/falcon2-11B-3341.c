//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int encrypt(const char* filename, const char* key, char* output_filename) {
    // Open the input file in read mode
    FILE* input_file = fopen(filename, "rb");

    // Check if the file was successfully opened
    if (input_file == NULL) {
        fprintf(stderr, "Could not open input file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the encrypted output file
    char* output_buffer = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    if (output_buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for encrypted output buffer.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the encrypted output buffer
    memset(output_buffer, 0, strlen(key) + 1);

    // Read the contents of the input file one byte at a time
    int byte;
    while ((byte = fgetc(input_file))!= EOF) {
        // Convert each byte to a hexadecimal string representation
        char hex[3];
        sprintf(hex, "%02X", byte);

        // XOR the byte with the corresponding character in the key
        char c = hex[0] ^ key[byte % strlen(key)];

        // Convert the resulting character back to an ASCII value and store it in the output buffer
        char ascii = c & 0xff;
        output_buffer[byte % strlen(key)] = ascii;
    }

    // Close the input file
    fclose(input_file);

    // Write the contents of the encrypted output buffer to the output file
    FILE* output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to open output file %s for writing.\n", output_filename);
        exit(EXIT_FAILURE);
    }
    fwrite(output_buffer, sizeof(char), strlen(key) + 1, output_file);
    fclose(output_file);

    return 0;
}

int decrypt(const char* filename, const char* key, char* output_filename) {
    // Open the input file in read mode
    FILE* input_file = fopen(filename, "rb");

    // Check if the file was successfully opened
    if (input_file == NULL) {
        fprintf(stderr, "Could not open input file %s for reading.\n", filename);
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the decrypted output file
    char* output_buffer = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    if (output_buffer == NULL) {
        fprintf(stderr, "Failed to allocate memory for decrypted output buffer.\n");
        exit(EXIT_FAILURE);
    }

    // Initialize the decrypted output buffer
    memset(output_buffer, 0, strlen(key) + 1);

    // Read the contents of the input file one byte at a time
    int byte;
    while ((byte = fgetc(input_file))!= EOF) {
        // Convert each byte to a hexadecimal string representation
        char hex[3];
        sprintf(hex, "%02X", byte);

        // XOR the byte with the corresponding character in the key
        char c = hex[0] ^ key[byte % strlen(key)];

        // Convert the resulting character back to an ASCII value and store it in the output buffer
        char ascii = c & 0xff;
        output_buffer[byte % strlen(key)] = ascii;
    }

    // Close the input file
    fclose(input_file);

    // Write the contents of the decrypted output buffer to the output file
    FILE* output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Failed to open output file %s for writing.\n", output_filename);
        exit(EXIT_FAILURE);
    }
    fwrite(output_buffer, sizeof(char), strlen(key) + 1, output_file);
    fclose(output_file);

    return 0;
}

char* generate_key(const char* key) {
    // Convert the key to a binary format
    unsigned char key_bytes[strlen(key)];
    int i;
    for (i = 0; i < strlen(key); i++) {
        key_bytes[i] = (unsigned char)key[i];
    }

    // Return the binary key as a string
    char* binary_key = (char*)malloc(sizeof(char) * (strlen(key) + 1));
    memcpy(binary_key, key_bytes, strlen(key) + 1);

    return binary_key;
}

int main(int argc, char** argv) {
    // Check if the correct number of arguments were provided
    if (argc!= 5) {
        fprintf(stderr, "Usage: %s <input file> <key> <output file> <decrypt flag>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read the input file, key, and output file from the command line arguments
    const char* input_file = argv[1];
    const char* key = argv[2];
    char* output_file = argv[3];
    int decrypt_flag = atoi(argv[4]);

    // Generate the binary key from the provided key
    char* binary_key = generate_key(key);

    // Encrypt or decrypt the file based on the decrypt flag
    if (decrypt_flag == 0) {
        decrypt(input_file, binary_key, output_file);
    } else {
        encrypt(input_file, binary_key, output_file);
    }

    free(binary_key);

    return 0;
}