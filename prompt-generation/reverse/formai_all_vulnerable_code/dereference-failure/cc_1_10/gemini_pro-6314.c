//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets to use for password generation
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_DIGITS    "0123456789"
#define CHARSET_SYMBOLS   "!@#$%^&*()_+=-"

// Define the length of the password to generate
#define PASSWORD_LENGTH 16

// Function to generate a random character from a given character set
char generate_random_char(const char *charset) {
    return charset[rand() % strlen(charset)];
}

// Function to generate a secure password
char *generate_password() {
    // Allocate memory for the password
    char *password = malloc(PASSWORD_LENGTH + 1);

    // Initialize the password with random characters from each character set
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int charset_index = rand() % 4;
        switch (charset_index) {
            case 0:
                password[i] = generate_random_char(CHARSET_LOWERCASE);
                break;
            case 1:
                password[i] = generate_random_char(CHARSET_UPPERCASE);
                break;
            case 2:
                password[i] = generate_random_char(CHARSET_DIGITS);
                break;
            case 3:
                password[i] = generate_random_char(CHARSET_SYMBOLS);
                break;
        }
    }

    // Terminate the password with a null character
    password[PASSWORD_LENGTH] = '\0';

    // Return the generated password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a secure password
    char *password = generate_password();

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}