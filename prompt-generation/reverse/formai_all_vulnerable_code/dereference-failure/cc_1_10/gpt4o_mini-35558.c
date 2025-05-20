//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

// Function for error handling
void handle_errors() {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to generate RSA key pair
RSA* generate_keypair(int length) {
    RSA* rsa = RSA_generate_key(length, RSA_F4, NULL, NULL);
    if (rsa == NULL) {
        handle_errors();
    }
    return rsa;
}

// Function to save public key to a file
void save_public_key(RSA* rsa, const char* public_filename) {
    FILE* fp = fopen(public_filename, "wb");
    if (fp == NULL) {
        perror("Unable to open public key file for writing");
        return;
    }
    if (PEM_write_RSA_PUBKEY(fp, rsa) != 1) {
        handle_errors();
    }
    fclose(fp);
}

// Function to save private key to a file
void save_private_key(RSA* rsa, const char* private_filename) {
    FILE* fp = fopen(private_filename, "wb");
    if (fp == NULL) {
        perror("Unable to open private key file for writing");
        return;
    }
    if (PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL) != 1) {
        handle_errors();
    }
    fclose(fp);
}

// Function to encrypt data using public key
void encrypt_data(RSA* rsa, unsigned char* plaintext, unsigned char* ciphertext) {
    int result = RSA_public_encrypt(strlen((char*)plaintext), plaintext, ciphertext, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handle_errors();
    }
}

// Function to decrypt data using private key
void decrypt_data(RSA* rsa, unsigned char* ciphertext, unsigned char* decryptedtext) {
    int result = RSA_private_decrypt(RSA_size(rsa), ciphertext, decryptedtext, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        handle_errors();
    }
}

// Main function to demonstrate RSA key generation, encryption, and decryption
int main() {
    // Generate RSA key pair
    RSA* rsa = generate_keypair(2048);   // Generation of 2048-bit keys
    const char* public_key_file = "public_key.pem";
    const char* private_key_file = "private_key.pem";

    // Save the keys to files
    save_public_key(rsa, public_key_file);
    save_private_key(rsa, private_key_file);

    // Sample data to encrypt
    unsigned char* plaintext = (unsigned char*)"Hello, this is a secret message!";
    unsigned char ciphertext[256]; // Making sure buffer is large enough
    unsigned char decryptedtext[256]; // Buffer for decrypted data

    // Encrypt the plaintext
    printf("Original plaintext: %s\n", plaintext);
    encrypt_data(rsa, plaintext, ciphertext);
    printf("Encrypted data: ");
    for (int i = 0; i < RSA_size(rsa); i++)
        printf("%02x", ciphertext[i]);
    printf("\n");

    // Decrypt the ciphertext
    decrypt_data(rsa, ciphertext, decryptedtext);
    decryptedtext[RSA_size(rsa)-1] = '\0'; // Ensure null-termination
    printf("Decrypted plaintext: %s\n", decryptedtext);

    // Clean up
    RSA_free(rsa);
    return 0;
}