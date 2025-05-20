//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

#define KEY_LENGTH 2048
#define PUB_EXP 3
#define PADDING RSA_PKCS1_OAEP_PADDING

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *createRSA(int lb) {
    BIGNUM *bne = BN_new();
    RSA *rsa = RSA_new();

    if (BN_set_word(bne, PUB_EXP) != 1) {
        handleErrors();
    }

    if (RSA_generate_key_ex(rsa, KEY_LENGTH, bne, NULL) != 1) {
        handleErrors();
    }

    BN_free(bne);
    return rsa;
}

void savePublicKey(RSA *rsa) {
    FILE *fp = fopen("public.pem", "wb");
    if (fp == NULL) {
        perror("Unable to open public.pem for writing");
        return;
    }

    if (PEM_write_RSA_PUBKEY(fp, rsa) != 1) {
        handleErrors();
    }
    
    fclose(fp);
}

void savePrivateKey(RSA *rsa) {
    FILE *fp = fopen("private.pem", "wb");
    if (fp == NULL) {
        perror("Unable to open private.pem for writing");
        return;
    }

    if (PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL) != 1) {
        handleErrors();
    }
    
    fclose(fp);
}

void encryptData(RSA *rsa, const char *data, unsigned char *encrypted) {
    int result = RSA_public_encrypt(strlen(data), (unsigned char*)data, 
                                     encrypted, rsa, PADDING);
    if (result == -1) {
        handleErrors();
    }
}

void decryptData(RSA *rsa, unsigned char *encrypted, unsigned char *decrypted) {
    int result = RSA_private_decrypt(RSA_size(rsa), encrypted, 
                                      decrypted, rsa, PADDING);
    if (result == -1) {
        handleErrors();
    }
    decrypted[result] = '\0'; // Null-terminate string
}

int main() {
    unsigned char *encrypted = malloc(RSA_size(NULL)); // Allocate for encryption
    unsigned char decrypted[KEY_LENGTH / 8]; // Buffer for decryption

    // Seed the OpenSSL random number generator
    if (RAND_status() != 1) {
        fprintf(stderr, "Random number generator not seeded!");
        return EXIT_FAILURE;
    }

    // Create RSA Keys
    RSA *rsa = createRSA(0);
    
    // Save Keys to files
    savePublicKey(rsa);
    savePrivateKey(rsa);

    // Data to encrypt
    const char *data = "To be or not to be, that is the question.";
    printf("Original data: %s\n", data);

    // Encrypt the data
    encryptData(rsa, data, encrypted);
    printf("Encrypted data (hex): ");
    for (int i = 0; i < RSA_size(rsa); i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    // Decrypt the data
    decryptData(rsa, encrypted, decrypted);
    printf("Decrypted data: %s\n", decrypted);

    // Cleanup
    RSA_free(rsa);
    free(encrypted);
    return EXIT_SUCCESS;
}