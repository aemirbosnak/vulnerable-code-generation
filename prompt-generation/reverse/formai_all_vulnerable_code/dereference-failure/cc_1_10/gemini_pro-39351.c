//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Define the character sets for the password
#define LOWERCASE_LETTERS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_LETTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGITS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+[]{};:,<.>/?~"

// Define the length of the password
#define PASSWORD_LENGTH 16

// Generate a random number between min and max
int generate_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Generate a random character from the given character set
char generate_random_character(char *character_set) {
    int index = generate_random_number(0, strlen(character_set) - 1);
    return character_set[index];
}

// Generate a random password
char *generate_random_password() {
    // Create a buffer to store the password
    char *password = malloc(PASSWORD_LENGTH + 1);

    // Generate a random character for each position in the password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int character_set_index = generate_random_number(0, 3);
        char *character_set;

        switch (character_set_index) {
            case 0:
                character_set = LOWERCASE_LETTERS;
                break;
            case 1:
                character_set = UPPERCASE_LETTERS;
                break;
            case 2:
                character_set = DIGITS;
                break;
            case 3:
                character_set = SPECIAL_CHARACTERS;
                break;
        }

        password[i] = generate_random_character(character_set);
    }

    // Terminate the password with a null character
    password[PASSWORD_LENGTH] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_random_password();

    // Print the password
    printf("Password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}