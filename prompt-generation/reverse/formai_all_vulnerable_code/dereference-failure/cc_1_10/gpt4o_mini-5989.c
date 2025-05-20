//GPT-4o-mini DATASET v1.0 Category: Password Strength Checker ; Style: distributed
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to check password length
int check_length(const char *password) {
    return strlen(password) >= 8; // At least 8 characters
}

// Function to check for at least one uppercase letter
int check_uppercase(const char *password) {
    while (*password) {
        if (isupper((unsigned char)*password)) {
            return 1; // Uppercase letter found
        }
        password++;
    }
    return 0; // No uppercase letter found
}

// Function to check for at least one lowercase letter
int check_lowercase(const char *password) {
    while (*password) {
        if (islower((unsigned char)*password)) {
            return 1; // Lowercase letter found
        }
        password++;
    }
    return 0; // No lowercase letter found
}

// Function to check for at least one digit
int check_digit(const char *password) {
    while (*password) {
        if (isdigit((unsigned char)*password)) {
            return 1; // Digit found
        }
        password++;
    }
    return 0; // No digit found
}

// Function to check for special characters
int check_special_char(const char *password) {
    while (*password) {
        if (ispunct((unsigned char)*password)) {
            return 1; // Special character found
        }
        password++;
    }
    return 0; // No special character found
}

// Function to calculate and print password strength
void assess_password_strength(const char *password) {
    int length_check = check_length(password);
    int uppercase_check = check_uppercase(password);
    int lowercase_check = check_lowercase(password);
    int digit_check = check_digit(password);
    int special_check = check_special_char(password);

    int strength_score = length_check + uppercase_check + lowercase_check + digit_check + special_check;

    printf("Password strength assessment:\n");
    printf("Length (>=8): %s\n", length_check ? "Valid" : "Invalid");
    printf("Uppercase letter: %s\n", uppercase_check ? "Valid" : "Invalid");
    printf("Lowercase letter: %s\n", lowercase_check ? "Valid" : "Invalid");
    printf("Digit: %s\n", digit_check ? "Valid" : "Invalid");
    printf("Special character: %s\n", special_check ? "Valid" : "Invalid");

    if (strength_score == 5) {
        printf("Password is Strong\n");
    } else if (strength_score >= 3) {
        printf("Password is Medium\n");
    } else {
        printf("Password is Weak\n");
    }
}

int main() {
    char password[100];

    printf("Enter a password to check its strength: ");
    scanf("%99s", password); // Limit input to prevent buffer overflow

    assess_password_strength(password);

    return 0;
}