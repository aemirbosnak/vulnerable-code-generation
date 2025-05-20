//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mman.h>

#define PASSWORD_MAX_LENGTH 64
#define SALT_MAX_LENGTH 32

typedef struct {
    char *password;
    char *salt;
} password_t;

void password_init(password_t *pwd) {
    pwd->password = malloc(PASSWORD_MAX_LENGTH);
    pwd->salt = malloc(SALT_MAX_LENGTH);
}

void password_set(password_t *pwd, const char *password, const char *salt) {
    size_t password_len = strlen(password);
    size_t salt_len = strlen(salt);

    if (password_len > PASSWORD_MAX_LENGTH) {
        fprintf(stderr, "Password too long (max %zu characters)\n", PASSWORD_MAX_LENGTH);
        exit(EXIT_FAILURE);
    }

    if (salt_len > SALT_MAX_LENGTH) {
        fprintf(stderr, "Salt too long (max %zu characters)\n", SALT_MAX_LENGTH);
        exit(EXIT_FAILURE);
    }

    pwd->password = realloc(pwd->password, password_len + 1);
    pwd->salt = realloc(pwd->salt, salt_len + 1);

    strcpy(pwd->password, password);
    strcpy(pwd->salt, salt);
}

void password_check(password_t *pwd, const char *input) {
    size_t password_len = strlen(pwd->password);
    size_t input_len = strlen(input);

    if (password_len != input_len) {
        fprintf(stderr, "Incorrect password length\n");
        exit(EXIT_FAILURE);
    }

    if (strcmp(pwd->password, input) != 0) {
        fprintf(stderr, "Incorrect password\n");
        exit(EXIT_FAILURE);
    }
}

int main() {
    password_t pwd;

    password_init(&pwd);

    char *password = "my_secret_password";
    char *salt = "my_salt";

    password_set(&pwd, password, salt);

    char *input = "my_secret_password";

    password_check(&pwd, input);

    return 0;
}