//Falcon-180B DATASET v1.0 Category: Password management ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 64
#define SALT_LENGTH 16
#define HASH_LENGTH 64

typedef struct {
    char *username;
    char *password;
} User;

void generate_salt(char *salt) {
    for (int i = 0; i < SALT_LENGTH; i++) {
        char c = (rand() % 26) + 'a';
        salt[i] = c;
    }
    salt[SALT_LENGTH] = '\0';
}

void generate_hash(char *password, char *salt, char *hash) {
    int i, j;
    for (i = 0, j = 0; i < strlen(password); i++) {
        char c = tolower(password[i]);
        if (isalpha(c)) {
            hash[j++] = c;
        }
    }
    hash[j] = '\0';

    char *hash_temp = malloc(strlen(hash) + SALT_LENGTH + 1);
    strcpy(hash_temp, hash);
    strcat(hash_temp, salt);

    char *hash_final = malloc(HASH_LENGTH + 1);
    for (i = 0, j = 0; i < strlen(hash_temp); i++) {
        char c = tolower(hash_temp[i]);
        if (isalpha(c)) {
            hash_final[j++] = c;
        }
    }
    hash_final[j] = '\0';

    free(hash_temp);
}

int check_hash(char *password, char *hash) {
    int i;
    for (i = 0; i < strlen(password); i++) {
        if (tolower(password[i])!= hash[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    User *user = malloc(sizeof(User));
    user->username = "example";
    user->password = "password";

    char salt[SALT_LENGTH + 1];
    generate_salt(salt);

    char hash[HASH_LENGTH + 1];
    generate_hash(user->password, salt, hash);

    printf("Username: %s\n", user->username);
    printf("Password: %s\n", user->password);
    printf("Salt: %s\n", salt);
    printf("Hash: %s\n", hash);

    free(user);
    return 0;
}