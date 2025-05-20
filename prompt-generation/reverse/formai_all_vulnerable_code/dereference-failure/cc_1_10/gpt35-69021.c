//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/*** FUNCTION DECLARATIONS ***/
void encrypt(char *message, char *key, uint8_t key_length);
void decrypt(char *message, char *key, uint8_t key_length);

/*** MAIN FUNCTION ***/
int main()
{
    char message[100] = "Hello, World!";
    char key[20] = "mysecretkey";
    uint8_t key_length = strlen(key);

    printf("Message: %s\nKey: %s\n", message, key);

    /* Encryption */
    encrypt(message, key, key_length);
    printf("Encrypted message: %s\n", message);

    /* Decryption */
    decrypt(message, key, key_length);
    printf("Decrypted message: %s\n", message);

    return 0;
}

/*** FUNCTION DEFINITIONS ***/
void encrypt(char *message, char *key, uint8_t key_length)
{
    uint8_t i, j = 0;
    uint8_t message_length = strlen(message);
    char *encrypted_message = (char *) malloc(message_length * sizeof(char));

    for (i = 0; i < message_length; i++)
    {
        encrypted_message[i] = message[i] ^ key[j];
        j = (j + 1) % key_length;
    }

    /* Copy encrypted message back to original message */
    for (i = 0; i < message_length; i++)
    {
        message[i] = encrypted_message[i];
    }
    free(encrypted_message);
}

void decrypt(char *message, char *key, uint8_t key_length)
{
    encrypt(message, key, key_length);
}