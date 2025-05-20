//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

void handleErrors(void)
{
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *createRSAWithFilename(char *filename, int publicKey)
{
    RSA *rsa = NULL;
    FILE *fp = NULL;

    if (publicKey)
        fp = fopen(filename, "rb");
    else
        fp = fopen(filename, "rb");

    if (fp == NULL)
        return NULL;

    if (publicKey)
        rsa = PEM_read_RSA_PUBKEY(fp, &rsa, NULL, NULL);
    else
        rsa = PEM_read_RSAPrivateKey(fp, &rsa, NULL, NULL);

    fclose(fp);
    return rsa;
}

void generateKeys(const char *publicKeyFile, const char *privateKeyFile)
{
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    BIO *bpPublic = BIO_new_file(publicKeyFile, "w+");
    BIO *bpPrivate = BIO_new_file(privateKeyFile, "w+");

    if (PEM_write_bio_RSA_PUBKEY(bpPublic, rsa) != 1)
        handleErrors();

    if (PEM_write_bio_RSAPrivateKey(bpPrivate, rsa, NULL, NULL, 0, NULL, NULL) != 1)
        handleErrors();

    BIO_free_all(bpPublic);
    BIO_free_all(bpPrivate);
    RSA_free(rsa);
}

void encrypt(RSA *rsa, const char *message, unsigned char **encrypted)
{
    int encrypted_length;
    *encrypted = (unsigned char *)malloc(RSA_size(rsa));

    if ((*encrypted) == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    encrypted_length = RSA_public_encrypt(strlen(message) + 1, (unsigned char *)message, *encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (encrypted_length == -1)
        handleErrors();
}

void decrypt(RSA *rsa, unsigned char *encrypted, char *decrypted)
{
    int decrypted_length;
    
    decrypted_length = RSA_private_decrypt(RSA_size(rsa), encrypted, (unsigned char *)decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (decrypted_length == -1)
        handleErrors();

    decrypted[decrypted_length] = '\0'; // Null-terminate the decrypted string
}

int main()
{
    const char *publicKeyFile = "public.pem";
    const char *privateKeyFile = "private.pem";
    char message[] = "This is a secret message!";
    unsigned char *encrypted = NULL;
    char decrypted[256];

    // Generate the RSA Keys
    generateKeys(publicKeyFile, privateKeyFile);
    printf("RSA Keys generated successfully!\n");

    // Load public key
    RSA *rsaPublic = createRSAWithFilename((char *)publicKeyFile, 1);
    if (!rsaPublic)
    {
        fprintf(stderr, "Unable to load public key\n");
        exit(EXIT_FAILURE);
    }

    // Encrypt the message
    encrypt(rsaPublic, message, &encrypted);
    printf("Original message: %s\n", message);
    printf("Encrypted message: ");
    for (int i = 0; i < RSA_size(rsaPublic); i++)
    {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    // Load private key
    RSA *rsaPrivate = createRSAWithFilename((char *)privateKeyFile, 0);
    if (!rsaPrivate)
    {
        fprintf(stderr, "Unable to load private key\n");
        exit(EXIT_FAILURE);
    }

    // Decrypt the message
    decrypt(rsaPrivate, encrypted, decrypted);
    printf("Decrypted message: %s\n", decrypted);

    // Clean up
    free(encrypted);
    RSA_free(rsaPublic);
    RSA_free(rsaPrivate);

    return 0;
}