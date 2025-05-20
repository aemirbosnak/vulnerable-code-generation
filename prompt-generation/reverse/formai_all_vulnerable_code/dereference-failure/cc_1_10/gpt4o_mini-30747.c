//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

void xor_encrypt_decrypt(const char *inputfile, const char *outputfile, char key) {
    FILE *input_fp = fopen(inputfile, "rb");
    FILE *output_fp = fopen(outputfile, "wb");

    if (!input_fp || !output_fp) {
        perror("Error opening files");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    while ((bytes_read = fread(buffer, sizeof(char), BUFFER_SIZE, input_fp)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key; // XOR operation
        }
        fwrite(buffer, sizeof(char), bytes_read, output_fp);
    }

    fclose(input_fp);
    fclose(output_fp);
    
    printf("Processing completed: '%s' has been encrypted/decrypted to '%s' using key '%c'\n", inputfile, outputfile, key);
}

void display_usage(const char *program_name) {
    printf("Usage: %s <action> <inputfile> <outputfile> <key>\n", program_name);
    printf("Actions:\n");
    printf("  encrypt  - Encrypt the input file\n");
    printf("  decrypt  - Decrypt the input file\n");
    printf("Key is a single character used for XOR encryption/decryption.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        display_usage(argv[0]);
        return EXIT_FAILURE;
    }

    const char *action = argv[1];
    const char *inputfile = argv[2];
    const char *outputfile = argv[3];
    char key = argv[4][0];

    if (strcmp(action, "encrypt") == 0) {
        xor_encrypt_decrypt(inputfile, outputfile, key);
    } else if (strcmp(action, "decrypt") == 0) {
        xor_encrypt_decrypt(inputfile, outputfile, key);
    } else {
        printf("Invalid action: '%s'. Use 'encrypt' or 'decrypt'.\n", action);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}