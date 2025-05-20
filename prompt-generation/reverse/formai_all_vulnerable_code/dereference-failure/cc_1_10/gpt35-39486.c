//FormAI DATASET v1.0 Category: Encryption ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16

// Function to encrypt the given message using the given key using XOR operation
void encrypt(char* message, char* key, char* encrypted_message) {
    int message_length = strlen(message);
    int key_length = strlen(key);

    for (int i=0; i<message_length; i++) {
        encrypted_message[i] = message[i] ^ key[i%key_length];
    }

    encrypted_message[message_length] += '\0';
}

// Function to decrypt the given message using the given key using XOR operation
void decrypt(char* encrypted_message, char* key, char* decrypted_message) {
    int message_length = strlen(encrypted_message);
    int key_length = strlen(key);

    for (int i=0; i<message_length; i++) {
        decrypted_message[i] = encrypted_message[i] ^ key[i%key_length];
    }

    decrypted_message[message_length] += '\0';
}

// Driver function
int main() {
    char* message = "This is an example message";
    char key[KEY_LENGTH] = "cryptionkey1234";
    char encrypted_message[strlen(message)];
    char decrypted_message[strlen(message)];

    // Encrypt the message using the key
    encrypt(message, key, encrypted_message);

    // Print the encrypted message
    printf("Encrypted Message: %s\n", encrypted_message);

    // Decrypt the encrypted message using the key
    decrypt(encrypted_message, key, decrypted_message);

    // Print the decrypted message
    printf("Decrypted Message: %s\n", decrypted_message);

    return 0;
}