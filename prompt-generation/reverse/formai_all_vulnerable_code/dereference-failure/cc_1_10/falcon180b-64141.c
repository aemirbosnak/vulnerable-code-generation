//Falcon-180B DATASET v1.0 Category: Spell checking ; Style: invasive
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Function to check if a word is in the dictionary
bool isWord(char *word) {
    FILE *dict;
    char ch;
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: Dictionary not found.\n");
        exit(1);
    }
    while ((ch = fgetc(dict))!= EOF) {
        if (ch == '\n') {
            continue;
        }
        if (strcmp(word, ch) == 0) {
            fclose(dict);
            return true;
        }
    }
    fclose(dict);
    return false;
}

// Function to suggest corrections for misspelled words
void suggestCorrection(char *word) {
    char *correctWord = NULL;
    char *suggestion = NULL;
    int i, j, k, len, minLen = 1000;
    FILE *dict;
    dict = fopen("dictionary.txt", "r");
    if (dict == NULL) {
        printf("Error: Dictionary not found.\n");
        exit(1);
    }
    while ((correctWord = fgets(correctWord, 1000, dict))!= NULL) {
        len = strlen(correctWord);
        if (len < minLen) {
            minLen = len;
            suggestion = correctWord;
        }
    }
    fclose(dict);
    if (suggestion == NULL) {
        printf("No suggestions found.\n");
    } else {
        printf("Did you mean %s?\n", suggestion);
    }
}

// Function to check spelling of a sentence
void checkSpelling(char *sentence) {
    char *word = strtok(sentence, " ");
    while (word!= NULL) {
        if (!isWord(word)) {
            suggestCorrection(word);
        }
        word = strtok(NULL, " ");
    }
}

int main() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, 1000, stdin);
    checkSpelling(sentence);
    return 0;
}