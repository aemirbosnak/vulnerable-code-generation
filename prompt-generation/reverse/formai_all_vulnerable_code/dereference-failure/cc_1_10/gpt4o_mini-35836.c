//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128
#define MIN_LENGTH 8

// Function to display the usage
void showUsage() {
    printf("Usage: ./password_generator [length] [options]\n");
    printf("Options:\n");
    printf("  -l : Include lowercase letters\n");
    printf("  -u : Include uppercase letters\n");
    printf("  -n : Include numbers\n");
    printf("  -s : Include special characters\n");
}

// Function to generate a random character from the specified set
char getRandomCharacter(const char *set, size_t len) {
    return set[rand() % len];
}

// Function to generate a secure password
void generatePassword(int length, int includeLowercase, int includeUppercase, 
                      int includeNumbers, int includeSpecial) {
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *numbers = "0123456789";
    const char *specialCharacters = "!@#$%^&*()-_=+[]{}|;:,.<>?";

    char password[MAX_LENGTH + 1];
    char availableChars[MAX_LENGTH];
    int index = 0;

    // Build the set of available characters
    if (includeLowercase) {
        strcpy(&availableChars[index], lowercase);
        index += strlen(lowercase);
    }
    if (includeUppercase) {
        strcpy(&availableChars[index], uppercase);
        index += strlen(uppercase);
    }
    if (includeNumbers) {
        strcpy(&availableChars[index], numbers);
        index += strlen(numbers);
    }
    if (includeSpecial) {
        strcpy(&availableChars[index], specialCharacters);
        index += strlen(specialCharacters);
    }

    // Check if any character types were selected
    if (index == 0) {
        printf("Error: No character types selected.\n");
        return;
    }

    // Ensure the password length is within bounds
    if (length < MIN_LENGTH || length > MAX_LENGTH) {
        printf("Error: Password length must be between %d and %d.\n", MIN_LENGTH, MAX_LENGTH);
        return;
    }

    // Randomly generate password
    for (int i = 0; i < length; i++) {
        password[i] = getRandomCharacter(availableChars, index);
    }
    password[length] = '\0'; // Null terminate the string

    printf("Generated Password: %s\n", password);
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed for random number generation

    if (argc < 3) {
        showUsage();
        return 1;
    }

    int length = atoi(argv[1]);
    int includeLowercase = 0;
    int includeUppercase = 0;
    int includeNumbers = 0;
    int includeSpecial = 0;

    // Process options
    for (int i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0) {
            includeLowercase = 1;
        } else if (strcmp(argv[i], "-u") == 0) {
            includeUppercase = 1;
        } else if (strcmp(argv[i], "-n") == 0) {
            includeNumbers = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            includeSpecial = 1;
        } else {
            printf("Warning: Unrecognized option: %s\n", argv[i]);
        }
    }

    generatePassword(length, includeLowercase, includeUppercase, 
                     includeNumbers, includeSpecial);

    return 0;
}