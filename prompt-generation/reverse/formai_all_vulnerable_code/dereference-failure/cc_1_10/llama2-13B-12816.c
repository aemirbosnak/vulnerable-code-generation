//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: secure
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 64
#define SALT_LENGTH 16

typedef struct {
    char *password;
    char *salt;
} password_t;

void generate_password(password_t *pwd) {
    int i, j;
    char c;

    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        c = 'a' + (rand() % 26);
        pwd->password[i] = c;
    }

    for (j = 0; j < SALT_LENGTH; j++) {
        c = 'a' + (rand() % 26);
        pwd->salt[j] = c;
    }
}

int verify_password(password_t *pwd, char *input) {
    int i, j;
    int mismatch = 0;

    for (i = 0; i < PASSWORD_MAX_LENGTH; i++) {
        if (pwd->password[i] != input[i]) {
            mismatch++;
        }
    }

    for (j = 0; j < SALT_LENGTH; j++) {
        if (pwd->salt[j] != input[i + j]) {
            mismatch++;
        }
    }

    return mismatch;
}

int main() {
    password_t *pwd = malloc(sizeof(password_t));
    generate_password(pwd);

    char *input = malloc(PASSWORD_MAX_LENGTH + SALT_LENGTH);
    printf("Enter password: ");
    fgets(input, PASSWORD_MAX_LENGTH + SALT_LENGTH, stdin);

    int mismatch = verify_password(pwd, input);
    if (mismatch == 0) {
        printf("Password correct!\n");
    } else {
        printf("Password incorrect, try again.\n");
    }

    free(pwd);
    free(input);

    return 0;
}