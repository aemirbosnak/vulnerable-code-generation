//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wcA = (const WordCount*)a;
    const WordCount* wcB = (const WordCount*)b;

    return strcmp(wcA->word, wcB->word);
}

void countWords(char* text, WordCount* wordCounts, int numWordCounts) {
    char* word = strtok(text, ",.?!;:");
    while (word!= NULL) {
        int i;
        for (i = 0; i < numWordCounts; i++) {
            if (strcmp(word, wordCounts[i].word) == 0) {
                wordCounts[i].count++;
                break;
            }
        }
        if (i == numWordCounts) {
            if (numWordCounts == MAX_WORD_LENGTH) {
                printf("Error: Too many words.\n");
                exit(1);
            }
            strncpy(wordCounts[numWordCounts].word, word, MAX_WORD_LENGTH - 1);
            wordCounts[numWordCounts].word[MAX_WORD_LENGTH - 1] = '\0';
            wordCounts[numWordCounts].count = 1;
            numWordCounts++;
        }
        word = strtok(NULL, ",.?!;:");
    }
}

void printWordCounts(WordCount* wordCounts, int numWordCounts) {
    qsort(wordCounts, numWordCounts, sizeof(WordCount), compareWords);

    printf("Word Count:\n");
    for (int i = 0; i < numWordCounts; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    char* text = NULL;
    size_t textSize = 0;
    if (fread(text, 1, MAX_WORD_LENGTH, file)!= 0) {
        text[textSize - 1] = '\0';
        textSize--;
    }
    fclose(file);

    WordCount wordCounts[MAX_WORD_LENGTH];
    int numWordCounts = 0;
    countWords(text, wordCounts, MAX_WORD_LENGTH);

    printWordCounts(wordCounts, numWordCounts);

    free(text);
    return 0;
}