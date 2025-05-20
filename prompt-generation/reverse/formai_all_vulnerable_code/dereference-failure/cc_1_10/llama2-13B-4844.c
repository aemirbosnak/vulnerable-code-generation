//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define SALT_LENGTH 10

typedef struct {
    char *password;
    char *salt;
} password_t;

void generate_password(password_t *password) {
    int i, j;
    char c;
    char salt[SALT_LENGTH];

    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        c = 'a' + (rand() % 26);
        password->password[i] = c;
    }

    for (i = 0; i < SALT_LENGTH; i++) {
        c = 'a' + (rand() % 26);
        salt[i] = c;
    }

    password->salt = salt;
}

int check_password(password_t *password, char *input) {
    int i, j;
    char c;

    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        c = password->password[i];
        if (c != input[i]) {
            return 0;
        }
    }

    for (i = 0; i < SALT_LENGTH; i++) {
        c = password->salt[i];
        if (c != input[i + PASSWORD_MAX_LENGTH]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    password_t password;
    generate_password(&password);

    char input[PASSWORD_MAX_LENGTH + SALT_LENGTH];
    printf("Enter your password: ");
    fgets(input, sizeof(input), stdin);

    if (check_password(&password, input)) {
        printf("Password correct!\n");
    } else {
        printf("Password incorrect.\n");
    }

    return 0;
}