//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10

typedef struct WordNode {
    char *word;
    struct WordNode *next;
} WordNode;

WordNode *createWordList(char **words, int numWords);

void playMemoryGame(WordNode *wordList);

int main() {
    char **words = NULL;
    int numWords = 0;

    words = malloc(MAX_WORDS * sizeof(char *));
    for (int i = 0; i < MAX_WORDS; i++) {
        words[i] = NULL;
    }

    words[0] = "Apple";
    words[1] = "Banana";
    words[2] = "Orange";
    words[3] = "Grape";
    words[4] = "Strawberry";

    numWords = 5;

    WordNode *wordList = createWordList(words, numWords);

    playMemoryGame(wordList);

    free(words);
    free(wordList);

    return 0;
}

WordNode *createWordList(char **words, int numWords) {
    WordNode *wordList = NULL;

    for (int i = 0; i < numWords; i++) {
        WordNode *newNode = malloc(sizeof(WordNode));
        newNode->word = strdup(words[i]);
        newNode->next = wordList;
        wordList = newNode;
    }

    return wordList;
}

void playMemoryGame(WordNode *wordList) {
    char *guessWord = malloc(20);
    guessWord[0] = '\0';

    printf("Please guess a word:");
    scanf("%s", guessWord);

    WordNode *currentWord = wordList;

    while (currentWord) {
        if (strcmp(guessWord, currentWord->word) == 0) {
            printf("Correct! The word is: %s\n", currentWord->word);
            break;
        } else {
            currentWord = currentWord->next;
        }
    }

    if (currentWord == NULL) {
        printf("Sorry, the word is not found.\n");
    }

    free(guessWord);
}