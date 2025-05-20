//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <openssl/evp.h>

// generate a random key with specified length
void generate_key(unsigned char *key, int keylen) 
{
    FILE* fp = fopen("/dev/urandom", "r");
    fread(key, 1, keylen, fp);
    fclose(fp);
}

// encrypt a string using symmetric key cryptography
int encrypt_string(unsigned char *input, int input_len, unsigned char *key,
                   unsigned char *iv, unsigned char *output) 
{
    EVP_CIPHER_CTX *ctx;
    int len, encrypted_len;

    // create and initialize the context
    ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // encrypt the input string
    EVP_EncryptUpdate(ctx, output, &len, input, input_len);
    encrypted_len = len;

    // finalize the encryption process
    EVP_EncryptFinal_ex(ctx, output + len, &len);
    encrypted_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return encrypted_len;
}

// decrypt a string using symmetric key cryptography
int decrypt_string(unsigned char *input, int input_len, unsigned char *key,
                   unsigned char *iv, unsigned char *output) 
{
    EVP_CIPHER_CTX *ctx;
    int len, decrypted_len;

    // create and initialize the context
    ctx = EVP_CIPHER_CTX_new();
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    // decrypt the input string
    EVP_DecryptUpdate(ctx, output, &len, input, input_len);
    decrypted_len = len;

    // finalize the decryption process
    EVP_DecryptFinal_ex(ctx, output + len, &len);
    decrypted_len += len;

    EVP_CIPHER_CTX_free(ctx);

    return decrypted_len;
}

int main() 
{
    // generate a 256-bit (32 byte) random key
    unsigned char key[32];
    generate_key(key, sizeof(key));

    // create an initialization vector with a fixed value (for simplicity)
    unsigned char iv[] = {0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88,
                          0x99, 0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x00};

    char plaintext[] = "Hello, world!";
    int plaintext_len = strlen(plaintext);

    // allocate space for the encrypted and decrypted strings
    unsigned char *encrypted = malloc(plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc()));
    unsigned char *decrypted = malloc(plaintext_len + EVP_CIPHER_block_size(EVP_aes_256_cbc()));

    // encrypt the plaintext string and print the results
    int encrypted_len = encrypt_string(plaintext, plaintext_len, key, iv, encrypted);
    printf("Encrypted: ");
    for (int i=0; i<encrypted_len; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    // decrypt the encrypted string and print the results
    int decrypted_len = decrypt_string(encrypted, encrypted_len, key, iv, decrypted);
    printf("Decrypted: %s\n", decrypted);

    free(encrypted);
    free(decrypted);

    return 0;
}