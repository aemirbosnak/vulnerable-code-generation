//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets
const char *lowercase_chars = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase_chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits_chars = "0123456789";
const char *symbols_chars = "!@#$%^&*()_+";

// Define the password length
const int password_length = 16;

// Function to generate a random number between min and max
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from a character set
char get_random_character(const char *character_set) {
    return character_set[get_random_number(0, strlen(character_set) - 1)];
}

// Function to generate a random password
char *generate_password() {
    // Allocate memory for the password
    char *password = malloc(password_length + 1);

    // Initialize the password with random characters
    for (int i = 0; i < password_length; i++) {
        int character_set_index = get_random_number(0, 3);
        switch (character_set_index) {
            case 0:
                password[i] = get_random_character(lowercase_chars);
                break;
            case 1:
                password[i] = get_random_character(uppercase_chars);
                break;
            case 2:
                password[i] = get_random_character(digits_chars);
                break;
            case 3:
                password[i] = get_random_character(symbols_chars);
                break;
        }
    }

    // Terminate the password with a null character
    password[password_length] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_password();

    // Print the password
    printf("Generated password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    // Exit the program
    return 0;
}