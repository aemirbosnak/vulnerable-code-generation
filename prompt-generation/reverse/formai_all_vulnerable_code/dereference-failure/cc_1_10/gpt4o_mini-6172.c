//GPT-4o-mini DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void generate_keys() {
    RSA *rsa = RSA_generate_key(2048, RSA_F4, NULL, NULL);
    
    // Prepare to open files for public and private keys
    FILE *pub_file = fopen("public_key.pem", "wb");
    FILE *priv_file = fopen("private_key.pem", "wb");

    // Write public key
    if (pub_file) {
        PEM_write_RSAPublicKey(pub_file, rsa);
        fclose(pub_file);
    } else {
        fprintf(stderr, "Unable to open public key file for writing.\n");
    }

    // Write private key
    if (priv_file) {
        PEM_write_RSAPrivateKey(priv_file, rsa, NULL, NULL, 0, NULL, NULL);
        fclose(priv_file);
    } else {
        fprintf(stderr, "Unable to open private key file for writing.\n");
    }

    RSA_free(rsa);
}

void surreal_encrypt(const char *plain_text) {
    FILE *pub_file = fopen("public_key.pem", "rb");
    RSA *rsa = RSA_new();
    PEM_read_RSAPublicKey(pub_file, &rsa, NULL, NULL);
    fclose(pub_file);

    int rsa_size = RSA_size(rsa);
    unsigned char *encrypted = malloc(rsa_size);
    
    // Encrypt the text
    int result = RSA_public_encrypt(strlen(plain_text), (unsigned char*)plain_text, encrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    
    if (result == -1) {
        fprintf(stderr, "Encryption failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(encrypted);
        return;
    }

    // Save the encoded message
    FILE *enc_file = fopen("encrypted_message.bin", "wb");
    fwrite(encrypted, sizeof(unsigned char), result, enc_file);
    fclose(enc_file);
    free(encrypted);
    RSA_free(rsa);
}

void surreal_decrypt() {
    FILE *priv_file = fopen("private_key.pem", "rb");
    RSA *rsa = RSA_new();
    PEM_read_RSAPrivateKey(priv_file, &rsa, NULL, NULL);
    fclose(priv_file);

    FILE *enc_file = fopen("encrypted_message.bin", "rb");
    fseek(enc_file, 0, SEEK_END);
    long enc_length = ftell(enc_file);
    fseek(enc_file, 0, SEEK_SET);
    unsigned char *encrypted = malloc(enc_length);
    fread(encrypted, sizeof(unsigned char), enc_length, enc_file);
    fclose(enc_file);

    unsigned char *decrypted = malloc(RSA_size(rsa));
    int result = RSA_private_decrypt(enc_length, encrypted, decrypted, rsa, RSA_PKCS1_OAEP_PADDING);
    
    if (result == -1) {
        fprintf(stderr, "Decryption failed: %s\n", ERR_error_string(ERR_get_error(), NULL));
        free(encrypted);
        free(decrypted);
        return;
    }

    // Print the decoded message that dances on the edge of perception
    printf("Decrypted message: %s\n", decrypted);
    
    free(encrypted);
    free(decrypted);
    RSA_free(rsa);
}

int main() {
    srand(time(NULL));
    char *cosmic_message = "In a world where time swirls like a reel of film, the encryptions of the soul entwine.";
    printf("Generating surreal keys...\n");
    
    // Create a scene of strange solitude
    generate_keys();

    printf("Encrypted whispers from the void...\n");
    surreal_encrypt(cosmic_message);

    printf("Now, let's unravel the echoes of existence...\n");
    surreal_decrypt();

    printf("A symphony of keys has set the stage for endless iterations of reality...\n");
    return 0;
}