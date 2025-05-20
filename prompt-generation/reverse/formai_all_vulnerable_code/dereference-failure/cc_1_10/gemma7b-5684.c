//Gemma-7B DATASET v1.0 Category: Password Strength Checker ; Style: future-proof
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define MAX_PASSWORD_LENGTH 255
#define PASSWORD_STRENGTH_MINIMUM 5

typedef enum PasswordStrength {
    VERY_WEAK,
    WEAK,
    AVERAGE,
    STRONG,
    VERY_STRONG
} PasswordStrength;

int calculate_password_strength(char *password) {
    int password_length = strlen(password);
    int has_numbers = 0;
    int has_letters = 0;
    int has_symbols = 0;
    int has_repeating_characters = 0;

    for (int i = 0; i < password_length; i++) {
        if (isdigit(password[i])) {
            has_numbers = 1;
        } else if (islower(password[i])) {
            has_letters = 1;
        } else if (isupper(password[i])) {
            has_letters = 1;
        } else if (ispunct(password[i])) {
            has_symbols = 1;
        } else if (password[i] == password[i - 1]) {
            has_repeating_characters = 1;
        }
    }

    int strength = 0;
    if (has_numbers) {
        strength++;
    }
    if (has_letters) {
        strength++;
    }
    if (has_symbols) {
        strength++;
    }
    if (!has_repeating_characters) {
        strength++;
    }

    return strength;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];

    printf("Enter your password: ");
    fgets(password, MAX_PASSWORD_LENGTH, stdin);

    PasswordStrength strength = calculate_password_strength(password);

    switch (strength) {
        case VERY_WEAK:
            printf("Your password is very weak.\n");
            break;
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case AVERAGE:
            printf("Your password is average.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }

    return 0;
}