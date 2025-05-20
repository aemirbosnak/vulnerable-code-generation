//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the minimum and maximum password lengths
#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Define the character sets used in password generation
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_DIGITS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()-_=+[]{};:,<.>/?`~"

// Define the strength levels for passwords
enum PasswordStrength {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
};

// Function to check the strength of a password
enum PasswordStrength check_password_strength(const char *password) {
    int length = strlen(password);
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_symbol = 0;

    // Check the length of the password
    if (length < MIN_PASSWORD_LENGTH) {
        return WEAK;
    } else if (length > MAX_PASSWORD_LENGTH) {
        return VERY_STRONG;
    }

    // Check for lowercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
            break;
        }
    }

    // Check for uppercase characters
    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
            break;
        }
    }

    // Check for digits
    for (int i = 0; i < length; i++) {
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
            break;
        }
    }

    // Check for symbols
    for (int i = 0; i < length; i++) {
        if (strchr(CHARSET_SYMBOLS, password[i]) != NULL) {
            has_symbol = 1;
            break;
        }
    }

    // Determine the strength of the password
    if (has_lowercase && has_uppercase && has_digit && has_symbol) {
        return VERY_STRONG;
    } else if (has_lowercase && has_uppercase && has_digit) {
        return STRONG;
    } else if (has_lowercase && has_uppercase) {
        return MEDIUM;
    } else {
        return WEAK;
    }
}

// Function to generate a random password of a given length
char *generate_random_password(int length) {
    char *password = malloc(length + 1);

    for (int i = 0; i < length; i++) {
        int charset_index = rand() % (strlen(CHARSET_LOWERCASE) + strlen(CHARSET_UPPERCASE) + strlen(CHARSET_DIGITS) + strlen(CHARSET_SYMBOLS));

        if (charset_index < strlen(CHARSET_LOWERCASE)) {
            password[i] = CHARSET_LOWERCASE[rand() % strlen(CHARSET_LOWERCASE)];
        } else if (charset_index < strlen(CHARSET_LOWERCASE) + strlen(CHARSET_UPPERCASE)) {
            password[i] = CHARSET_UPPERCASE[rand() % strlen(CHARSET_UPPERCASE)];
        } else if (charset_index < strlen(CHARSET_LOWERCASE) + strlen(CHARSET_UPPERCASE) + strlen(CHARSET_DIGITS)) {
            password[i] = CHARSET_DIGITS[rand() % strlen(CHARSET_DIGITS)];
        } else {
            password[i] = CHARSET_SYMBOLS[rand() % strlen(CHARSET_SYMBOLS)];
        }
    }

    password[length] = '\0';

    return password;
}

// Function to get a password from the user
char *get_password() {
    char *password = NULL;
    size_t len = 0;

    // Get the password from the user
    printf("Enter your password: ");
    getline(&password, &len, stdin);

    // Remove the newline character from the password
    password[strcspn(password, "\n")] = '\0';

    return password;
}

// Function to print the strength of a password
void print_password_strength(enum PasswordStrength strength) {
    switch (strength) {
        case WEAK:
            printf("Your password is weak.\n");
            break;
        case MEDIUM:
            printf("Your password is medium.\n");
            break;
        case STRONG:
            printf("Your password is strong.\n");
            break;
        case VERY_STRONG:
            printf("Your password is very strong.\n");
            break;
    }
}

// Main function
int main() {
    // Get the password from the user
    char *password = get_password();

    // Check the strength of the password
    enum PasswordStrength strength = check_password_strength(password);

    // Print the strength of the password
    print_password_strength(strength);

    // Free the memory allocated for the password
    free(password);

    return 0;
}