//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 10000

// Struct to hold word count data
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Function to compare two words (case insensitive)
bool compareWords(const void *a, const void *b) {
    const char *word1 = *(const char **)a;
    const char *word2 = *(const char **)b;

    return strcasecmp(word1, word2) < 0;
}

// Function to count the number of words in a string
int countWords(const char *text) {
    int numWords = 0;
    char *word = strtok(text, " ");

    while (word!= NULL) {
        numWords++;
        word = strtok(NULL, " ");
    }

    return numWords;
}

// Function to print the word count data
void printWordCounts(WordCount *wordCounts, int numWords) {
    qsort(wordCounts, numWords, sizeof(WordCount), compareWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

// Function to read text from a file
char *readTextFromFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *text = malloc(fileSize + 1);
    if (text == NULL) {
        fclose(file);
        return NULL;
    }

    if (fread(text, fileSize, 1, file)!= 1) {
        free(text);
        fclose(file);
        return NULL;
    }

    text[fileSize] = '\0';
    fclose(file);

    return text;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char *text = readTextFromFile(argv[1]);
    if (text == NULL) {
        return 2;
    }

    int numWords = countWords(text);
    WordCount *wordCounts = malloc(numWords * sizeof(WordCount));
    if (wordCounts == NULL) {
        free(text);
        return 3;
    }

    char *word = strtok(text, " ");
    int currentWordIndex = 0;

    while (word!= NULL) {
        strcpy(wordCounts[currentWordIndex].word, word);
        wordCounts[currentWordIndex].count = 1;
        currentWordIndex++;

        word = strtok(NULL, " ");
    }

    free(text);
    printWordCounts(wordCounts, numWords);
    free(wordCounts);

    return 0;
}