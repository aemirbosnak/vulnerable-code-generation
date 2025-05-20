//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MIN_WORD_LENGTH 3
#define MAX_WORD_LENGTH 10
#define NUM_WORDS 10
#define LINE_LENGTH 80

typedef struct Word {
    char *word;
    int len;
} Word;

Word *generate_words(void);
void print_words(Word *words);
void free_words(Word *words);

int main(void) {
    Word *words = generate_words();
    int i, score = 0;

    printf("Typing Speed Test\n");
    printf("------------------\n");
    printf("Type the following words as fast as you can:\n");

    clock_t start = clock();

    for (i = 0; i < NUM_WORDS; i++) {
        printf("\n%s: ", words[i].word);
        scanf("%s", words[i].word);
        if (strcmp(words[i].word, words[i].word) == 0) {
            score += words[i].len;
        }
    }

    clock_t end = clock();
    double elapsed_time = (end - start) / (double) CLOCKS_PER_SEC;
    double wpm = (double) score / elapsed_time * 60;

    printf("\nTest Completed! Your typing speed is %0.2f wpm.\n", wpm);

    free_words(words);

    return 0;
}

Word *generate_words(void) {
    Word *words = malloc(NUM_WORDS * sizeof(Word));
    int i;

    for (i = 0; i < NUM_WORDS; i++) {
        words[i].len = rand() % (MAX_WORD_LENGTH - MIN_WORD_LENGTH + 1) + MIN_WORD_LENGTH;
        words[i].word = malloc(words[i].len + 1);
        memset(words[i].word, 'a' + rand() % 26, words[i].len);
        words[i].word[words[i].len] = '\0';
    }

    return words;
}

void print_words(Word *words) {
    int i;

    for (i = 0; i < NUM_WORDS; i++) {
        printf("%s (%d chars)\n", words[i].word, words[i].len);
    }
}

void free_words(Word *words) {
    int i;

    for (i = 0; i < NUM_WORDS; i++) {
        free(words[i].word);
    }

    free(words);
}