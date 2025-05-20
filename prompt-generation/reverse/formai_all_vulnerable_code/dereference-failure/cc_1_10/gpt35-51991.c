//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>

void handleErrors(void)
{
    printf("An error occurred in the cipher operation.");
    exit(1);
}

int main(int argc, char *argv[])
{
    EVP_CIPHER_CTX *ctx;
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    unsigned char inbuf[1024];
    unsigned char outbuf[1024 + EVP_MAX_BLOCK_LENGTH];
    int inlen, outlen;
    const EVP_CIPHER *cipher;
    const EVP_MD *dgst;
    char *passphrase;
    int i;

    if (argc != 2)
    {
        printf("USAGE: %s <passphrase>\n", argv[0]);
        return 1;
    }

    OpenSSL_add_all_algorithms();
    passphrase = argv[1];
    cipher = EVP_get_cipherbyname("aes-256-cbc");

    if (!cipher)
    {
        printf("The provided cipher is not supported.");
        return 2;
    }

    dgst = EVP_get_digestbyname("md5");

    if (!dgst)
    {
        printf("The provided digest is not supported.");
        return 3;
    }

    if (strlen(passphrase) > EVP_MAX_KEY_LENGTH)
    {
        printf("The provided passphrase is too long.");
        return 4;
    }

    EVP_BytesToKey(cipher, dgst, NULL, (unsigned char *)passphrase,
                   strlen(passphrase), 1, key, iv);

    ctx = EVP_CIPHER_CTX_new();

    if (!ctx)
    {
        printf("An error occurred in the cipher context.");
        return 5;
    }

    if (!EVP_EncryptInit_ex(ctx, cipher, NULL, key, iv))
    {
        printf("An error occurred in the cipher initialization.");
        return 6;
    }

    while ((inlen = fread(inbuf, 1, 1024, stdin)) > 0)
    {
        if (!EVP_EncryptUpdate(ctx, outbuf, &outlen, inbuf, inlen))
        {
            handleErrors();
        }

        fwrite(outbuf, 1, outlen, stdout);
    }

    if (!EVP_EncryptFinal_ex(ctx, outbuf, &outlen))
    {
        handleErrors();
    }

    fwrite(outbuf, 1, outlen, stdout);

    EVP_CIPHER_CTX_free(ctx);

    OPENSSL_cleanse(key, sizeof(key));
    OPENSSL_cleanse(iv, sizeof(iv));
    OPENSSL_cleanse(inbuf, sizeof(inbuf));
    OPENSSL_cleanse(outbuf, sizeof(outbuf));

    return 0;
}