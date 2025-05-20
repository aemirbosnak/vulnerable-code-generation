//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH+1];
    int count;
} WordFrequency;

int compareWords(const void* a, const void* b) {
    return strcmp(*(char**)a, *(char**)b);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    char* line = NULL;
    size_t len = 0;
    ssize_t read;

    WordFrequency words[MAX_WORDS];
    int numWords = 0;

    while ((read = getline(&line, &len, file))!= -1) {
        // convert line to lowercase
        for (int i = 0; i < read; i++) {
            line[i] = tolower(line[i]);
        }

        // tokenize line into words
        char* wordStart = line;
        char* wordEnd = strtok(line, ",.?!;:\"'()[]{}<>");
        while (wordEnd!= NULL) {
            int wordLength = strlen(wordStart);
            if (wordLength > MAX_WORD_LENGTH) {
                printf("Word too long: %s\n", wordStart);
                continue;
            }
            strncpy(words[numWords].word, wordStart, MAX_WORD_LENGTH);
            words[numWords].word[MAX_WORD_LENGTH] = '\0';
            words[numWords].count = 1;
            numWords++;

            wordStart = wordEnd + 1;
            wordEnd = strtok(NULL, ",.?!;:\"'()[]{}<>");
        }
    }

    fclose(file);

    // sort words by frequency
    qsort(words, numWords, sizeof(WordFrequency), compareWords);

    // print word frequency table
    printf("Word\tFrequency\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", words[i].word, words[i].count);
    }

    return 0;
}