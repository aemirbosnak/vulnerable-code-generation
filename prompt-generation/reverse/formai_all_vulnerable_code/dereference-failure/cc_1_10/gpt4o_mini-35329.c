//GPT-4o-mini DATASET v1.0 Category: Encryption ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 1024
#define KEY_LENGTH 16

void generate_key(char *key, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    for (int i = 0; i < length; i++) {
        int key_position = rand() % (sizeof(charset) - 1);
        key[i] = charset[key_position];
    }
    key[length] = '\0';
}

void encrypt(char *plaintext, char *ciphertext, char *key) {
    for (int i = 0; i < strlen(plaintext); i++) {
        ciphertext[i] = plaintext[i] ^ key[i % KEY_LENGTH];
    }
    ciphertext[strlen(plaintext)] = '\0';
}

void decrypt(char *ciphertext, char *plaintext, char *key) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        plaintext[i] = ciphertext[i] ^ key[i % KEY_LENGTH];
    }
    plaintext[strlen(ciphertext)] = '\0';
}

void take_input(char *buffer, size_t size) {
    if (fgets(buffer, size, stdin) != NULL) {
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n') {
            buffer[len - 1] = '\0'; // Remove newline character
        }
    }
}

void print_usage(const char *prog_name) {
    printf("Usage: %s <encrypt|decrypt>\n", prog_name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Seed the random number generator
    srand(time(NULL));

    char key[KEY_LENGTH + 1];
    generate_key(key, KEY_LENGTH);
    char buffer[MAX_SIZE];
    char result[MAX_SIZE];

    if (strcmp(argv[1], "encrypt") == 0) {
        printf("Enter plaintext to encrypt: ");
        take_input(buffer, MAX_SIZE);
        
        encrypt(buffer, result, key);
        printf("Encrypted text: %s\n", result);
        printf("Encryption key (store this safely!): %s\n", key);

    } else if (strcmp(argv[1], "decrypt") == 0) {
        printf("Enter ciphertext to decrypt: ");
        take_input(buffer, MAX_SIZE);
        
        printf("Enter the key used for encryption: ");
        char input_key[KEY_LENGTH + 1];
        take_input(input_key, KEY_LENGTH + 1);
        
        decrypt(buffer, result, input_key);
        printf("Decrypted text: %s\n", result);

    } else {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    // Additional paranoia: Clear buffers
    memset(buffer, 0, sizeof(buffer));
    memset(result, 0, sizeof(result));
    
    return EXIT_SUCCESS;
}