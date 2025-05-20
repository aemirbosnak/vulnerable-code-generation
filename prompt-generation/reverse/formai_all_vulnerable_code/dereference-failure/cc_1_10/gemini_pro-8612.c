//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Encryption function
char *encrypt(char *plaintext, char *key)
{
    int keyLen = strlen(key);
    char *ciphertext = malloc(strlen(plaintext) + 1);
    int i, j;
    for (i = 0, j = 0; plaintext[i] != '\0'; i++, j++)
    {
        ciphertext[i] = plaintext[i] ^ key[j % keyLen];
    }
    ciphertext[i] = '\0';
    return ciphertext;
}

// Decryption function
char *decrypt(char *ciphertext, char *key)
{
    int keyLen = strlen(key);
    char *plaintext = malloc(strlen(ciphertext) + 1);
    int i, j;
    for (i = 0, j = 0; ciphertext[i] != '\0'; i++, j++)
    {
        plaintext[i] = ciphertext[i] ^ key[j % keyLen];
    }
    plaintext[i] = '\0';
    return plaintext;
}

int main()
{
    // Your secret message
    char plaintext[] = "Encrypt this message!";

    // Your encryption key
    char key[] = "supersecretkey";

    // Encrypt the message
    char *ciphertext = encrypt(plaintext, key);

    // Print the encrypted message
    printf("Encrypted message: %s\n", ciphertext);

    // Decrypt the message
    char *decryptedText = decrypt(ciphertext, key);

    // Print the decrypted message
    printf("Decrypted message: %s\n", decryptedText);

    // Free the allocated memory
    free(ciphertext);
    free(decryptedText);

    return 0;
}