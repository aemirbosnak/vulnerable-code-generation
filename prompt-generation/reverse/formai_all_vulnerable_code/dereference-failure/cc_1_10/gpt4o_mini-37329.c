//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>
#include <openssl/rand.h>

#define AES_BLOCK_SIZE 16

void handleErrors() {
    fprintf(stderr, "An error occurred\n");
    exit(1);
}

void generateKey(unsigned char *key) {
    if (!RAND_bytes(key, AES_BLOCK_SIZE)) {
        handleErrors();
    }
}

void generateIV(unsigned char *iv) {
    if (!RAND_bytes(iv, AES_BLOCK_SIZE)) {
        handleErrors();
    }
}

void aesEncrypt(const unsigned char *input, unsigned char *output, const unsigned char *key, const unsigned char *iv) {
    AES_KEY enc_key;
    if (AES_set_encrypt_key(key, 128, &enc_key)) {
        handleErrors();
    }
    AES_cbc_encrypt(input, output, AES_BLOCK_SIZE, &enc_key, (unsigned char *)iv, AES_ENCRYPT);
}

void aesDecrypt(const unsigned char *input, unsigned char *output, const unsigned char *key, const unsigned char *iv) {
    AES_KEY dec_key;
    if (AES_set_decrypt_key(key, 128, &dec_key)) {
        handleErrors();
    }
    AES_cbc_encrypt(input, output, AES_BLOCK_SIZE, &dec_key, (unsigned char *)iv, AES_DECRYPT);
}

void encryptFile(const char *inputFile, const char *outputFile, unsigned char *key, unsigned char *iv) {
    FILE *fin = fopen(inputFile, "rb");
    if (!fin) {
        perror("Failed to open input file");
        exit(1);
    }

    FILE *fout = fopen(outputFile, "wb");
    if (!fout) {
        perror("Failed to open output file");
        fclose(fin);
        exit(1);
    }

    unsigned char buffer[AES_BLOCK_SIZE];
    unsigned char ciphertext[AES_BLOCK_SIZE];

    while (fread(buffer, 1, AES_BLOCK_SIZE, fin) > 0) {
        aesEncrypt(buffer, ciphertext, key, iv);
        fwrite(ciphertext, 1, AES_BLOCK_SIZE, fout);
    }

    fclose(fin);
    fclose(fout);
}

void decryptFile(const char *inputFile, const char *outputFile, unsigned char *key, unsigned char *iv) {
    FILE *fin = fopen(inputFile, "rb");
    if (!fin) {
        perror("Failed to open input file");
        exit(1);
    }

    FILE *fout = fopen(outputFile, "wb");
    if (!fout) {
        perror("Failed to open output file");
        fclose(fin);
        exit(1);
    }

    unsigned char buffer[AES_BLOCK_SIZE];
    unsigned char plaintext[AES_BLOCK_SIZE];

    while (fread(buffer, 1, AES_BLOCK_SIZE, fin) > 0) {
        aesDecrypt(buffer, plaintext, key, iv);
        fwrite(plaintext, 1, AES_BLOCK_SIZE, fout);
    }

    fclose(fin);
    fclose(fout);
}

int main() {
    unsigned char key[AES_BLOCK_SIZE];
    unsigned char iv[AES_BLOCK_SIZE];

    generateKey(key);
    generateIV(iv);

    printf("Generated Key: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", key[i]);
    }
    printf("\n");

    printf("Generated IV: ");
    for (int i = 0; i < AES_BLOCK_SIZE; i++) {
        printf("%02x", iv[i]);
    }
    printf("\n");

    const char *inputFile = "plain.txt";
    const char *encryptedFile = "encrypted.bin";
    const char *decryptedFile = "decrypted.txt";

    encryptFile(inputFile, encryptedFile, key, iv);
    printf("File encrypted successfully.\n");

    decryptFile(encryptedFile, decryptedFile, key, iv);
    printf("File decrypted successfully.\n");

    return 0;
}