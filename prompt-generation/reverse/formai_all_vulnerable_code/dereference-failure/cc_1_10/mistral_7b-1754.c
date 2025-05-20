//MISTRAL-7B DATASET v1.0 Category: Encryption ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define KEY_SIZE 10
#define MAX_PLAIN_TEXT_SIZE 100
#define MAX_CIPHER_TEXT_SIZE 100

// Function to encrypt plain text using Caesar Cipher
char* encrypt(char* plain_text, int key) {
    int i;
    char* cipher_text = (char*)malloc(strlen(plain_text) + 1);

    for (i = 0; plain_text[i] != '\0'; i++) {
        if (plain_text[i] >= 'a' && plain_text[i] <= 'z') {
            cipher_text[i] = ((plain_text[i] - 'a' + key) % 26 + 'a');
        } else if (plain_text[i] >= 'A' && plain_text[i] <= 'Z') {
            cipher_text[i] = ((plain_text[i] - 'A' + key) % 26 + 'A');
        } else {
            cipher_text[i] = plain_text[i];
        }
    }

    cipher_text[strlen(plain_text)] = '\0';
    return cipher_text;
}

// Function to decrypt cipher text using Caesar Cipher
char* decrypt(char* cipher_text, int key) {
    int i;
    char* plain_text = (char*)malloc(strlen(cipher_text) + 1);

    for (i = 0; cipher_text[i] != '\0'; i++) {
        if (cipher_text[i] >= 'a' && cipher_text[i] <= 'z') {
            plain_text[i] = ((cipher_text[i] - 'a' - key + 26) % 26 + 'a');
        } else if (cipher_text[i] >= 'A' && cipher_text[i] <= 'Z') {
            plain_text[i] = ((cipher_text[i] - 'A' - key + 26) % 26 + 'A');
        } else {
            plain_text[i] = cipher_text[i];
        }
    }

    plain_text[strlen(cipher_text)] = '\0';
    return plain_text;
}

int main() {
    int key, i;
    char plain_text[MAX_PLAIN_TEXT_SIZE], cipher_text[MAX_CIPHER_TEXT_SIZE];

    // Generate random key
    srand(time(NULL));
    key = rand() % KEY_SIZE;

    printf("Enter plain text: ");
    scanf("%s", plain_text);

    // Encrypt plain text using Caesar Cipher
    char* encrypted_text = encrypt(plain_text, key);
    printf("Encrypted text: %s\n", encrypted_text);

    // Decrypt encrypted text using Caesar Cipher
    char* decrypted_text = decrypt(encrypted_text, key);
    printf("Decrypted text: %s\n", decrypted_text);

    // Free memory
    free(encrypted_text);
    free(decrypted_text);

    return 0;
}