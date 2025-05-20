//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define KEY "mysecretkey"
#define BLOCK_SIZE 128

void encrypt(char *plaintext, char *ciphertext);
void decrypt(char *ciphertext, char *plaintext);
void get_key(char *key);

int main()
{
    char plaintext[BLOCK_SIZE];
    char ciphertext[BLOCK_SIZE];
    char decrypted[BLOCK_SIZE];

    // Get the encryption key
    char key[BLOCK_SIZE];
    get_key(key);

    // Get user input for plaintext
    printf("Enter a string to encrypt: ");
    fgets(plaintext, BLOCK_SIZE, stdin);

    // Encrypt the plaintext
    encrypt(plaintext, ciphertext);
    printf("Encrypted text: %s\n", ciphertext);

    // Decrypt the ciphertext
    decrypt(ciphertext, decrypted);
    printf("Decrypted text: %s\n", decrypted);

    return 0;
}

void encrypt(char *plaintext, char *ciphertext)
{
    int i;
    char key[BLOCK_SIZE];
    strcpy(key, KEY);

    // Add key to plaintext
    strcat(plaintext, key);

    // Replace each character with its ASCII value XORed with corresponding key character
    for (i = 0; i < strlen(plaintext); i++)
    {
        ciphertext[i] = plaintext[i] ^ key[i % strlen(key)];
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *plaintext)
{
    int i;
    char key[BLOCK_SIZE];
    strcpy(key, KEY);

    // Replace each character with its ASCII value XORed with corresponding key character
    for (i = 0; i < strlen(ciphertext); i++)
    {
        plaintext[i] = ciphertext[i] ^ key[i % strlen(key)];
    }
    plaintext[i] = '\0';

    // Remove key from plaintext
    int key_length = strlen(key);
    int index = strlen(plaintext) - key_length;
    while (plaintext[index] != '\0')
    {
        plaintext[index] = '\0';
        index++;
    }
}

void get_key(char *key)
{
    printf("Enter a key (must be at least %d characters long): ", BLOCK_SIZE);
    fgets(key, BLOCK_SIZE, stdin);

    // Remove newline character from key if present
    if (key[strlen(key) - 1] == '\n')
    {
        key[strlen(key) - 1] = '\0';
    }

    // Check if key is long enough
    while (strlen(key) < BLOCK_SIZE)
    {
        printf("Key must be at least %d characters long. Enter key again: ", BLOCK_SIZE);
        fgets(key, BLOCK_SIZE, stdin);

        // Remove newline character from key if present
        if (key[strlen(key) - 1] == '\n')
        {
            key[strlen(key) - 1] = '\0';
        }
    }
}