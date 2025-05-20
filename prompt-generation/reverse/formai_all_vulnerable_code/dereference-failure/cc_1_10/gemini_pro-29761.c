//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

#define PASSWORD_LENGTH 16

// Function to generate a random character
char generate_random_character() {
    int random_number = rand() % 94 + 33;
    return (char) random_number;
}

// Function to generate a random password
char *generate_random_password() {
    char *password = malloc(PASSWORD_LENGTH + 1);
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generate_random_character();
    }
    password[PASSWORD_LENGTH] = '\0';
    return password;
}

// Function to check if a password is strong
bool is_password_strong(char *password) {
    int has_lowercase = 0;
    int has_uppercase = 0;
    int has_digit = 0;
    int has_symbol = 0;

    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        }
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        }
        if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        }
        if (password[i] >= 33 && password[i] <= 47) {
            has_symbol = 1;
        }
    }
    return (has_lowercase && has_uppercase && has_digit && has_symbol);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_random_password();

    // Check if the password is strong
    bool is_strong = is_password_strong(password);

    // Print the password
    printf("Generated Password: %s\n", password);

    // Print whether the password is strong or not
    if (is_strong) {
        printf("The password is strong.\n");
    } else {
        printf("The password is not strong.\n");
    }

    // Free the allocated memory
    free(password);

    return 0;
}