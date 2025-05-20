//Gemma-7B DATASET v1.0 Category: Spam Detection System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 100

typedef struct Word {
    char *word;
    struct Word *next;
} Word;

Word *createWordList(char **words, int numWords) {
    Word *head = NULL;
    for (int i = 0; i < numWords; i++) {
        Word *newWord = malloc(sizeof(Word));
        newWord->word = strdup(words[i]);
        newWord->next = head;
        head = newWord;
    }
    return head;
}

int detectSpam(Word *wordList) {
    char *suspiciousWords[] = {"free", "lottery", "miracle", "prize", "offer"};
    int numSuspiciousWords = sizeof(suspiciousWords) / sizeof(char *);

    for (Word *word = wordList; word; word = word->next) {
        for (int i = 0; i < numSuspiciousWords; i++) {
            if (strcmp(word->word, suspiciousWords[i]) == 0) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char *messages[] = {"This is a spam message", "This is not spam", "Free lottery!", "You can win big!"};
    int numMessages = sizeof(messages) / sizeof(char *);

    Word *wordList = createWordList(messages, numMessages);
    int isSpam = detectSpam(wordList);

    if (isSpam) {
        printf("Message is spam.\n");
    } else {
        printf("Message is not spam.\n");
    }

    return 0;
}