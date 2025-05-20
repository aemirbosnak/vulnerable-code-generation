//FormAI DATASET v1.0 Category: Alien Language Translator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to determine whether a string is in the C Alien Language
int isInAlienLanguage(char* word, char* alienLanguage) {
    for (int i = 0; word[i]; i++) {
        char currentChar = word[i];
        int index = strchr(alienLanguage, currentChar) - alienLanguage;
        if (index == strlen(alienLanguage)) {
            return 0;
        }
    }
    return 1;
}

// Function to translate a word from the C Alien Language to English
char* translateToEnglish(char* word, char* alienLanguage, char* englishLanguage) {
    char* translatedWord = (char*) malloc(strlen(word) + 1);
    for (int i = 0; word[i]; i++) {
        char currentChar = word[i];
        int index = strchr(alienLanguage, currentChar) - alienLanguage;
        translatedWord[i] = englishLanguage[index];
    }
    translatedWord[strlen(word)] = '\0';
    return translatedWord;
}

int main() {
    char* alienLanguage = "ABCDKLMNOPQRSTUVWXYZ";
    char* englishLanguage = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int numWords;
    scanf("%d", &numWords);
    char** words = (char**) malloc(sizeof(char*) * numWords);
    for (int i = 0; i < numWords; i++) {
        words[i] = (char*) malloc(101);
        scanf("%s", words[i]);
    }
    for (int i = 0; i < numWords; i++) {
        char* currentWord = words[i];
        int isAlienLanguage = isInAlienLanguage(currentWord, alienLanguage);
        if (!isAlienLanguage) {
            printf("%s", currentWord);
        } else {
            char* translatedWord = translateToEnglish(currentWord, alienLanguage, englishLanguage);
            printf("%s", translatedWord);
            free(translatedWord);
        }
        if (i != numWords - 1) {
            printf(" ");
        }
    }
    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }
    free(words);
    return 0;
}