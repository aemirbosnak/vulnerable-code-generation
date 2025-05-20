//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encrypt a string
char *encrypt(char *plaintext, int key)
{
    int len = strlen(plaintext);
    char *ciphertext = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        ciphertext[i] = plaintext[i] + key;
    }
    ciphertext[len] = '\0';
    return ciphertext;
}

// Function to decrypt a string
char *decrypt(char *ciphertext, int key)
{
    int len = strlen(ciphertext);
    char *plaintext = malloc(len + 1);
    for (int i = 0; i < len; i++)
    {
        plaintext[i] = ciphertext[i] - key;
    }
    plaintext[len] = '\0';
    return plaintext;
}

int main()
{
    // Get the plaintext and key from the user.
    char plaintext[100];
    int key;
    printf("Enter the plaintext to encrypt: ");
    scanf("%s", plaintext);
    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    // Encrypt the plaintext using the given key.
    char *ciphertext = encrypt(plaintext, key);

    // Print the ciphertext.
    printf("Encrypted ciphertext: %s\n", ciphertext);

    // Decrypt the ciphertext using the same key.
    char *decryptedtext = decrypt(ciphertext, key);

    // Print the decrypted text.
    printf("Decrypted plaintext: %s\n", decryptedtext);

    return 0;
}