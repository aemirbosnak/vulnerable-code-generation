//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

int main()
{
    // Message to encrypt
    char message[] = "This is a secret message.";

    // Initialize variables
    EVP_CIPHER_CTX *ctx;
    int message_len = strlen(message);
    int cipher_len, decrypted_len;
    unsigned char *cipher_text, *decrypted_text;

    // Initialize encryption key and IV
    unsigned char *key = (unsigned char *)"01234567890123456789012345678901";
    unsigned char *iv = (unsigned char *)"0123456789012345";

    // Allocate memory for cipher text and decrypted text
    cipher_text = malloc(message_len + EVP_MAX_BLOCK_LENGTH);
    decrypted_text = malloc(message_len + EVP_MAX_BLOCK_LENGTH);

    // Create and initialize the context for encryption
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // Encrypt the message
    EVP_EncryptUpdate(ctx, cipher_text, &cipher_len, (unsigned char *)message, message_len);
    EVP_EncryptFinal_ex(ctx, cipher_text + cipher_len, &cipher_len);

    // Print the encrypted message
    printf("Encrypted message: ");
    for (int i = 0; i < cipher_len; i++) {
        printf("%x", cipher_text[i]);
    }

    // Reset the context for decryption
    EVP_CIPHER_CTX_reset(ctx);

    // Decrypt the message
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);
    EVP_DecryptUpdate(ctx, decrypted_text, &decrypted_len, cipher_text, cipher_len);
    EVP_DecryptFinal_ex(ctx, decrypted_text + decrypted_len, &decrypted_len);

    // Print the decrypted message
    printf("\nDecrypted message: %s", decrypted_text);

    // Free memory and clean up the context
    free(cipher_text);
    free(decrypted_text);
    EVP_CIPHER_CTX_cleanup(ctx);

    return 0;
}