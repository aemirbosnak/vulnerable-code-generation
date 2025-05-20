//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets for the password
#define CHARSET_UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define CHARSET_LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define CHARSET_NUMBERS "0123456789"
#define CHARSET_SYMBOLS "!@#$%^&*()_+-="

// Get the length of a character set
#define CHARSET_LENGTH(charset) (sizeof(charset) - 1)

// Get a random character from a character set
char get_random_char(const char *charset) {
    int index = rand() % CHARSET_LENGTH(charset);
    return charset[index];
}

// Generate a password of a given length
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Initialize the password to all zeroes
    memset(password, 0, length + 1);

    // Generate the password
    for (int i = 0; i < length; i++) {
        // Get a random character from each character set
        char upper = get_random_char(CHARSET_UPPERCASE);
        char lower = get_random_char(CHARSET_LOWERCASE);
        char number = get_random_char(CHARSET_NUMBERS);
        char symbol = get_random_char(CHARSET_SYMBOLS);

        // Choose a random character from the four options
        int choice = rand() % 4;
        switch (choice) {
            case 0:
                password[i] = upper;
                break;
            case 1:
                password[i] = lower;
                break;
            case 2:
                password[i] = number;
                break;
            case 3:
                password[i] = symbol;
                break;
        }
    }

    // Return the password
    return password;
}

// Get the user's input
int main() {
    // Get the desired password length
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate the password
    char *password = generate_password(length);

    // Print the password
    printf("Generated password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}