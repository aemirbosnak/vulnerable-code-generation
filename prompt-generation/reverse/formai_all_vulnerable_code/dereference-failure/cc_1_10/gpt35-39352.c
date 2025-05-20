//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/pem.h>

#define KEY_LENGTH 2048

void handleErrors(void)
{
    printf("An error occurred...\n");
    exit(1);    
}

int main(void)
{
    // Generate public and private key
    RSA *keypair = RSA_generate_key(KEY_LENGTH, RSA_F4, NULL, NULL);
    if (!keypair) {
        handleErrors();
    }

    // Convert RSA key to PEM format
    BIO *priBio = BIO_new(BIO_s_mem());
    if (!priBio) {
        handleErrors();
    }
    if (!PEM_write_bio_RSAPrivateKey(priBio, keypair, NULL, NULL, 0, NULL, NULL)) {
        handleErrors();
    }

    // Print private key
    char *priKey;
    long priKeyLen = BIO_get_mem_data(priBio, &priKey);
    if (priKeyLen <= 0) {
        handleErrors();
    }
    printf("Private Key:\n%s\n", priKey);

    // Convert public key to PEM format
    BIO *pubBio = BIO_new(BIO_s_mem());
    if (!pubBio) {
        handleErrors();
    }
    if (!PEM_write_bio_RSA_PUBKEY(pubBio, keypair)) {
        handleErrors();
    }

    // Print public key
    char *pubKey;
    long pubKeyLen = BIO_get_mem_data(pubBio, &pubKey);
    if (pubKeyLen <= 0) {
        handleErrors();
    }
    printf("Public Key:\n%s\n", pubKey);

    // Encrypt message using public key
    char *msg = "Hello World!";
    int msgLen = strlen(msg);
    unsigned char *encMsg = (unsigned char*)malloc(RSA_size(keypair));
    int encMsgLen = RSA_public_encrypt(msgLen, (unsigned char*)msg, encMsg, keypair, RSA_PKCS1_OAEP_PADDING);
    if (encMsgLen <= 0) {
        handleErrors();
    }
    printf("Encrypted Message:\n");
    for (int i = 0; i < encMsgLen; i++) {
        printf("%02x", encMsg[i]);
    }
    printf("\n");

    // Decrypt message using private key
    unsigned char *decMsg = (unsigned char*)malloc(msgLen);
    int decMsgLen = RSA_private_decrypt(encMsgLen, encMsg, decMsg, keypair, RSA_PKCS1_OAEP_PADDING);
    if (decMsgLen <= 0) {
        handleErrors();
    }
    printf("Decrypted Message:\n%s\n", decMsg);

    // Cleanup
    RSA_free(keypair);
    BIO_free_all(priBio);
    BIO_free_all(pubBio);
    free(encMsg);
    free(decMsg);

    return 0;
}