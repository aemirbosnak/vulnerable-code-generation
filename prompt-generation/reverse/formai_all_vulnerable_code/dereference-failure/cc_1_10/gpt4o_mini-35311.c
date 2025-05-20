//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASSWORD_LENGTH 128
#define DEFAULT_PASSWORD_LENGTH 12
#define NUM_OF_SPECIAL_CHARS 10

// Define character sets
const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits = "0123456789";
const char *specialChars = "!@#$%^&*()_+-=[]{}|;':\",.<>?";

// Function to get a random character from a given set
char getRandomChar(const char *set) {
    return set[rand() % strlen(set)];
}

// Function to generate a secure password
void generatePassword(char *password, int length) {
    int i;

    // Ensure the first character is a letter
    password[0] = getRandomChar(lowercase);
    // Fill the password with random characters
    for (i = 1; i < length; i++) {
        int set_choice = rand() % 4; // Choose a random character set

        if (set_choice == 0) {
            password[i] = getRandomChar(lowercase);
        } else if (set_choice == 1) {
            password[i] = getRandomChar(uppercase);
        } else if (set_choice == 2) {
            password[i] = getRandomChar(digits);
        } else {
            password[i] = getRandomChar(specialChars);
        }
    }
    
    password[length] = '\0'; // Null-terminating the string
}

// Function to validate the generated password
int validatePassword(const char *password) {
    int hasLower = 0, hasUpper = 0, hasDigit = 0, hasSpecial = 0;
    const char *pattern = lowercase;
    const char *patternUpper = uppercase;
    const char *patternDigit = digits;
    const char *patternSpecial = specialChars;

    for (size_t i = 0; i < strlen(password); i++) {
        if (strchr(pattern, password[i])) {
            hasLower = 1;
        } else if (strchr(patternUpper, password[i])) {
            hasUpper = 1;
        } else if (strchr(patternDigit, password[i])) {
            hasDigit = 1;
        } else if (strchr(patternSpecial, password[i])) {
            hasSpecial = 1;
        }
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
}

// Function to prompt user for password length
int getPasswordLength() {
    int length;
    printf("Enter the desired password length (minimum %d, maximum %d): ", 
           DEFAULT_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
    scanf("%d", &length);
    
    if (length < DEFAULT_PASSWORD_LENGTH || length > MAX_PASSWORD_LENGTH) {
        printf("Invalid length. Using default length of %d.\n", DEFAULT_PASSWORD_LENGTH);
        length = DEFAULT_PASSWORD_LENGTH;
    }
    return length;
}

// Main function
int main() {
    srand(time(NULL)); // Seed for random number generation

    int length = getPasswordLength();
    char *password = malloc((length + 1) * sizeof(char));

    generatePassword(password, length);
    
    if (validatePassword(password)) {
        printf("Generated secure password: %s\n", password);
    } else {
        printf("Generated password did not meet the security criteria.\n");
    }

    free(password); // Free allocated memory
    return 0;
}