//GEMINI-pro DATASET v1.0 Category: Word Frequency Counter ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000

typedef struct {
    char *word;
    int count;
} WordCount;

int compareWordCounts(const void *a, const void *b) {
    WordCount *wa = (WordCount *)a;
    WordCount *wb = (WordCount *)b;
    return wb->count - wa->count;
}

int main() {
    // Get the input text from the user.
    char inputText[10000];
    printf("Enter the text you want to analyze: ");
    fgets(inputText, sizeof(inputText), stdin);

    // Tokenize the input text into words.
    char *words[MAX_WORDS];
    int numWords = 0;
    char *token = strtok(inputText, " ");
    while (token != NULL) {
        words[numWords++] = token;
        token = strtok(NULL, " ");
    }

    // Count the frequency of each word.
    WordCount wordCounts[MAX_WORDS];
    for (int i = 0; i < numWords; i++) {
        int found = 0;
        for (int j = 0; j < numWords; j++) {
            if (strcmp(words[i], wordCounts[j].word) == 0) {
                wordCounts[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            wordCounts[numWords].word = words[i];
            wordCounts[numWords++].count = 1;
        }
    }

    // Sort the word counts in descending order.
    qsort(wordCounts, numWords, sizeof(WordCount), compareWordCounts);

    // Print the word counts.
    printf("Word\tCount\n");
    for (int i = 0; i < numWords; i++) {
        printf("%s\t%d\n", wordCounts[i].word, wordCounts[i].count);
    }

    return 0;
}