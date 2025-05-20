//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordCount;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower((unsigned char) str[i]);
    }
}

int addWord(WordCount *wordCounts, int *wordCount, const char *word) {
    for (int i = 0; i < *wordCount; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            wordCounts[i].frequency++;
            return 1; // Word already exists, updated frequency
        }
    }
    
    // Add new word
    strncpy(wordCounts[*wordCount].word, word, MAX_WORD_LENGTH);
    wordCounts[*wordCount].frequency = 1;
    (*wordCount)++;
    return 0; // New word added
}

void printWordFrequencies(WordCount *wordCounts, int wordCount) {
    printf("\nWord Frequency Count:\n");
    printf("------------------------------\n");
    for (int i = 0; i < wordCount; i++) {
        printf("%-15s : %d\n", wordCounts[i].word, wordCounts[i].frequency);
    }
    printf("------------------------------\n");
}

void cleanWord(char *word) {
    char *start = word;
    while (*start && !isalnum(*start)) start++;
    
    char *end = word + strlen(word) - 1;
    while (end > start && !isalnum(*end)) end--;
    
    *(end + 1) = '\0';
    memmove(word, start, end - start + 2);
}

void countWordsInFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return;
    }

    WordCount wordCounts[MAX_WORDS] = {{0}};
    int wordCount = 0;
    char word[MAX_WORD_LENGTH];

    while (fscanf(file, "%49s", word) == 1) {
        cleanWord(word);
        toLowerCase(word);
        if (strlen(word) > 0) {
            addWord(wordCounts, &wordCount, word);
        }
    }
    
    fclose(file);
    
    printWordFrequencies(wordCounts, wordCount);
}

int main(int argc, char *argv[]) {
    printf("Welcome to the Word Frequency Counter!\n");
    printf("****************************************\n");
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    countWordsInFile(argv[1]);

    printf("Thank you for using the Word Frequency Counter!\n");
    printf("****************************************\n");

    return EXIT_SUCCESS;
}