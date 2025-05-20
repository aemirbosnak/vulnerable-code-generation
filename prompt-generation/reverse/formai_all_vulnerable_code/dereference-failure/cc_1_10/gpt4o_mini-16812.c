//GPT-4o-mini DATASET v1.0 Category: Secure Password Generator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define PASSWORD_LENGTH 16
#define NUM_UPPERCASE 4
#define NUM_LOWERCASE 4
#define NUM_DIGITS 4
#define NUM_SPECIAL 4
#define TOTAL_CHARSET (NUM_UPPERCASE + NUM_LOWERCASE + NUM_DIGITS + NUM_SPECIAL)

void generateRandomPassword(char *password);
void shuffleString(char *str);
void fillCharacterSet(char *set, const char *charset, int num);
void printUsage();

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printUsage();
        return EXIT_FAILURE;
    }

    int passwordCount = atoi(argv[1]);
    if (passwordCount <= 0) {
        printUsage();
        return EXIT_FAILURE;
    }

    char password[PASSWORD_LENGTH + 1];
    srand(time(NULL));

    for (int i = 0; i < passwordCount; i++) {
        generateRandomPassword(password);
        printf("Generated Password %d: %s\n", i + 1, password);
    }

    return EXIT_SUCCESS;
}

void generateRandomPassword(char *password) {
    char passwordSet[TOTAL_CHARSET + 1];
    
    // Fill passwordSet with required character types
    fillCharacterSet(passwordSet, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", NUM_UPPERCASE);
    fillCharacterSet(passwordSet + NUM_UPPERCASE, "abcdefghijklmnopqrstuvwxyz", NUM_LOWERCASE);
    fillCharacterSet(passwordSet + NUM_UPPERCASE + NUM_LOWERCASE, "0123456789", NUM_DIGITS);
    fillCharacterSet(passwordSet + NUM_UPPERCASE + NUM_LOWERCASE + NUM_DIGITS, "!@#$%^&*()-_=+", NUM_SPECIAL);

    // Add null terminator for string
    passwordSet[TOTAL_CHARSET] = '\0';

    // Shuffle and fill password
    strncpy(password, passwordSet, TOTAL_CHARSET);
    password[TOTAL_CHARSET] = '\0';
    shuffleString(password);
}

void fillCharacterSet(char *set, const char *charset, int num) {
    int charsetLength = strlen(charset);
    
    for (int i = 0; i < num; i++) {
        set[i] = charset[rand() % charsetLength];
    }
}

void shuffleString(char *str) {
    int n = strlen(str);
    
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        // Swap characters
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

void printUsage() {
    printf("Usage: password_generator <number_of_passwords>\n");
    printf("Example: password_generator 5\n");
    printf("This will generate 5 random passwords.\n");
}