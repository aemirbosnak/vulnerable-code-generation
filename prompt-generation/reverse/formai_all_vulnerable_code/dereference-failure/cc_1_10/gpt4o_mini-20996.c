//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to generate a new RSA key pair
RSA *generateRSAKey(int bits) {
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (rsa == NULL) {
        handleErrors();
    }
    return rsa;
}

// Function to save the RSA private key to a file
void savePrivateKey(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to open file for saving private key");
        exit(EXIT_FAILURE);
    }
    if (PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL) != 1) {
        fclose(fp);
        handleErrors();
    }
    fclose(fp);
}

// Function to save the RSA public key to a file
void savePublicKey(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        perror("Unable to open file for saving public key");
        exit(EXIT_FAILURE);
    }
    if (PEM_write_RSA_PUBKEY(fp, rsa) != 1) {
        fclose(fp);
        handleErrors();
    }
    fclose(fp);
}

// Function to encrypt a message using the public key
unsigned char *encryptMessage(RSA *rsa, const unsigned char *message, int *encryptedLen) {
    unsigned char *encrypted = malloc(RSA_size(rsa));
    if (encrypted == NULL) {
        perror("Unable to allocate memory for encrypted message");
        exit(EXIT_FAILURE);
    }
    *encryptedLen = RSA_public_encrypt(strlen((const char *)message), message, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*encryptedLen == -1) {
        free(encrypted);
        handleErrors();
    }
    return encrypted;
}

// Function to decrypt a message using the private key
unsigned char *decryptMessage(RSA *rsa, const unsigned char *encrypted, int encryptedLen, int *decryptedLen) {
    unsigned char *decrypted = malloc(RSA_size(rsa));
    if (decrypted == NULL) {
        perror("Unable to allocate memory for decrypted message");
        exit(EXIT_FAILURE);
    }
    *decryptedLen = RSA_private_decrypt(encryptedLen, encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*decryptedLen == -1) {
        free(decrypted);
        handleErrors();
    }
    return decrypted;
}

int main() {
    int bits = 2048;
    RSA *rsa = generateRSAKey(bits);

    // Save private and public keys to files
    savePrivateKey(rsa, "private_key.pem");
    savePublicKey(rsa, "public_key.pem");

    const char *message = "Hello, this is a secret message!";
    int encryptedLen;
    unsigned char *encryptedMessage = encryptMessage(rsa, (unsigned char *)message, &encryptedLen);
    
    printf("Encrypted Message: ");
    for (int i = 0; i < encryptedLen; i++) {
        printf("%02X", encryptedMessage[i]);
    }
    printf("\n");

    int decryptedLen;
    unsigned char *decryptedMessage = decryptMessage(rsa, encryptedMessage, encryptedLen, &decryptedLen);
    decryptedMessage[decryptedLen] = '\0'; // Null-terminate the decrypted string

    printf("Decrypted Message: %s\n", decryptedMessage);

    // Clean up
    free(encryptedMessage);
    free(decryptedMessage);
    RSA_free(rsa);
    
    return 0;
}