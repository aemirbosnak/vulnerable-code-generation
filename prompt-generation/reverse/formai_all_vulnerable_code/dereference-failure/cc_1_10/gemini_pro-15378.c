//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

int main()
{
    // Generate a 1024-bit RSA key pair.
    RSA *rsa = RSA_new();
    if (!RSA_generate_key_ex(rsa, 1024, 3, NULL))
    {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Export the public key in PEM format.
    BIO *bio = BIO_new(BIO_s_mem());
    if (!PEM_write_bio_RSA_PUBKEY(bio, rsa))
    {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }
    char *pem = NULL;
    long pem_len = BIO_get_mem_data(bio, &pem);
    BIO_free(bio);

    // Encrypt a message using the public key.
    char *message = "Hello, world!";
    int message_len = strlen(message);
    unsigned char *encrypted = malloc(RSA_size(rsa));
    if (!RSA_public_encrypt(message_len, (unsigned char *)message, encrypted, rsa, RSA_PKCS1_OAEP_PADDING))
    {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Decrypt the message using the private key.
    unsigned char *decrypted = malloc(RSA_size(rsa));
    if (!RSA_private_decrypt(RSA_size(rsa), encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING))
    {
        ERR_print_errors_fp(stderr);
        return EXIT_FAILURE;
    }

    // Print the decrypted message.
    printf("Decrypted message: %s\n", decrypted);

    // Free the memory.
    RSA_free(rsa);
    free(encrypted);
    free(decrypted);
    free(pem);

    return EXIT_SUCCESS;
}