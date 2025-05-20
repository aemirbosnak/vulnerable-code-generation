//FormAI DATASET v1.0 Category: Spell checking ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100 // Maximum size of word to be checked
#define MAX_DICTIONARY_SIZE 3000 // Maximum number of words in dictionary

// Function to convert a word to lowercase
void toLowercase(char *word) {
    int i;
    for (i = 0; word[i] != '\0'; i++) {
        word[i] = tolower(word[i]);
    }
}

// Function to check if a word is present in the dictionary
int checkDictionary(char *word, char **dictionary, int numOfWords) {
    int i;
    for (i = 0; i < numOfWords; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to get suggestions for a misspelled word
void getSuggestions(char *word, char **dictionary, int numOfWords) {
    int i, j, k, len;
    char temp[MAX_WORD_SIZE];
    len = strlen(word);
    int flag = 0;

    // Swap adjacent characters in the word and check against dictionary
    for (i = 0; i < len - 1; i++) {
        strcpy(temp, word);
        temp[i] = word[i+1];
        temp[i+1] = word[i];
        if (checkDictionary(temp, dictionary, numOfWords)) {
            printf("Did you mean: %s\n", temp);
            flag = 1;
        }
    }

    // Replace each character in the word with other alphabets
    for (i = 0; i < len; i++) {
        strcpy(temp, word);
        for (j = 'a'; j <= 'z'; j++) {
            temp[i] = j;
            if (checkDictionary(temp, dictionary, numOfWords)) {
                printf("Did you mean: %s\n", temp);
                flag = 1;
            }
        }
    }

    // Add each alphabet between two adjacent characters of the word
    for (i = 0; i < len; i++) {
        for (j = 'a'; j <= 'z'; j++) {
            strcpy(temp, "");
            sprintf(temp, "%.*s%c%s", i, word, j, word + i);
            if (checkDictionary(temp, dictionary, numOfWords)) {
                printf("Did you mean: %s\n", temp);
                flag = 1;
            }
        }
    }

    // Delete each character from the word
    for (i = 0; i < len; i++) {
        strcpy(temp, "");
        for (j = 0; word[j] != '\0'; j++) {
            if (j != i) {
                sprintf(temp + strlen(temp), "%c", word[j]);
            }
        }
        if (checkDictionary(temp, dictionary, numOfWords)) {
            printf("Did you mean: %s\n", temp);
            flag = 1;
        }
    }

    if (!flag) {
        printf("No suggestions found\n");
    }
}

int main() {
    char **dictionary = (char**) malloc(MAX_DICTIONARY_SIZE * sizeof(char*));
    int numOfWords = 0, i;
    char word[MAX_WORD_SIZE];

    printf("Enter dictionary words and type q to exit\n");
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "q") == 0) {
            break;
        }
        toLowercase(word);
        dictionary[numOfWords] = (char*) malloc(strlen(word) * sizeof(char));
        strcpy(dictionary[numOfWords], word);
        numOfWords++;
    }

    printf("Enter word to be checked and type q to exit\n");
    while (1) {
        scanf("%s", word);
        if (strcmp(word, "q") == 0) {
            break;
        }
        toLowercase(word);
        if (checkDictionary(word, dictionary, numOfWords)) {
            printf("Word is correct\n");
        }
        else {
            printf("Word is incorrect\nSuggestions:\n");
            getSuggestions(word, dictionary, numOfWords);
        }
    }

    for (i = 0; i < numOfWords; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    return 0;
}