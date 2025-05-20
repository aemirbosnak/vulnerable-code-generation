//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

// Function to generate RSA keys
void generate_RSA_keys(int bits, const char* publicKeyFile, const char* privateKeyFile) {
    RSA* rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    
    // Save the public key
    FILE* pubFile = fopen(publicKeyFile, "wb");
    if (pubFile) {
        PEM_write_RSA_PUBKEY(pubFile, rsa);
        fclose(pubFile);
    } else {
        fprintf(stderr, "Error saving public key to file: %s\n", publicKeyFile);
    }

    // Save the private key
    FILE* privFile = fopen(privateKeyFile, "wb");
    if (privFile) {
        PEM_write_RSAPrivateKey(privFile, rsa, NULL, NULL, 0, NULL, NULL);
        fclose(privFile);
    } else {
        fprintf(stderr, "Error saving private key to file: %s\n", privateKeyFile);
    }

    RSA_free(rsa);
}

// Function to encrypt data using the public key
void encrypt_data(const char* publicKeyFile, const char* data, unsigned char** encryptedData, int* encryptedDataLen) {
    FILE* pubFile = fopen(publicKeyFile, "rb");
    if (!pubFile) {
        fprintf(stderr, "Error opening public key file: %s\n", publicKeyFile);
        return;
    }

    RSA* rsa = PEM_read_RSA_PUBKEY(pubFile, NULL, NULL, NULL);
    fclose(pubFile);

    *encryptedData = malloc(RSA_size(rsa));
    if (*encryptedData == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }
    
    *encryptedDataLen = RSA_public_encrypt(strlen(data) + 1, (unsigned char*)data, *encryptedData, rsa, RSA_PKCS1_OAEP_PADDING);
    
    if (*encryptedDataLen == -1) {
        fprintf(stderr, "Encryption failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(*encryptedData);
        *encryptedData = NULL;
    }

    RSA_free(rsa);
}

// Function to decrypt data using the private key
void decrypt_data(const char* privateKeyFile, unsigned char* encryptedData, int encryptedDataLen, unsigned char** decryptedData) {
    FILE* privFile = fopen(privateKeyFile, "rb");
    if (!privFile) {
        fprintf(stderr, "Error opening private key file: %s\n", privateKeyFile);
        return;
    }

    RSA* rsa = PEM_read_RSAPrivateKey(privFile, NULL, NULL, NULL);
    fclose(privFile);

    *decryptedData = malloc(RSA_size(rsa));
    if (*decryptedData == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return;
    }

    int decryptedDataLen = RSA_private_decrypt(encryptedDataLen, encryptedData, *decryptedData, rsa, RSA_PKCS1_OAEP_PADDING);
    
    if (decryptedDataLen == -1) {
        fprintf(stderr, "Decryption failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(*decryptedData);
        *decryptedData = NULL;
    } else {
        (*decryptedData)[decryptedDataLen] = '\0'; // Null-terminate the string
    }

    RSA_free(rsa);
}

int main() {
    const char* publicKeyFile = "public_key.pem";
    const char* privateKeyFile = "private_key.pem";
    
    // Generate RSA keys
    generate_RSA_keys(2048, publicKeyFile, privateKeyFile);
    printf("RSA keys generated and saved to %s and %s\n", publicKeyFile, privateKeyFile);

    const char* originalData = "Under the brave sky, let secrets fly!";
    unsigned char* encryptedData = NULL;
    int encryptedDataLen = 0;

    // Encrypt the original data
    encrypt_data(publicKeyFile, originalData, &encryptedData, &encryptedDataLen);
    
    if (encryptedData) {
        printf("Data encrypted successfully! Encrypted length: %d\n", encryptedDataLen);
    }

    unsigned char* decryptedData = NULL;

    // Decrypt the data
    decrypt_data(privateKeyFile, encryptedData, encryptedDataLen, &decryptedData);
    
    if (decryptedData) {
        printf("Decrypted data: %s\n", decryptedData);
    }

    // Clean up
    free(encryptedData);
    free(decryptedData);

    return 0;
}