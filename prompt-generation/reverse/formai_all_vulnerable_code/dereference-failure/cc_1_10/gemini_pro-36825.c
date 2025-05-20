//GEMINI-pro DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <openssl/rand.h>
#include <openssl/err.h>

#define SALT_SIZE 8
#define PWD_MAX_SIZE 64

typedef struct {
    char salt[SALT_SIZE];
    char hash[SHA256_DIGEST_LENGTH];
} passwd_t;

static void generate_salt(char *salt) {
    RAND_bytes((unsigned char *)salt, SALT_SIZE);
}

static void hash_pwd(const char *pwd, const char *salt, passwd_t *out) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char combined[SALT_SIZE + PWD_MAX_SIZE];
    memcpy(combined, salt, SALT_SIZE);
    memcpy(combined + SALT_SIZE, pwd, strlen(pwd));

    SHA256((unsigned char *)combined, strlen(combined), (unsigned char *)hash);
    memcpy(out->salt, salt, SALT_SIZE);
    memcpy(out->hash, hash, SHA256_DIGEST_LENGTH);
}

static int compare_pwd(const char *pwd, const passwd_t *stored) {
    passwd_t new_pwd;
    hash_pwd(pwd, stored->salt, &new_pwd);
    return memcmp(stored->hash, new_pwd.hash, SHA256_DIGEST_LENGTH) == 0;
}

int main(int argc, char **argv) {
    char pwd[PWD_MAX_SIZE];
    char stored_pwd[PWD_MAX_SIZE + SALT_SIZE + SHA256_DIGEST_LENGTH * 2];
    int store = 0;

    if (argc < 2 || (argc % 2) != 0) {
        fprintf(stderr, "Usage: %s [-s] username password [username password ...]\n", argv[0]);
        exit(1);
    }

    if (strcmp(argv[1], "-s") == 0) {
        store = 1;
        argv++;
        argc--;
    }

    for (int i = 1; i < argc; i += 2) {
        if (store) {
            passwd_t new_pwd;
            generate_salt(new_pwd.salt);
            hash_pwd(argv[i + 1], new_pwd.salt, &new_pwd);
            printf("%s:%s\n", argv[i], new_pwd);
        } else {
            int success = compare_pwd(argv[i + 1], (passwd_t *)argv[i]);
            printf("%s:%s\n", argv[i], success ? "OK" : "FAIL");
        }
    }

    return 0;
}