//Falcon-180B DATASET v1.0 Category: Text processing ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    const WordCount *wordA = a;
    const WordCount *wordB = b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char line[2048];
    char *word = NULL;
    size_t wordLength = 0;
    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    while (fgets(line, sizeof(line), file)!= NULL) {
        char *p = line;
        while ((word = strtok_r(p, " \t\n\r\f\v", &p))!= NULL) {
            wordLength = strlen(word);
            if (wordLength > MAX_WORD_LENGTH - 1) {
                printf("Error: word '%s' is too long.\n", word);
                return 1;
            }
            strncpy(wordCounts[numWords].word, word, MAX_WORD_LENGTH);
            wordCounts[numWords].word[wordLength] = '\0';
            wordCounts[numWords].count = 1;
            numWords++;
        }
    }

    fclose(file);

    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}