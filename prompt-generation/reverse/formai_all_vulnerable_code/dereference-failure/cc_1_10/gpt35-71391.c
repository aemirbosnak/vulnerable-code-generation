//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char* word;
    int count;
} WordCount;

char* readWord(FILE* file) {
    char* word = malloc(sizeof(char) * MAX_WORD_LENGTH);
    int i = 0;
    char c;
    while ((c = fgetc(file)) != EOF) {
        if (isalpha(c)) {
            word[i++] = tolower(c);
        }
        else if (i != 0) {
            break;
        }
    }
    if (i == 0) {
        free(word);
        return NULL;
    }
    word[i] = '\0';
    return word;
}

int compareWordCounts(const void* a, const void* b) {
    WordCount* wcA = (WordCount*) a;
    WordCount* wcB = (WordCount*) b;
    return strcmp(wcA->word, wcB->word);
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: wordFreq <filename>\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        return 2;
    }

    WordCount* wordCounts = malloc(sizeof(WordCount));
    int wordCountSize = 0;
    char* word;
    while ((word = readWord(file)) != NULL) {
        int i;
        for (i = 0; i < wordCountSize; i++) {
            if (strcmp(wordCounts[i].word, word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == wordCountSize) {
            wordCounts = realloc(wordCounts, sizeof(WordCount) * (wordCountSize + 1));
            wordCounts[wordCountSize].word = word;
            wordCounts[wordCountSize].count = 1;
            wordCountSize++;
        }
        else {
            free(word);
        }
    }

    qsort(wordCounts, wordCountSize, sizeof(WordCount), compareWordCounts);

    printf("Word Frequency Count for %s:\n", filename);
    printf("-----------------------------\n");
    int totalWords = 0;
    for (int i = 0; i < wordCountSize; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
        totalWords += wordCounts[i].count;
    }
    printf("-----------------------------\n");
    printf("Total unique words: %d\n", wordCountSize);
    printf("Total words: %d\n", totalWords);

    for (int i = 0; i < wordCountSize; i++) {
        free(wordCounts[i].word);
    }
    free(wordCounts);
    fclose(file);

    return 0;
}