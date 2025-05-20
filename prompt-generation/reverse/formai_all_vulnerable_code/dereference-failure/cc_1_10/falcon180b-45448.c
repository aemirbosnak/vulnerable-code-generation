//Falcon-180B DATASET v1.0 Category: Word Frequency Counter ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORDS 10000
#define MAX_WORD_LENGTH 50

struct WordFrequency {
    char word[MAX_WORD_LENGTH];
    int frequency;
};

int compareWords(const void *a, const void *b) {
    const struct WordFrequency *wordA = a;
    const struct WordFrequency *wordB = b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE *inputFile;
    char line[1024];
    char word[MAX_WORD_LENGTH];
    int wordLength;
    int totalWords = 0;
    struct WordFrequency wordFrequencies[MAX_WORDS];

    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    while (fgets(line, sizeof(line), inputFile)!= NULL) {
        totalWords += countWords(line, wordFrequencies);
    }

    qsort(wordFrequencies, totalWords, sizeof(struct WordFrequency), compareWords);

    for (int i = 0; i < totalWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].frequency);
    }

    fclose(inputFile);
    return 0;
}

int countWords(const char *line, struct WordFrequency *wordFrequencies) {
    char *wordStart = line;
    char *wordEnd;
    int wordCount = 0;

    while ((wordEnd = strpbrk(wordStart, " \t\r\n\f\v"))!= NULL) {
        wordEnd[0] = '\0';
        wordCount++;
        wordStart = wordEnd + 1;
    }

    if (wordStart[0]!= '\0') {
        wordCount++;
    }

    if (wordCount >= MAX_WORDS) {
        printf("Error: Too many words in line.\n");
        return -1;
    }

    for (int i = 0; i < wordCount; i++) {
        wordFrequencies[i].word[0] = '\0';
        strncat(wordFrequencies[i].word, wordStart, MAX_WORD_LENGTH - 1);
        wordFrequencies[i].frequency = 1;

        wordStart = wordEnd + 1;
    }

    return wordCount;
}