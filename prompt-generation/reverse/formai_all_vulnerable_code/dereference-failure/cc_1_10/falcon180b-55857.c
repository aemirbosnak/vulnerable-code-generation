//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000000
#define MAX_WORD_LENGTH 100

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency *)a;
    WordFrequency *wordB = (WordFrequency *)b;

    return strcmp(wordA->word, wordB->word);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file %s\n", argv[1]);
        return 1;
    }

    char *line = NULL;
    size_t lineCapacity = 0;
    ssize_t lineLength = 0;

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    while ((lineLength = getline(&line, &lineCapacity, file))!= -1) {
        char *wordStart = line;
        char *wordEnd;

        while ((wordEnd = strpbrk(wordStart, " \t\n\r\f\v"))!= NULL) {
            *wordEnd = '\0';

            if (strlen(wordStart) > 0) {
                WordFrequency *word = &words[numWords];

                strcpy(word->word, wordStart);
                word->frequency = 1;

                numWords++;
            }

            wordStart = wordEnd + 1;
        }

        // Last word in line
        if (strlen(wordStart) > 0) {
            WordFrequency *word = &words[numWords];

            strcpy(word->word, wordStart);
            word->frequency = 1;

            numWords++;
        }
    }

    fclose(file);

    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].frequency);
    }

    return 0;
}