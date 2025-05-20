//Falcon2-11B DATASET v1.0 Category: Alien Language Translator ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>

// Function to check if a word is in the dictionary
bool checkDictionary(const char* word) {
    FILE* dictFile = fopen("alien_dictionary.txt", "r");
    char buffer[100];
    bool found = false;
    
    while (fgets(buffer, sizeof(buffer), dictFile)!= NULL) {
        char* token = strtok(buffer, "\n");
        if (strcmp(word, token) == 0) {
            found = true;
            break;
        }
    }
    
    fclose(dictFile);
    return found;
}

// Function to translate a word from the alien language to English
char* translate(const char* word) {
    FILE* dictFile = fopen("alien_dictionary.txt", "r");
    char buffer[100];
    char* translatedWord = (char*)malloc(100 * sizeof(char));
    
    while (fgets(buffer, sizeof(buffer), dictFile)!= NULL) {
        char* token = strtok(buffer, "\n");
        if (strcmp(word, token) == 0) {
            strcpy(translatedWord, token);
            break;
        }
    }
    
    fclose(dictFile);
    return translatedWord;
}

int main() {
    char word[100];
    printf("Enter an alien word to translate: ");
    fgets(word, sizeof(word), stdin);
    
    if (checkDictionary(word)) {
        char* translatedWord = translate(word);
        printf("Translation: %s\n", translatedWord);
        free(translatedWord);
    } else {
        printf("Word not found in the dictionary.\n");
    }
    
    return 0;
}