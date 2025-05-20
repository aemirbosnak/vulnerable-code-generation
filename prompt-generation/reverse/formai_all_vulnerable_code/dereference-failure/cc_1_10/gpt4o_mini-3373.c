//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

// Function to generate RSA key pair
void generate_key_pair(int bits) {
    RSA *rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
    
    // Save Public Key
    FILE *pubkey_file = fopen("public_key.pem", "wb");
    PEM_write_RSAPublicKey(pubkey_file, rsa);
    fclose(pubkey_file);
    
    // Save Private Key
    FILE *privkey_file = fopen("private_key.pem", "wb");
    PEM_write_RSAPrivateKey(privkey_file, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(privkey_file);
    
    RSA_free(rsa);
}

// Function to encrypt message using public key
void encrypt_message(const char *message, const char *public_key_file) {
    FILE *pubkey_file = fopen(public_key_file, "rb");
    RSA *rsa = PEM_read_RSAPublicKey(pubkey_file, NULL, NULL, NULL);
    fclose(pubkey_file);
    
    size_t rsa_len = RSA_size(rsa);
    unsigned char *encrypted = malloc(rsa_len);
    
    if (RSA_public_encrypt(strlen(message), (unsigned char *)message, encrypted, rsa, RSA_PKCS1_OAEP_PADDING) == -1) {
        fprintf(stderr, "Encryption Error: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(encrypted);
        RSA_free(rsa);
        exit(EXIT_FAILURE);
    }
    
    FILE *enc_file = fopen("encrypted_message.bin", "wb");
    fwrite(encrypted, 1, rsa_len, enc_file);
    fclose(enc_file);
    
    printf("Message Encrypted Successfully!\n");
    free(encrypted);
    RSA_free(rsa);
}

// Function to decrypt message using private key
void decrypt_message(const char *private_key_file) {
    FILE *privkey_file = fopen(private_key_file, "rb");
    RSA *rsa = PEM_read_RSAPrivateKey(privkey_file, NULL, NULL, NULL);
    fclose(privkey_file);
    
    FILE *enc_file = fopen("encrypted_message.bin", "rb");
    fseek(enc_file, 0, SEEK_END);
    long enc_len = ftell(enc_file);
    fseek(enc_file, 0, SEEK_SET);
    
    unsigned char *encrypted = malloc(enc_len);
    fread(encrypted, 1, enc_len, enc_file);
    fclose(enc_file);
    
    size_t rsa_len = RSA_size(rsa);
    unsigned char *decrypted = malloc(rsa_len);
    
    if (RSA_private_decrypt(enc_len, encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING) == -1) {
        fprintf(stderr, "Decryption Error: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(encrypted);
        free(decrypted);
        RSA_free(rsa);
        exit(EXIT_FAILURE);
    }
    
    printf("Decrypted Message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    RSA_free(rsa);
}

int main() {
    int bits = 2048; // For a stronger key, you may choose a bigger length
    generate_key_pair(bits);

    const char *message = "Hello, this is a secret message.";
    
    printf("Original Message: %s\n", message);
    
    encrypt_message(message, "public_key.pem");
    
    printf("Now let's decrypt...\n");
    decrypt_message("private_key.pem");

    return 0;
}