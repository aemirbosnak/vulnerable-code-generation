//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random key
void generate_key(char *key, int key_len) {
    srand(time(NULL));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < key_len; i++) {
        key[i] = charset[rand() % strlen(charset)];
    }
}

// Function to encrypt a message using the key
char *encrypt(char *message, char *key) {
    int len_message = strlen(message);
    int len_key = strlen(key);
    char *encrypted_message = (char *) malloc(len_message + 1);

    for (int i = 0; i < len_message; i++) {
        int key_index = i % len_key;
        encrypted_message[i] = (char) ((message[i] + key[key_index]) % 256);
    }
    encrypted_message[len_message] = '\0';
    return encrypted_message;
}

// Function to decrypt a message using the key
char *decrypt(char *encrypted_message, char *key) {
    int len_message = strlen(encrypted_message);
    int len_key = strlen(key);
    char *decrypted_message = (char *) malloc(len_message + 1);

    for (int i = 0; i < len_message; i++) {
        int key_index = i % len_key;
        decrypted_message[i] = (char) ((encrypted_message[i] - key[key_index] + 256) % 256);
    }
    decrypted_message[len_message] = '\0';
    return decrypted_message;
}

int main() {
    char message[] = "This is a message to encrypt!";
    int key_len = 16;
    char key[key_len + 1];
    char *encrypted_message, *decrypted_message;

    generate_key(key, key_len);
    printf("Generated Key: %s\n", key);

    encrypted_message = encrypt(message, key);
    printf("Encrypted Message: %s\n", encrypted_message);

    decrypted_message = decrypt(encrypted_message, key);
    printf("Decrypted Message: %s\n", decrypted_message);

    free(encrypted_message);
    free(decrypted_message);

    return 0;
}