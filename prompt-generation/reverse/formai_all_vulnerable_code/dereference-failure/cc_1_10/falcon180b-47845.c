//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORD_LENGTH 100

// Function to check if a word is in the dictionary
bool isInDictionary(const char *word) {
    FILE *dictionaryFile = fopen("dictionary.txt", "r");
    char dictionaryWord[MAX_WORD_LENGTH];
    char *wordToCheck = strdup(word);
    tolower(wordToCheck);
    while (fscanf(dictionaryFile, "%s", dictionaryWord)!= EOF) {
        if (strcmp(wordToCheck, dictionaryWord) == 0) {
            free(wordToCheck);
            return true;
        }
    }
    free(wordToCheck);
    return false;
}

// Function to check if a word is a valid English word
bool isValidWord(const char *word) {
    int length = strlen(word);
    if (length <= 2 || length > MAX_WORD_LENGTH) {
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}

// Function to suggest corrections for a misspelled word
void suggestCorrections(const char *word) {
    char correctedWord[MAX_WORD_LENGTH];
    strcpy(correctedWord, word);
    for (int i = 0; i < strlen(correctedWord); i++) {
        if (isalpha(correctedWord[i])) {
            correctedWord[i] = toupper(correctedWord[i]);
        }
    }
    printf("Did you mean: %s\n", correctedWord);
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    char *token = strtok(sentence, " ");
    while (token!= NULL) {
        if (isValidWord(token)) {
            if (isInDictionary(token)) {
                printf("%s is spelled correctly.\n", token);
            } else {
                suggestCorrections(token);
            }
        } else {
            printf("%s is not a valid English word.\n", token);
        }
        token = strtok(NULL, " ");
    }
    return 0;
}