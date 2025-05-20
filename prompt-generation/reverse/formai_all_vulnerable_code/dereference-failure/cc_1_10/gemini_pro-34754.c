//GEMINI-pro DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/err.h>

// Function to generate a password hash using SHA256
int generate_password_hash(const char *password, unsigned char *hash) {
    const EVP_MD *md = EVP_sha256();
    EVP_MD_CTX *ctx = EVP_MD_CTX_new();
    if (EVP_DigestInit_ex(ctx, md, NULL) != 1) {
        EVP_MD_CTX_free(ctx);
        return -1;
    }
    if (EVP_DigestUpdate(ctx, password, strlen(password)) != 1) {
        EVP_MD_CTX_free(ctx);
        return -1;
    }
    if (EVP_DigestFinal_ex(ctx, hash, NULL) != 1) {
        EVP_MD_CTX_free(ctx);
        return -1;
    }
    EVP_MD_CTX_free(ctx);
    return 0;
}

// Function to generate a random salt
int generate_salt(unsigned char *salt) {
    if (!RAND_bytes(salt, sizeof(salt))) {
        return -1;
    }
    return 0;
}

// Function to combine a password hash and salt
int combine_password_hash_and_salt(const unsigned char *hash, const unsigned char *salt, unsigned char *combined) {
    memcpy(combined, hash, sizeof(hash));
    memcpy(combined + sizeof(hash), salt, sizeof(salt));
    return 0;
}

// Function to verify a password against a hash
int verify_password(const char *password, const unsigned char *hash, const unsigned char *salt) {
    unsigned char combined[sizeof(hash) + sizeof(salt)];
    combine_password_hash_and_salt(hash, salt, combined);
    unsigned char new_hash[sizeof(hash)];
    generate_password_hash(password, new_hash);
    return memcmp(new_hash, combined, sizeof(hash) + sizeof(salt)) == 0;
}

int main() {
    // Initialize the OpenSSL library
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();

    // Define the password and salt
    const char *password = "password123";
    unsigned char salt[32];
    generate_salt(salt);

    // Generate the password hash
    unsigned char hash[32];
    generate_password_hash(password, hash);

    // Combine the password hash and salt
    unsigned char combined[sizeof(hash) + sizeof(salt)];
    combine_password_hash_and_salt(hash, salt, combined);

    // Store the combined password hash and salt in a secure place
    // ...

    // Later, when the user enters their password again
    printf("Password: ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    // Verify the password against the hash
    int verified = verify_password(input, hash, salt);
    if (verified) {
        printf("Password is correct\n");
    } else {
        printf("Password is incorrect\n");
    }

    // Clean up the OpenSSL library
    EVP_cleanup();
    ERR_free_strings();

    return 0;
}