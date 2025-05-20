//LLAMA2-13B DATASET v1.0 Category: Password management ; Style: detailed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_MAX_LENGTH 20
#define HASH_LENGTH 32

typedef struct {
    char *password;
    char *hash;
} password_t;

void init_password(password_t *password) {
    password->password = NULL;
    password->hash = NULL;
}

void set_password(password_t *password, const char *new_password) {
    char hash[HASH_LENGTH];
    int i;

    // Generate a hash for the new password
    for (i = 0; i < HASH_LENGTH; i++) {
        hash[i] = new_password[i] ^ (i % 2 == 0 ? 'a' : 'A');
    }

    // Free any existing password and hash
    free(password->password);
    free(password->hash);

    // Set the new password and hash
    password->password = new_password;
    password->hash = hash;
}

int verify_password(password_t *password, const char *entered_password) {
    int i;

    // Compare the entered password with the stored password
    for (i = 0; i < strlen(password->password); i++) {
        if (password->password[i] != entered_password[i]) {
            return 0;
        }
    }

    // Check if the entered password matches the stored hash
    for (i = 0; i < HASH_LENGTH; i++) {
        if (password->hash[i] != entered_password[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    password_t password;
    char entered_password[PASSWORD_MAX_LENGTH];

    // Initialize the password
    init_password(&password);

    // Set the password and verify it
    set_password(&password, "HelloWorld!");
    if (!verify_password(&password, "HelloWorld!")) {
        printf("Incorrect password\n");
        return 1;
    }

    // Set a new password and verify it
    set_password(&password, "SecretPassword");
    if (!verify_password(&password, "SecretPassword")) {
        printf("Incorrect password\n");
        return 1;
    }

    // Test the password with some variations
    entered_password[0] = 'H';
    if (!verify_password(&password, entered_password)) {
        printf("Incorrect password (case-sensitive)\n");
        return 1;
    }

    entered_password[0] = 'S';
    if (!verify_password(&password, entered_password)) {
        printf("Incorrect password (case-insensitive)\n");
        return 1;
    }

    // Free the password and hash
    free(password.password);
    free(password.hash);

    return 0;
}