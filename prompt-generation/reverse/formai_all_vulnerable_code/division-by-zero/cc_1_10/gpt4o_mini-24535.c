//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+<>?{}[]|"
#define ALPHABET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
#define NUMBERS "0123456789"

void generate_password(char *password) {
    const int alphaSize = strlen(ALPHABET);
    const int numberSize = strlen(NUMBERS);
    const int specialSize = strlen(SPECIAL_CHARACTERS);
    const char *charset[] = { ALPHABET, NUMBERS, SPECIAL_CHARACTERS };
    
    // Make sure we have at least one of each character type
    password[0] = ALPHABET[rand() % alphaSize]; // Upper or Lower case letter
    password[1] = NUMBERS[rand() % numberSize]; // Digit
    password[2] = SPECIAL_CHARACTERS[rand() % specialSize]; // Special Character
    
    // Fill the rest of the password with a mix of the character sets
    for (int i = 3; i < PASSWORD_LENGTH; ++i) {
        const int randomSet = rand() % 3; // Choose a random set
        const char *currentSet = charset[randomSet];
        const int currentSize = strlen(currentSet);
        password[i] = currentSet[rand() % currentSize]; // Pick a random character from the chosen set
    }
    
    // Shuffle the password to avoid predictable patterns
    for (int i = 0; i < PASSWORD_LENGTH; ++i) {
        int randIndex = rand() % PASSWORD_LENGTH;
        // Swap characters
        char temp = password[i];
        password[i] = password[randIndex];
        password[randIndex] = temp;
    }
    
    // Null terminate the string
    password[PASSWORD_LENGTH] = '\0';
}

int main() {
    // Seed the random number generator
    srand((unsigned int)time(NULL));
    
    // Declare a password buffer
    char password[PASSWORD_LENGTH + 1]; // +1 for null terminator
    
    printf("Surprise! Generating a secure password...\n");
    
    // Generate a password
    generate_password(password);
    
    // Output the password
    printf("Here is your secure password: %s\n", password);
    
    // Ask for user input to keep the program running for a moment
    printf("\nPress enter to exit...");
    getchar();
    
    return 0;
}