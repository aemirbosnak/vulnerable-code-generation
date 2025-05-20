//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL_CHARS "!@#$%^&*()-_=+[]{}|;:,.<>?/`~"

char randomChar(const char *str) {
    return str[rand() % strlen(str)];
}

void generatePassword(char *password) {
    // Seed the random number generator
    srand(time(NULL));

    // Ensure password has at least one character from each category
    password[0] = randomChar(UPPERCASE);
    password[1] = randomChar(LOWERCASE);
    password[2] = randomChar(DIGITS);
    password[3] = randomChar(SPECIAL_CHARS);

    // Fill in the rest of the password with random characters
    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        char *allCharacters = (char *)malloc(strlen(UPPERCASE) + strlen(LOWERCASE) + strlen(DIGITS) + strlen(SPECIAL_CHARS) + 1);
        sprintf(allCharacters, "%s%s%s%s", UPPERCASE, LOWERCASE, DIGITS, SPECIAL_CHARS);
        password[i] = randomChar(allCharacters);
        free(allCharacters);
    }

    // Shuffle the password to avoid predictable patterns
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char tmp = password[i];
        password[i] = password[j];
        password[j] = tmp;
    }

    password[PASSWORD_LENGTH] = '\0'; // Null-terminate the string
}

int main() {
    char password[PASSWORD_LENGTH + 1];

    printf("Generating a secure random password...\n");
    generatePassword(password);
    
    printf("Your secure password is: %s\n", password);
    return 0;
}