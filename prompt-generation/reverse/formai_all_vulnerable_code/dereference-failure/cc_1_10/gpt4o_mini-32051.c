//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_MESSAGE_LENGTH 1024
#define KEY_LENGTH 16 // AES uses 128 bit = 16 bytes key

void generate_key(char *key, int length) {
    // Initialize random number generator
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        key[i] = rand() % 256; // key values between 0-255
    }
}

void xor_cipher(const char *input, char *output, const char *key) {
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] ^ key[i % KEY_LENGTH]; // XOR each byte with key
    }
    output[len] = '\0'; // null-terminate the string
}

void print_usage() {
    printf("Usage: ./crypto <message>\n");
    printf("This program encrypts and decrypts the provided message using XOR cipher.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage();
        return 1;
    }

    const char *message = argv[1];
    char key[KEY_LENGTH + 1]; // +1 for null terminator
    char encrypted[MAX_MESSAGE_LENGTH];
    char decrypted[MAX_MESSAGE_LENGTH];

    // Generate the key
    generate_key(key, KEY_LENGTH);
    printf("Generated Key: ");
    for (int i = 0; i < KEY_LENGTH; i++) {
        printf("%02X ", (unsigned char)key[i]);
    }
    printf("\n");

    // Encrypt the message
    xor_cipher(message, encrypted, key);
    printf("Encrypted Message: ");
    for (int i = 0; i < strlen(message); i++) {
        printf("%02X ", (unsigned char)encrypted[i]);
    }
    printf("\n");

    // Decrypt the message
    xor_cipher(encrypted, decrypted, key);
    printf("Decrypted Message: %s\n", decrypted);

    return 0;
}