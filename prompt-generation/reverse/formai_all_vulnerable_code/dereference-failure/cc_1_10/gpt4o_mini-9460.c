//GPT-4o-mini DATASET v1.0 Category: Modern Encryption ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

#define SALT_SIZE 16
#define KEY_SIZE 32
#define IV_SIZE 16
#define BUFFER_SIZE 1024

void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

void generate_salt(unsigned char *salt, int size) {
    if (RAND_bytes(salt, size) != 1) {
        handleErrors();
    }
}

void derive_key_and_iv(const char *password, unsigned char *salt, unsigned char *key, unsigned char *iv) {
    if (PKCS5_PBKDF2_HMAC(password, strlen(password), salt, SALT_SIZE, 10000, EVP_sha256(), KEY_SIZE, key) == 0) {
        handleErrors();
    }

    // The IV is the same as the key size for AES
    if (PKCS5_PBKDF2_HMAC(password, strlen(password), salt, SALT_SIZE, 10000, EVP_sha256(), IV_SIZE, iv) == 0) {
        handleErrors();
    }
}

void encrypt(const char *plaintext, unsigned char *key, unsigned char *iv, unsigned char *ciphertext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_EncryptUpdate(ctx, ciphertext, &len, (unsigned char*)plaintext, strlen(plaintext)) != 1) handleErrors();
    ciphertext_len = len;

    if (EVP_EncryptFinal_ex(ctx, ciphertext + len, &len) != 1) handleErrors();
    ciphertext_len += len;

    EVP_CIPHER_CTX_free(ctx);
}

void decrypt(unsigned char *ciphertext, int ciphertext_len, unsigned char *key, unsigned char *iv, unsigned char *plaintext) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) handleErrors();

    if (EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv) != 1) handleErrors();

    if (EVP_DecryptUpdate(ctx, plaintext, &len, ciphertext, ciphertext_len) != 1) handleErrors();
    plaintext_len = len;

    if (EVP_DecryptFinal_ex(ctx, plaintext + len, &len) != 1) handleErrors();
    plaintext_len += len;

    EVP_CIPHER_CTX_free(ctx);
    plaintext[plaintext_len] = '\0'; // Null terminate the plaintext
}

void print_hex(const char *label, unsigned char *data, size_t length) {
    printf("%s", label);
    for (size_t i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    const char *password = "SecurePassword!";
    unsigned char plaintext[BUFFER_SIZE] = "The quick brown fox jumps over the lazy dog.";
    unsigned char salt[SALT_SIZE];
    unsigned char key[KEY_SIZE];
    unsigned char iv[IV_SIZE];
    unsigned char ciphertext[BUFFER_SIZE];
    unsigned char decryptedtext[BUFFER_SIZE];

    printf("Original text: %s\n", plaintext);

    // Step 1: Generate a new salt
    generate_salt(salt, SALT_SIZE);

    // Step 2: Derive the key and IV from the password and salt
    derive_key_and_iv(password, salt, key, iv);

    // Step 3: Encrypt the plaintext
    encrypt((char *)plaintext, key, iv, ciphertext);
    print_hex("Salt: ", salt, SALT_SIZE);
    print_hex("Key: ", key, KEY_SIZE);
    print_hex("IV: ", iv, IV_SIZE);
    print_hex("Ciphertext: ", ciphertext, strlen((char *)plaintext) + EVP_CIPHER_block_size(EVP_aes_256_cbc()) - 1);

    // Step 4: Decrypt the ciphertext
    decrypt(ciphertext, strlen((char *)plaintext) + EVP_CIPHER_block_size(EVP_aes_256_cbc()) - 1, key, iv, decryptedtext);
    
    printf("Decrypted text: %s\n", decryptedtext);

    return 0;
}