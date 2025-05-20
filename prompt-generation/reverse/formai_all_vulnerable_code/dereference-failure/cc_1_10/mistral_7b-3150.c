//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_WORD_LENGTH 5
#define MAX_WORD_LENGTH 20
#define WORDS_COUNT 10

typedef struct Word {
    char *word;
    int length;
} Word;

void generateWords(Word **words, int count) {
    int i;
    for (i = 0; i < count; i++) {
        size_t len = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
        words[i] = malloc(len + 1);
        words[i]->length = len;
        for (int j = 0; j < len; j++) {
            words[i]->word[j] = 'a' + (rand() % 26);
        }
        words[i]->word[len] = '\0';
    }
}

void printWord(Word *word) {
    for (int i = 0; i < word->length; i++) {
        printf("%c", word->word[i]);
    }
    printf(" ");
}

void freeWords(Word **words, int count) {
    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

int main() {
    srand(time(NULL));

    Word *words;
    int wordsCount = WORDS_COUNT;

    generateWords(&words, wordsCount);

    clock_t start = clock();

    for (int i = 0; i < wordsCount; i++) {
        printWord(words + i);
    }

    printf("\n");

    freeWords(&words, wordsCount);

    clock_t end = clock();

    double elapsed = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Typing speed test completed in %.2f seconds.\n", elapsed);

    return 0;
}