//Falcon-180B DATASET v1.0 Category: Ebook reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

typedef struct {
    char *word;
    int count;
} WordFrequency;

int main() {
    FILE *file;
    char line[MAX_WORD_LENGTH];
    char *word;
    int numWords = 0;
    int totalWords = 0;
    WordFrequency *wordFrequencies = malloc(MAX_WORDS * sizeof(WordFrequency));

    if (wordFrequencies == NULL) {
        printf("Error: Could not allocate memory for word frequencies.\n");
        return 1;
    }

    file = fopen("example.txt", "r");

    if (file == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_WORD_LENGTH, file)!= NULL) {
        numWords = 0;
        totalWords += countWords(line, wordFrequencies, &numWords);
    }

    fclose(file);

    printf("Total words: %d\n", totalWords);

    for (int i = 0; i < numWords; i++) {
        printf("%s: %d\n", wordFrequencies[i].word, wordFrequencies[i].count);
    }

    free(wordFrequencies);

    return 0;
}

int countWords(char *line, WordFrequency *wordFrequencies, int *numWords) {
    char *word;
    int count = 0;
    int wordIndex = 0;

    word = strtok(line, " ");

    while (word!= NULL) {
        if (strlen(word) > 0) {
            if (isalpha(word[0])) {
                if (wordIndex < MAX_WORDS) {
                    wordFrequencies[wordIndex].word = strdup(word);
                    wordFrequencies[wordIndex].count++;
                    count++;
                } else {
                    printf("Warning: Maximum number of words reached.\n");
                }
            }
        }

        wordIndex++;
        word = strtok(NULL, " ");
    }

    *numWords = count;

    return count;
}