//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the character sets for password generation
char lowercase[] = "abcdefghijklmnopqrstuvwxyz";
char uppercase[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char numbers[] = "0123456789";
char symbols[] = "!@#$%^&*()-=+";

// Define the maximum length of the password
#define MAX_PASSWORD_LENGTH 20

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to generate a random character from a given string
char random_character(char *string) {
    int index = random_number(0, strlen(string) - 1);
    return string[index];
}

// Function to generate a random password
char *generate_password() {
    // Allocate memory for the password
    char *password = malloc(MAX_PASSWORD_LENGTH + 1);

    // Generate the password
    for (int i = 0; i < MAX_PASSWORD_LENGTH; i++) {
        // Choose a random character set
        int character_set = random_number(0, 3);

        // Generate a random character from the chosen character set
        switch (character_set) {
            case 0:
                password[i] = random_character(lowercase);
                break;
            case 1:
                password[i] = random_character(uppercase);
                break;
            case 2:
                password[i] = random_character(numbers);
                break;
            case 3:
                password[i] = random_character(symbols);
                break;
        }
    }

    // Terminate the password with a null character
    password[MAX_PASSWORD_LENGTH] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a random password
    char *password = generate_password();

    // Print the password
    printf("Password: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}