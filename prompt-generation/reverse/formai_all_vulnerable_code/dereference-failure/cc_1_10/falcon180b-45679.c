//Falcon-180B DATASET v1.0 Category: Password management ; Style: decentralized
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <openssl/sha.h>

#define HASH_SIZE 64
#define SALT_SIZE 16

struct password {
    char *username;
    char *password;
    char salt[SALT_SIZE];
};

void generate_salt(char *salt) {
    int i;
    for (i = 0; i < SALT_SIZE; i++) {
        salt[i] = rand() % 26 + 'a';
    }
    salt[SALT_SIZE - 1] = '\0';
}

void hash_password(char *password, char *salt, char *hash) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, password, strlen(password));
    SHA256_Update(&ctx, salt, SALT_SIZE);
    SHA256_Final(hash, &ctx);
}

void print_password(struct password *p) {
    printf("Username: %s\n", p->username);
    printf("Password: %s\n", p->password);
    printf("Salt: %s\n", p->salt);
}

int main() {
    int num_passwords = 5;
    struct password passwords[num_passwords];

    srand(time(NULL));

    int i;
    for (i = 0; i < num_passwords; i++) {
        char *username = malloc(10 * sizeof(char));
        sprintf(username, "user%d", i);

        char *password = malloc(10 * sizeof(char));
        sprintf(password, "password%d", i);

        char salt[SALT_SIZE];
        generate_salt(salt);

        hash_password(password, salt, passwords[i].salt);
        passwords[i].username = username;
        passwords[i].password = password;
    }

    printf("Passwords:\n");
    int j;
    for (j = 0; j < num_passwords; j++) {
        print_password(&passwords[j]);
    }

    return 0;
}