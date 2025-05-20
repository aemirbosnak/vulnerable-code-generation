//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 12
#define NUM_PASSWORDS 5

const char *lowercase = "abcdefghijklmnopqrstuvwxyz";
const char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const char *digits = "0123456789";
const char *specialChars = "!@#$%^&*()-_=+[]{};:,.<>?";

void generatePassword(char *password) {
    // Randomly pick characters from different categories
    password[0] = lowercase[rand() % strlen(lowercase)];
    password[1] = uppercase[rand() % strlen(uppercase)];
    password[2] = digits[rand() % strlen(digits)];
    password[3] = specialChars[rand() % strlen(specialChars)];

    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        // Randomly choose from all categories for the remaining characters
        char allChars[100];
        snprintf(allChars, sizeof(allChars), "%s%s%s%s", lowercase, uppercase, digits, specialChars);
        password[i] = allChars[rand() % strlen(allChars)];
    }

    // Shuffle the password to avoid predictability
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }
    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
}

int main() {
    srand(time(NULL)); // Seed the random number generator
    char password[PASSWORD_LENGTH + 1]; // +1 for the null terminator

    printf("Secure Password Generator\n");
    printf("==========================\n\n");

    for (int i = 0; i < NUM_PASSWORDS; i++) {
        generatePassword(password);
        printf("Password %d: %s\n", i + 1, password);
    }

    printf("\nKeep your passwords safe!\n");
    return 0;
}