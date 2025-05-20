//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: calm
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Spam {
    char **words;
    char **sentences;
    int wordCount;
    int sentenceCount;
} Spam;

Spam *createSpam(int wordCount, int sentenceCount) {
    Spam *spam = malloc(sizeof(Spam));

    spam->words = malloc(wordCount * sizeof(char *));
    spam->sentences = malloc(sentenceCount * sizeof(char *));

    spam->wordCount = wordCount;
    spam->sentenceCount = sentenceCount;

    return spam;
}

void analyzeSpam(Spam *spam) {
    for (int i = 0; i < spam->wordCount; i++) {
        for (int j = 0; j < spam->sentenceCount; j++) {
            if (strstr(spam->sentences[j], spam->words[i]) != NULL) {
                printf("Word: %s, Sentence: %s\n", spam->words[i], spam->sentences[j]);
            }
        }
    }
}

int main() {
    Spam *spam = createSpam(50, 10);

    // Add words and sentences to the spam object
    spam->words[0] = "Free";
    spam->words[1] = "Money";
    spam->words[2] = "Click Here";
    spam->words[3] = "Lottery";
    spam->words[4] = "Prizes";

    spam->sentences[0] = "Click here to claim your free prize!";
    spam->sentences[1] = "Get free money now!";
    spam->sentences[2] = "Win a lottery!";

    analyzeSpam(spam);

    return 0;
}