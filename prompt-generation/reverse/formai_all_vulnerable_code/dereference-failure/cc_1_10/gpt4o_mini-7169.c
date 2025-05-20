//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define BITS 2048
#define PUBLIC_EXPONENT 3
#define MESSAGE_LENGTH 256

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *createRSA(unsigned char * key, int isPublic) {
    RSA *rsa = NULL;
    BIO *keyBio = BIO_new_mem_buf(key, -1);

    if (isPublic) {
        rsa = PEM_read_bio_RSA_PUBKEY(keyBio, &rsa, NULL, NULL);
    } else {
        rsa = PEM_read_bio_RSAPrivateKey(keyBio, &rsa, NULL, NULL);
    }

    BIO_free(keyBio);
    return rsa;
}

unsigned char *encryptMessage(RSA *rsa, unsigned char *message, int *encryptedLength) {
    unsigned char *encryptedMessage = malloc(RSA_size(rsa));
    *encryptedLength = RSA_public_encrypt(strlen((char *)message), message, encryptedMessage, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*encryptedLength == -1) {
        handleErrors();
    }
    return encryptedMessage;
}

unsigned char *decryptMessage(RSA *rsa, unsigned char *encryptedMessage, int encryptedLength, int *decryptedLength) {
    unsigned char *decryptedMessage = malloc(RSA_size(rsa));
    *decryptedLength = RSA_private_decrypt(encryptedLength, encryptedMessage, decryptedMessage, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*decryptedLength == -1) {
        handleErrors();
    }
    return decryptedMessage;
}

void generateKeys(RSA **rsa, unsigned char **publicKey, unsigned char **privateKey) {
    *rsa = RSA_new();
    BIGNUM *bne = BN_new();
    BN_set_word(bne, PUBLIC_EXPONENT);

    if (RSA_generate_key_ex(*rsa, BITS, bne, NULL) != 1) {
        handleErrors();
    }

    BIO *pubBio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSA_PUBKEY(pubBio, *rsa);
    BIO_get_mem_data(pubBio, publicKey);
    
    BIO *privBio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPrivateKey(privBio, *rsa, NULL, NULL, 0, NULL, NULL);
    BIO_get_mem_data(privBio, privateKey);

    BIO_free_all(pubBio);
    BIO_free_all(privBio);
    BN_free(bne);
}

int main() {
    RSA *rsa = NULL;
    unsigned char *publicKey = NULL;
    unsigned char *privateKey = NULL;

    // Generate RSA keys
    generateKeys(&rsa, &publicKey, &privateKey);
    printf("Public Key:\n%s\n", publicKey);
    printf("Private Key:\n%s\n", privateKey);

    // Message to encrypt
    unsigned char message[MESSAGE_LENGTH];
    printf("Enter a message to encrypt: ");
    fgets((char *)message, MESSAGE_LENGTH, stdin);
    message[strcspn((char *)message, "\n")] = '\0'; // Remove trailing newline

    int encryptedLength = 0;
    unsigned char *encryptedMessage = encryptMessage(rsa, message, &encryptedLength);
    printf("Encrypted Message Length: %d\n", encryptedLength);

    int decryptedLength = 0;
    unsigned char *decryptedMessage = decryptMessage(rsa, encryptedMessage, encryptedLength, &decryptedLength);
    decryptedMessage[decryptedLength] = '\0'; // Null terminate string

    printf("Decrypted Message: %s\n", decryptedMessage);

    // Clean up
    free(encryptedMessage);
    free(decryptedMessage);
    RSA_free(rsa);
    free(publicKey);
    free(privateKey);
    
    return 0;
}