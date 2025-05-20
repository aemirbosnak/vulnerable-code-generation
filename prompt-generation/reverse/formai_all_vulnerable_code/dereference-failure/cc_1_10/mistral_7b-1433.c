//MISTRAL-7B DATASET v1.0 Category: Alien Language Translator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Alien struct
typedef struct {
    char symbol;
    int value;
} AlienSymbol;

// Alien symbol table
AlienSymbol alienSymbols[10] = {
    {'A', 1}, {'B', 2}, {'C', 3}, {'D', 4}, {'E', 5}, {'F', 6}, {'G', 7}, {'H', 8}, {'I', 9}, {'J', 10}
};

// Function to get value of alien symbol
int getAlienSymbolValue(char symbol) {
    for (int i = 0; i < 10; i++) {
        if (alienSymbols[i].symbol == symbol) {
            return alienSymbols[i].value;
        }
    }
    // If symbol not found, return -1
    return -1;
}

// Function to translate human text to alien language
void translateToAlien(char *text) {
    for (int i = 0; text[i] != '\0'; i++) {
        // If character is a letter, translate it to alien symbol
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z')) {
            int symbolValue = getAlienSymbolValue(text[i]);
            if (symbolValue != -1) {
                printf("%c", alienSymbols[symbolValue - 1].symbol);
            } else {
                printf("?"); // Unknown human symbol, print question mark
            }
        } else {
            // If character is not a letter, print it as is
            printf("%c", text[i]);
        }
    }
    printf("\n");
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <human text>\n", argv[0]);
        return 1;
    }

    translateToAlien(argv[1]);
    return 0;
}