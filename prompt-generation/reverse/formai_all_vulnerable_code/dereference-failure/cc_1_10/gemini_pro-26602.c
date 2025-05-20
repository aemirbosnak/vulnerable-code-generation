//GEMINI-pro DATASET v1.0 Category: Password management ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crypt.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/err.h>

#define SALT_SIZE 8
#define KEY_SIZE 16
#define BUF_SIZE 512

int main(int argc, char *argv[])
{
    char pass[BUF_SIZE];
    char salt[SALT_SIZE];
    char key[KEY_SIZE];
    char buf[BUF_SIZE];
    int len;

    // Generate a random salt
    if (RAND_bytes(salt, SALT_SIZE) != 1) {
        fprintf(stderr, "Error generating salt\n");
        return EXIT_FAILURE;
    }

    // Encrypt the password
    len = EVP_BytesToKey(EVP_aes_128_cbc(), EVP_sha1(), salt, pass, strlen(pass), 1, key, NULL);
    if (len != KEY_SIZE) {
        fprintf(stderr, "Error encrypting password\n");
        return EXIT_FAILURE;
    }

    // Store the salt and encrypted password
    FILE *fp = fopen("passwords.txt", "w");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        return EXIT_FAILURE;
    }
    fwrite(salt, SALT_SIZE, 1, fp);
    fwrite(key, KEY_SIZE, 1, fp);
    fclose(fp);

    // Decrypt the password
    len = EVP_BytesToKey(EVP_aes_128_cbc(), EVP_sha1(), salt, key, KEY_SIZE, 1, pass, NULL);
    if (len != strlen(pass)) {
        fprintf(stderr, "Error decrypting password\n");
        return EXIT_FAILURE;
    }

    // Print the decrypted password
    printf("Decrypted password: %s\n", pass);

    return EXIT_SUCCESS;
}