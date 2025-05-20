//GEMINI-pro DATASET v1.0 Category: Encryption ; Style: expert-level
// Ciphertext/Key/IV Initialization
unsigned char ciphertext[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f};
unsigned char key[] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff};
unsigned char iv[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

// OpenSSL Header Inclusions
#include <openssl/conf.h>
#include <openssl/evp.h>
#include <openssl/err.h>

// Decrypt Function
int decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv) {
    // Create and Initialize Cipher Context
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        printf("EVP_CIPHER_CTX_new() failed.\n");
        return -1;
    }

    // Initialize Cipher
    if (!EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv)) {
        printf("EVP_DecryptInit_ex() failed.\n");
        return -1;
    }

    // Decrypt Data
    int plaintext_len;
    unsigned char *plaintext = malloc(ciphertext_len);
    if (!EVP_DecryptUpdate(ctx, plaintext, &plaintext_len, ciphertext, ciphertext_len)) {
        printf("EVP_DecryptUpdate() failed.\n");
        return -1;
    }

    // Finalize Decryption
    if (!EVP_DecryptFinal_ex(ctx, plaintext + plaintext_len, &plaintext_len)) {
        printf("EVP_DecryptFinal_ex() failed.\n");
        return -1;
    }

    // Print Decrypted Plaintext
    printf("Decrypted Plaintext: ");
    for (int i = 0; i < plaintext_len; i++) {
        printf("%02x", plaintext[i]);
    }
    printf("\n");

    // Cleanup
    EVP_CIPHER_CTX_free(ctx);
    free(plaintext);

    return 0;
}

// Main Function
int main() {
    // Initialize OpenSSL
    OPENSSL_init_ssl(0, NULL);

    int ciphertext_len = sizeof(ciphertext);
    int key_len = sizeof(key);
    int iv_len = sizeof(iv);

    // Decrypt Ciphertext
    int decrypt_status = decrypt(ciphertext, ciphertext_len, key, iv);

    // Cleanup OpenSSL
    OPENSSL_cleanup();

    // Return Decrypt Status
    return decrypt_status;
}