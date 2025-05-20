//GEMINI-pro DATASET v1.0 Category: Secure Password Generator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_PASSWORD_LENGTH 8
#define MAX_PASSWORD_LENGTH 64

// Function to generate a random character
char generateRandomCharacter() {
    int randomNumber = rand() % 94 + 33;
    return (char) randomNumber;
}

// Function to generate a random password
char *generateRandomPassword(int length) {
    char *password = malloc(length + 1);
    for (int i = 0; i < length; i++) {
        password[i] = generateRandomCharacter();
    }
    password[length] = '\0';
    return password;
}

// Function to check if a password is strong enough
int isPasswordStrongEnough(char *password) {
    int length = strlen(password);
    int hasUppercaseLetter = 0;
    int hasLowercaseLetter = 0;
    int hasDigit = 0;
    int hasSpecialCharacter = 0;

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            hasUppercaseLetter = 1;
        } else if (password[i] >= 'a' && password[i] <= 'z') {
            hasLowercaseLetter = 1;
        } else if (password[i] >= '0' && password[i] <= '9') {
            hasDigit = 1;
        } else {
            hasSpecialCharacter = 1;
        }
    }

    return hasUppercaseLetter && hasLowercaseLetter && hasDigit && hasSpecialCharacter && length >= MIN_PASSWORD_LENGTH;
}

// Function to get a random password from the user
char *getRandomPasswordFromUser(int length) {
    char *password = malloc(length + 1);
    printf("Enter a random password: ");
    scanf("%s", password);
    return password;
}

// Function to print a password
void printPassword(char *password) {
    printf("Your password is: %s\n", password);
}

// Main function
int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Get the desired password length from the user
    int length;
    printf("Enter the desired password length: ");
    scanf("%d", &length);

    // Generate a random password
    char *password = generateRandomPassword(length);

    // Check if the password is strong enough
    int isStrongEnough = isPasswordStrongEnough(password);

    // If the password is not strong enough, get a random password from the user
    while (!isStrongEnough) {
        free(password);
        password = getRandomPasswordFromUser(length);
        isStrongEnough = isPasswordStrongEnough(password);
    }

    // Print the password
    printPassword(password);

    // Free the allocated memory
    free(password);

    return 0;
}