//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 1024
#define MAXWORDS 1000

// Function to tokenize a string into words
char **tokenize(char *str) {
    char **words = malloc(MAXWORDS * sizeof(char *));
    char *word;
    int i = 0;
    word = strtok(str, " ");
    while (word != NULL) {
        words[i++] = word;
        word = strtok(NULL, " ");
    }
    words[i] = NULL;
    return words;
}

// Function to calculate the frequency of each word in a text
int *wordFrequency(char **words) {
    int *freq = malloc(MAXWORDS * sizeof(int));
    int i, j;
    for (i = 0; words[i] != NULL; i++) {
        freq[i] = 0;
        for (j = 0; words[j] != NULL; j++) {
            if (strcmp(words[i], words[j]) == 0) {
                freq[i]++;
            }
        }
    }
    return freq;
}

// Function to sort the words by frequency
void sortWords(char **words, int *freq) {
    int i, j;
    char *temp;
    int tempFreq;
    for (i = 0; words[i] != NULL; i++) {
        for (j = i + 1; words[j] != NULL; j++) {
            if (freq[i] < freq[j]) {
                temp = words[i];
                words[i] = words[j];
                words[j] = temp;
                tempFreq = freq[i];
                freq[i] = freq[j];
                freq[j] = tempFreq;
            }
        }
    }
}

// Function to print the summary of the text
void printSummary(char **words, int *freq, int numWords) {
    int i;
    printf("Summary of the text:\n");
    for (i = 0; i < numWords; i++) {
        printf("%s: %d\n", words[i], freq[i]);
    }
}

int main() {
    char text[BUFSIZE];
    char **words;
    int *freq;
    int numWords;

    // Get the text from the user
    printf("Enter the text: ");
    fgets(text, BUFSIZE, stdin);

    // Tokenize the text into words
    words = tokenize(text);

    // Calculate the frequency of each word
    freq = wordFrequency(words);

    // Sort the words by frequency
    sortWords(words, freq);

    // Print the summary of the text
    numWords = 10; // Number of words to display in the summary
    printSummary(words, freq, numWords);

    // Free the allocated memory
    free(words);
    free(freq);

    return 0;
}