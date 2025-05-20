//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MIN_LENGTH 8
#define MAX_LENGTH 20

// Function prototypes
void generatePassword(int length, char *password);
int isValidLength(int length);
void printHelp();

int main(int argc, char *argv[]) {
    int length;
    char password[MAX_LENGTH + 1]; // +1 for null terminator

    // Seed random number generator
    srand(time(NULL));

    // Check for proper command-line argument
    if (argc != 2) {
        printHelp();
        return 1;
    }

    // Get desired password length
    length = atoi(argv[1]);
    if (!isValidLength(length)) {
        printHelp();
        return 1;
    }

    // Generate and display password
    generatePassword(length, password);
    printf("Generated Password: %s\n", password);
    
    return 0;
}

// Generate a secure password of given length
void generatePassword(int length, char *password) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    // Ensure at least one character from each category is included
    password[0] = upper[rand() % strlen(upper)];
    password[1] = lower[rand() % strlen(lower)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = special[rand() % strlen(special)];

    // Fill the rest of the password with random characters from all categories
    const char *allCharacters = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+[]{}|;:,.<>?";
    for (int i = 4; i < length; i++) {
        password[i] = allCharacters[rand() % strlen(allCharacters)];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < length; i++) {
        int j = rand() % length;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null-terminate the password
    password[length] = '\0';
}

// Check if the desired password length is valid
int isValidLength(int length) {
    return length >= MIN_LENGTH && length <= MAX_LENGTH;
}

// Print help information for the user
void printHelp() {
    printf("Usage: ./password_generator <length>\n");
    printf("Length must be between %d and %d characters.\n", MIN_LENGTH, MAX_LENGTH);
}