//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <time.h>

#define RSA_KEY_BITS 2048

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA* generateRSAKeyPair(int bits) {
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (!rsa) {
        handleErrors();
    }
    return rsa;
}

void savePublicKeyToFile(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
    if (PEM_write_RSAPublicKey(fp, rsa) != 1) {
        handleErrors();
    }
    fclose(fp);
}

void savePrivateKeyToFile(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Failed to open file for writing");
        exit(EXIT_FAILURE);
    }
    if (PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL) != 1) {
        handleErrors();
    }
    fclose(fp);
}

void encryptMessage(RSA *rsa, const char *message, unsigned char **encrypted) {
    int rsaLen = RSA_size(rsa);
    *encrypted = malloc(rsaLen);
    if (*encrypted == NULL) {
        fprintf(stderr, "Memory allocation failed for encrypted message");
        exit(EXIT_FAILURE);
    }

    int encryptedLength = RSA_public_encrypt(strlen(message) + 1, (unsigned char*)message, *encrypted, rsa, RSA_PKCS1_PADDING);
    if (encryptedLength == -1) {
        handleErrors();
    }
}

void decryptMessage(RSA *rsa, unsigned char *encrypted, unsigned char **decrypted) {
    int rsaLen = RSA_size(rsa);
    *decrypted = malloc(rsaLen);
    if (*decrypted == NULL) {
        fprintf(stderr, "Memory allocation failed for decrypted message");
        exit(EXIT_FAILURE);
    }

    int decryptedLength = RSA_private_decrypt(rsaLen, encrypted, *decrypted, rsa, RSA_PKCS1_PADDING);
    if (decryptedLength == -1) {
        handleErrors();
    }
}

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Generate RSA Key Pair
    RSA *rsa = generateRSAKeyPair(RSA_KEY_BITS);
    
    // Save the public and private keys to files
    savePublicKeyToFile(rsa, "public.pem");
    savePrivateKeyToFile(rsa, "private.pem");
    printf("RSA Key Pair generated and saved to files.\n");

    const char *originalMessage = "Hello, Secure World!";
    unsigned char *encryptedMessage = NULL;

    // Encrypt the message
    encryptMessage(rsa, originalMessage, &encryptedMessage);
    printf("Message encrypted successfully.\n");

    unsigned char *decryptedMessage = NULL;

    // Decrypt the message
    decryptMessage(rsa, encryptedMessage, &decryptedMessage);
    printf("Message decrypted successfully: %s\n", decryptedMessage);

    // Free allocated resources
    free(encryptedMessage);
    free(decryptedMessage);
    RSA_free(rsa);
    
    return 0;
}