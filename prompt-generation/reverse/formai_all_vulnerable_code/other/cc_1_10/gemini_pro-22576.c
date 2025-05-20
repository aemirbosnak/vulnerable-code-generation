//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 64

// Function to generate a random character
char generate_random_character(void) {
    int random_number = rand() % 94 + 33;
    return (char)random_number;
}

// Function to generate a random string of a given length
char *generate_random_string(int length) {
    char *random_string = malloc(length + 1);
    assert(random_string != NULL);

    for (int i = 0; i < length; i++) {
        random_string[i] = generate_random_character();
    }

    random_string[length] = '\0';

    return random_string;
}

// Function to generate a secure password
char *generate_secure_password(int length) {
    assert(length >= MIN_LENGTH && length <= MAX_LENGTH);

    char *password = generate_random_string(length);

    // Check if the password contains at least one uppercase letter, one lowercase letter, one digit, and one special character
    int has_uppercase = 0;
    int has_lowercase = 0;
    int has_digit = 0;
    int has_special_character = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            has_uppercase = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            has_lowercase = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            has_digit = 1;
        } else {
            has_special_character = 1;
        }
    }

    // If the password does not meet the requirements, generate a new password
    while (!has_uppercase || !has_lowercase || !has_digit || !has_special_character) {
        free(password);
        password = generate_random_string(length);

        has_uppercase = 0;
        has_lowercase = 0;
        has_digit = 0;
        has_special_character = 0;

        for (int i = 0; i < length; i++) {
            if (password[i] >= 'A' && password[i] <= 'Z') {
                has_uppercase = 1;
            } else if (password[i] >= 'a' && password[i] <= 'z') {
                has_lowercase = 1;
            } else if (password[i] >= '0' && password[i] <= '9') {
                has_digit = 1;
            } else {
                has_special_character = 1;
            }
        }
    }

    return password;
}

int main(void) {
    // Seed the random number generator
    srand(time(NULL));

    // Get the length of the password from the user
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Generate a secure password
    char *password = generate_secure_password(length);

    // Print the password
    printf("Your password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}