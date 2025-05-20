//Falcon-180B DATASET v1.0 Category: Password management ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define PASSWORD_LENGTH 16
#define SALT_LENGTH 8
#define ITERATIONS 10000

void generate_salt(char *salt) {
    for (int i = 0; i < SALT_LENGTH; i++) {
        salt[i] = rand() % 26 + 'a';
    }
    salt[SALT_LENGTH] = '\0';
}

void hash_password(char *password, char *salt, char *hash) {
    char *p = (char *) malloc(PASSWORD_LENGTH + SALT_LENGTH + 1);
    strcpy(p, password);
    strcat(p, salt);

    char *hashed_password = (char *) malloc(PASSWORD_LENGTH + 1);
    hashed_password[0] = '\0';

    for (int i = 0; i < ITERATIONS; i++) {
        for (int j = 0; j < PASSWORD_LENGTH + SALT_LENGTH; j++) {
            hashed_password[j] = tolower(p[j]);
        }
    }

    strcpy(hash, hashed_password);
    free(p);
    free(hashed_password);
}

int main() {
    char *password = (char *) malloc(PASSWORD_LENGTH + 1);
    char *salt = (char *) malloc(SALT_LENGTH + 1);
    char *hash = (char *) malloc(PASSWORD_LENGTH + 1);

    generate_salt(salt);

    printf("Enter your password: ");
    scanf("%s", password);

    hash_password(password, salt, hash);

    printf("Your password hash is: %s\n", hash);

    return 0;
}