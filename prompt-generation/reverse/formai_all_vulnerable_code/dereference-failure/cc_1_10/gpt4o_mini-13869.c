//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

// Function to handle errors
void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to generate new RSA keys
RSA *generateRSAKeys(int bits) {
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (!rsa) {
        handleErrors();
    }
    return rsa;
}

// Function to get the public key in PEM format
char *getPublicKey(RSA *rsa) {
    BIO *bio = BIO_new(BIO_s_mem());
    if (!PEM_write_bio_RSA_PUBKEY(bio, rsa)) {
        handleErrors();
    }
    BUF_MEM *bufferPtr;
    BIO_get_mem_ptr(bio, &bufferPtr);
    char *publicKey = (char *) malloc(bufferPtr->length + 1);
    BIO_read(bio, publicKey, bufferPtr->length);
    publicKey[bufferPtr->length] = '\0'; // Null terminate
    BIO_free_all(bio);
    return publicKey;
}

// Function to get the private key in PEM format
char *getPrivateKey(RSA *rsa) {
    BIO *bio = BIO_new(BIO_s_mem());
    if (!PEM_write_bio_RSAPrivateKey(bio, rsa, NULL, NULL, 0, NULL, NULL)) {
        handleErrors();
    }
    BUF_MEM *bufferPtr;
    BIO_get_mem_ptr(bio, &bufferPtr);
    char *privateKey = (char *) malloc(bufferPtr->length + 1);
    BIO_read(bio, privateKey, bufferPtr->length);
    privateKey[bufferPtr->length] = '\0'; // Null terminate
    BIO_free_all(bio);
    return privateKey;
}

// Function to encrypt a message using the public key
unsigned char *encrypt(RSA *rsa, const unsigned char *message, int *encryptedLength) {
    unsigned char *encryptedMessage = (unsigned char *) malloc(RSA_size(rsa));
    *encryptedLength = RSA_public_encrypt(strlen((const char *)message), message, encryptedMessage, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*encryptedLength == -1) {
        handleErrors();
    }
    return encryptedMessage;
}

// Function to decrypt a message using the private key
unsigned char *decrypt(RSA *rsa, const unsigned char *encryptedMessage, int encryptedLength) {
    unsigned char *decryptedMessage = (unsigned char *) malloc(RSA_size(rsa));
    int decryptedLength = RSA_private_decrypt(encryptedLength, encryptedMessage, decryptedMessage, rsa, RSA_PKCS1_OAEP_PADDING);
    if (decryptedLength == -1) {
        handleErrors();
    }
    decryptedMessage[decryptedLength] = '\0'; // Null terminate
    return decryptedMessage;
}

// Main function
int main() {
    // Error handling initialization
    ERR_load_CRYPTO_strings();
    OpenSSL_add_all_algorithms();

    // Generate RSA keys
    int bits = 2048;
    RSA *rsa = generateRSAKeys(bits);
    
    // Get public and private keys
    char *publicKey = getPublicKey(rsa);
    char *privateKey = getPrivateKey(rsa);

    // Display the keys
    printf("Public Key:\n%s\n", publicKey);
    printf("Private Key:\n%s\n", privateKey);

    // Message to encrypt
    const char *message = "Hello, this is a test message!";
    printf("Original Message: %s\n", message);

    // Encrypt the message
    int encryptedLength;
    unsigned char *encryptedMessage = encrypt(rsa, (const unsigned char *)message, &encryptedLength);
    printf("Encrypted Message Length: %d\n", encryptedLength);

    // Decrypt the message
    unsigned char *decryptedMessage = decrypt(rsa, encryptedMessage, encryptedLength);
    printf("Decrypted Message: %s\n", decryptedMessage);

    // Free allocated memory
    free(publicKey);
    free(privateKey);
    free(encryptedMessage);
    free(decryptedMessage);
    RSA_free(rsa);
    
    // Cleanup for OpenSSL
    EVP_cleanup();
    ERR_free_strings();

    return 0;
}