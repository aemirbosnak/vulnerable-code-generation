//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define KEY_SIZE 16
#define BLOCK_SIZE 16
#define MAX_MESSAGE_SIZE 256

// Function to generate a random key
void generate_random_key(unsigned char *key) {
    for (int i = 0; i < KEY_SIZE; i++) {
        key[i] = rand() % 256; // Random byte
    }
}

// Simple XOR encryption function
void xor_encrypt_decrypt(unsigned char *input, unsigned char *output, unsigned char *key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        output[i] = input[i] ^ key[i % KEY_SIZE];
    }
}

// Function to pad the message
size_t pad_message(unsigned char *message, unsigned char *padded_message, size_t length) {
    size_t padded_length = ((length / BLOCK_SIZE) + 1) * BLOCK_SIZE;
    memcpy(padded_message, message, length);
    for (size_t i = length; i < padded_length; i++) {
        padded_message[i] = padded_length - length; // Padding with the length of the padding
    }
    return padded_length;
}

// Function to display hexadecimal representation
void print_hex(unsigned char *data, size_t length) {
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    // Seed for random number generator
    srand(time(NULL));

    // Key and message initialization
    unsigned char key[KEY_SIZE];
    generate_random_key(key);

    char message[MAX_MESSAGE_SIZE];
    printf("Enter the message to encrypt: ");
    fgets(message, MAX_MESSAGE_SIZE, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character
    size_t message_length = strlen(message);

    // Padded message buffer
    size_t padded_length = pad_message((unsigned char *)message, (unsigned char *)malloc(BLOCK_SIZE + message_length), message_length);
    unsigned char *padded_message = (unsigned char*) malloc(padded_length);
    pad_message((unsigned char *)message, padded_message, message_length);

    // Encrypted message buffer
    unsigned char *encrypted_message = (unsigned char *) malloc(padded_length);
    xor_encrypt_decrypt(padded_message, encrypted_message, key, padded_length);

    // Outputs
    printf("Original Message: %s\n", message);
    printf("Key: ");
    print_hex(key, KEY_SIZE);
    printf("Encrypted Message (Hex): ");
    print_hex(encrypted_message, padded_length);

    // Decrypted message buffer
    unsigned char *decrypted_message = (unsigned char *) malloc(padded_length);
    xor_encrypt_decrypt(encrypted_message, decrypted_message, key, padded_length);

    // Unpad the decrypted message
    size_t original_length = padded_length - decrypted_message[padded_length - 1];
    printf("Decrypted Message: ");
    fwrite(decrypted_message, 1, original_length, stdout);
    printf("\n");

    // Free allocated memory
    free(padded_message);
    free(encrypted_message);
    free(decrypted_message);

    return 0;
}