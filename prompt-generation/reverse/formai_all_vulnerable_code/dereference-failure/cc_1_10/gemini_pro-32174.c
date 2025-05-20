//GEMINI-pro DATASET v1.0 Category: Password Strength Checker ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Declare the strength levels
typedef enum {
    WEAK,
    MEDIUM,
    STRONG,
    VERY_STRONG
} strength_level;

// Function to check the strength of a password
strength_level check_password_strength(char *password) {
    // Length of the password
    int length = strlen(password);

    // Strength level of the password
    strength_level strength = WEAK;

    // Check if the length of the password is greater than 15 characters
    if (length > 5) {
        strength = MEDIUM;
    }

    // Check if the password contains at least one uppercase letter
    int has_uppercase = 0;
    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) {
            has_uppercase = 1;
            break;
        }
    }

    // Check if the password contains at least one lowercase letter
    int has_lowercase = 0;
    for (int i = 0; i < length; i++) {
        if (islower(password[i])) {
            has_lowercase = 1;
            break;
        }
    }

    // Check if the password contains at least one digit
    int has_digit = 0;
    for (int i = 0; i < length; i++) {
        if (isdigit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check if the password contains at least one special character
    int has_special = 0;
    for (int i = 0; i < length; i++) {
        if (!isalnum(password[i])) {
            has_special = 1;
            break;
        }
    }

    // Check if the password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
    if (has_uppercase && has_lowercase && has_digit && has_special) {
        strength = VERY_STRONG;
    }

    // Return the strength level of the password
    return strength;
}

// Function to get the password from the user
char *get_password() {
    // Allocate memory for the password
    char *password = malloc(100);

    // Get the password from the user
    printf("Enter your password: ");
    scanf("%s", password);

    // Return the password
    return password;
}

// Function to print the strength level of the password
void print_password_strength(strength_level strength) {
    // Print the strength level of the password
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
    strength_level strength = check_password_strength(password);

    // Print the strength level of the password
    print_password_strength(strength);

    // Free the memory allocated for the password
    free(password);

    return 0;
}