//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: beginner-friendly
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

void generateKeys(RSA **rsaPublic, RSA **rsaPrivate, int bits) {
    BIGNUM *bn = BN_new();
    if (BN_set_word(bn, RSA_F4) != 1) {
        handleErrors();
    }

    *rsaPrivate = RSA_new();
    if (RSA_generate_key_ex(*rsaPrivate, bits, bn, NULL) != 1) {
        handleErrors();
    }

    *rsaPublic = RSAPublicKey_dup(*rsaPrivate);
    
    BN_free(bn);
}

void savePrivateKey(RSA *rsaPrivate, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to open file for writing private key");
        return;
    }
    
    if (PEM_write_RSAPrivateKey(fp, rsaPrivate, NULL, NULL, 0, NULL, NULL) != 1) {
        handleErrors();
    }
    fclose(fp);
}

void savePublicKey(RSA *rsaPublic, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to open file for writing public key");
        return;
    }
    
    if (PEM_write_RSA_PUBKEY(fp, rsaPublic) != 1) {
        handleErrors();
    }
    fclose(fp);
}

int encryptMessage(RSA *rsaPublic, const char *message, unsigned char **encryptedMessage) {
    int keySize = RSA_size(rsaPublic);
    *encryptedMessage = (unsigned char *)malloc(keySize);
    
    int result = RSA_public_encrypt(strlen(message) + 1, (unsigned char *)message, *encryptedMessage, rsaPublic, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    
    return result; // Returns the size of the encrypted message
}

int decryptMessage(RSA *rsaPrivate, unsigned char *encryptedMessage, int encryptedMessageLength, unsigned char **decryptedMessage) {
    *decryptedMessage = (unsigned char *)malloc(RSA_size(rsaPrivate));
    
    int result = RSA_private_decrypt(encryptedMessageLength, encryptedMessage, *decryptedMessage, rsaPrivate, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handleErrors();
    }
    
    return result; // Returns the size of the decrypted message
}

int main() {
    RSA *rsaPublic = NULL;
    RSA *rsaPrivate = NULL;
    
    // Generate RSA Keys
    generateKeys(&rsaPublic, &rsaPrivate, 2048);
    
    // Save Keys to file
    savePublicKey(rsaPublic, "publicKey.pem");
    savePrivateKey(rsaPrivate, "privateKey.pem");
    
    printf("\nRSA Public and Private keys generated and saved in files!\n");

    // Encrypt a message
    const char *message = "Hello, this is a secret message!";
    unsigned char *encryptedMessage;
    int encryptedLength = encryptMessage(rsaPublic, message, &encryptedMessage);
    
    printf("\nMessage encrypted successfully!\n");

    // Decrypt the message
    unsigned char *decryptedMessage;
    int decryptedLength = decryptMessage(rsaPrivate, encryptedMessage, encryptedLength, &decryptedMessage);
    
    printf("\nDecrypted message: %s\n", decryptedMessage);

    // Free allocated memory
    free(encryptedMessage);
    free(decryptedMessage);
    RSA_free(rsaPublic);
    RSA_free(rsaPrivate);

    return 0;
}