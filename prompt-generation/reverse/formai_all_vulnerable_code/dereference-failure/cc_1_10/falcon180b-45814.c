//Falcon-180B DATASET v1.0 Category: Cat Language Translator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void readFile(FILE *file, char *text) {
    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);
    text = (char *) malloc((fileSize + 1) * sizeof(char));
    fread(text, fileSize, 1, file);
    text[fileSize] = '\0';
}

void tokenize(char *text, char **tokens, int *numTokens) {
    int i = 0;
    char *token = strtok(text, ",.!?;:");
    while (token!= NULL) {
        tokens[i] = token;
        i++;
        token = strtok(NULL, ",.!?;:");
    }
    *numTokens = i;
}

void countWords(char **tokens, int numTokens, WordCount *wordCounts, int numWordCounts) {
    for (int i = 0; i < numTokens; i++) {
        int wordIndex = -1;
        for (int j = 0; j < numWordCounts; j++) {
            if (strcmp(tokens[i], wordCounts[j].word) == 0) {
                wordIndex = j;
                break;
            }
        }
        if (wordIndex == -1) {
            if (numWordCounts >= MAX_WORDS) {
                printf("Error: Maximum number of words exceeded.\n");
                exit(1);
            }
            strcpy(wordCounts[numWordCounts].word, tokens[i]);
            numWordCounts++;
        }
        wordCounts[wordIndex].count++;
    }
}

void printWordCounts(WordCount *wordCounts, int numWordCounts) {
    printf("Word Counts:\n");
    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error: Please specify a file to analyze.\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }
    char *text = NULL;
    readFile(file, text);
    fclose(file);

    char **tokens = (char **) malloc((MAX_WORDS + 1) * sizeof(char *));
    int numTokens = 0;
    tokenize(text, tokens, &numTokens);

    WordCount *wordCounts = (WordCount *) malloc((MAX_WORDS + 1) * sizeof(WordCount));
    int numWordCounts = 0;
    countWords(tokens, numTokens, wordCounts, &numWordCounts);

    printWordCounts(wordCounts, numWordCounts);

    for (int i = 0; i < numWordCounts; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);

    for (int i = 0; i < numTokens; i++) {
        free(tokens[i]);
    }
    free(tokens);

    free(text);

    return 0;
}