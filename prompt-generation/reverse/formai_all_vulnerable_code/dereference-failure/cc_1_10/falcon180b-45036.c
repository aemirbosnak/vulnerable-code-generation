//Falcon-180B DATASET v1.0 Category: Text Summarizer ; Style: enthusiastic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_SENTENCE_LENGTH 1000
#define MAX_SENTENCES 1000
#define MIN_SENTENCE_LENGTH 5

typedef struct {
    char *text;
    int length;
} Sentence;

Sentence sentences[MAX_SENTENCES];
int numSentences = 0;

void addSentence(char *sentence) {
    if (numSentences >= MAX_SENTENCES || strlen(sentence) < MIN_SENTENCE_LENGTH) {
        return;
    }

    sentences[numSentences].text = malloc(strlen(sentence) + 1);
    strcpy(sentences[numSentences].text, sentence);
    sentences[numSentences].length = strlen(sentence);

    numSentences++;
}

void printSentences() {
    for (int i = 0; i < numSentences; i++) {
        printf("%s\n", sentences[i].text);
    }
}

void freeSentences() {
    for (int i = 0; i < numSentences; i++) {
        free(sentences[i].text);
    }
}

char *getLongestSentence(char *text) {
    char *longest = NULL;
    int longestLength = 0;

    for (char *sentence = strtok(text, "."); sentence!= NULL; sentence = strtok(NULL, ".")) {
        int length = strlen(sentence);

        if (length > longestLength) {
            longest = sentence;
            longestLength = length;
        }
    }

    return longest;
}

int main() {
    char input[MAX_SENTENCE_LENGTH];
    char *longest;

    printf("Enter the text to summarize:\n");
    fgets(input, MAX_SENTENCE_LENGTH, stdin);

    addSentence(input);

    longest = getLongestSentence(input);

    printf("Longest sentence: %s\n", longest);

    printSentences();

    freeSentences();

    return 0;
}