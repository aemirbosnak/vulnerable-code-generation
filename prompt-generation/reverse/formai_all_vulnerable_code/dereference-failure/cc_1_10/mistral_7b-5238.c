//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 30
#define NUM_WORDS 10
#define LINE_LENGTH (MAX_WORD_LENGTH * 2 + 1)

typedef struct Word {
    char *word;
    int length;
} Word;

Word *generateWords(int numWords) {
    Word *words = (Word *) malloc(numWords * sizeof(Word));
    for (int i = 0; i < numWords; ++i) {
        size_t len = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
        char *word = (char *) malloc(len * sizeof(char));
        for (size_t j = 0; j < len; ++j) {
            word[j] = (char) ('a' + rand() % 26);
        }
        words[i].length = len;
        words[i].word = word;
    }
    return words;
}

void printWord(const Word *word) {
    printf("%.*s", word->length, word->word);
}

void freeWords(Word *words, int numWords) {
    for (int i = 0; i < numWords; ++i) {
        free(words[i].word);
    }
    free(words);
}

void testTypingSpeed(const Word *words, int numWords) {
    char input[LINE_LENGTH];
    clock_t start = clock();
    int numCorrect = 0;
    for (int i = 0; i < numWords; ++i) {
        printf("%s: ", words[i].word);
        scanf("%s", input);
        if (strcmp(words[i].word, input) == 0) {
            ++numCorrect;
        }
    }
    clock_t end = clock();
    double timeTaken = (double) (end - start) / CLOCKS_PER_SEC;
    printf("\nYou typed %d words correctly in %.2fs.\n", numCorrect, timeTaken);
}

int main() {
    srand(time(NULL));
    Word *words = generateWords(NUM_WORDS);
    testTypingSpeed(words, NUM_WORDS);
    freeWords(words, NUM_WORDS);
    return 0;
}