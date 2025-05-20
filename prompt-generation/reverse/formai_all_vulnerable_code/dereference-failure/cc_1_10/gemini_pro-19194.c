//GEMINI-pro DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/bn.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

int main(int argc, char **argv)
{
    /* Check arguments */
    if (argc != 4)
    {
        fprintf(stderr, "Usage: %s <input file> <output file> <key file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    /* Read input file */
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        fprintf(stderr, "Error opening input file: %s\n", argv[1]);
        return EXIT_FAILURE;
    }
    char *plaintext = malloc(1024);
    size_t plaintext_len = fread(plaintext, 1, 1024, input);
    fclose(input);

    /* Load public key */
    FILE *key = fopen(argv[3], "r");
    if (key == NULL)
    {
        fprintf(stderr, "Error opening key file: %s\n", argv[3]);
        return EXIT_FAILURE;
    }
    RSA *rsa = PEM_read_RSA_PUBKEY(key, NULL, NULL, NULL);
    fclose(key);
    if (rsa == NULL)
    {
        fprintf(stderr, "Error loading public key: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    /* Encrypt plaintext */
    int encrypted_len = RSA_size(rsa);
    unsigned char *encrypted = malloc(encrypted_len);
    int result = RSA_public_encrypt(plaintext_len, (unsigned char *)plaintext, encrypted, rsa, RSA_PKCS1_PADDING);
    if (result == -1)
    {
        fprintf(stderr, "Error encrypting plaintext: %s\n", ERR_error_string(ERR_get_error(), NULL));
        return EXIT_FAILURE;
    }

    /* Write output file */
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fprintf(stderr, "Error opening output file: %s\n", argv[2]);
        return EXIT_FAILURE;
    }
    fwrite(encrypted, 1, encrypted_len, output);
    fclose(output);

    /* Cleanup */
    free(plaintext);
    free(encrypted);
    RSA_free(rsa);

    return EXIT_SUCCESS;
}