//Falcon-180B DATASET v1.0 Category: Modern Encryption ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX_KEY_SIZE 32
#define MAX_PLAINTEXT_SIZE 1000

// Function to generate a random key
void generate_key(char* key, int key_size) {
    srand(time(NULL));
    for (int i = 0; i < key_size; i++) {
        key[i] = rand() % 26 + 'a';
    }
    key[key_size] = '\0';
}

// Function to encrypt plaintext using a key
void encrypt(char* plaintext, char* key, char* ciphertext) {
    for (int i = 0; i < strlen(plaintext); i++) {
        if (isalpha(plaintext[i])) {
            ciphertext[i] = (char) (((int) plaintext[i] - (int) 'a' + (int) key[i % strlen(key)]) % 26 + 'a');
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    ciphertext[strlen(plaintext)] = '\0';
}

// Function to decrypt ciphertext using a key
void decrypt(char* ciphertext, char* key, char* plaintext) {
    for (int i = 0; i < strlen(ciphertext); i++) {
        if (isalpha(ciphertext[i])) {
            plaintext[i] = (char) (((int) ciphertext[i] - (int) 'a' - (int) key[i % strlen(key)]) % 26 + 'a');
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    plaintext[strlen(ciphertext)] = '\0';
}

int main() {
    char key[MAX_KEY_SIZE];
    char plaintext[MAX_PLAINTEXT_SIZE];
    char ciphertext[MAX_PLAINTEXT_SIZE];

    // Generate a random key
    generate_key(key, strlen(key));

    // Get plaintext from user
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_PLAINTEXT_SIZE, stdin);

    // Encrypt plaintext using key
    encrypt(plaintext, key, ciphertext);

    // Print ciphertext
    printf("Ciphertext: %s\n", ciphertext);

    // Decrypt ciphertext using key
    decrypt(ciphertext, key, plaintext);

    // Print decrypted plaintext
    printf("Decrypted plaintext: %s\n", plaintext);

    return 0;
}