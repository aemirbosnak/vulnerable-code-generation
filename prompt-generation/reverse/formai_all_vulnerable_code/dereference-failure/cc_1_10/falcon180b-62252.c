//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: energetic
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wc1 = a;
    const WordCount *wc2 = b;

    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE *inputFile;
    char line[1000];
    char *word;
    WordCount *wordCounts = malloc(MAX_WORDS * sizeof(WordCount));
    int numWords = 0;

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *token = strtok(line, ",.!?;:\"'()[]{}<>");

        while (token!= NULL) {
            int wordLength = strlen(token);

            if (wordLength > MAX_WORD_LENGTH) {
                printf("Warning: word \"%s\" is too long and will be truncated.\n", token);
                wordLength = MAX_WORD_LENGTH;
            }

            strncpy(wordCounts[numWords].word, token, MAX_WORD_LENGTH);
            wordCounts[numWords].word[wordLength] = '\0';
            wordCounts[numWords].count = 1;

            numWords++;

            token = strtok(NULL, ",.!?;:\"'()[]{}<>");
        }
    }

    fclose(inputFile);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    printf("Word\tCount\n");

    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    free(wordCounts);

    return 0;
}