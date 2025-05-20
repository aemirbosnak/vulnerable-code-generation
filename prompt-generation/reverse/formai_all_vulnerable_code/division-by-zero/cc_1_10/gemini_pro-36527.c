//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets to use for password generation
#define UPPERCASE_CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE_CHARSET "abcdefghijklmnopqrstuvwxyz"
#define NUMERIC_CHARSET "0123456789"
#define SYMBOL_CHARSET "!@#$%^&*()"

// Get the length of the password to be generated
int get_password_length() {
    int length;
    printf("Enter the desired length of the password (minimum 8 characters): ");
    scanf("%d", &length);
    while (length < 8) {
        printf("The password must be at least 8 characters long. Please enter a valid length: ");
        scanf("%d", &length);
    }
    return length;
}

// Get the character sets to be used for password generation
int get_character_sets() {
    int character_sets;
    printf("Select the character sets to be used for password generation:\n");
    printf("1. Uppercase letters\n");
    printf("2. Lowercase letters\n");
    printf("3. Numeric characters\n");
    printf("4. Symbols\n");
    printf("Enter the numbers corresponding to the desired character sets (e.g., 123 for uppercase, lowercase, and numeric): ");
    scanf("%d", &character_sets);
    return character_sets;
}

// Generate a random password based on the given parameters
char *generate_password(int length, int character_sets) {
    // Initialize the password string
    char *password = malloc(length + 1);
    password[length] = '\0';

    // Initialize the random number generator
    srand(time(NULL));

    // Iterate over the password length and generate each character randomly
    for (int i = 0; i < length; i++) {
        // Get a random character from the selected character sets
        int charset_index = rand() % character_sets;
        char *charset;
        switch (charset_index) {
            case 0:
                charset = UPPERCASE_CHARSET;
                break;
            case 1:
                charset = LOWERCASE_CHARSET;
                break;
            case 2:
                charset = NUMERIC_CHARSET;
                break;
            case 3:
                charset = SYMBOL_CHARSET;
                break;
            default:
                charset = UPPERCASE_CHARSET;
                break;
        }

        // Get a random character from the selected character set
        int char_index = rand() % strlen(charset);
        char character = charset[char_index];

        // Add the character to the password string
        password[i] = character;
    }

    // Return the generated password
    return password;
}

// Print the generated password to the console
void print_password(char *password) {
    printf("Your randomly generated password is: %s\n", password);
}

// Main function
int main() {
    // Get the password length and character sets from the user
    int length = get_password_length();
    int character_sets = get_character_sets();

    // Generate the password
    char *password = generate_password(length, character_sets);

    // Print the password to the console
    print_password(password);

    // Free the allocated memory
    free(password);

    return 0;
}