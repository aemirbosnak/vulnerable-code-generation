//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Asynchronous function to generate random characters
void generateRandomCharacters(char* password, int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()";
    int charsetLen = sizeof(charset) - 1;

    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        password[i] = charset[rand() % charsetLen];
    }
    password[len] = '\0';
}

// Asynchronous function to add random numbers to password
// Replaces characters at random index with randomly generated numbers
void addRandomNumbers(char* password, int len, int numCount) {
    int randIndex;
    char randNum;
    srand(time(NULL));

    for (int i = 0; i < numCount; i++) {
        randIndex = rand() % len;
        randNum = (rand() % 10) + 48; // ASCII code of numbers start from 48
        password[randIndex] = randNum;
    }
}

// Asynchronous function to add random symbols to password
// Replaces characters at random index with randomly generated symbols
void addRandomSymbols(char* password, int len, int symCount) {
    int randIndex;
    char randSym;
    const char symbols[] = "!@#$%^&*()";
    int symbolsLen = sizeof(symbols) - 1;
    srand(time(NULL));

    for (int i = 0; i < symCount; i++) {
        randIndex = rand() % len;
        randSym = symbols[rand() % symbolsLen];
        password[randIndex] = randSym;
    }
}

// Main function to generate secure password
int main() {
    int len, numCount, symCount;
    char password[128];

    printf("Enter length of password: ");
    scanf("%d", &len);

    printf("Enter number of digits required in password: ");
    scanf("%d", &numCount);

    printf("Enter number of symbols required in password: ");
    scanf("%d", &symCount);

    generateRandomCharacters(password, len);

    if (numCount > 0) {
        addRandomNumbers(password, len, numCount);
    }

    if (symCount > 0) {
        addRandomSymbols(password, len, symCount);
    }

    printf("Generated Secure Password: %s\n", password);
    return 0;
}