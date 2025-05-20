//Falcon-180B DATASET v1.0 Category: Word Count Tool ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 100
#define MAX_NUM_WORDS 1000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

int compareWords(const void* a, const void* b) {
    WordCount* wordA = (WordCount*)a;
    WordCount* wordB = (WordCount*)b;

    return strcmp(wordA->word, wordB->word);
}

int main() {
    FILE* inputFile;
    char inputBuffer[1024];
    char* inputLine;
    WordCount words[MAX_NUM_WORDS];
    int numWords = 0;
    int i;

    // Open input file
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error: Cannot open input file.\n");
        return 1;
    }

    // Read input file line by line
    while (fgets(inputBuffer, sizeof(inputBuffer), inputFile)!= NULL) {
        // Remove newline character from end of line
        inputLine = strtok(inputBuffer, "\n");

        // Convert input line to lowercase
        for (i = 0; inputLine[i]!= '\0'; i++) {
            inputLine[i] = tolower(inputLine[i]);
        }

        // Split input line into words
        char* word = strtok(inputLine, " ");
        while (word!= NULL) {
            // Check if maximum number of words has been reached
            if (numWords >= MAX_NUM_WORDS) {
                printf("Error: Maximum number of words (%d) has been reached.\n", MAX_NUM_WORDS);
                return 1;
            }

            // Add word to array of words
            strcpy(words[numWords].word, word);
            words[numWords].count = 1;
            numWords++;

            // Get next word
            word = strtok(NULL, " ");
        }
    }

    // Sort array of words alphabetically
    qsort(words, numWords, sizeof(WordCount), compareWords);

    // Print word count for each word
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i].word, words[i].count);
    }

    // Close input file
    fclose(inputFile);

    return 0;
}