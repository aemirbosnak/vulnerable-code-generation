//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Password strength levels
#define WEAK 0
#define MODERATE 1
#define STRONG 2

// Function prototypes
int passwordStrength(char* password);
int hasLowerCase(char* password);
int hasUpperCase(char* password);
int hasDigit(char* password);
int hasSpecialChar(char* password);

int main() {
    char password[50];

    // Get the password from the user
    printf("Enter a password: ");
    fgets(password, 50, stdin);

    // Remove the newline character at the end of the password
    password[strcspn(password, "\n")] = 0;

    // Check the strength of the password and print the result
    int strength = passwordStrength(password);
    switch (strength) {
        case WEAK:
            printf("Weak password\n");
            break;
        case MODERATE:
            printf("Moderate password\n");
            break;
        case STRONG:
            printf("Strong password\n");
            break;
        default:
            printf("Invalid password strength\n");
    }

    return 0;
}

/*
 * Determines the strength of a password.
 * Returns 0 for weak, 1 for moderate, and 2 for strong passwords.
 */
int passwordStrength(char* password) {
    int length = strlen(password);
    int strength = WEAK;

    // Check if the password is long enough
    if (length >= 8) {
        strength = MODERATE;
    }

    // Check if the password has mixed case letters
    if (hasLowerCase(password) && hasUpperCase(password)) {
        strength = STRONG;
    }

    // Check if the password has digits
    if (hasDigit(password)) {
        strength = STRONG;
    }

    // Check if the password has special characters
    if (hasSpecialChar(password)) {
        strength = STRONG;
    }

    return strength;
}

/*
 * Determines if a password contains at least one lowercase letter.
 * Returns 1 if it does, and 0 otherwise.
 */
int hasLowerCase(char* password) {
    int i, length = strlen(password);
    for (i = 0; i < length; i++) {
        if (islower(password[i])) {
            return 1;
        }
    }
    return 0;
}

/*
 * Determines if a password contains at least one uppercase letter.
 * Returns 1 if it does, and 0 otherwise.
 */
int hasUpperCase(char* password) {
    int i, length = strlen(password);
    for (i = 0; i < length; i++) {
        if (isupper(password[i])) {
            return 1;
        }
    }
    return 0;
}

/*
 * Determines if a password contains at least one digit.
 * Returns 1 if it does, and 0 otherwise.
 */
int hasDigit(char* password) {
    int i, length = strlen(password);
    for (i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            return 1;
        }
    }
    return 0;
}

/*
 * Determines if a password contains at least one special character.
 * Returns 1 if it does, and 0 otherwise.
 */
int hasSpecialChar(char* password) {
    int i, length = strlen(password);
    char specialChars[] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '{', '}', '[', ']', '|', '\\', ':', ';', '"', '\'', '<', '>', ',', '.', '?', '/'};
    for (i = 0; i < length; i++) {
        if (strchr(specialChars, password[i]) != NULL) {
            return 1;
        }
    }
    return 0;
}