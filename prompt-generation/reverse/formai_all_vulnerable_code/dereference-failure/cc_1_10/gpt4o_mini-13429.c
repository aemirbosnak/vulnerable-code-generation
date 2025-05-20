//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

void generateKeyPair() {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (rsa == NULL) handleErrors();

    // Save private key
    FILE *privateKeyFile = fopen("private_key.pem", "wb");
    if (privateKeyFile == NULL) {
        fprintf(stderr, "Failed to open private key file for writing.\n");
        handleErrors();
    }
    PEM_write_RSAPrivateKey(privateKeyFile, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(privateKeyFile);
    printf("Private key generated and saved to private_key.pem\n");

    // Save public key
    FILE *publicKeyFile = fopen("public_key.pem", "wb");
    if (publicKeyFile == NULL) {
        fprintf(stderr, "Failed to open public key file for writing.\n");
        handleErrors();
    }
    PEM_write_RSA_PUBKEY(publicKeyFile, rsa);
    fclose(publicKeyFile);
    printf("Public key generated and saved to public_key.pem\n");

    RSA_free(rsa);
}

void encryptMessage(const char *message, unsigned char **encryptedMessage, int *encryptedLength) {
    FILE *publicKeyFile = fopen("public_key.pem", "rb");
    if (publicKeyFile == NULL) handleErrors();

    RSA *rsa = PEM_read_RSA_PUBKEY(publicKeyFile, NULL, NULL, NULL);
    fclose(publicKeyFile);
    if (rsa == NULL) handleErrors();

    *encryptedMessage = (unsigned char *)malloc(RSA_size(rsa));
    if (*encryptedMessage == NULL) {
        fprintf(stderr, "Failed to allocate memory for encrypted message.\n");
        handleErrors();
    }

    *encryptedLength = RSA_public_encrypt(strlen(message) + 1, (unsigned char *)message, *encryptedMessage, rsa, RSA_PKCS1_OAEP_PADDING);
    if (*encryptedLength == -1) handleErrors();

    RSA_free(rsa);
    printf("Message encrypted successfully!\n");
}

void decryptMessage(unsigned char *encryptedMessage, int encryptedLength, char **decryptedMessage) {
    FILE *privateKeyFile = fopen("private_key.pem", "rb");
    if (privateKeyFile == NULL) handleErrors();

    RSA *rsa = PEM_read_RSAPrivateKey(privateKeyFile, NULL, NULL, NULL);
    fclose(privateKeyFile);
    if (rsa == NULL) handleErrors();

    *decryptedMessage = (char *)malloc(RSA_size(rsa));
    if (*decryptedMessage == NULL) {
        fprintf(stderr, "Failed to allocate memory for decrypted message.\n");
        handleErrors();
    }

    int decryptedLength = RSA_private_decrypt(encryptedLength, encryptedMessage, (unsigned char *)*decryptedMessage, rsa, RSA_PKCS1_OAEP_PADDING);
    if (decryptedLength == -1) handleErrors();

    (*decryptedMessage)[decryptedLength] = '\0'; // Null-terminate the decrypted message
    RSA_free(rsa);
    printf("Message decrypted successfully!\n");
}

int main() {
    printf("Welcome to the Surprising Public-Key Encryption Program!\n");
    printf("Generating RSA key pairs...\n");
    generateKeyPair();

    const char *message = "Hello, this is a secret message!";
    printf("Original Message: %s\n", message);

    unsigned char *encryptedMessage = NULL;
    int encryptedLength = 0;
    
    printf("Encrypting message...\n");
    encryptMessage(message, &encryptedMessage, &encryptedLength);
    
    // Display encrypted message in hex form
    printf("Encrypted Message (hex): ");
    for (int i = 0; i < encryptedLength; i++) {
        printf("%02x", encryptedMessage[i]);
    }
    printf("\n");

    char *decryptedMessage = NULL;
    printf("Decrypting message...\n");
    decryptMessage(encryptedMessage, encryptedLength, &decryptedMessage);
    printf("Decrypted Message: %s\n", decryptedMessage);

    // Clean up
    free(encryptedMessage);
    free(decryptedMessage);
    
    printf("All done! Encryption and Decryption were successful.\n");
    return 0;
}