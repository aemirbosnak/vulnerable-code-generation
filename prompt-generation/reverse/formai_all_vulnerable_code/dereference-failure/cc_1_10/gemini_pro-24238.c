//GEMINI-pro DATASET v1.0 Category: Password management ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORDS 100
#define MAX_PASSWORD_LEN 256
#define SALT_LEN 16

typedef struct {
    char *username;
    char *password;
    char *salt;
} password_entry;

password_entry passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *username, char *password) {
    if (num_passwords >= MAX_PASSWORDS) {
        fprintf(stderr, "Error: password database full\n");
        exit(1);
    }

    passwords[num_passwords].username = strdup(username);
    passwords[num_passwords].password = strdup(password);
    passwords[num_passwords].salt = malloc(SALT_LEN);
    RAND_bytes(passwords[num_passwords].salt, SALT_LEN);
    num_passwords++;
}

int verify_password(char *username, char *password) {
    int i;

    for (i = 0; i < num_passwords; i++) {
        if (strcmp(passwords[i].username, username) == 0) {
            char *hashed_password = malloc(SHA256_DIGEST_LENGTH);
            SHA256_CTX ctx;
            SHA256_Init(&ctx);
            SHA256_Update(&ctx, passwords[i].salt, SALT_LEN);
            SHA256_Update(&ctx, password, strlen(password));
            SHA256_Final((unsigned char *)hashed_password, &ctx);
            if (memcmp(hashed_password, passwords[i].password, SHA256_DIGEST_LENGTH) == 0) {
                free(hashed_password);
                return 1;
            }
            free(hashed_password);
            return 0;
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s username password\n", argv[0]);
        exit(1);
    }

    add_password(argv[1], argv[2]);

    if (verify_password(argv[1], argv[2])) {
        printf("Password verified\n");
    } else {
        printf("Password incorrect\n");
    }

    return 0;
}