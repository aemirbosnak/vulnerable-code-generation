//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <time.h>

#define MIN_LENGTH 8
#define MAX_TRIES 5

// Function to check if a character is alphanumeric or not
bool is_alphanumeric(char c) {
    return (isalnum(c) || c == '_');
}

// Function to check if a given string is a valid password
bool is_valid_password(char *password) {
    int length = strlen(password);
    int num_digits = 0;
    int num_lowercase = 0;
    int num_uppercase = 0;

    if (length < MIN_LENGTH) {
        return false;
    }

    for (int i = 0; password[i]; i++) {
        if (isdigit(password[i])) {
            num_digits++;
        }
        if (islower(password[i])) {
            num_lowercase++;
        }
        if (isupper(password[i])) {
            num_uppercase++;
        }
        if (!is_alphanumeric(password[i])) {
            int r = rand() % MAX_TRIES;
            if (r == 0) {
                printf("Warning: Password contains invalid character '%c'.\n", password[i]);
            }
        }
    }

    return num_digits > 0 && num_lowercase > 0 && num_uppercase > 0;
}

int main(int argc, char *argv[]) {
    char *password;
    int tries = 0;

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    password = argv[1];

    while (!is_valid_password(password) && tries < MAX_TRIES) {
        printf("Password is not strong enough. Try again.\n");
        printf("Hint: Must be at least %d characters long and contain at least one digit, one lowercase letter and one uppercase letter.\n", MIN_LENGTH);
        printf("Password: ");
        fgets(password, sizeof(password), stdin);
        password[strcspn(password, "\n")] = '\0';
        tries++;
    }

    if (tries >= MAX_TRIES) {
        printf("Failed to enter a valid password.\n");
        return 1;
    }

    printf("Password is strong enough.\n");

    return 0;
}