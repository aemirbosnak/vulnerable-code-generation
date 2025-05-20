//GEMINI-pro DATASET v1.0 Category: Word Count Tool ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of a word
#define MAX_WORD_LENGTH 100

// Create a struct to store the word and its count
typedef struct {
    char word[MAX_WORD_LENGTH];
    int count;
} WordCount;

// Create a function to compare two WordCount structs
int compareWordCounts(const void *a, const void *b) {
    WordCount *wordCount1 = (WordCount *)a;
    WordCount *wordCount2 = (WordCount *)b;

    return strcmp(wordCount1->word, wordCount2->word);
}

// Create a function to count the number of words in a string
int countWords(const char *string) {
    int wordCount = 0;
    int inWord = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) {
            if (!inWord) {
                wordCount++;
                inWord = 1;
            }
        } else {
            inWord = 0;
        }
    }

    return wordCount;
}

// Create a function to create a WordCount struct for each word in a string
WordCount *createWordCounts(const char *string, int wordCount) {
    WordCount *wordCounts = malloc(sizeof(WordCount) * wordCount);

    int wordIndex = 0;
    int startIndex = 0;
    int endIndex = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) {
            if (startIndex == 0) {
                startIndex = i;
            }
            endIndex = i;
        } else {
            if (startIndex != 0) {
                strncpy(wordCounts[wordIndex].word, &string[startIndex], endIndex - startIndex + 1);
                wordCounts[wordIndex].word[endIndex - startIndex + 1] = '\0';
                wordCounts[wordIndex].count = 1;
                wordIndex++;
                startIndex = 0;
                endIndex = 0;
            }
        }
    }

    if (startIndex != 0) {
        strncpy(wordCounts[wordIndex].word, &string[startIndex], endIndex - startIndex + 1);
        wordCounts[wordIndex].word[endIndex - startIndex + 1] = '\0';
        wordCounts[wordIndex].count = 1;
        wordIndex++;
    }

    return wordCounts;
}

// Create a function to count the number of occurrences of each word in a string
void countWordOccurrences(WordCount *wordCounts, int wordCount, const char *string) {
    for (int i = 0; string[i] != '\0'; i++) {
        if (isalnum(string[i])) {
            int startIndex = i;
            int endIndex = i;

            while (isalnum(string[endIndex])) {
                endIndex++;
            }

            char word[MAX_WORD_LENGTH];
            strncpy(word, &string[startIndex], endIndex - startIndex + 1);
            word[endIndex - startIndex + 1] = '\0';

            for (int j = 0; j < wordCount; j++) {
                if (strcmp(wordCounts[j].word, word) == 0) {
                    wordCounts[j].count++;
                    break;
                }
            }
        }
    }
}

// Create a function to print the word counts to the console
void printWordCounts(WordCount *wordCounts, int wordCount) {
    qsort(wordCounts, wordCount, sizeof(WordCount), compareWordCounts);

    for (int i = 0; i < wordCount; i++) {
        printf("%s: %d\n", wordCounts[i].word, wordCounts[i].count);
    }
}

// Create a function to get the input string from the user
char *getInputString() {
    char *string = NULL;
    size_t len = 0;

    printf("Enter a string: ");
    getline(&string, &len, stdin);

    return string;
}

// Create a function to free the memory allocated for the WordCount structs
void freeWordCounts(WordCount *wordCounts, int wordCount) {
    for (int i = 0; i < wordCount; i++) {
        free(wordCounts[i].word);
    }

    free(wordCounts);
}

// Create the main function
int main() {
    // Get the input string from the user
    char *string = getInputString();

    // Count the number of words in the string
    int wordCount = countWords(string);

    // Create a WordCount struct for each word in the string
    WordCount *wordCounts = createWordCounts(string, wordCount);

    // Count the number of occurrences of each word in the string
    countWordOccurrences(wordCounts, wordCount, string);

    // Print the word counts to the console
    printWordCounts(wordCounts, wordCount);

    // Free the memory allocated for the WordCount structs
    freeWordCounts(wordCounts, wordCount);

    // Free the memory allocated for the input string
    free(string);

    return 0;
}