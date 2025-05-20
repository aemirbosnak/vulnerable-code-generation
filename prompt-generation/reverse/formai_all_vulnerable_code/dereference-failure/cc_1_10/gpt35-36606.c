//FormAI DATASET v1.0 Category: Spell checking ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to check whether a character is a letter
int isLetter(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

// Function to convert a word to lowercase
void toLowercase(char *word) {
    int i = 0;
    while (word[i]) {
        word[i] = tolower(word[i]);
        i++;
    }
}

// Function to compare two words ignoring case
int stricmp(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        int diff = tolower(*s1) - tolower(*s2);
        if (diff != 0) {
            return diff;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

// Function to find a word in the dictionary
int findWord(char **dict, int dictSize, char *word) {
    int i;
    for (i = 0; i < dictSize; i++) {
        if (stricmp(dict[i], word) == 0) {
            return 1;
        }
    }
    return 0;
}

// Function to read a word from the input file
char *readWord(FILE *file) {
    char buffer[100];
    int i = 0;

    while (!isLetter(fgetc(file)) && !feof(file)) {
        // Skip non-letters
    }

    if (feof(file)) {
        return NULL;
    }

    buffer[i++] = fgetc(file);
    while (isLetter(fgetc(file)) && !feof(file) && i < sizeof(buffer)-1) {
        buffer[i++] = fgetc(file);
    }

    buffer[i] = '\0';

    char *word = (char*) malloc(i+1);
    strcpy(word, buffer);

    return word;
}

int main() {
    char **dict;    // Dictionary array
    int dictSize = 0;   // Dictionary size
    char *word; // Current word being checked
    
    // Read dictionary file
    FILE *dictFile = fopen("dictionary.txt", "r");
    if (dictFile == NULL) {
        fprintf(stderr, "Error: Could not open dictionary file\n");
        exit(1);
    }

    dict = (char**) malloc(sizeof(char*));
    while ((word = readWord(dictFile)) != NULL) {
        dict = (char**) realloc(dict, (dictSize+1) * sizeof(char*));
        toLowercase(word);
        dict[dictSize++] = word;
    }

    fclose(dictFile);

    // Check input file for spelling errors
    FILE *inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error: Could not open input file\n");
        exit(1);
    }

    printf("Potential spelling errors:\n");
    while ((word = readWord(inputFile)) != NULL) {
        int isCorrect = findWord(dict, dictSize, word);
        if (!isCorrect) {
            printf("%s\n", word);
        }
        free(word);
    }

    // Clean up
    int i;
    for (i = 0; i < dictSize; i++) {
        free(dict[i]);
    }
    free(dict);
    fclose(inputFile);

    return 0;
}