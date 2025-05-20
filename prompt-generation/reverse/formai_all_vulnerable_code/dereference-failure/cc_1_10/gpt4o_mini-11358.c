//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define PASSWORD_LENGTH 12
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define DIGITS "0123456789"
#define SPECIAL_CHARACTERS "!@#$%^&*()-_=+<>?"
#define TOTAL_CHARSET "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!@#$%^&*()-_=+<>?"

void generatePassword(char *password) {
    int length = strlen(UPPERCASE) + strlen(LOWERCASE) + strlen(DIGITS) + strlen(SPECIAL_CHARACTERS);
    char characterSet[length + 1];

    // Combine all character sets
    strcpy(characterSet, UPPERCASE);
    strcat(characterSet, LOWERCASE);
    strcat(characterSet, DIGITS);
    strcat(characterSet, SPECIAL_CHARACTERS);

    // Ensure to include at least one character from each category
    password[0] = UPPERCASE[rand() % strlen(UPPERCASE)];
    password[1] = LOWERCASE[rand() % strlen(LOWERCASE)];
    password[2] = DIGITS[rand() % strlen(DIGITS)];
    password[3] = SPECIAL_CHARACTERS[rand() % strlen(SPECIAL_CHARACTERS)];

    for (int i = 4; i < PASSWORD_LENGTH; i++) {
        password[i] = characterSet[rand() % length];
    }

    // Shuffle the password to ensure randomness
    for (int i = 0; i < PASSWORD_LENGTH; i++) {
        int j = rand() % PASSWORD_LENGTH;
        char temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    // Null terminate the string
    password[PASSWORD_LENGTH] = '\0';
}

void printHelp() {
    printf("Usage: ./PasswordGenerator [options]\n");
    printf("Options:\n");
    printf("  -h         Display this help menu\n");
    printf("  -n <num>   Number of passwords to generate (default: 1)\n");
}

int main(int argc, char *argv[]) {
    srand(time(NULL)); // Seed for random number generation

    int numPasswords = 1;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printHelp();
            return 0;
        } else if (strcmp(argv[i], "-n") == 0 && i + 1 < argc) {
            numPasswords = atoi(argv[++i]);
        }
    }

    char password[PASSWORD_LENGTH + 1];
    printf("Generating %d secure passwords:\n", numPasswords);

    for (int i = 0; i < numPasswords; i++) {
        generatePassword(password);
        printf("Password %d: %s\n", i + 1, password);
    }

    return 0;
}