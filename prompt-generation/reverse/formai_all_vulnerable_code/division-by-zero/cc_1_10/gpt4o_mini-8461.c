//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16
#define LOWERCASE_CHARS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DIGIT_CHARS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_+=<>?"

void printIntro();
void generatePassword(char *password);
void shuffleString(char *password, int length);
void handleError(const char *message);

int main() {
    char password[PASSWORD_LENGTH + 1];
    printIntro();
    generatePassword(password);
    printf("Generated Secure Password: %s\n", password);
    return 0;
}

void printIntro() {
    printf("========================================\n");
    printf("     Cyberpunk Secure Password Generator\n");
    printf("========================================\n");
    printf("In a world ruled by tech, ensure your power is secured...\n\n");
}

void generatePassword(char *password) {
    const char *charSets[] = {LOWERCASE_CHARS, UPPERCASE_CHARS, DIGIT_CHARS, SPECIAL_CHARS};

    srand(time(NULL)); // Seed the random number generator

    // Ensure at least one character from each set is included
    password[0] = charSets[0][rand() % strlen(LOWERCASE_CHARS)];
    password[1] = charSets[1][rand() % strlen(UPPERCASE_CHARS)];
    password[2] = charSets[2][rand() % strlen(DIGIT_CHARS)];
    password[3] = charSets[3][rand() % strlen(SPECIAL_CHARS)];

    // Fill the rest of the password length with random characters from all sets
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        int setIndex = rand() % 4; // Select a random character set
        int charIndex = rand() % strlen(charSets[setIndex]);
        password[i] = charSets[setIndex][charIndex];
    }

    // Null terminate the password string
    password[PASSWORD_LENGTH] = '\0';

    // Shuffle the password to ensure randomness
    shuffleString(password, PASSWORD_LENGTH);
}

void shuffleString(char *str, int length) {
    for (int i = length - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Random index to swap
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void handleError(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(EXIT_FAILURE);
}