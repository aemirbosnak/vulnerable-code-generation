//GPT-4o-mini DATASET v1.0 Category: Text Summarizer ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_LENGTH 10000
#define MAX_SUMMARY_LENGTH 2000
#define MAX_WORD_LENGTH 50
#define MAX_NUM_WORDS 2000

typedef struct {
    char word[MAX_WORD_LENGTH];
    int frequency;
} WordFrequency;

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

void splitIntoWords(char *text, char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int *numWords) {
    char *token = strtok(text, " ,.!?;:\n\r");
    
    while (token != NULL) {
        toLowerCase(token);
        strcpy(words[*numWords], token);
        (*numWords)++;
        token = strtok(NULL, " ,.!?;:\n\r");
    }
}

void countWordFrequencies(char words[MAX_NUM_WORDS][MAX_WORD_LENGTH], int numWords, WordFrequency *wordFreq, int *uniqueWordCount) {
    for (int i = 0; i < numWords; i++) {
        int found = 0;
        for (int j = 0; j < *uniqueWordCount; j++) {
            if (strcmp(wordFreq[j].word, words[i]) == 0) {
                wordFreq[j].frequency++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(wordFreq[*uniqueWordCount].word, words[i]);
            wordFreq[*uniqueWordCount].frequency = 1;
            (*uniqueWordCount)++;
        }
    }
}

int compareFrequencies(const void *a, const void *b) {
    WordFrequency *wordFreqA = (WordFrequency *)a;
    WordFrequency *wordFreqB = (WordFrequency *)b;

    return wordFreqB->frequency - wordFreqA->frequency;
}

void generateSummary(WordFrequency *wordFreq, int uniqueWordCount, char *summary, int maxLength) {
    int length = 0;
    for (int i = 0; i < uniqueWordCount && length < maxLength; i++) {
        length += snprintf(summary + length, maxLength - length, "%s(%d) ", wordFreq[i].word, wordFreq[i].frequency);
    }
    summary[length - 1] = '\0'; // Remove the last space
}

int main() {
    char text[MAX_TEXT_LENGTH];
    char words[MAX_NUM_WORDS][MAX_WORD_LENGTH];
    WordFrequency wordFreq[MAX_NUM_WORDS];
    int numWords = 0, uniqueWordCount = 0;
    char summary[MAX_SUMMARY_LENGTH];
    
    printf("Enter text (end with a blank line):\n");
    int ch;
    int i = 0;
    while (1) {
        ch = getchar();
        if (ch == '\n' && i == 0) {
            break; // End on double new line
        }
        if (i < MAX_TEXT_LENGTH - 1) {
            text[i++] = ch;
        }
    }
    text[i] = '\0'; // Null-terminate the string

    splitIntoWords(text, words, &numWords);
    countWordFrequencies(words, numWords, wordFreq, &uniqueWordCount);
    
    qsort(wordFreq, uniqueWordCount, sizeof(WordFrequency), compareFrequencies);
    
    generateSummary(wordFreq, uniqueWordCount, summary, MAX_SUMMARY_LENGTH);
    
    printf("\nSummary:\n%s\n", summary);
    
    return 0;
}