//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>
#include <time.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_keypair(int bits) {
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (rsa == NULL) handleErrors();

    // Save Public Key
    BIO *bp_public = BIO_new_file("public.pem", "w+");
    PEM_write_bio_RSAPublicKey(bp_public, rsa);
    BIO_free(bp_public);

    // Save Private Key
    BIO *bp_private = BIO_new_file("private.pem", "w+");
    PEM_write_bio_RSAPrivateKey(bp_private, rsa, NULL, NULL, 0, NULL, NULL);
    BIO_free(bp_private);

    RSA_free(rsa);
}

void encrypt_message(unsigned char *message, unsigned char *encrypted) {
    RSA *rsa = NULL;
    FILE *fp = fopen("public.pem", "rb");
    if (fp == NULL) {
        perror("Unable to open public key file");
        exit(EXIT_FAILURE);
    }
    rsa = PEM_read_RSAPublicKey(fp, NULL, NULL, NULL);
    fclose(fp);
    
    int result = RSA_public_encrypt(strlen((char *)message), message, encrypted, rsa, RSA_PKCS1_PADDING);
    if (result == -1) handleErrors();

    RSA_free(rsa);
}

void decrypt_message(unsigned char *encrypted, unsigned char *decrypted) {
    RSA *rsa = NULL;
    FILE *fp = fopen("private.pem", "rb");
    if (fp == NULL) {
        perror("Unable to open private key file");
        exit(EXIT_FAILURE);
    }
    rsa = PEM_read_RSAPrivateKey(fp, NULL, NULL, NULL);
    fclose(fp);
    
    int result = RSA_private_decrypt(RSA_size(rsa), encrypted, decrypted, rsa, RSA_PKCS1_PADDING);
    if (result == -1) handleErrors();

    decrypted[result] = '\0'; // Null-terminate decrypted message
    RSA_free(rsa);
}

int main() {
    srand(time(NULL)); // Seed for randomness
    
    // Generate RSA Keypair
    generate_keypair(2048);
    printf("RSA Keypair Generated!\n");
    
    // Message to be encrypted
    unsigned char *message = (unsigned char *)"This is a secret message!";
    unsigned char encrypted[256]; // Buffer for encrypted message
    unsigned char decrypted[256]; // Buffer for decrypted message

    // Encrypt the message
    encrypt_message(message, encrypted);
    printf("Message Encrypted!\n");

    // Decrypt the message
    decrypt_message(encrypted, decrypted);
    printf("Message Decrypted: %s\n", decrypted);
    
    return 0;
}