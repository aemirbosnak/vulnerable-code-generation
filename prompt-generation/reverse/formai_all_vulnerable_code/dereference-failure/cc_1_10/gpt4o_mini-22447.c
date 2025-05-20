//GPT-4o-mini DATASET v1.0 Category: File Encryptor ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt the file data using XOR cipher
void encrypt_file(const char *input_file, const char *output_file, char key) {
    FILE *in_file = fopen(input_file, "rb");
    FILE *out_file = fopen(output_file, "wb");
    
    if (!in_file || !out_file) {
        fprintf(stderr, "Error opening files.\n");
        exit(EXIT_FAILURE);
    }

    int ch;
    while ((ch = fgetc(in_file)) != EOF) {
        // XOR the character with the key for encryption
        fputc(ch ^ key, out_file);
    }

    fclose(in_file);
    fclose(out_file);
}

// Function to decrypt the file data using XOR cipher
void decrypt_file(const char *input_file, const char *output_file, char key) {
    encrypt_file(input_file, output_file, key); // The encryption and decryption methods are symmetric
}

// Function to display a welcome message and usage instructions
void display_welcome_message() {
    printf("Welcome to the Introspective File Encryptor!\n");
    printf("This program encrypts a file using a simple XOR cipher.\n");
    printf("Usage:\n");
    printf("  encryptor <input_file> <output_file> <key>\n");
    printf("  decryptor <input_file> <output_file> <key>\n");
    printf("Where <key> is a single character that will be used for encryption/decryption.\n");
    printf("Prepare to embark on an introspective journey through your files!\n\n");
}

// Function to check the command line arguments
void check_arguments(int argc) {
    if (argc != 5) {
        fprintf(stderr, "Invalid number of arguments.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to decide whether to encrypt or decrypt based on the operation flag
void process_file(int argc, char *argv[]) {
    char mode = argv[1][0];
    char *input_file = argv[2];
    char *output_file = argv[3];
    char key = argv[4][0];

    if (mode == 'e') {
        printf("Encrypting file: %s with key: '%c'...\n", input_file, key);
        encrypt_file(input_file, output_file, key);
        printf("Encryption completed! Encrypted data written to: %s\n", output_file);
    } else if (mode == 'd') {
        printf("Decrypting file: %s with key: '%c'...\n", input_file, key);
        decrypt_file(input_file, output_file, key);
        printf("Decryption completed! Decrypted data written to: %s\n", output_file);
    } else {
        fprintf(stderr, "Invalid operation '%c'. Use 'e' for encrypt and 'd' for decrypt.\n", mode);
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    display_welcome_message();
    check_arguments(argc);
    process_file(argc, argv);
    
    return 0;
}