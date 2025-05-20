//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 10
#define WORDS_PER_TEST 5

typedef struct Word {
    char **words;
    int index;
} Word;

Word *createWordList() {
    Word *wordList = malloc(sizeof(Word));
    wordList->words = malloc(MAX_WORDS * sizeof(char *));
    wordList->index = 0;
    return wordList;
}

void addWordToWordList(Word *wordList, char *word) {
    wordList->words[wordList->index++] = word;
}

int main() {
    Word *wordList = createWordList();

    char **testWords = malloc(WORDS_PER_TEST * sizeof(char *));
    testWords[0] = "Apple";
    testWords[1] = "Banana";
    testWords[2] = "Orange";
    testWords[3] = "Peach";
    testWords[4] = "Pear";

    for (int i = 0; i < WORDS_PER_TEST; i++) {
        addWordToWordList(wordList, testWords[i]);
    }

    time_t start = time(NULL);
    int wordsTyped = 0;

    // Simulate typing words asynchronously
    for (int i = 0; i < MAX_WORDS; i++) {
        char *word = wordList->words[rand() % wordList->index];
        printf("%s ", word);
        wordsTyped++;
        sleep(rand() % 2);
    }

    time_t end = time(NULL);

    printf("\nTime taken: %ld seconds", end - start);
    printf("\nNumber of words typed: %d", wordsTyped);

    return 0;
}