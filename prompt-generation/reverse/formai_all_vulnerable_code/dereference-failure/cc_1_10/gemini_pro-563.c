//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants for the password generation
#define PASSWORD_LENGTH 16
#define MIN_ASCII_VALUE 33
#define MAX_ASCII_VALUE 126

// Function to generate a random number between two values
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// Function to generate a random character
char generateRandomCharacter() {
    return (char) generateRandomNumber(MIN_ASCII_VALUE, MAX_ASCII_VALUE);
}

// Function to generate a random password
char* generateRandomPassword() {
    // Allocate memory for the password
    char* password = malloc(PASSWORD_LENGTH + 1);

    // Generate each character of the password
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        password[i] = generateRandomCharacter();
    }

    // Terminate the password with a null character
    password[PASSWORD_LENGTH] = '\0';

    // Return the password
    return password;
}

// Main function
int main() {
    // Initialize the random seed
    srand(time(NULL));

    // Generate a random password
    char* password = generateRandomPassword();

    // Print the password to the console
    printf("Your randomly generated password is: %s\n", password);

    // Free the memory allocated for the password
    free(password);

    return 0;
}