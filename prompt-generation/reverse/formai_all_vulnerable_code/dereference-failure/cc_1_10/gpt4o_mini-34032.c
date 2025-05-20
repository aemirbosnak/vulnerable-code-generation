//GPT-4o-mini DATASET v1.0 Category: Cryptography Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>

#define BLOCK_SIZE 16 
#define HASH_SIZE SHA256_DIGEST_LENGTH
#define PASSWORD_SIZE 32
#define SALT_SIZE 16

// Function to generate a secure random salt
void generate_salt(unsigned char *salt, int length) {
    if (RAND_bytes(salt, length) != 1) {
        fprintf(stderr, "Error generating salt.\n");
        exit(EXIT_FAILURE);
    }
}

// Function to derive a key using PBKDF2 with a given salt
void derive_key(const char *password, const unsigned char *salt, unsigned char *key) {
    if (PKCS5_PBKDF2_HMAC_SHA1(password, strlen(password), salt, SALT_SIZE, 10000, PASSWORD_SIZE, key) != 1) {
        fprintf(stderr, "Error deriving key.\n");
        exit(EXIT_FAILURE);
    }
}

// Encryption function using XOR and a simple substitution cipher
void encrypt(const unsigned char *plaintext, unsigned char *ciphertext, const unsigned char *key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        ciphertext[i] = plaintext[i] ^ key[i % PASSWORD_SIZE]; // Simple XOR Encryption
    }
}

// Decryption function (symmetric to the encryption)
void decrypt(const unsigned char *ciphertext, unsigned char *plaintext, const unsigned char *key, size_t length) {
    for (size_t i = 0; i < length; i++) {
        plaintext[i] = ciphertext[i] ^ key[i % PASSWORD_SIZE]; // Simple XOR Decryption
    }
}

void sha256(const unsigned char *data, size_t len, unsigned char *hash) {
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, data, len);
    SHA256_Final(hash, &sha256);
}

void print_bytes(const unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

int main() {
    unsigned char salt[SALT_SIZE];
    unsigned char key[PASSWORD_SIZE];
    
    const char *password = "strongsecretpassword";
    generate_salt(salt, SALT_SIZE);
    
    printf("Generating key from password...\n");
    derive_key(password, salt, key);
    
    const char *message = "Hello, this is a secret message!";
    size_t message_length = strlen(message);
    
    unsigned char *ciphertext = malloc(message_length);
    unsigned char *decryptedtext = malloc(message_length);
    
    printf("Message: %s\n", message);
    
    printf("Encrypting message...\n");
    encrypt((unsigned char *)message, ciphertext, key, message_length);
    
    printf("Ciphertext: ");
    print_bytes(ciphertext, message_length);
    
    printf("Decrypting message...\n");
    decrypt(ciphertext, decryptedtext, key, message_length);
    
    decryptedtext[message_length] = '\0'; // Null-terminate the decrypted string
    printf("Decrypted text: %s\n", decryptedtext);
    
    unsigned char hash[HASH_SIZE];
    sha256((unsigned char *)message, message_length, hash);
    printf("SHA256 Hash of original message: ");
    print_bytes(hash, HASH_SIZE);
    
    // Cleaning up allocated memory
    free(ciphertext);
    free(decryptedtext);

    return 0;
}