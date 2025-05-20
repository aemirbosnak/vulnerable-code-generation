//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16 // Size of the encryption key
#define BLOCK_SIZE 16 // Size of data blocks
#define BUFFER_SIZE 256 // Maximum buffer size for input

void generate_key(char *key) {
    srand(time(NULL)); // Seed for random number generation
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Generate random bytes for the key
    }
}

void xor_encrypt_decrypt(char *input, char *output, char *key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % KEY_SIZE]; // XOR encryption/decryption
    }
}

void encrypt_file(const char *input_file, const char *output_file, char *key) {
    FILE *in = fopen(input_file, "rb");
    FILE *out = fopen(output_file, "wb");

    if (in == NULL || out == NULL) {
        fprintf(stderr, "Error opening file.\n");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        char encrypted[BUFFER_SIZE];
        xor_encrypt_decrypt(buffer, encrypted, key, bytes_read);
        fwrite(encrypted, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
}

void decrypt_file(const char *input_file, const char *output_file, char *key) {
    encrypt_file(input_file, output_file, key); // XOR decryption
}

void print_key(char *key) {
    printf("Encryption Key: ");
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%02x", (unsigned char)key[i]);
    }
    printf("\n");
}

void print_usage() {
    printf("Usage: \n");
    printf("  Encrypt: ./crypto_tool encrypt <input_file> <output_file>\n");
    printf("  Decrypt: ./crypto_tool decrypt <input_file> <output_file>\n");
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        print_usage();
        return EXIT_FAILURE;
    }

    char key[KEY_SIZE];
    generate_key(key);
    print_key(key);

    if (strcmp(argv[1], "encrypt") == 0) {
        encrypt_file(argv[2], argv[3], key);
        printf("File encrypted successfully.\n");
    } else if (strcmp(argv[1], "decrypt") == 0) {
        decrypt_file(argv[2], argv[3], key);
        printf("File decrypted successfully.\n");
    } else {
        print_usage();
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}