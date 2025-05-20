//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

void generatePassword(int length, char *password);
int isValidCharacter(char c, int options);
void displayPasswordOptions();

int main() {
    srand(time(NULL)); // Seed the random number generator
    int length;
    char password[MAX_LENGTH + 1];  // +1 for the null terminator

    // Display instructions
    printf("Welcome to the Secure Password Generator!\n");
    printf("You can create a password based on your specifications.\n");
    displayPasswordOptions();

    // Get password length from user
    printf("Enter the desired password length (8-128): ");
    scanf("%d", &length);
    
    // Validate length
    if (length < 8 || length > MAX_LENGTH) {
        printf("Invalid length! Please choose between 8 and 128 characters.\n");
        return 1;
    }

    // Generate the password
    generatePassword(length, password);
    printf("Your secure password is: %s\n", password);

    return 0;
}

void generatePassword(int length, char *password) {
    const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
    const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()-_=+<>?";
    
    // Include all character sets
    char *allChars = "";  
    int options = 0;

    // Ask the user which types of characters they want
    printf("Do you want to include:\n");
    printf("1. Lowercase letters (y/n): ");
    if (getchar() == 'y') {
        allChars = strcat(allChars, lowercase);
        options |= 1; // Lowercase option
    }

    printf("2. Uppercase letters (y/n): ");
    if (getchar() == 'y') {
        allChars = strcat(allChars, uppercase);
        options |= 2; // Uppercase option
    }

    printf("3. Digits (y/n): ");
    if (getchar() == 'y') {
        allChars = strcat(allChars, digits);
        options |= 4; // Digit option
    }

    printf("4. Special characters (y/n): ");
    if (getchar() == 'y') {
        allChars = strcat(allChars, special);
        options |= 8; // Special character option
    }

    // Check if at least one character set is selected
    if (options == 0) {
        printf("You must select at least one character type!\n");
        return;
    }

    // Generate password
    for (int i = 0; i < length; i++) {
        int index = rand() % strlen(allChars);
        password[i] = allChars[index];
    }

    password[length] = '\0'; // Null-terminate the password
}

void displayPasswordOptions() {
    printf("You can choose from the following character types:\n");
    printf("1. Lowercase letters: a-z\n");
    printf("2. Uppercase letters: A-Z\n");
    printf("3. Digits: 0-9\n");
    printf("4. Special characters: !@#$%^&*()-_=+<>?\n");
    printf("You will be prompted to include each set when generating your password.\n");
    printf("Let's get started!\n\n");
}