//GEMINI-pro DATASET v1.0 Category: Modern Encryption ; Style: complex
#include <openssl/evp.h>
#include <openssl/err.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    EVP_CIPHER_CTX *ctx;
    int keylen = 256;
    unsigned char *key = "This is a 256 bit key";
    unsigned char *iv = "This is a 16 byte IV";
    unsigned char *input = "Hello World!";
    int inputlen = strlen(input);
    unsigned char *output;
    int outputlen;
    int ciphertextlen;
    int rc;

    /* Initialize the library */
    OpenSSL_add_all_algorithms();

    /* Create a new cipher context */
    ctx = EVP_CIPHER_CTX_new();

    /* Initialize the cipher context for encryption */
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    output = malloc(inputlen + EVP_CIPHER_CTX_block_size(ctx));
    if (output == NULL)
    {
        fprintf(stderr, "malloc() failed\n");
        return 1;
    }

    /* Encrypt the plaintext */
    rc = EVP_EncryptUpdate(ctx, output, &outputlen, input, inputlen);
    if (rc != 1)
    {
        fprintf(stderr, "EVP_EncryptUpdate() failed\n");
        return 1;
    }

    /* Get the ciphertext length */
    ciphertextlen = outputlen;

    /* Finalize the encryption */
    rc = EVP_EncryptFinal_ex(ctx, output + ciphertextlen, &outputlen);
    if (rc != 1)
    {
        fprintf(stderr, "EVP_EncryptFinal_ex() failed\n");
        return 1;
    }

    ciphertextlen += outputlen;

    /* Clean up the cipher context */
    EVP_CIPHER_CTX_cleanup(ctx);

    /* Print the ciphertext */
    printf("Ciphertext: ");
    for (int i = 0; i < ciphertextlen; i++)
    {
        printf("%02x", output[i]);
    }
    printf("\n");

    /* Free the output buffer */
    free(output);

    /* Clean up the library */
    EVP_cleanup();

    return 0;
}