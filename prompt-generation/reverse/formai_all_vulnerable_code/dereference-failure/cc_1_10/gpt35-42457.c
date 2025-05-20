//FormAI DATASET v1.0 Category: Spell checking ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define WORD_LENGTH 30

int compareWords(char *word, char *dictionary) {
    // compare word with dictionary
    int result = strcmp(word, dictionary);
    if (result == 0) { // words are equal
        return 1;
    } else if (result < 0) { // word is before dictionary
        return -1;
    } else { // word is after dictionary
        return 0;
    }
}

int checkSpelling(char *word, char **dictionary, int dictSize) {
    // check if word is in dictionary
    int i;
    for (i = 0; i < dictSize; i++) {
        int comparison = compareWords(word, dictionary[i]);
        if (comparison == 1) { // word is in dictionary
            return 1;
        } else if (comparison == -1) { // word is before dictionary
            return 0;
        }
    }
    // word is after last dictionary word
    return 0;
}

int main() {
    // read dictionary from file
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        printf("Error: could not open dictionary file\n");
        return 1;
    }
    int dictSize = 0;
    char **dictionary = malloc(sizeof(char *));
    char buffer[WORD_LENGTH];
    while (fscanf(dictFile, "%s", buffer) != EOF) {
        // add word to dictionary
        dictSize++;
        dictionary = realloc(dictionary, sizeof(char *) * dictSize);
        dictionary[dictSize - 1] = malloc(sizeof(char) * (strlen(buffer) + 1));
        strcpy(dictionary[dictSize - 1], buffer);
    }
    fclose(dictFile);

    // read text from user input
    char **text = malloc(sizeof(char *));
    int textLength = 0;
    int wordLength = 0;
    char c;
    while ((c = getchar()) != EOF && c != '\n') {
        if (isspace(c)) { // word is finished
            if (wordLength > 0) {
                // add word to text
                textLength++;
                text = realloc(text, sizeof(char *) * textLength);
                text[textLength - 1] = malloc(sizeof(char) * (wordLength + 1));
                memcpy(text[textLength - 1], buffer, wordLength);
                text[textLength - 1][wordLength] = '\0';
                wordLength = 0;
            }
        } else { // add character to word
            if (isalpha(c)) {
                buffer[wordLength] = tolower(c);
                wordLength++;
            }
        }
    }

    // check spelling of each word in text
    int i;
    for (i = 0; i < textLength; i++) {
        if (!checkSpelling(text[i], dictionary, dictSize)) {
            printf("%s is misspelled\n", text[i]);
        }
    }

    // free memory
    for (i = 0; i < dictSize; i++) {
        free(dictionary[i]);
    }
    free(dictionary);
    for (i = 0; i < textLength; i++) {
        free(text[i]);
    }
    free(text);

    return 0;
}