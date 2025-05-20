//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100000
#define MAX_WORD_LENGTH 50

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

int compareWords(const void *a, const void *b) {
    WordFrequency *wordA = (WordFrequency*)a;
    WordFrequency *wordB = (WordFrequency*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *file;
    char ch;
    char word[MAX_WORD_LENGTH];
    WordFrequency *wordFrequencyTable = (WordFrequency*)malloc(MAX_WORDS * sizeof(WordFrequency));
    int wordCount = 0;

    if (wordFrequencyTable == NULL) {
        printf("Error: Out of memory\n");
        exit(1);
    }

    file = fopen("input.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    while ((ch = fgetc(file))!= EOF) {
        if (isalpha(ch)) {
            word[0] = toupper(ch);
            word[1] = '\0';
            while ((ch = fgetc(file))!= EOF && isalpha(ch)) {
                strcat(word, &ch);
            }
            wordFrequencyTable[wordCount].frequency = 1;
            strcpy(wordFrequencyTable[wordCount].word, word);
            wordCount++;
        }
    }

    fclose(file);

    qsort(wordFrequencyTable, wordCount, sizeof(WordFrequency), compareWords);

    printf("Word\tFrequency\n");

    for (int i = 0; i < wordCount; i++) {
        printf("%s\t%d\n", wordFrequencyTable[i].word, wordFrequencyTable[i].frequency);
    }

    free(wordFrequencyTable);

    return 0;
}