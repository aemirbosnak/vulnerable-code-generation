//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: shape shifting
// A quick and dirty text summarizer in C
// Inspired by the shape-shifting abilities of a certain aquatic mammal

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Some constants
#define MAX_WORDS 1000
#define MAX_SUMMARY_LENGTH 200

// A simple struct to represent a word
typedef struct {
    char *word;
    int count;
} Word;

// A function to compare two words
int compareWords(const void *a, const void *b) {
    Word *word1 = (Word *)a;
    Word *word2 = (Word *)b;
    return strcmp(word1->word, word2->word);
}

// A function to count the number of words in a string
int countWords(char *string) {
    int count = 0;
    char *token = strtok(string, " ");
    while (token != NULL) {
        count++;
        token = strtok(NULL, " ");
    }
    return count;
}

// A function to create an array of words from a string
Word *createWordArray(char *string) {
    int numWords = countWords(string);
    Word *words = (Word *)malloc(sizeof(Word) * numWords);
    char *token = strtok(string, " ");
    int i = 0;
    while (token != NULL) {
        words[i].word = strdup(token);
        words[i].count = 1;
        i++;
        token = strtok(NULL, " ");
    }
    return words;
}

// A function to count the number of times a word appears in an array of words
int countWordOccurrences(Word *words, int numWords, char *word) {
    int count = 0;
    for (int i = 0; i < numWords; i++) {
        if (strcmp(words[i].word, word) == 0) {
            count++;
        }
    }
    return count;
}

// A function to find the most frequently occurring words in an array of words
Word *findMostFrequentWords(Word *words, int numWords, int numMostFrequentWords) {
    // Sort the words by their count
    qsort(words, numWords, sizeof(Word), compareWords);

    // Create an array of the most frequent words
    Word *mostFrequentWords = (Word *)malloc(sizeof(Word) * numMostFrequentWords);
    for (int i = 0; i < numMostFrequentWords; i++) {
        mostFrequentWords[i] = words[i];
    }

    return mostFrequentWords;
}

// A function to create a summary of a string
char *summarizeText(char *string, int numMostFrequentWords) {
    // Create an array of words from the string
    Word *words = createWordArray(string);

    // Find the most frequently occurring words
    Word *mostFrequentWords = findMostFrequentWords(words, numMostFrequentWords, numMostFrequentWords);

    // Create a summary of the string
    char *summary = (char *)malloc(sizeof(char) * MAX_SUMMARY_LENGTH);
    summary[0] = '\0';
    for (int i = 0; i < numMostFrequentWords; i++) {
        strcat(summary, mostFrequentWords[i].word);
        strcat(summary, " ");
    }

    // Free the memory allocated for the words and most frequent words
    free(words);
    free(mostFrequentWords);

    return summary;
}

// A function to print a summary of a string
void printSummary(char *string, int numMostFrequentWords) {
    char *summary = summarizeText(string, numMostFrequentWords);
    printf("Summary: %s\n", summary);
    free(summary);
}

int main() {
    // Get the input text from the user
    char text[1000];
    printf("Enter the text you want to summarize: ");
    gets(text);

    // Get the number of most frequent words to include in the summary
    int numMostFrequentWords;
    printf("Enter the number of most frequent words to include in the summary: ");
    scanf("%d", &numMostFrequentWords);

    // Print the summary of the text
    printSummary(text, numMostFrequentWords);

    return 0;
}