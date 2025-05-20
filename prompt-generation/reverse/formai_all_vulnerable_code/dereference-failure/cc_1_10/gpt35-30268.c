//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Linus Torvalds style implementation of Cryptography
// - "Bad Crypto for Fun and Profit"
//
// This is a simple implementation of a XOR cipher, using the
// current time as a pseudo-random seed. It's not a cryptographically
// secure algorithm by any means, but it's good enough for "bad crypto".
//
// To encrypt a message, XOR each character of the plaintext with
// a character from the randomly generated key. To decrypt the
// ciphertext, XOR each character with the same key character.
//
// Usage: ./badcrypto plaintext
//
// Example:
// $ ./badcrypto "Hello World"
// Key: 742648
// Encrypted: %&'&%!*,+))%
// Decrypted: Hello World

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s plaintext\n", argv[0]);
        return 1;
    }

    // Generate a seed for the pseudo-random number generator
    time_t current_time;
    time(&current_time);
    srand(current_time);

    // Generate a random key
    char key[strlen(argv[1])];
    printf("Key: ");
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        key[i] = rand() % 128;
        printf("%d", (int)key[i]);
    }
    printf("\n");

    // Encrypt the plaintext
    char ciphertext[strlen(argv[1])];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        ciphertext[i] = argv[1][i] ^ key[i];
    }
    printf("Encrypted: %s\n", ciphertext);

    // Decrypt the ciphertext
    char decrypted_plaintext[strlen(argv[1])];
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        decrypted_plaintext[i] = ciphertext[i] ^ key[i];
    }
    printf("Decrypted: %s\n", decrypted_plaintext);

    return 0;
}