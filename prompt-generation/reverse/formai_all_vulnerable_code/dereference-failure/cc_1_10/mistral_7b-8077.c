//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien Symbol Table
#define MAX_ALIEN_SYMBOLS 100
typedef struct {
    char symbol;
    char english;
} AlienSymbolTable;

AlienSymbolTable alienSymbols[MAX_ALIEN_SYMBOLS];
int numAlienSymbols = 0;

// Paranoid Checks
void panic(char *msg) {
    fprintf(stderr, "[!!] %s\n", msg);
    exit(EXIT_FAILURE);
}

// Validate Alien Symbol Table
void validateAlienSymbolTable() {
    if (numAlienSymbols > MAX_ALIEN_SYMBOLS) {
        panic("Error: Alien Symbol Table is full.");
    }
}

// Add Alien Symbol to Table
void addAlienSymbol(char symbol, char english) {
    validateAlienSymbolTable();

    alienSymbols[numAlienSymbols].symbol = symbol;
    alienSymbols[numAlienSymbols].english = english;
    numAlienSymbols++;
}

// Translate Alien to English
int translateAlien(char *alienText, char *englishText, int maxLength) {
    int alienIndex, englishIndex = 0;
    int alienTextLength = strlen(alienText);

    for (alienIndex = 0; alienIndex < alienTextLength && englishIndex < maxLength; alienIndex++) {
        if (alienText[alienIndex] == '\0') {
            break;
        }

        int symbolIndex;
        for (symbolIndex = 0; symbolIndex < numAlienSymbols; symbolIndex++) {
            if (alienText[alienIndex] == alienSymbols[symbolIndex].symbol) {
                englishText[englishIndex++] = alienSymbols[symbolIndex].english;
                break;
            }
        }

        if (symbolIndex == numAlienSymbols) {
            panic("Error: Unknown Alien Symbol.");
        }
    }

    englishText[englishIndex] = '\0';

    return englishIndex;
}

int main(int argc, char **argv) {
    if (argc != 3) {
        panic("Usage: ./translator <alienText> <englishText>");
    }

    addAlienSymbol('A', 'A');
    addAlienSymbol('B', 'B');
    addAlienSymbol('C', 'C');

    char alienText[100];
    strcpy(alienText, argv[1]);

    char englishText[100];
    int maxLength = sizeof(englishText);

    int length = translateAlien(alienText, englishText, maxLength);

    printf("Alien: %s\n", alienText);
    printf("English: %s\n", englishText);
    printf("Length: %d\n", length);

    return EXIT_SUCCESS;
}