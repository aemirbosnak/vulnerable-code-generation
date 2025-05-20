//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void handleErrors() {
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *generate_key_pair() {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    if (!rsa) handleErrors();
    return rsa;
}

void save_public_key(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file for writing public key.\n");
        return;
    }
    PEM_write_RSA_PUBKEY(fp, rsa);
    fclose(fp);
    printf("Public Key saved to %s\n", filename);
}

void save_private_key(RSA *rsa, const char *filename) {
    FILE *fp = fopen(filename, "wb");
    if (!fp) {
        fprintf(stderr, "Unable to open file for writing private key.\n");
        return;
    }
    PEM_write_RSAPrivateKey(fp, rsa, NULL, NULL, 0, NULL, NULL);
    fclose(fp);
    printf("Private Key saved to %s\n", filename);
}

void encrypt_message(RSA *rsa_public, const char *message, unsigned char **encrypted) {
    int len = RSA_size(rsa_public);
    *encrypted = malloc(len);
    if (*encrypted == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return;
    }
    
    int result = RSA_public_encrypt(strlen(message), (unsigned char *)message, *encrypted, rsa_public, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) handleErrors();
    printf("Message encrypted successfully.\n");
}

void decrypt_message(RSA *rsa_private, unsigned char *encrypted, int encrypted_length, unsigned char **decrypted) {
    *decrypted = malloc(RSA_size(rsa_private));
    if (*decrypted == NULL) {
        fprintf(stderr, "Memory allocation error.\n");
        return;
    }
    
    int result = RSA_private_decrypt(encrypted_length, encrypted, *decrypted, rsa_private, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) handleErrors();
    
    (*decrypted)[result] = '\0'; // Null terminate the decrypted string
    printf("Message decrypted successfully: %s\n", *decrypted);
}

int main() {
    char *public_key_file = "public.pem";
    char *private_key_file = "private.pem";
    RSA *rsa = generate_key_pair();

    save_public_key(rsa, public_key_file);
    save_private_key(rsa, private_key_file);
    
    const char *original_message = "Hello, this is a secret message!";
    unsigned char *encrypted_message;
    
    encrypt_message(rsa, original_message, &encrypted_message);
    printf("Original message: %s\n", original_message);

    unsigned char *decrypted_message;
    decrypt_message(rsa, encrypted_message, RSA_size(rsa), &decrypted_message);
    
    free(encrypted_message);
    free(decrypted_message);
    RSA_free(rsa);
    return 0;
}