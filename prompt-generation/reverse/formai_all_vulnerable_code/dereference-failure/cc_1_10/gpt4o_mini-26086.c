//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

WordCount wordCounts[MAX_WORDS];
int wordCount = 0;

int findWord(const char* word) {
    for (int i = 0; i < wordCount; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            return i;
        }
    }
    return -1;
}

void addWord(const char* word) {
    int index = findWord(word);
    if (index >= 0) {
        wordCounts[index].count++;
    } else {
        strcpy(wordCounts[wordCount].word, word);
        wordCounts[wordCount].count = 1;
        wordCount++;
    }
}

void toLowerCase(char* str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

void processTextFile(FILE* file) {
    char word[MAX_WORD_LENGTH];
    while (fscanf(file, "%s", word) != EOF) {
        toLowerCase(word);
        addWord(word);
    }
}

void printSummary(int topN) {
    for (int i = 0; i < wordCount; i++) {
        for (int j = i + 1; j < wordCount; j++) {
            if (wordCounts[i].count < wordCounts[j].count) {
                WordCount temp = wordCounts[i];
                wordCounts[i] = wordCounts[j];
                wordCounts[j] = temp;
            }
        }
    }
    
    printf("\n--- Summary ---\n");
    for (int i = 0; i < topN && i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage: %s <filename> <topN>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[1];
    int topN = atoi(argv[2]);

    if (topN <= 0) {
        printf("Please enter a positive integer for topN.\n");
        return 1;
    }

    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return 1;
    }

    processTextFile(file);
    fclose(file);

    printSummary(topN);

    return 0;
}