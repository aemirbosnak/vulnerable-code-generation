//Falcon-180B DATASET v1.0 Category: Text processing ; Style: rigorous
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readTextFile(FILE *file, char *text) {
    char c;
    int i = 0;
    while ((c = fgetc(file))!= EOF) {
        text[i++] = tolower(c);
    }
    text[i] = '\0';
}

void tokenize(char *text, char **tokens) {
    char *token = strtok(text, ",.?!;:\"'");
    int i = 0;
    while (token!= NULL) {
        tokens[i++] = token;
        token = strtok(NULL, ",.?!;:\"'");
    }
}

void countWords(char **tokens, WordCount *wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        WordCount *word = wordCounts + i;
        int j;
        for (j = 0; j < MAX_WORD_LENGTH; j++) {
            if (tokens[i][j] == '\0') {
                word->word[j] = '\0';
                break;
            }
            word->word[j] = tokens[i][j];
        }
        word->count = 1;
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    int i;
    for (i = 0; i < numWords; i++) {
        WordCount *word = wordCounts + i;
        printf("%s: %d\n", word->word, word->count);
    }
}

int main() {
    FILE *file;
    char text[MAX_WORD_LENGTH * 1000];
    char *tokens[MAX_WORDS];
    WordCount wordCounts[MAX_WORDS];

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    readTextFile(file, text);
    fclose(file);

    tokenize(text, tokens);
    countWords(tokens, wordCounts, MAX_WORDS);
    printWordCounts(wordCounts, MAX_WORDS);

    return 0;
}