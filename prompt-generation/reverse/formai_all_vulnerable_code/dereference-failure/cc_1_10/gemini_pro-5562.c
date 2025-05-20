//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define PASSWORD_LENGTH 16

// Character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()_+=-";

// Function to generate a random character from a given character set
char generate_random_character(char *character_set) {
    int index = rand() % strlen(character_set);
    return character_set[index];
}

// Function to generate a random password
char *generate_password(int length) {
    // Allocate memory for the password
    char *password = malloc(length + 1);

    // Initialize the password with random characters
    for (int i = 0; i < length; i++) {
        // Select a random character set
        int character_set_index = rand() % 4;
        char *character_set = NULL;
        switch (character_set_index) {
            case 0:
                character_set = lowercase;
                break;
            case 1:
                character_set = uppercase;
                break;
            case 2:
                character_set = numbers;
                break;
            case 3:
                character_set = symbols;
                break;
        }

        // Generate a random character from the selected character set
        char character = generate_random_character(character_set);

        // Add the character to the password
        password[i] = character;
    }

    // Terminate the password with a null character
    password[length] = '\0';

    // Return the password
    return password;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_password(PASSWORD_LENGTH);

    // Print the password
    printf("Generated password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}