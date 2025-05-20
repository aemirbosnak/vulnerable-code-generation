//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

Word wordList[MAX_WORDS];
int wordCount = 0;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void addWord(const char *word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordList[i].word, word) == 0) {
            wordList[i].count++;
            return;
        }
    }
    strcpy(wordList[wordCount].word, word);
    wordList[wordCount].count = 1;
    wordCount++;
}

void readWordsFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%99s", word) != EOF) {
        toLowerCase(word);
        // Remove punctuation from the word
        char *p = word;
        while (*p) {
            if (ispunct((unsigned char)*p) || isspace((unsigned char)*p)) {
                *p = '\0';
                break;
            }
            p++;
        }
        if (strlen(word) > 0) {
            addWord(word);
        }
    }
    fclose(file);
}

int compareWords(const void *a, const void *b) {
    Word *wordA = (Word *)a;
    Word *wordB = (Word *)b;
    return wordB->count - wordA->count;  // sort by frequency descending
}

void printTopWords(int N) {
    printf("Top %d words:\n", N);
    for (int i = 0; i < N && i < wordCount; i++) {
        printf("%s: %d\n", wordList[i].word, wordList[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <filename> <top N words>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    int topN = atoi(argv[2]);

    readWordsFromFile(filename);

    qsort(wordList, wordCount, sizeof(Word), compareWords);

    printTopWords(topN);

    return EXIT_SUCCESS;
}