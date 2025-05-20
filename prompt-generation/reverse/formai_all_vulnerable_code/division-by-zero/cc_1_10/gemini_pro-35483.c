//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// 1. Define the character classes and their corresponding ranges
#define LOWER_ALPHABET_RANGE "abcdefghijklmnopqrstuvwxyz"        // 26 characters
#define UPPER_ALPHABET_RANGE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"        // 26 characters
#define NUMERIC_RANGE "0123456789"                               // 10 characters
#define SPECIAL_CHAR_RANGE "!@#$%^&*()_-+=<>?/"                    // 14 characters

// 2. Define the password length
#define PASSWORD_LENGTH 15

// 3. Function to generate a random number within a given range
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

// 4. Function to generate a random character from a given character class
char generateRandomCharacter(char *characterClass) {
    int index = generateRandomNumber(0, strlen(characterClass) - 1);
    return characterClass[index];
}

// 5. Function to generate a secure password
char *generateSecurePassword() {
    char *password = malloc(PASSWORD_LENGTH + 1);  // +1 for the null-terminator
    int characterCount = 0;

    // Ensure that the password contains at least one character from each character class
    while (characterCount < PASSWORD_LENGTH) {
        char characterClass;
        // Choose a random character class
        int classIndex = generateRandomNumber(0, 3);
        switch (classIndex) {
            case 0:
                characterClass = LOWER_ALPHABET_RANGE;
                break;
            case 1:
                characterClass = UPPER_ALPHABET_RANGE;
                break;
            case 2:
                characterClass = NUMERIC_RANGE;
                break;
            case 3:
                characterClass = SPECIAL_CHAR_RANGE;
                break;
        }
        
        // Generate a random character from the chosen character class
        char character = generateRandomCharacter(characterClass);
        
        // Add the character to the password
        password[characterCount] = character;
        characterCount++;
    }

    // Null-terminate the password
    password[PASSWORD_LENGTH] = '\0';

    return password;
}

int main() {
    // Initialize the random number generator
    srand(time(NULL));

    // Generate a secure password
    char *password = generateSecurePassword();

    // Print the generated password
    printf("Generated password: %s\n", password);

    // Free the allocated memory
    free(password);

    return 0;
}