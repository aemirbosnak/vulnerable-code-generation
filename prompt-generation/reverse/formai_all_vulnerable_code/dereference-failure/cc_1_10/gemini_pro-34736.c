//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets for password generation
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMERIC_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()_+-="

// Define the maximum length of the password
#define MAX_PASSWORD_LENGTH 20

// Declare a function to generate a random number within a specified range
int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Declare a function to generate a random character from a given character set
char get_random_character(const char *character_set) {
    int index = get_random_number(0, strlen(character_set) - 1);
    return character_set[index];
}

// Declare a function to generate a random password
char *generate_password() {
    // Initialize the password string
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);
    password[MAX_PASSWORD_LENGTH] = '\0';

    // Generate a random number of lowercase characters
    int num_lowercase_chars = get_random_number(1, 5);

    // Generate a random number of uppercase characters
    int num_uppercase_chars = get_random_number(1, 5);

    // Generate a random number of numeric characters
    int num_numeric_chars = get_random_number(1, 5);

    // Generate a random number of special characters
    int num_special_chars = get_random_number(1, 5);

    // Generate the password characters
    int current_index = 0;
    while (current_index < num_lowercase_chars) {
        password[current_index] = get_random_character(LOWERCASE_CHARS);
        current_index++;
    }
    while (current_index < num_lowercase_chars + num_uppercase_chars) {
        password[current_index] = get_random_character(UPPERCASE_CHARS);
        current_index++;
    }
    while (current_index < num_lowercase_chars + num_uppercase_chars + num_numeric_chars) {
        password[current_index] = get_random_character(NUMERIC_CHARS);
        current_index++;
    }
    while (current_index < num_lowercase_chars + num_uppercase_chars + num_numeric_chars + num_special_chars) {
        password[current_index] = get_random_character(SPECIAL_CHARS);
        current_index++;
    }

    // Shuffle the password characters to increase security
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        int random_index = get_random_number(0, MAX_PASSWORD_LENGTH - 1);
        char temp = password[i];
        password[i] = password[random_index];
        password[random_index] = temp;
    }

    // Return the generated password
    return password;
}

// Declare a function to print a password
void print_password(const char *password) {
    printf("Generated Password: %s\n", password);
}

// Declare the main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_password();

    // Print the generated password
    print_password(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}