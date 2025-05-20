//Falcon-180B DATASET v1.0 Category: Spam Detection System ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} Word;

int compareWords(const void* a, const void* b) {
    const Word* w1 = a;
    const Word* w2 = b;
    return strcmp(w1->word, w2->word);
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    char line[100];
    fgets(line, sizeof(line), inputFile);
    char* input = strdup(line);

    char* token = strtok(input, " ");
    int numWords = 0;
    while (token!= NULL) {
        numWords++;
        token = strtok(NULL, " ");
    }

    Word* words = malloc(numWords * sizeof(Word));
    int i = 0;
    char* inputCopy = strdup(input);
    char* tokenCopy = strtok(inputCopy, " ");
    while (tokenCopy!= NULL) {
        strcpy(words[i].word, tokenCopy);
        words[i].count = 0;
        i++;
        tokenCopy = strtok(NULL, " ");
    }

    qsort(words, numWords, sizeof(Word), compareWords);

    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        return 1;
    }

    for (i = 0; i < numWords; i++) {
        if (words[i].count > 0) {
            fprintf(outputFile, "%s: %d\n", words[i].word, words[i].count);
        }
    }

    fclose(inputFile);
    fclose(outputFile);
    free(input);
    free(inputCopy);
    free(words);

    return 0;
}