//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH + 1];
    int count;
} WordCount;

int compareWords(const void *a, const void *b) {
    WordCount *wordA = (WordCount *) a;
    WordCount *wordB = (WordCount *) b;
    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    FILE *inputFile;
    char line[1024];
    char *word;
    WordCount words[MAX_WORDS];
    int numWords = 0;

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    inputFile = fopen(argv[1], "r");
    if (inputFile == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        char *p = line;
        while ((word = strtok_r(p, " \t\n\r\f\v", &p))!= NULL) {
            if (numWords >= MAX_WORDS) {
                printf("Maximum number of words reached\n");
                break;
            }
            WordCount *wc = &words[numWords++];
            strcpy(wc->word, word);
            wc->count = 1;
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}