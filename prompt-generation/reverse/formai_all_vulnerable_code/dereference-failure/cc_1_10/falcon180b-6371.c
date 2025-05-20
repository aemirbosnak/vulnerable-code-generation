//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LENGTH 1024
#define MAX_WORD_LENGTH 64

typedef struct {
    char* word;
    int frequency;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    WordFrequency* wordA = (WordFrequency*)a;
    WordFrequency* wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* file;
    char* line = NULL;
    size_t lineSize = 0;
    char* word = NULL;
    size_t wordSize = 0;
    WordFrequency* wordFrequencies = NULL;
    int numWords = 0;

    file = fopen("example.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while ((getline(&line, &lineSize, file))!= -1) {
        word = strtok(line, ",.?!;:");
        while (word!= NULL) {
            wordSize = strlen(word);
            if (wordSize > MAX_WORD_LENGTH) {
                printf("Error: Word '%s' is too long.\n", word);
                return 2;
            }

            if (numWords == 0) {
                wordFrequencies = malloc(sizeof(WordFrequency));
            } else {
                wordFrequencies = realloc(wordFrequencies, sizeof(WordFrequency) * (numWords + 1));
            }

            wordFrequencies[numWords].word = strdup(word);
            wordFrequencies[numWords].frequency = 1;
            numWords++;

            word = strtok(NULL, ",.?!;:");
        }
    }

    qsort(wordFrequencies, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    free(line);
    free(word);
    for (int i = 0; i < numWords; i++) {
        free(wordFrequencies[i].word);
    }
    free(wordFrequencies);

    return 0;
}