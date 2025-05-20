//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    // Key and plaintext inputs
    unsigned char *key = (unsigned char *)"0123456789abcdef";
    unsigned char *input = (unsigned char *)"This is a secret message!";

    // Calculate the length of input string and allocate space for output
    size_t input_len = strlen((const char *)input) + 1;
    size_t output_len = 0;

    // Initialize the AES encryption context
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, 128, &enc_key) < 0)
    {
        perror("Error initializing AES encryption context: ");
        exit(1);
    }

    // Allocate space for the output buffer
    unsigned char *output = (unsigned char *)malloc(input_len * sizeof(unsigned char));

    // Encrypt the input string
    AES_encrypt(input, output, &enc_key);

    // Print the encrypted output
    printf("Encrypted output: ");
    for (int i = 0; i < input_len; i++)
        printf("%02x", output[i]);
    printf("\n");

    // Initialize the AES decryption context
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, 128, &dec_key) < 0)
    {
        perror("Error initializing AES decryption context: ");
        exit(1);
    }

    // Allocate space for the decrypted output
    unsigned char *decrypted_output = (unsigned char *)malloc(input_len * sizeof(unsigned char));

    // Decrypt the encrypted message
    AES_decrypt(output, decrypted_output, &dec_key);

    // Print the decrypted output
    printf("Decrypted output: %s\n", (char *)decrypted_output);

    // Free the allocated memory
    free(output);
    free(decrypted_output);

    return 0;
}