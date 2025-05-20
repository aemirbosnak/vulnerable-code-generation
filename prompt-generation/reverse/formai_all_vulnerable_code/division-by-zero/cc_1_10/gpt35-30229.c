//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Function declarations */
void encrypt(char* message, char* key);
void decrypt(char* message, char* key);

int main()
{
    char message[100];
    char key[100];

    printf("Enter message to encrypt: ");
    fgets(message, sizeof(message), stdin);

    printf("Enter key: ");
    fgets(key, sizeof(key), stdin);

    /* Remove newline character from the end of the input */
    message[strcspn(message, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    encrypt(message, key);
    printf("Encrypted message: %s\n", message);

    decrypt(message, key);
    printf("Decrypted message: %s\n", message);

    return 0;
}

void encrypt(char* message, char* key)
{
    size_t message_len = strlen(message);
    size_t key_len = strlen(key);

    /* Use the message length as the seed for the random number generator */
    srand(message_len);

    for (size_t i = 0; i < message_len; i++) {
        /* Generate a random number between 0 and 255 */
        uint8_t random = rand() % 256;

        /* XOR the message character with the random number */
        message[i] ^= random;

        /* XOR the key character with the random number */
        key[i % key_len] ^= random;
    }
}

void decrypt(char* message, char* key)
{
    size_t message_len = strlen(message);
    size_t key_len = strlen(key);

    /* Use the message length as the seed for the random number generator */
    srand(message_len);

    for (size_t i = 0; i < message_len; i++) {
        /* Generate a random number between 0 and 255 */
        uint8_t random = rand() % 256;

        /* XOR the key character with the random number */
        key[i % key_len] ^= random;

        /* XOR the message character with the same random number */
        message[i] ^= random;
    }
}