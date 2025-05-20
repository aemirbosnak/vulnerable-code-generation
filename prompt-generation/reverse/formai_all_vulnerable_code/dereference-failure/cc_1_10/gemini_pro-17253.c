//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Constants
#define PASSWORD_LENGTH 16

// Function prototypes
char *generatePassword();
void printPassword(char *password);

// Main function
int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a password
    char *password = generatePassword();

    // Print the password
    printPassword(password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}

// Function to generate a password
char *generatePassword() {
    // Create an array to store the password
    char *password = malloc(PASSWORD_LENGTH + 1);

    // Generate a random password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = (rand() % 94) + 33;
    }

    // Terminate the password with a null character
    password[PASSWORD_LENGTH] = '\0';

    // Return the password
    return password;
}

// Function to print a password
void printPassword(char *password) {
    // Print the password to the console
    printf("Your password is: %s\n", password);
}