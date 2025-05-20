//GEMINI-pro DATASET v1.0 Category: File Encyptor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a file using a simple XOR cipher
void encrypt_file(char* input_file, char* output_file, unsigned char key) {
    // Open the input and output files
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return;
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return;
    }

    // Read the input file and apply the XOR encryption
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to decrypt a file using the same XOR cipher
void decrypt_file(char* input_file, char* output_file, unsigned char key) {
    // Open the input and output files
    FILE* input = fopen(input_file, "rb");
    if (input == NULL) {
        fprintf(stderr, "Error opening input file: %s\n", input_file);
        return;
    }

    FILE* output = fopen(output_file, "wb");
    if (output == NULL) {
        fprintf(stderr, "Error opening output file: %s\n", output_file);
        return;
    }

    // Read the input file and apply the XOR decryption
    unsigned char buffer[1024];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), input)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, 1, bytes_read, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);
}

// Function to generate a random key for the encryption
unsigned char generate_key() {
    // Seed the random number generator with the current time
    srand(time(NULL));

    // Generate a random number between 0 and 255
    return rand() % 256;
}

// Main function
int main(int argc, char* argv[]) {
    // Check if the user has provided enough arguments
    if (argc < 3) {
        fprintf(stderr, "Usage: %s input_file output_file [encrypt|decrypt]\n", argv[0]);
        return 1;
    }

    // Get the input and output file names
    char* input_file = argv[1];
    char* output_file = argv[2];

    // Get the encryption or decryption mode
    char* mode = NULL;
    if (argc >= 4) {
        mode = argv[3];
    }

    // Generate a random key if necessary
    unsigned char key;
    if (mode == NULL || strcmp(mode, "encrypt") == 0) {
        key = generate_key();
    } else if (strcmp(mode, "decrypt") == 0) {
        // Prompt the user for the key
        printf("Enter the encryption key: ");
        scanf("%hhu", &key);
    } else {
        fprintf(stderr, "Invalid mode: %s\n", mode);
        return 1;
    }

    // Encrypt or decrypt the file
    if (strcmp(mode, "encrypt") == 0) {
        encrypt_file(input_file, output_file, key);
    } else if (strcmp(mode, "decrypt") == 0) {
        decrypt_file(input_file, output_file, key);
    }

    return 0;
}