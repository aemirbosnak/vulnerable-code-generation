//Falcon-180B DATASET v1.0 Category: Password Strength Checker ; Style: standalone
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 100

// Function to check if a character is a letter
int is_letter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to check if a character is a digit
int is_digit(char c) {
    return c >= '0' && c <= '9';
}

// Function to check if a character is a special character
int is_special_char(char c) {
    return (c >= '!' && c <= '/') || (c >= ':' && c <= '@') || (c >= '[' && c <= '`') || (c >= '{' && c <= '~');
}

// Function to check if a password is strong
int is_strong_password(char* password) {
    int length = strlen(password);
    int has_letter = 0;
    int has_digit = 0;
    int has_special_char = 0;

    // Check if password has at least one letter
    for (int i = 0; i < length; i++) {
        if (is_letter(password[i])) {
            has_letter = 1;
            break;
        }
    }

    // Check if password has at least one digit
    for (int i = 0; i < length; i++) {
        if (is_digit(password[i])) {
            has_digit = 1;
            break;
        }
    }

    // Check if password has at least one special character
    for (int i = 0; i < length; i++) {
        if (is_special_char(password[i])) {
            has_special_char = 1;
            break;
        }
    }

    // Check if password meets all criteria for a strong password
    if (length >= 8 && has_letter && has_digit && has_special_char) {
        return 1;
    } else {
        return 0;
    }
}

// Function to generate a random password
void generate_password(char* password, int length) {
    const char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()_+";
    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % strlen(charset)];
    }
    password[length] = '\0';
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int length;

    // Get desired password length from user
    printf("Enter desired password length (between 8 and %d): ", MAX_PASSWORD_LENGTH - 1);
    scanf("%d", &length);

    // Generate a random password
    generate_password(password, length);

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Check if password is strong
    if (is_strong_password(password)) {
        printf("Password is strong.\n");
    } else {
        printf("Password is weak.\n");
    }

    return 0;
}