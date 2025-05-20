//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char* word;
    int count;
} WordFreq;

void addWord(WordFreq* data, char* word) {
    for(int i = 0; i < MAX_WORDS; i++) {
        if(data[i].word == NULL) {
            data[i].word = strdup(word);
            data[i].count++;
            return;
        }
        if(strcmp(data[i].word, word) == 0) {
            data[i].count++;
            return;
        }
    }
}

void printResults(WordFreq* data) {
    printf("Word Frequency:\n");
    printf("---------------\n");
    for(int i = 0; i < MAX_WORDS; i++) {
        if(data[i].word != NULL) {
            printf("%d %s\n", data[i].count, data[i].word);
        }
        else {
            return;
        }
    }
}

int main() {
    char* text;
    text = (char*) malloc(MAX_WORD_LENGTH * MAX_WORDS * sizeof(char));
    fgets(text, MAX_WORD_LENGTH * MAX_WORDS, stdin);

    // Remove punctuation and convert to lowercase
    for(int i = 0; i < strlen(text); i++) {
        if(isalpha(text[i])) {
            text[i] = tolower(text[i]);
        }
        else {
            text[i] = ' ';
        }
    }

    // Tokenize and count words
    char* token;
    WordFreq data[MAX_WORDS];
    token = strtok(text, " ");
    while(token != NULL) {
        addWord(data, token);
        token = strtok(NULL, " ");
    }

    // Print results
    printResults(data);
    
    free(text);
    for(int i = 0; i < MAX_WORDS; i++) {
        free(data[i].word);
    }
    return 0;
}