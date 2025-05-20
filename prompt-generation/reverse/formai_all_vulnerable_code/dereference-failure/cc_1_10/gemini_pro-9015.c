//GEMINI-pro DATASET v1.0 Category: Password management ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_PASSWORDS 10
#define MAX_PASSWORD_LEN 128

typedef struct {
    char password[MAX_PASSWORD_LEN];
    char salt[16];
} password_t;

password_t passwords[MAX_PASSWORDS];
int num_passwords = 0;

void add_password(char *password, char *salt) {
    if (num_passwords >= MAX_PASSWORDS) {
        fprintf(stderr, "Error: too many passwords\n");
        exit(1);
    }

    strcpy(passwords[num_passwords].password, password);
    strcpy(passwords[num_passwords].salt, salt);
    num_passwords++;
}

int verify_password(char *password, char *salt) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char hashed_password[SHA256_DIGEST_LENGTH * 2 + 1];
    int i;

    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password, strlen(password));
    SHA256_Update(&ctx, salt, strlen(salt));
    SHA256_Final(hash, &ctx);

    for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashed_password + i * 2, "%02x", hash[i]);
    }

    return strcmp(hashed_password, password) == 0;
}

int main(int argc, char *argv[]) {
    char password[MAX_PASSWORD_LEN];
    char salt[16];
    int i;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <password>\n", argv[0]);
        exit(1);
    }

    strcpy(password, argv[1]);

    // Generate a random salt
    for (i = 0; i < 16; i++) {
        salt[i] = rand() % 256;
    }

    // Add the password to the list of passwords
    add_password(password, salt);

    // Verify the password
    if (verify_password(password, salt)) {
        printf("Password is correct\n");
    } else {
        printf("Password is incorrect\n");
    }

    return 0;
}