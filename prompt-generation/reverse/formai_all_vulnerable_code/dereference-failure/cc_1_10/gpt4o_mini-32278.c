//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void generate_keys(const char *pub_filename, const char *priv_filename) {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    
    // Save public key
    FILE *pub_file = fopen(pub_filename, "wb");
    if (!pub_file) {
        perror("Unable to open public key file");
        exit(EXIT_FAILURE);
    }
    PEM_write_RSA_PUBKEY(pub_file, rsa);
    fclose(pub_file);
    
    // Save private key
    FILE *priv_file = fopen(priv_filename, "wb");
    if (!priv_file) {
        perror("Unable to open private key file");
        exit(EXIT_FAILURE);
    }
    PEM_write_RSAPrivateKey(priv_file, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(priv_file);
    
    RSA_free(rsa);
}

void encrypt_message(const char *message, const char *pub_filename, unsigned char **encrypted) {
    FILE *pub_file = fopen(pub_filename, "rb");
    if (!pub_file) {
        perror("Unable to open public key file");
        exit(EXIT_FAILURE);
    }
    
    RSA *rsa = PEM_read_RSA_PUBKEY(pub_file, NULL, NULL, NULL);
    fclose(pub_file);
    
    int len = RSA_size(rsa);
    *encrypted = malloc(len);
    if (*encrypted == NULL) {
        perror("Unable to allocate memory for encrypted message");
        exit(EXIT_FAILURE);
    }
    
    int result = RSA_public_encrypt(strlen(message), (unsigned char *)message, *encrypted, rsa, RSA_PKCS1_PADDING);
    if (result == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    RSA_free(rsa);
}

void decrypt_message(unsigned char *encrypted, int encrypted_length, const char *priv_filename, char **decrypted) {
    FILE *priv_file = fopen(priv_filename, "rb");
    if (!priv_file) {
        perror("Unable to open private key file");
        exit(EXIT_FAILURE);
    }
    
    RSA *rsa = PEM_read_RSAPrivateKey(priv_file, NULL, NULL, NULL);
    fclose(priv_file);
    
    int len = RSA_size(rsa);
    *decrypted = malloc(len);
    if (*decrypted == NULL) {
        perror("Unable to allocate memory for decrypted message");
        exit(EXIT_FAILURE);
    }
    
    int result = RSA_private_decrypt(encrypted_length, encrypted, (unsigned char *)(*decrypted), rsa, RSA_PKCS1_PADDING);
    if (result == -1) {
        ERR_print_errors_fp(stderr);
        exit(EXIT_FAILURE);
    }
    
    (*decrypted)[result] = '\0'; // null terminate the decrypted message
    RSA_free(rsa);
}

int main() {
    const char *pub_filename = "public_key.pem";
    const char *priv_filename = "private_key.pem";
    generate_keys(pub_filename, priv_filename);

    const char *message = "Hello, RSA!";
    unsigned char *encrypted = NULL;
    encrypt_message(message, pub_filename, &encrypted);
    
    printf("Original message: %s\n", message);
    printf("Encrypted message (hex): ");
    for (int i = 0; i < RSA_size(RSA_generate_key(2048, RSA_F4, NULL, NULL)); i++) {
        printf("%02x", encrypted[i]);
    }
    printf("\n");

    char *decrypted = NULL;
    decrypt_message(encrypted, RSA_size(RSA_generate_key(2048, RSA_F4, NULL, NULL)), priv_filename, &decrypted);
    
    printf("Decrypted message: %s\n", decrypted);

    free(encrypted);
    free(decrypted);
    return 0;
}