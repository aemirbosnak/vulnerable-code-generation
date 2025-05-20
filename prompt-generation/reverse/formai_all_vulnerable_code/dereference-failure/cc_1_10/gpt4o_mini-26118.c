//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <unistd.h>

#define MAX_INPUT_SIZE 256
#define HASH_SIZE SHA256_DIGEST_LENGTH
#define VERSION "CyberCrypt v1.0"

void print_banner() {
    printf("=====================================\n");
    printf("   *  Welcome to %s  *\n", VERSION);
    printf("     The Cyberpunk Cryptography Tool\n");
    printf("=====================================\n");
}

void print_help() {
    printf("Usage: cybercrypt [options] <text>\n");
    printf("Options:\n");
    printf("  -h, --help         Show this help message\n");
    printf("  -e, --encrypt      Encrypt the given text\n");
    printf("  -d, --decrypt      Decrypt the given text (only basic XOR)\n");
    printf("  -H, --hash         Generate SHA256 hash of the text\n");
}

void xor_encrypt_decrypt(char *input, char *output, char key) {
    for (size_t i = 0; i < strlen(input); i++) {
        output[i] = input[i] ^ key;  // XOR operation
    }
    output[strlen(input)] = '\0'; // Null-terminate the string
}

void generate_sha256(char *input, unsigned char *hash_output) {
    SHA256((unsigned char *)input, strlen(input), hash_output);
}

void print_hash(unsigned char *hash_output) {
    printf("SHA256 Hash: ");
    for (int i = 0; i < HASH_SIZE; i++) {
        printf("%02x", hash_output[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        print_help();
        return 1;
    }

    print_banner();

    char operation = ' ';
    char input[MAX_INPUT_SIZE];
    unsigned char hash_output[HASH_SIZE];
    char key = 'K'; // Basic XOR key for simplicity
    
    // Parse command-line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_help();
            return 0;
        } else if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--encrypt") == 0) {
            operation = 'e';
        } else if (strcmp(argv[i], "-d") == 0 || strcmp(argv[i], "--decrypt") == 0) {
            operation = 'd';
        } else if (strcmp(argv[i], "-H") == 0 || strcmp(argv[i], "--hash") == 0) {
            operation = 'H';
        } else {
            strncpy(input, argv[i], MAX_INPUT_SIZE - 1);
            input[MAX_INPUT_SIZE - 1] = '\0'; // Ensure null-termination
        }
    }

    switch (operation) {
        case 'e':
            {
                char output[MAX_INPUT_SIZE];
                memset(output, 0, sizeof(output));
                xor_encrypt_decrypt(input, output, key);
                printf("Encrypted: %s\n", output);
            }
            break;

        case 'd':
            {
                char output[MAX_INPUT_SIZE];
                memset(output, 0, sizeof(output));
                xor_encrypt_decrypt(input, output, key);
                printf("Decrypted: %s\n", output);
            }
            break;

        case 'H':
            generate_sha256(input, hash_output);
            print_hash(hash_output);
            break;

        default:
            printf("Error: No valid operation specified.\n");
            print_help();
            return 1;
    }

    return 0;
}