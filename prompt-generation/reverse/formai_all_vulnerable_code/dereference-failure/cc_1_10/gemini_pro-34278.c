//GEMINI-pro DATASET v1.0 Category: Alien Language Translator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Alien language dictionary
char alienDict[26][10] = {
    "A", "Bb", "Ccc", "Dd", "Ee", "Fff", "Ggg", "Hhh", "Iii", "Jjj",
    "Kkk", "Lll", "Mmm", "Nnn", "Ooo", "Ppp", "Qqq", "Rrr", "Sss", "Ttt",
    "Uuu", "Vvv", "Www", "Xxxx", "Yyyy", "Zzzz"
};

// Function to translate a human language word to Alien language
char* translateToAlien(char* humanWord) {
    int len = strlen(humanWord);
    char* alienWord = malloc(len * 10 + 1); // Allocate memory for the Alien word

    int i, j;
    for (i = 0, j = 0; i < len; i++) {
        char c = humanWord[i];
        if (c >= 'A' && c <= 'Z') {
            strcpy(alienWord + j, alienDict[c - 'A']);
            j += strlen(alienDict[c - 'A']);
        } else if (c >= 'a' && c <= 'z') {
            strcpy(alienWord + j, alienDict[c - 'a']);
            j += strlen(alienDict[c - 'a']);
        } else {
            alienWord[j++] = c;
        }
    }
    alienWord[j] = '\0'; // Null-terminate the Alien word

    return alienWord;
}

// Function to translate an Alien language word to human language
char* translateFromAlien(char* alienWord) {
    int len = strlen(alienWord);
    char* humanWord = malloc(len + 1); // Allocate memory for the human word

    int i, j;
    for (i = 0, j = 0; i < len;) {
        char c = alienWord[i];
        if (c >= 'A' && c <= 'Z') {
            for (int k = 0; k < 26; k++) {
                if (strcmp(alienDict[k], alienWord + i) == 0) {
                    humanWord[j++] = k + 'A';
                    i += strlen(alienDict[k]);
                    break;
                }
            }
        } else if (c >= 'a' && c <= 'z') {
            for (int k = 0; k < 26; k++) {
                if (strcmp(alienDict[k], alienWord + i) == 0) {
                    humanWord[j++] = k + 'a';
                    i += strlen(alienDict[k]);
                    break;
                }
            }
        } else {
            humanWord[j++] = c;
            i++;
        }
    }
    humanWord[j] = '\0'; // Null-terminate the human word

    return humanWord;
}

int main() {
    // Get the human language word from the user
    char humanWord[100];
    printf("Enter a human language word: ");
    scanf("%s", humanWord);

    // Translate the human language word to Alien language
    char* alienWord = translateToAlien(humanWord);

    // Print the Alien language word
    printf("Alien language word: %s\n", alienWord);

    // Translate the Alien language word back to human language
    char* translatedHumanWord = translateFromAlien(alienWord);

    // Print the translated human language word
    printf("Translated human language word: %s\n", translatedHumanWord);

    // Free the allocated memory
    free(alienWord);
    free(translatedHumanWord);

    return 0;
}