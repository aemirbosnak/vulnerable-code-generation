//Falcon-180B DATASET v1.0 Category: Image Classification system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    const WordCount* wc1 = a;
    const WordCount* wc2 = b;
    return strcmp(wc1->word, wc2->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line[MAX_WORD_LENGTH];
    while (fgets(line, MAX_WORD_LENGTH, inputFile)!= NULL) {
        int numWords = 0;
        char* token = strtok(line, " ");
        while (token!= NULL) {
            numWords++;
            token = strtok(NULL, " ");
        }
        if (numWords == 0) {
            continue;
        }

        WordCount* words = malloc(numWords * sizeof(WordCount));
        int i = 0;
        token = strtok(line, " ");
        while (token!= NULL) {
            strcpy(words[i].word, token);
            words[i].count = 1;
            i++;
            token = strtok(NULL, " ");
        }

        qsort(words, numWords, sizeof(WordCount), compareWords);

        for (i = 0; i < numWords; i++) {
            printf("%s: %d\n", words[i].word, words[i].count);
        }
        free(words);
    }

    fclose(inputFile);
    return 0;
}