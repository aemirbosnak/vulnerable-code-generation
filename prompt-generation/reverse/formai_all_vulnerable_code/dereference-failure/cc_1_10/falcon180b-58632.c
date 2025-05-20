//Falcon-180B DATASET v1.0 Category: Database Indexing System ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_SIZE 100
#define MAX_NUM_WORDS 1000

// Function to remove all punctuation marks from a string
void removePunctuation(char *str) {
    int i, j;
    for (i = 0, j = 0; str[i]!= '\0'; i++) {
        if (!isspace(str[i]) &&!ispunct(str[i])) {
            str[j++] = tolower(str[i]);
        }
    }
    str[j] = '\0';
}

// Function to split a string into words
void splitWords(char *str, char words[MAX_NUM_WORDS][MAX_WORD_SIZE]) {
    char *token = strtok(str, " ");
    int numWords = 0;

    while (token!= NULL) {
        strcpy(words[numWords], token);
        numWords++;
        token = strtok(NULL, " ");
    }
}

// Function to build an inverted index
void buildIndex(char words[MAX_NUM_WORDS][MAX_WORD_SIZE], int numWords, FILE *indexFile) {
    int i;
    for (i = 0; i < numWords; i++) {
        fprintf(indexFile, "%s\t%d\n", words[i], i);
    }
}

// Function to search the index for a keyword
int searchIndex(char keyword[MAX_WORD_SIZE], FILE *indexFile) {
    char line[MAX_WORD_SIZE];
    int result = -1;

    rewind(indexFile);
    while (fgets(line, MAX_WORD_SIZE, indexFile)!= NULL) {
        char *token = strtok(line, "\t");
        if (strcmp(token, keyword) == 0) {
            result = atoi(strtok(NULL, "\n"));
            break;
        }
    }

    return result;
}

int main() {
    char inputText[MAX_WORD_SIZE];
    char words[MAX_NUM_WORDS][MAX_WORD_SIZE];
    int numWords;
    FILE *indexFile;

    printf("Enter the text to be indexed:\n");
    fgets(inputText, MAX_WORD_SIZE, stdin);

    // Remove punctuation marks and convert to lowercase
    removePunctuation(inputText);

    // Split the text into words
    splitWords(inputText, words);
    numWords = strlen(words[0]);

    // Build the inverted index
    indexFile = fopen("index.txt", "w");
    buildIndex(words, numWords, indexFile);
    fclose(indexFile);

    // Search the index for a keyword
    char keyword[MAX_WORD_SIZE];
    printf("Enter the keyword to search for:\n");
    fgets(keyword, MAX_WORD_SIZE, stdin);

    int result = searchIndex(keyword, indexFile);

    if (result == -1) {
        printf("Keyword not found.\n");
    } else {
        printf("Keyword found in document %d.\n", result + 1);
    }

    return 0;
}