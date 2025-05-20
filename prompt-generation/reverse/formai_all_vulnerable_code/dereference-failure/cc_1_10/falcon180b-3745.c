//Falcon-180B DATASET v1.0 Category: Resume Parsing System ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 100

typedef struct {
    char* word;
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    if (wordA->count > wordB->count) {
        return -1;
    } else if (wordA->count < wordB->count) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    FILE* inputFile;
    char line[100];
    char* word;
    int numWords = 0;
    WordCount words[MAX_WORDS];

    inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: could not open input file.\n");
        exit(1);
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        word = strtok(line, " ");

        while (word!= NULL) {
            int i;

            for (i = 0; i < numWords; i++) {
                if (strcmp(words[i].word, word) == 0) {
                    words[i].count++;
                    break;
                }
            }

            if (i == numWords) {
                if (numWords >= MAX_WORDS) {
                    printf("Error: too many words.\n");
                    exit(1);
                }

                words[numWords].word = strdup(word);
                words[numWords].count = 1;
                numWords++;
            }

            word = strtok(NULL, " ");
        }
    }

    fclose(inputFile);

    qsort(words, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    return 0;
}