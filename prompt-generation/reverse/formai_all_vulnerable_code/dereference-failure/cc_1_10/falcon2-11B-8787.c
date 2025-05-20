//Falcon2-11B DATASET v1.0 Category: File Encyptor ; Style: unmistakable
#include<stdio.h>
#include<string.h>
#include<openssl/evp.h>

#define BLOCK_SIZE 16

void encryptFile(char *filename, char *passphrase) {
    FILE *fp;
    EVP_CIPHER_CTX *ctx;
    unsigned char plaintext[BLOCK_SIZE], ciphertext[BLOCK_SIZE];
    unsigned char *pt, *ct;
    int n;

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
        printf("EVP_CIPHER_CTX_new() failed\n");
        return;
    }

    if (1!= EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, passphrase, NULL)) {
        printf("EVP_EncryptInit_ex() failed\n");
        return;
    }

    while ((n = fread(plaintext, 1, BLOCK_SIZE, fp)) > 0) {
        pt = plaintext;
        if (1!= EVP_EncryptUpdate(ctx, ciphertext, &n, pt, n)) {
            printf("EVP_EncryptUpdate() failed\n");
            return;
        }
        fwrite(ciphertext, 1, n, stdout);
    }

    if (1!= EVP_EncryptFinal_ex(ctx, ciphertext, &n)) {
        printf("EVP_EncryptFinal_ex() failed\n");
        return;
    }
    printf("File %s has been encrypted successfully\n", filename);

    fclose(fp);
    EVP_CIPHER_CTX_free(ctx);
}

void decryptFile(char *filename, char *passphrase) {
    FILE *fp;
    EVP_CIPHER_CTX *ctx;
    unsigned char plaintext[BLOCK_SIZE], ciphertext[BLOCK_SIZE];
    unsigned char *pt, *ct;
    int n;

    if ((fp = fopen(filename, "rb")) == NULL) {
        printf("Could not open file %s\n", filename);
        return;
    }

    if ((ctx = EVP_CIPHER_CTX_new()) == NULL) {
        printf("EVP_CIPHER_CTX_new() failed\n");
        return;
    }

    if (1!= EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, passphrase, NULL)) {
        printf("EVP_DecryptInit_ex() failed\n");
        return;
    }

    while ((n = fread(ciphertext, 1, BLOCK_SIZE, fp)) > 0) {
        ct = ciphertext;
        if (1!= EVP_DecryptUpdate(ctx, plaintext, &n, ct, n)) {
            printf("EVP_DecryptUpdate() failed\n");
            return;
        }
        fwrite(plaintext, 1, n, stdout);
    }

    if (1!= EVP_DecryptFinal_ex(ctx, plaintext, &n)) {
        printf("EVP_DecryptFinal_ex() failed\n");
        return;
    }
    printf("File %s has been decrypted successfully\n", filename);

    fclose(fp);
    EVP_CIPHER_CTX_free(ctx);
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <filename> <passphrase> <action> (encrypt/decrypt)\n", argv[0]);
        return 1;
    }

    char action = argv[3][0];
    if (action!= 'e' && action!= 'd') {
        printf("Invalid action: %c\n", action);
        return 1;
    }

    encryptFile(argv[1], argv[2]);
    return 0;
}