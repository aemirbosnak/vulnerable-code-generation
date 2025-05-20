//FormAI DATASET v1.0 Category: Word Frequency Counter ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_WORD_LENGTH 50 // Maximum word length

typedef struct WordFreq {
    char word[MAX_WORD_LENGTH];
    int frequency;
} wordFreq;

wordFreq* createWordFreq(char* word, int frequency) {
    wordFreq* newWordFreq = malloc(sizeof(wordFreq));
    strncpy(newWordFreq->word, word, MAX_WORD_LENGTH);
    newWordFreq->frequency = frequency;
    return newWordFreq;
}

int compareWordFreq(const void* a, const void* b) {
    const wordFreq* x = *(const wordFreq**)a;
    const wordFreq* y = *(const wordFreq**)b;
    return strcmp(x->word, y->word);
}

void printWordFreqList(wordFreq** wordFreqList, int numWords) {
    for (int i = 0; i < numWords; i++) {
        printf("%-20s %d\n", wordFreqList[i]->word, wordFreqList[i]->frequency);
    }
}

void freeWordFreqList(wordFreq** wordFreqList, int numWords) {
    for (int i = 0; i < numWords; i++) {
        free(wordFreqList[i]);
    }
    free(wordFreqList);
}

int main() {
    char inputText[1000];
    printf("Enter some text to count word frequency: ");
    fgets(inputText, 1000, stdin);
    
    int numWords = 0;
    wordFreq** wordFreqList = calloc(numWords, sizeof(wordFreq*));

    // Tokenize the input text
    char* word = strtok(inputText, " ");
    while (word != NULL) {
        // Strip non-letter characters from start and end of word
        int start = 0;
        while (!isalpha(word[start])) {
            start++;
        }
        int end = strlen(word) - 1;
        while (!isalpha(word[end])) {
            end--;
        }
        if (start <= end) {
            // Copy the word to a new string
            char cleanedWord[MAX_WORD_LENGTH];
            for (int i = start; i <= end; i++) {
                cleanedWord[i - start] = tolower(word[i]);
            }
            cleanedWord[end - start + 1] = '\0';

            // Update frequency count for the word
            int found = 0;
            for (int i = 0; i < numWords; i++) {
                if (strcmp(wordFreqList[i]->word, cleanedWord) == 0) {
                    wordFreqList[i]->frequency++;
                    found = 1;
                    break;
                }
            }
            if (!found) {
                // Add a new word frequency record to the list
                numWords++;
                wordFreqList = realloc(wordFreqList, numWords * sizeof(wordFreq*));
                wordFreqList[numWords - 1] = createWordFreq(cleanedWord, 1);
            }
        }

        // Get the next word in the input text
        word = strtok(NULL, " ");
    }

    // Sort the word frequency list alphabetically
    qsort(wordFreqList, numWords, sizeof(wordFreq*), compareWordFreq);

    // Print the word frequency list
    printWordFreqList(wordFreqList, numWords);

    // Free dynamically allocated memory
    freeWordFreqList(wordFreqList, numWords);

    return 0;
}