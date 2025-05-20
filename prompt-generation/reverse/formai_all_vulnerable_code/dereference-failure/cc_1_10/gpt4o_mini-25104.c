//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

// Function to handle errors
void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to generate RSA key pair
void generateRSAKeys(int bits) {
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    if (rsa == NULL) {
        handleErrors();
    }

    // Save private key
    FILE *privKeyFile = fopen("private_key.pem", "wb");
    PEM_write_RSAPrivateKey(privKeyFile, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(privKeyFile);

    // Save public key
    FILE *pubKeyFile = fopen("public_key.pem", "wb");
    PEM_write_RSA_PUBKEY(pubKeyFile, rsa);
    fclose(pubKeyFile);

    RSA_free(rsa);
    printf("Keys generated successfully!\n");
}

// Function to encrypt plaintext using public key
void encrypt(const char *publicKeyFile, const char *plaintext) {
    RSA *rsa = NULL;
    FILE *pubKeyFile = fopen(publicKeyFile, "rb");
    if (!pubKeyFile) {
        perror("Unable to open public key file");
        return;
    }
    rsa = PEM_read_RSA_PUBKEY(pubKeyFile, NULL, NULL, NULL);
    fclose(pubKeyFile);

    if (!rsa) {
        handleErrors();
    }

    // Encrypt the plaintext
    int encrypted_length = RSA_size(rsa);
    unsigned char *encrypted = malloc(encrypted_length);
    if (RSA_public_encrypt(strlen(plaintext) + 1, (unsigned char *)plaintext, encrypted, rsa, RSA_PKCS1_OAEP_PADDING) < 0) {
        handleErrors();
    }

    printf("Encrypted text:\n");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    free(encrypted);
    RSA_free(rsa);
}

// Function to decrypt ciphertext using private key
void decrypt(const char *privateKeyFile, const unsigned char *ciphertext, int cipherLen) {
    RSA *rsa = NULL;
    FILE *privKeyFile = fopen(privateKeyFile, "rb");
    if (!privKeyFile) {
        perror("Unable to open private key file");
        return;
    }
    rsa = PEM_read_RSAPrivateKey(privKeyFile, NULL, NULL, NULL);
    fclose(privKeyFile);

    if (!rsa) {
        handleErrors();
    }

    // Decrypt the ciphertext
    unsigned char *decrypted = malloc(RSA_size(rsa));
    int decrypted_length = RSA_private_decrypt(cipherLen, ciphertext, decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    if (decrypted_length < 0) {
        handleErrors();
    }

    printf("Decrypted text: %s\n", decrypted);

    free(decrypted);
    RSA_free(rsa);
}

int main() {
    const int bits = 2048;
    generateRSAKeys(bits);

    const char *plaintext = "Hello World!";
    printf("Original text: %s\n", plaintext);
    
    encrypt("public_key.pem", plaintext);

    // Example of using the decrypt function
    char *ciphertext_hex = "YOUR_ENCRYPTED_HEX_HERE"; // *Use actual hex encrypted text*
    unsigned char ciphertext[256]; // Adjust size according to your encryption results
    for (int i = 0; i < strlen(ciphertext_hex) / 2; ++i) {
        sscanf(ciphertext_hex + 2 * i, "%2hhx", &ciphertext[i]);
    }
    decrypt("private_key.pem", ciphertext, sizeof(ciphertext));

    return 0;
}