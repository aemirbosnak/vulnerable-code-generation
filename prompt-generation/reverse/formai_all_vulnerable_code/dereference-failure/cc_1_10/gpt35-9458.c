//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/evp.h>

/* Function to generate random bytes for key and IV */
void gen_random_bytes(unsigned char *bytes, int len){
    FILE *fp;
    fp = fopen("/dev/urandom", "rb");
    fread(bytes, len, 1, fp);
    fclose(fp);
}

int main(){
    /* Initialize OpenSSL library */
    OpenSSL_add_all_algorithms();

    /* Generate random key and IV */
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    gen_random_bytes(key, EVP_MAX_KEY_LENGTH);
    gen_random_bytes(iv, EVP_MAX_IV_LENGTH);

    /* Initialize encryption context */
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Message to encrypt */
    char *plaintext = "This is a sample message to encrypt.";

    /* Get the length of the plaintext */
    int plaintext_len = strlen(plaintext);

    /* Determine the size of the output buffer */
    int ciphertext_len = plaintext_len + EVP_CIPHER_CTX_block_size(ctx);

    /* Allocate memory for output buffer */
    unsigned char *ciphertext = (unsigned char*) malloc(ciphertext_len);

    /* Encrypt the plaintext */
    int len;
    EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char*) plaintext, plaintext_len);

    /* Finalize the encryption */
    EVP_EncryptFinal_ex(ctx, ciphertext + len, &len);
    ciphertext_len += len;

    /* Print the encrypted message */
    printf("Encrypted message: ");
    for(int i=0; i<ciphertext_len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    /* Initialize decryption context */
    EVP_CIPHER_CTX_init(ctx);
    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv);

    /* Determine the size of the output buffer */
    int decrypted_len = ciphertext_len + EVP_CIPHER_CTX_block_size(ctx);

    /* Allocate memory for output buffer */
    unsigned char *decrypted = (unsigned char*) malloc(decrypted_len);

    /* Decrypt the ciphertext */
    EVP_DecryptUpdate(ctx, decrypted, &len, ciphertext, ciphertext_len);

    /* Finalize the decryption */
    EVP_DecryptFinal_ex(ctx, decrypted + len, &len);
    decrypted_len += len;

    /* Print the decrypted message */
    printf("Decrypted message: %s\n", decrypted);

    /* Clean up */
    EVP_CIPHER_CTX_cleanup(ctx);
    free(ciphertext);
    free(decrypted);

    return 0;
}