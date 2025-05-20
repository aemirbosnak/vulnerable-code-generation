//MISTRAL-7B DATASET v1.0 Category: Typing Speed Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define WORD_COUNT 10
#define WORD_LENGTH 30
#define BUFFER_SIZE 256
#define DELAY 10

typedef struct {
    char *word;
    int length;
} Word;

void print_words(Word *words) {
    for (int i = 0; i < WORD_COUNT; ++i) {
        printf("%s ", words[i].word);
    }
    printf("\n");
}

void init_words(Word *words) {
    for (int i = 0; i < WORD_COUNT; ++i) {
        words[i].word = malloc(WORD_LENGTH * sizeof(char));
        for (int j = 0; j < WORD_LENGTH; ++j) {
            words[i].word[j] = 'a' + rand() % 26;
        }
        words[i].length = WORD_LENGTH;
    }
}

void free_words(Word *words) {
    for (int i = 0; i < WORD_COUNT; ++i) {
        free(words[i].word);
    }
}

void test(Word *words) {
    clock_t start = clock();

    for (int i = 0; i < WORD_COUNT; ++i) {
        printf("%s ", words[i].word);
        usleep(DELAY * 1000);
    }

    printf("\n");
    clock_t end = clock();
    double elapsed_secs = (end - start) / CLOCKS_PER_SEC;
    printf("Time taken: %.6f seconds.\n", elapsed_secs);
}

int main() {
    srand(time(NULL));

    Word *words = calloc(WORD_COUNT, sizeof(Word));
    if (words == NULL) {
        perror("Calloc failed");
        return 1;
    }

    init_words(words);

    printf("Press Enter to start the test...\n");
    getchar();

    print_words(words);

    test(words);

    free_words(words);
    free(words);

    return 0;
}