//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int findWord(WordCount *wordCounts, char *word, int numWords) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(WordCount *wordCounts, char *word, int *numWords) {
    int index = findWord(wordCounts, word, *numWords);
    if (index >= 0) {
        wordCounts[index].count++;
    } else {
        strcpy(wordCounts[*numWords].word, word);
        wordCounts[*numWords].count = 1;
        (*numWords)++;
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    printf("Word Frequency Count:\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void processText(FILE *file) {
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%49s", word) == 1) {
        toLowerCase(word);
        // Remove punctuation from the end of the word
        char *p = word + strlen(word) - 1;
        while (p >= word && ispunct(*p)) {
            *p = '\0';
            p--;
        }
        // Only add non-empty words
        if (strlen(word) > 0) {
            addWord(wordCounts, word, &numWords);
        }
    }
    printWordCounts(wordCounts, numWords);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    processText(file);
    fclose(file);
    return 0;
}