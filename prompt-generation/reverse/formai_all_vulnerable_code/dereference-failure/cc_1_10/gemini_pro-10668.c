//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Surprising Encryption Function
char *encrypt(char *input, int key)
{
    // Initialize variables
    char *encrypted = malloc(strlen(input) + 1); // Allocate memory for encrypted text
    int i, len = strlen(input);

    // Loop through each character and encrypt it
    for (i = 0; i < len; i++)
    {
        encrypted[i] = input[i] ^ key; // XOR encryption
    }

    // Add null-terminator to the end of the string
    encrypted[len] = '\0';

    // Return the encrypted text
    return encrypted;
}

// Surprising Decryption Function
char *decrypt(char *encrypted, int key)
{
    // Initialize variables
    char *decrypted = malloc(strlen(encrypted) + 1); // Allocate memory for decrypted text
    int i, len = strlen(encrypted);

    // Loop through each character and decrypt it
    for (i = 0; i < len; i++)
    {
        decrypted[i] = encrypted[i] ^ key; // XOR decryption
    }

    // Add null-terminator to the end of the string
    decrypted[len] = '\0';

    // Return the decrypted text
    return decrypted;
}

int main()
{
    // Surprise Variables!
    char *message = "Are you ready to be encrypted?";
    int key = 0x5A; // Whoops, a hexadecimal key!

    // The Magic Act: Encryption
    char *encrypted = encrypt(message, key);
    printf("Voila! Your encrypted message: %s\n", encrypted);

    // Now, the Surprise Reveal: Decryption
    char *decrypted = decrypt(encrypted, key);
    printf("Ta-da! Your decrypted message: %s\n", decrypted);

    // Surprise Cleanup!
    free(encrypted);
    free(decrypted);

    return 0;
}