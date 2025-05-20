//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

// AES-like simple block cipher
void encrypt_block(uint8_t *block, uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i]; // Simple XOR encryption
    }
}

void decrypt_block(uint8_t *block, uint8_t *key) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        block[i] ^= key[i]; // Simple XOR decryption
    }
}

// Utility function to pad the plaintext to a multiple of BLOCK_SIZE
void pad_text(uint8_t *text, size_t *length) {
    size_t pad_length = BLOCK_SIZE - (*length % BLOCK_SIZE);
    for (size_t i = 0; i < pad_length; i++) {
        text[*length + i] = (uint8_t)pad_length;
    }
    *length += pad_length;
}

// Encrypt/Decrypt Function
void process_data(uint8_t *data, size_t data_length, uint8_t *key, int encrypt) {
    size_t padded_length = data_length;
    if (encrypt) {
        pad_text(data, &padded_length);
    }

    for (size_t i = 0; i < padded_length; i += BLOCK_SIZE) {
        if (encrypt) {
            encrypt_block(&data[i], key);
        } else {
            decrypt_block(&data[i], key);
        }
    }
}

void display_data(const char *label, uint8_t *data, size_t length) {
    printf("%s: ", label);
    for (size_t i = 0; i < length; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
}

int main() {
    // Manually initialized key
    uint8_t key[KEY_SIZE] = { 0x1A, 0x2B, 0x3C, 0x4D, 
                               0x5E, 0x6F, 0x7A, 0x8B,
                               0x9C, 0xAD, 0xBE, 0xCF,
                               0xD0, 0xE1, 0xF2, 0x03 };

    // Input data to encrypt
    const char *message = "This is a secret message.";
    size_t data_length = strlen(message);
    // Allocate memory for data and copy the message
    uint8_t *data = malloc(data_length + BLOCK_SIZE);
    memcpy(data, message, data_length);

    // Encrypt the data
    process_data(data, data_length, key, 1);
    display_data("Encrypted Message", data, data_length + BLOCK_SIZE - (data_length % BLOCK_SIZE));

    // Decrypt the data
    process_data(data, data_length, key, 0);
    display_data("Decrypted Message", data, data_length);

    // Ensure the null terminator is there for displaying the string
    data[data_length] = '\0'; 
    printf("Decrypted Text: %s\n", data);
    
    // Clean up
    free(data);
    
    return 0;
}