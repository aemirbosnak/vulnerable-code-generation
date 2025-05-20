//FormAI DATASET v1.0 Category: Text Summarizer ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUMMARY_SIZE 1000

// Calculate the frequency of each word in the text
void calculateWordFrequency(char *text, int *freqArray) {
    char *word;
    word = strtok(text, " ");
    while (word != NULL) {
        freqArray[hash(word)]++;
        word = strtok(NULL, " ");
    }
}

// Hash function for words
int hash(char *str) {
    int i, sum = 0;
    for (i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    return sum % 100;
}

// Select the most frequent words according to the summary size
void selectWords(int *freqArray, int size, int summarySize, int *selectedWords) {
    int i, maxIndex, maxFreq, currentSize = 0;
    while (currentSize < summarySize) {
        maxIndex = -1;
        maxFreq = -1;
        for (i = 0; i < size; i++) {
            if (freqArray[i] > maxFreq) {
                maxIndex = i;
                maxFreq = freqArray[i];
            }
        }
        if (maxIndex >= 0) {
            selectedWords[maxIndex] = 1;
            freqArray[maxIndex] = 0;
            currentSize++;
        } else {
            break;
        }
    }
}

// Generate the final summary
char *generateSummary(char *text, int *selectedWords) {
    char *summary = (char*)malloc(sizeof(char)*MAX_SUMMARY_SIZE);
    char *word;
    int i, len = 0;

    summary[0] = '\0';
    word = strtok(text, " ");
    while (word != NULL) {
        i = hash(word);
        if (selectedWords[i]) {
            len += snprintf(summary+len, MAX_SUMMARY_SIZE-len, "%s ", word);
        }
        word = strtok(NULL, " ");
    }

    return summary;
}

int main() {
    char *text = "This is a test. This is only a test. Do not be alarmed.";
    int freqArray[100] = {0};
    int selectedWords[100] = {0};
    int summarySize = 5;
    char *summary;

    calculateWordFrequency(text, freqArray);
    selectWords(freqArray, 100, summarySize, selectedWords);
    summary = generateSummary(text, selectedWords);

    printf("Original text:\n%s\n", text);
    printf("Summary:\n%s\n", summary);

    free(summary);
    return 0;
}