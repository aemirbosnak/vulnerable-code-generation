//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Struct for storing the word and its count
typedef struct {
    char* word;
    int count;
} WordCount;

// Function for sorting WordCount array
int compare(const void* a, const void* b) {
    // Sort by count in descending order
    WordCount* wc1 = (WordCount*)a;
    WordCount* wc2 = (WordCount*)b;
    if (wc1->count < wc2->count) {
        return 1;
    } else if (wc1->count > wc2->count) {
        return -1;
    } else {
        // If counts are equal, sort by word in ascending order
        return strcmp(wc1->word, wc2->word);
    }
}

// Function to find index of word in WordCount array
int findWord(const char* word, WordCount* wordCount, int n) {
    for (int i = 0; i < n; i++) {
        if (strcmp(wordCount[i].word, word) == 0) {
            return i;
        }
    }
    // Word not found
    return -1;
}

// Function to add new word to WordCount array
void addWord(const char* word, WordCount* wordCount, int* n) {
    // Resize array if necessary
    if (*n % 10 == 0) {
        wordCount = (WordCount*)realloc(wordCount, (*n + 10) * sizeof(WordCount));
        if (wordCount == NULL) {
            printf("Error: Out of memory");
            exit(1);
        }
    }
    // Add new word to array
    wordCount[*n].word = (char*)malloc((strlen(word) + 1) * sizeof(char));
    if (wordCount[*n].word == NULL) {
        printf("Error: Out of memory");
        exit(1);
    }
    strcpy(wordCount[*n].word, word);
    wordCount[*n].count = 1;
    (*n)++;
}

// Function to read words from file and count frequency
WordCount* readWords(const char* filename, int* n) {
    WordCount* wordCount = (WordCount*)malloc(10 * sizeof(WordCount));
    if (wordCount == NULL) {
        printf("Error: Out of memory");
        exit(1);
    }
    *n = 0;
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file");
        exit(1);
    }
    char word[100];
    while (fscanf(fp, "%s", word) != EOF) {
        // Convert word to lowercase
        for (int i = 0; i < strlen(word); i++) {
            word[i] = tolower(word[i]);
        }
        int index = findWord(word, wordCount, *n);
        if (index == -1) {
            addWord(word, wordCount, n);
        } else {
            wordCount[index].count++;
        }
    }
    fclose(fp);
    // Sort WordCount array
    qsort(wordCount, *n, sizeof(WordCount), compare);
    return wordCount;
}

int main() {
    int n;
    WordCount* wordCount = readWords("input.txt", &n);
    // Print top 10 most frequent words
    printf("Top 10 most frequent words:\n");
    for (int i = 0; i < 10 && i < n; i++) {
        printf("%s: %d\n", wordCount[i].word, wordCount[i].count);
    }
    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(wordCount[i].word);
    }
    free(wordCount);
    return 0;
}