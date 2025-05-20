//GPT-4o-mini DATASET v1.0 Category: Word Frequency Counter ; Style: mind-bending
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

void initializeWordCount(WordCount *wordCount, const char *word) {
    strncpy(wordCount->word, word, MAX_WORD_LENGTH - 1);
    wordCount->word[MAX_WORD_LENGTH - 1] = '\0'; // Ensure null-termination
    wordCount->count = 1; // Start counting from 1
}

int findWord(WordCount *wordCounts, int numWords, const char *word) {
    for (int i = 0; i < numWords; i++) {
        if (strcmp(wordCounts[i].word, word) == 0) {
            return i; // Return the index of the found word
        }
    }
    return -1; // Not found
}

void incrementWordCount(WordCount *wordCount) {
    wordCount->count++;
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void sanitizeWord(char *word) {
    char *start = word;
    char *end = word + strlen(word) - 1;

    // Trim leading punctuation
    while (*start && ispunct(*start)) start++;

    // Trim trailing punctuation
    while (end > start && ispunct(*end)) end--;

    // Null-terminate the string at the end of the trimmed word
    *(end + 1) = '\0';
    strcpy(word, start); // Adjust the original word
}

void countWords(FILE *file, WordCount *wordCounts, int *numWords) {
    char buffer[MAX_WORD_LENGTH];
    
    while (fscanf(file, "%s", buffer) != EOF) {
        sanitizeWord(buffer);
        if (strlen(buffer) == 0) continue; // Skip empty words

        toLowerCase(buffer);
        
        int index = findWord(wordCounts, *numWords, buffer);
        if (index >= 0) {
            incrementWordCount(&wordCounts[index]);
        } else {
            if (*numWords < MAX_WORDS) {
                initializeWordCount(&wordCounts[*numWords], buffer);
                (*numWords)++;
            } else {
                printf("Warning: Reached maximum word limit (1000).\n");
            }
        }
    }
}

void printWordCounts(WordCount *wordCounts, int numWords) {
    printf("\nWord Frequency Count:\n");
    printf("----------------------\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    WordCount wordCounts[MAX_WORDS];
    int numWords = 0;

    countWords(file, wordCounts, &numWords);
    fclose(file);

    printWordCounts(wordCounts, numWords);

    return EXIT_SUCCESS;
}