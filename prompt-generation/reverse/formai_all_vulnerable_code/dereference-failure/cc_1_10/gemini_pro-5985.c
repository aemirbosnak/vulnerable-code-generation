//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Function to generate a random character
char generate_random_character(int type) {
    int random_number;
    char random_character;

    // Generate a random number between 0 and 35
    random_number = rand() % 36;

    // Check the type of character to generate
    switch (type) {
        case 0: // Lowercase letter
            random_character = 'a' + random_number;
            break;
        case 1: // Uppercase letter
            random_character = 'A' + random_number;
            break;
        case 2: // Digit
            random_character = '0' + random_number;
            break;
        case 3: // Symbol
            random_character = "!@#$%^&*()_+=-`~";
            break;
        default: // Default to lowercase letter
            random_character = 'a' + random_number;
    }

    // Return the random character
    return random_character;
}

// Function to generate a password of a given length
char *generate_password(int length) {
    char *password;
    int i;
    int type;

    // Allocate memory for the password
    password = malloc(length + 1);

    // Generate a random character for each position in the password
    for (i = 0; i < length; i++) {
        // Generate a random type of character
        type = rand() % 4;

        // Generate a random character
        password[i] = generate_random_character(type);
    }

    // Terminate the string with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    int length;
    char *password;

    // Get the length of the password from the user
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    // Generate a password of the given length
    password = generate_password(length);

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}