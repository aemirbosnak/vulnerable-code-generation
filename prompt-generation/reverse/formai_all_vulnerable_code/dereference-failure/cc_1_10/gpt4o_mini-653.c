//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 128
#define MIN_PASSWORD_LENGTH 8
#define DEFAULT_PASSWORD_COUNT 1

typedef struct {
    int upper;        // include uppercase letters
    int lower;        // include lowercase letters
    int digits;       // include digits
    int special;      // include special characters
} PasswordOptions;

void generatePassword(char *password, int length, PasswordOptions options) {
    const char *upper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char *lower = "abcdefghijklmnopqrstuvwxyz";
    const char *digits = "0123456789";
    const char *special = "!@#$%^&*()_+-=[]{}|;:,.<>?";

    char charset[MAX_PASSWORD_LENGTH];
    int index = 0;

    if (options.upper) {
        strcpy(&charset[index], upper);
        index += strlen(upper);
    }
    if (options.lower) {
        strcpy(&charset[index], lower);
        index += strlen(lower);
    }
    if (options.digits) {
        strcpy(&charset[index], digits);
        index += strlen(digits);
    }
    if (options.special) {
        strcpy(&charset[index], special);
        index += strlen(special);
    }

    int charsetSize = index;
    if (charsetSize == 0) {
        printf("At least one character type must be selected!\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charsetSize];
    }
    password[length] = '\0'; // Null-terminate the string
}

int main(int argc, char *argv[]) {
    int passwordLength = 12; // Default length
    int passwordCount = DEFAULT_PASSWORD_COUNT; // Default number of passwords
    PasswordOptions options = {1, 1, 1, 1}; // Default options (all types)

    // Parsing command line arguments
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-l") == 0 && i + 1 < argc) {
            passwordLength = atoi(argv[++i]);
            if (passwordLength < MIN_PASSWORD_LENGTH || passwordLength > MAX_PASSWORD_LENGTH) {
                printf("Password length must be between %d and %d characters.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
                return EXIT_FAILURE;
            }
        } else if (strcmp(argv[i], "-c") == 0 && i + 1 < argc) {
            passwordCount = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-u") == 0) {
            options.upper = 1;
        } else if (strcmp(argv[i], "-l") == 0) {
            options.lower = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            options.digits = 1;
        } else if (strcmp(argv[i], "-s") == 0) {
            options.special = 1;
        }
    }

    // Password generation
    char password[MAX_PASSWORD_LENGTH + 1];
    for (int i = 0; i < passwordCount; i++) {
        generatePassword(password, passwordLength, options);
        printf("Generated Password %d: %s\n", i + 1, password);
    }

    return EXIT_SUCCESS;
}