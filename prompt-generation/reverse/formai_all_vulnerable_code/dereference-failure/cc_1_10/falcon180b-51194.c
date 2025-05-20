//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_KEY_SIZE 64
#define MAX_DATA_SIZE 1024

// Function to generate a random key
void generate_key(char* key, int key_size) {
    const char alphanum[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i < key_size; i++) {
        key[i] = alphanum[rand() % strlen(alphanum)];
    }
    key[key_size] = '\0';
}

// Function to encrypt data using the key
void encrypt(char* data, char* key, int key_size) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % key_size];
    }
}

// Function to decrypt data using the key
void decrypt(char* data, char* key, int key_size) {
    for (int i = 0; i < strlen(data); i++) {
        data[i] ^= key[i % key_size];
    }
}

int main() {
    char input_data[MAX_DATA_SIZE];
    char key[MAX_KEY_SIZE];
    int key_size = MAX_KEY_SIZE;

    // Prompt user for data to encrypt
    printf("Enter data to encrypt: ");
    fgets(input_data, MAX_DATA_SIZE, stdin);

    // Prompt user for key size
    printf("Enter key size (1 to %d): ", MAX_KEY_SIZE - 1);
    scanf("%d", &key_size);

    // Generate random key
    generate_key(key, key_size);

    // Encrypt data
    encrypt(input_data, key, key_size);

    // Print encrypted data
    printf("Encrypted data: %s\n", input_data);

    // Decrypt data
    decrypt(input_data, key, key_size);

    // Print decrypted data
    printf("Decrypted data: %s\n", input_data);

    return 0;
}