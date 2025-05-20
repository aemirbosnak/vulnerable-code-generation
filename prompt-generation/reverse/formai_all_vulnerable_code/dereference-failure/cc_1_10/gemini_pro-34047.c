//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the encryption key
#define KEY "super_secret_key"

// Define the number of rounds (higher rounds mean stronger encryption)
#define ROUNDS 10

// Function to encrypt a single byte
unsigned char encrypt_byte(unsigned char byte) {
    // XOR the byte with the key
    byte ^= KEY[0];

    // Rotate the byte left by the number of rounds
    for (int i = 0; i < ROUNDS; i++) {
        byte = (byte << 1) | (byte >> 7);
    }

    // Return the encrypted byte
    return byte;
}

// Function to encrypt a string
char *encrypt_string(char *string) {
    // Allocate memory for the encrypted string
    char *encrypted_string = malloc(strlen(string) + 1);

    // Encrypt each byte of the string
    for (int i = 0; i < strlen(string); i++) {
        encrypted_string[i] = encrypt_byte(string[i]);
    }

    // Add the null terminator
    encrypted_string[strlen(string)] = '\0';

    // Return the encrypted string
    return encrypted_string;
}

// Function to decrypt a single byte
unsigned char decrypt_byte(unsigned char byte) {
    // Rotate the byte right by the number of rounds
    for (int i = 0; i < ROUNDS; i++) {
        byte = (byte >> 1) | (byte << 7);
    }

    // XOR the byte with the key
    byte ^= KEY[0];

    // Return the decrypted byte
    return byte;
}

// Function to decrypt a string
char *decrypt_string(char *string) {
    // Allocate memory for the decrypted string
    char *decrypted_string = malloc(strlen(string) + 1);

    // Decrypt each byte of the string
    for (int i = 0; i < strlen(string); i++) {
        decrypted_string[i] = decrypt_byte(string[i]);
    }

    // Add the null terminator
    decrypted_string[strlen(string)] = '\0';

    // Return the decrypted string
    return decrypted_string;
}

// Main function
int main() {
    // Get the string to be encrypted
    char *string = "Hello, world!";

    // Encrypt the string
    char *encrypted_string = encrypt_string(string);

    // Print the encrypted string
    printf("Encrypted string: %s\n", encrypted_string);

    // Decrypt the string
    char *decrypted_string = decrypt_string(encrypted_string);

    // Print the decrypted string
    printf("Decrypted string: %s\n", decrypted_string);

    // Free the memory allocated for the encrypted and decrypted strings
    free(encrypted_string);
    free(decrypted_string);

    return 0;
}