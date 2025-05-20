//Falcon2-11B DATASET v1.0 Category: Cryptographic hash function ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <openssl/sha.h>
#include <openssl/err.h>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/crypto.h>
#include <openssl/pem.h>

void generate_random_salt(unsigned char *salt, int salt_length) {
    int i;
    unsigned char *p;
    unsigned int j;
    for (i = 0; i < salt_length; i++) {
        salt[i] = (unsigned char) (rand() % 256);
    }
}

void generate_hash(unsigned char *hash, const unsigned char *password, int password_length, unsigned char *salt, int salt_length) {
    EVP_MD_CTX *context;
    unsigned char *pwd;
    unsigned char *salt_str;
    unsigned char *pwd_str;
    unsigned char *result;
    int result_length;
    int i;
    int j;
    int k;
    EVP_MD_CTX_init(&context);
    pwd = (unsigned char *) password;
    salt_str = (unsigned char *) salt;
    pwd_str = (unsigned char *) password;
    for (i = 0; i < salt_length; i++) {
        pwd_str[i] = salt_str[i];
    }
    for (i = 0; i < password_length; i++) {
        pwd_str[i + salt_length] = pwd[i];
    }
    pwd_str[i + salt_length] = '\0';
    result_length = EVP_MD_size(EVP_get_digestbyname("SHA256"));
    result = (unsigned char *) malloc(result_length);
    EVP_DigestInit_ex(&context, EVP_sha256(), NULL);
    EVP_DigestUpdate(&context, (const void *) pwd_str, strlen(pwd_str));
    EVP_DigestFinal_ex(&context, result, &result_length);
    for (j = 0; j < salt_length; j++) {
        printf("%02x", salt[j]);
    }
    printf("-");
    for (j = 0; j < result_length; j++) {
        printf("%02x", result[j]);
    }
    printf("\n");
}

int main() {
    unsigned char salt[16];
    unsigned char password[64];
    unsigned char hash[EVP_MAX_MD_SIZE];
    int i;
    int salt_length = sizeof(salt);
    int password_length = sizeof(password);
    generate_random_salt(salt, salt_length);
    for (i = 0; i < password_length; i++) {
        password[i] = (unsigned char) (rand() % 256);
    }
    generate_hash(hash, password, password_length, salt, salt_length);
    printf("Generated Hash: ");
    for (i = 0; i < EVP_MAX_MD_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}