//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PASSWORD_LENGTH 128
#define MIN_PASSWORD_LENGTH 8

void generatePassword(int length, bool useNumbers, bool useSymbols, bool useUppercase);
char getRandomCharacter(const char *set);
void printUsage();

int main(int argc, char *argv[]) {
    int passwordLength = 0;
    bool useNumbers = true;
    bool useSymbols = true;
    bool useUppercase = true;

    // Customizable Password Length
    if (argc > 1) {
        passwordLength = atoi(argv[1]);
        if (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
            printf("Please provide a password length between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
            return EXIT_FAILURE;
        }
    } else {
        printf("No length provided, using default: %d characters.\n", MIN_PASSWORD_LENGTH);
        passwordLength = MIN_PASSWORD_LENGTH;
    }

    // Ask user preference for including numbers, symbols, uppercase
    char choice;
    printf("Include numbers? (Y/N): ");
    getchar(); // consume newline
    choice = getchar();
    useNumbers = (choice == 'Y' || choice == 'y');

    printf("Include symbols? (Y/N): ");
    getchar(); // consume newline
    choice = getchar();
    useSymbols = (choice == 'Y' || choice == 'y');

    printf("Include uppercase letters? (Y/N): ");
    getchar(); // consume newline
    choice = getchar();
    useUppercase = (choice == 'Y' || choice == 'y');

    // Generate password
    generatePassword(passwordLength, useNumbers, useSymbols, useUppercase);

    return EXIT_SUCCESS;
}

void generatePassword(int length, bool useNumbers, bool useSymbols, bool useUppercase) {
    char password[MAX_PASSWORD_LENGTH + 1];
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *numbers = "0123456789";
    const char *symbols = "!@#$%^&*()-_=+[]{}|;:,.<>?/`~";
    
    // Create password character set
    char characterSet[MAX_PASSWORD_LENGTH];
    int index = 0;
    
    // Always include lowercase letters
    strcpy(characterSet, lowercase);
    index += strlen(lowercase);
    
    if (useUppercase) {
        strcpy(characterSet + index, uppercase);
        index += strlen(uppercase);
    }
    
    if (useNumbers) {
        strcpy(characterSet + index, numbers);
        index += strlen(numbers);
    }
    
    if (useSymbols) {
        strcpy(characterSet + index, symbols);
        index += strlen(symbols);
    }
    
    // Randomly generate password
    srand(time(NULL)); // Use current time as seed for random generator
    for (int i = 0; i < length; i++) {
        password[i] = getRandomCharacter(characterSet);
    }
    password[length] = '\0'; // Null-terminate the string

    printf("Generated Password: %s\n", password);
}

char getRandomCharacter(const char *set) {
    return set[rand() % strlen(set)];
}

void printUsage() {
    printf("Usage: password_generator [password_length]\n");
    printf("This generates a secure password considering various parameters.\n");
}