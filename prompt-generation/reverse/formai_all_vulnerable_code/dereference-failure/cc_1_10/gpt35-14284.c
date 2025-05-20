//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12  // Change this constant to increase or decrease password length.

// Function to generate and return a random integer within a given range.
int getRandomNumber(int minimum, int maximum) {
    return (rand() % (maximum - minimum + 1)) + minimum;
}

// Function to generate and return a randomly selected character from a given character set.
char getRandomCharacter(char* characterSet, int setLength) {
    int index = getRandomNumber(0, setLength - 1);
    return characterSet[index];
}

// Function to generate a secure password.
char* generateSecurePassword() {
    // Define character sets from which password characters will be generated.
    char uppercaseLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char lowercaseLetters[] = "abcdefghijklmnopqrstuvwxyz";
    char numbers[] = "0123456789";
    char specialCharacters[] = "!@#$%^&*()_+-=[]{}|\\;:\'\",./<>?";

    // Determine the length of each character set.
    int uppercaseLettersLength = strlen(uppercaseLetters);
    int lowercaseLettersLength = strlen(lowercaseLetters);
    int numbersLength = strlen(numbers);
    int specialCharactersLength = strlen(specialCharacters);

    // Create an array of pointers to character sets.
    char* characterSets[] = {uppercaseLetters, lowercaseLetters, numbers, specialCharacters};
    int numCharacterSets = 4;

    // Allocate memory for the password string and initialize it to null characters.
    char* password = malloc(PASSWORD_LENGTH + 1);
    memset(password, '\0', PASSWORD_LENGTH + 1);

    // Generate password characters randomly from each character set.
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        // Choose a random character set.
        int index = getRandomNumber(0, numCharacterSets - 1);
        char* characterSet = characterSets[index];
        int setLength = 0;

        // Get the length of the selected character set.
        switch (index) {
            case 0:
                setLength = uppercaseLettersLength;
                break;
            case 1:
                setLength = lowercaseLettersLength;
                break;
            case 2:
                setLength = numbersLength;
                break;
            case 3:
                setLength = specialCharactersLength;
                break;
        }

        // Generate a random character from the selected character set and add it to the password.
        password[i] = getRandomCharacter(characterSet, setLength);
    }

    return password;
}

int main() {
    // Seed the random number generator.
    srand(time(NULL));

    // Generate a secure password and print it to the console.
    char* password = generateSecurePassword();
    printf("Your new password is: %s\n", password);

    // Free memory allocated for the password string.
    free(password);

    return 0;
}