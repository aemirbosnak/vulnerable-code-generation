//GPT-4o-mini DATASET v1.0 Category: Text processing ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

void addWord(WordCount *wordCounts, int *wordCountSize, const char *word) {
    for (int i = 0; i < *wordCountSize; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].count++;
            return;
        }
    }
    strcpy(wordCounts[*wordCountSize].word, word);
    wordCounts[*wordCountSize].count = 1;
    (*wordCountSize)++;
}

void sortWords(WordCount *wordCounts, int wordCountSize) {
    for (int i = 0; i < wordCountSize - 1; i++) {
        for (int j = 0; j < wordCountSize - i - 1; j++) {
            if (wordCounts[j].count < wordCounts[j + 1].count) {
                WordCount temp = wordCounts[j];
                wordCounts[j] = wordCounts[j + 1];
                wordCounts[j + 1] = temp;
            }
        }
    }
}

void printTopWords(WordCount *wordCounts, int wordCountSize, int topN) {
    printf("\nTop %d words:\n", topN);
    for (int i = 0; i < topN && i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

void processTextFile(const char *filename, int topN) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Unable to open file");
        exit(EXIT_FAILURE);
    }

    WordCount wordCounts[MAX_WORDS] = {0};
    int wordCountSize = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, " \n");
        while (token) {
            addWord(wordCounts, &wordCountSize, token);
            token = strtok(NULL, " \n");
        }
    }
    fclose(file);

    sortWords(wordCounts, wordCountSize);
    printTopWords(wordCounts, wordCountSize, topN);
}

int main(int argc, char *argv[]) {
    printf("Welcome to the Text Processing Machine!\n");
    if (argc != 3) {
        printf("Usage: %s <filename> <topN>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    int topN = atoi(argv[2]);
    if (topN <= 0) {
        printf("Please enter a positive number for topN.\n");
        exit(EXIT_FAILURE);
    }

    processTextFile(filename, topN);

    printf("Text processing complete! Check the top words above.\n");
    return 0;
}