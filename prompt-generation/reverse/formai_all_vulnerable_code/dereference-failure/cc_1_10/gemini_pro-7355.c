//GEMINI-pro DATASET v1.0 Category: Text Summarizer ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100

typedef struct {
    char *word;
    int count;
} Word;

int compareWords(const void *a, const void *b) {
    Word *wa = (Word *)a;
    Word *wb = (Word *)b;
    return strcmp(wa->word, wb->word);
}

int main() {
    char *text = "This is a sample text to be summarized. This text contains some common words like 'the', 'is', 'a', 'to' and 'be'. These words are not very important for the summary, so we can ignore them. We can also ignore words that appear only once. The summary should focus on the important words that convey the main idea of the text.";

    char *words[MAX_WORDS];
    int wordCounts[MAX_WORDS];
    int numWords = 0;

    char *token = strtok(text, " ,.-");
    while (token != NULL) {
        int found = 0;
        for (int i = 0; i < numWords; i++) {
            if (strcmp(token, words[i]) == 0) {
                wordCounts[i]++;
                found = 1;
                break;
            }
        }
        if (!found) {
            words[numWords] = strdup(token);
            wordCounts[numWords] = 1;
            numWords++;
        }
        token = strtok(NULL, " ,.-");
    }

    Word wordArray[MAX_WORDS];
    for (int i = 0; i < numWords; i++) {
        wordArray[i].word = words[i];
        wordArray[i].count = wordCounts[i];
    }

    qsort(wordArray, numWords, sizeof(Word), compareWords);

    int numSummaryWords = 10;
    char *summaryWords[numSummaryWords];
    int summaryWordCounts[numSummaryWords];

    for (int i = 0; i < numSummaryWords; i++) {
        summaryWords[i] = wordArray[numWords - i - 1].word;
        summaryWordCounts[i] = wordArray[numWords - i - 1].count;
    }

    char *summary = malloc(1024);
    strcpy(summary, "");
    for (int i = 0; i < numSummaryWords; i++) {
        char *word = summaryWords[i];
        int count = summaryWordCounts[i];
        char *wordString = malloc(1024);
        sprintf(wordString, "%s (%d)", word, count);
        strcat(summary, wordString);
        free(wordString);
        if (i < numSummaryWords - 1) {
            strcat(summary, ", ");
        }
    }

    printf("Summary: %s\n", summary);

    for (int i = 0; i < numWords; i++) {
        free(words[i]);
    }

    free(summary);

    return 0;
}