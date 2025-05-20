//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: brave
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_WORDS 100
#define MAX_SENTENCE_LENGTH 200

typedef struct Spam {
    char **words;
    char **sentences;
    int numWords;
    int numSentences;
} Spam;

Spam *createSpam(int numWords, int numSentences) {
    Spam *spam = malloc(sizeof(Spam));
    spam->words = malloc(sizeof(char *) * numWords);
    spam->sentences = malloc(sizeof(char *) * numSentences);
    spam->numWords = numWords;
    spam->numSentences = numSentences;
    return spam;
}

void addWordToSpam(Spam *spam, char *word) {
    spam->words[spam->numWords++] = word;
}

void addSentenceToSpam(Spam *spam, char *sentence) {
    spam->sentences[spam->numSentences++] = sentence;
}

int detectSpam(Spam *spam) {
    int i, j;
    for (i = 0; i < spam->numSentences; i++) {
        for (j = 0; j < spam->numWords; j++) {
            if (strstr(spam->sentences[i], spam->words[j]) != NULL) {
                return 1;
            }
        }
    }
    return 0;
}

int main() {
    Spam *spam = createSpam(50, 10);
    addWordToSpam(spam, "free");
    addWordToSpam(spam, "lottery");
    addSentenceToSpam(spam, "You have won!");
    addSentenceToSpam(spam, "Congratulations!");

    if (detectSpam(spam)) {
        printf("Spam detected!");
    } else {
        printf("No spam detected.");
    }

    return 0;
}