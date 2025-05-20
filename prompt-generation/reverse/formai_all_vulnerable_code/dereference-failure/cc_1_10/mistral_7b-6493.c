//MISTRAL-7B DATASET v1.0 Category: Password Strength Checker ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MIN_LENGTH 8
#define MAX_ATTEMPTS 5

// Function to check if a character is an alphanumeric or a special character
int is_valid_char(char c) {
    if (isalnum(c) || (strchr("!@#$%^&*()_+-=[]{}|;:,.<>?", c) != NULL))
        return 1;
    return 0;
}

// Function to check if a password meets the minimum requirements
int check_password_strength(char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    // Check if password length is sufficient
    if (length < MIN_LENGTH) {
        printf("Password is too short.\n");
        return 0;
    }

    // Check if password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
    for (int i = 0; i < length; i++) {
        if (isupper(password[i]))
            has_upper = 1;
        if (islower(password[i]))
            has_lower = 1;
        if (isdigit(password[i]))
            has_digit = 1;
        if (!has_special && is_valid_char(password[i]))
            has_special = 1;
    }

    // If all requirements are met, return 1
    if (has_upper && has_lower && has_digit && has_special)
        return 1;

    // Otherwise, print error message and return 0
    printf("Password does not meet the minimum requirements.\n");
    return 0;
}

int main() {
    char *password;
    int attempts = 0;

    // Allocate memory for password input using malloc()
    password = (char *)malloc(100 * sizeof(char));

    // Get user input for password and check its strength
    while (attempts < MAX_ATTEMPTS && !check_password_strength(password)) {
        printf("Enter a password: ");
        fgets(password, 100, stdin);
        password[strcspn(password, "\n")] = '\0';
        attempts++;
    }

    // If password is strong, print success message and free memory
    if (check_password_strength(password)) {
        printf("Password is strong.\n");
        free(password);
    }

    // If maximum attempts are reached, print failure message and free memory
    else {
        printf("Maximum attempts reached.\n");
        free(password);
    }

    return 0;
}