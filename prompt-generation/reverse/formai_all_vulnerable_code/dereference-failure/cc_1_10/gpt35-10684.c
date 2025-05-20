//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

#define AES_KEY_LEN 128
#define IV_LEN 16

unsigned char key[AES_KEY_LEN/8]; 
unsigned char iv[IV_LEN];

void generate_key_iv()
{
    FILE* urandom = fopen("/dev/urandom", "r");
    fread(key, AES_KEY_LEN/8, 1, urandom);
    fread(iv, IV_LEN, 1, urandom);
    fclose(urandom);
}

void encrypt_decrypt(AES_KEY *key, int enc, const unsigned char *in, unsigned char *out, size_t length)
{
    AES_set_encrypt_key(key, AES_KEY_LEN, iv);
    if (enc)
        AES_cbc_encrypt(in, out, length, key, iv, AES_ENCRYPT);
    else
        AES_cbc_encrypt(in, out, length, key, iv, AES_DECRYPT);
}

int main(int argc, char **argv)
{
    generate_key_iv();
    AES_KEY aes_key;
    AES_set_encrypt_key(key, AES_KEY_LEN, &aes_key);

    // Encrypt string
    char plain[] = "Hello, world!";
    int len = strlen(plain) + 1;
    int padded_len = len + AES_BLOCK_SIZE - (len % AES_BLOCK_SIZE);
    unsigned char *cipher = malloc(padded_len);
    memset(cipher, 0, padded_len);
    encrypt_decrypt(&aes_key, 1, plain, cipher, padded_len);

    // Decrypt string
    char *plain2 = malloc(padded_len);
    memset(plain2, 0, padded_len);
    encrypt_decrypt(&aes_key, 0, cipher, plain2, padded_len);

    printf("Original: %s\nEncrypted: %s\nDecrypted: %s\n", plain, cipher, plain2);

    free(plain2);
    free(cipher);
    return 0;
}