//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateRSAKeypair(int bits, RSA** rsa) {
    BIGNUM* bn = BN_new();
    if (!BN_set_word(bn, RSA_F4)) {
        handleErrors();
    }

    *rsa = RSA_new();
    if (!RSA_generate_key_ex(*rsa, bits, bn, NULL)) {
        handleErrors();
    }

    BN_free(bn);
}

void savePublicKeyToFile(RSA* rsa, const char* pubKeyFile) {
    FILE* fp = fopen(pubKeyFile, "wb");
    if (!fp) {
        perror("Failed to open public key file");
        exit(EXIT_FAILURE);
    }

    if (!PEM_write_RSA_PUBKEY(fp, rsa)) {
        handleErrors();
    }

    fclose(fp);
}

void savePrivateKeyToFile(RSA* rsa, const char* privKeyFile) {
    FILE* fp = fopen(privKeyFile, "wb");
    if (!fp) {
        perror("Failed to open private key file");
        exit(EXIT_FAILURE);
    }

    if (!PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL)) {
        handleErrors();
    }

    fclose(fp);
}

void encryptData(RSA* rsa, const char* data, unsigned char** encryptedData, int* dataLen) {
    *encryptedData = (unsigned char*)malloc(RSA_size(rsa));
    if (*encryptedData == NULL) {
        perror("Failed to allocate memory for encrypted data");
        exit(EXIT_FAILURE);
    }

    *dataLen = RSA_public_encrypt(strlen(data), (unsigned char*)data, *encryptedData, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*dataLen == -1) {
        handleErrors();
    }
}

void decryptData(RSA* rsa, unsigned char* encryptedData, int dataLen, unsigned char** decryptedData) {
    *decryptedData = (unsigned char*)malloc(RSA_size(rsa));
    if (*decryptedData == NULL) {
        perror("Failed to allocate memory for decrypted data");
        exit(EXIT_FAILURE);
    }

    int decryptedLen = RSA_private_decrypt(dataLen, encryptedData, *decryptedData, rsa, RSA_PKCS1_OAEP_PADDING);
    if (decryptedLen == -1) {
        handleErrors();
    }

    (*decryptedData)[decryptedLen] = '\0'; // Null-terminate the decrypted data
}

int main() {
    RSA* rsaKeypair = NULL;
    const char* pubKeyFile = "public.pem";
    const char* privKeyFile = "private.pem";
    
    // Generate RSA Keypair
    generateRSAKeypair(2048, &rsaKeypair);
    // Save keys to files
    savePublicKeyToFile(rsaKeypair, pubKeyFile);
    savePrivateKeyToFile(rsaKeypair, privKeyFile);

    // Example data to encrypt
    const char* dataToEncrypt = "Hello, this is a secret message!";
    unsigned char* encryptedData = NULL;
    int encryptedLength = 0;

    printf("Encrypting data: %s\n", dataToEncrypt);
    encryptData(rsaKeypair, dataToEncrypt, &encryptedData, &encryptedLength);
    printf("Data encrypted successfully!\n");

    unsigned char* decryptedData = NULL;
    decryptData(rsaKeypair, encryptedData, encryptedLength, &decryptedData);
    printf("Decrypted data: %s\n", decryptedData);

    // Free allocated memory and RSA keypair
    free(encryptedData);
    free(decryptedData);
    RSA_free(rsaKeypair);

    return 0;
}