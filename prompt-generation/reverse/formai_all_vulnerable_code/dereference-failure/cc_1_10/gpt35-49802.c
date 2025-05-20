//FormAI DATASET v1.0 Category: Spell checking ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// A dynamic array to store the dictionary words
char **dictionary;
int dictSize = 0;

// Add a word to the dictionary
void addWordToDictionary(char *word) {
    dictionary = (char**) realloc(dictionary, (dictSize + 1) * sizeof(char*));
    dictionary[dictSize] = (char*) malloc((strlen(word) + 1) * sizeof(char));
    strcpy(dictionary[dictSize], word);
    dictSize++;
}

// Check if a word is in the dictionary
int isWordInDictionary(char *word) {
    int i;
    for (i = 0; i < dictSize; i++) {
        if (strcmp(word, dictionary[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

// Check if a character is alphabetic
int isAlpha(char c) {
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) {
        return 1;
    }
    return 0;
}

// Check if a character is non-alphabetic
int isNonAlpha(char c) {
    if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
        return 1;
    }
    return 0;
}

// Convert a string to lower case
void toLower(char *str) {
    int i;
    for (i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Check if a word is misspelled
void spellCheckWord(char *word) {
    if (!isWordInDictionary(word)) {
        printf("%s", word);
        if (isNonAlpha(word[strlen(word) - 1])) {
            printf(" ");
        }
        else {
            printf("\n");
        }
    }
}

// Spell check a sentence
void spellCheck(char *sentence) {
    // Tokenize the sentence into words
    char *word;
    word = strtok(sentence, " ");
    while (word != NULL) {
        // Strip any non-alpha characters from the beginning and end of the word
        while (word[0] && !isAlpha(word[0])) {
            word++;
        }
        int len = strlen(word);
        while (len > 0 && !isAlpha(word[len - 1])) {
            word[len - 1] = '\0';
            len--;
        }

        // Convert the word to lower case
        toLower(word);

        // Check if the word is misspelled
        spellCheckWord(word);

        // Get the next word
        word = strtok(NULL, " ");
    }
}

// The main function
int main() {
    // Read the dictionary file
    FILE *fp;
    fp = fopen("dictionary.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char word[30];
    while (fscanf(fp, "%s", word) != EOF) {
        addWordToDictionary(word);
    }
    fclose(fp);

    // Read the input file
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Unable to open file.\n");
        return 1;
    }
    char sentence[100];
    while (fgets(sentence, 100, fp)) {
        // Remove the newline character from the end of the sentence
        sentence[strlen(sentence) - 1] = '\0';

        // Spell check the sentence
        spellCheck(sentence);
    }
    fclose(fp);
    return 0;
}