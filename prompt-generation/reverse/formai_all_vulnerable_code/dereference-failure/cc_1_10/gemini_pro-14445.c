//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the character sets to use for password generation.
const char lowercase_chars[] = "abcdefghijklmnopqrstuvwxyz";
const char uppercase_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char digit_chars[] = "0123456789";
const char special_chars[] = "!@#$%^&*()";

// Define the password length.
#define PASSWORD_LENGTH 16

// Function to generate a random number between 0 and max.
int rand_int(int max) {
    return rand() % (max + 1);
}

// Function to generate a random character from a character set.
char rand_char(const char *charset) {
    return charset[rand_int(strlen(charset) - 1)];
}

// Function to generate a random password.
char *generate_password() {
    // Allocate memory for the password.
    char *password = malloc(PASSWORD_LENGTH + 1);

    // Initialize the password to all zeros.
    memset(password, 0, PASSWORD_LENGTH + 1);

    // Generate a random password.
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        // Choose a random character set to use.
        int charset_index = rand_int(3);
        const char *charset;
        switch (charset_index) {
            case 0:
                charset = lowercase_chars;
                break;
            case 1:
                charset = uppercase_chars;
                break;
            case 2:
                charset = digit_chars;
                break;
            case 3:
                charset = special_chars;
                break;
        }

        // Generate a random character from the chosen character set.
        password[i] = rand_char(charset);
    }

    // Return the password.
    return password;
}

// Main function.
int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Generate a random password.
    char *password = generate_password();

    // Print the password to the console.
    printf("Generated password: %s\n", password);

    // Free the memory allocated for the password.
    free(password);

    return 0;
}