//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MIN_LENGTH 8
#define MIN_DIGITS 2
#define MIN_SPECIAL_CHARS 1

bool contains_digit(char c) {
    return isdigit(c);
}

bool contains_special_char(char c) {
    return (strchr("!@#$%^&*()_+-=[]{}|;:,.<>/?", c) != NULL);
}

bool strong_password(char *password) {
    int length = strlen(password);
    int digits_count = 0;
    int special_chars_count = 0;
    int lowercase_letters_count = 0;
    int uppercase_letters_count = 0;

    if (length < MIN_LENGTH) {
        printf("Your password is too short. It should have at least %d characters.\n", MIN_LENGTH);
        return false;
    }

    for (int i = 0; password[i] != '\0'; ++i) {
        if (isdigit(password[i])) {
            digits_count++;
        } else if (isalpha(password[i])) {
            if (islower(password[i])) {
                lowercase_letters_count++;
            } else {
                uppercase_letters_count++;
            }
        } else if (contains_special_char(password[i])) {
            special_chars_count++;
        }
    }

    if (digits_count < MIN_DIGITS) {
        printf("Your password should contain at least %d digits.\n", MIN_DIGITS);
        return false;
    }

    if (special_chars_count < MIN_SPECIAL_CHARS) {
        printf("Your password should contain at least %d special characters.\n", MIN_SPECIAL_CHARS);
        return false;
    }

    if (lowercase_letters_count == 0) {
        printf("Your password should contain at least one lowercase letter.\n");
        return false;
    }

    if (uppercase_letters_count == 0) {
        printf("Your password should contain at least one uppercase letter.\n");
        return false;
    }

    printf("Your password is strong and romantic! %s\n", password);
    return true;
}

int main(int argc, char **argv) {
    char password[1024];

    if (argc != 2) {
        printf("Usage: %s <password>\n", argv[0]);
        return 1;
    }

    strcpy(password, argv[1]);

    if (!strong_password(password)) {
        return 1;
    }

    return 0;
}