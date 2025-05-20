//Gemma-7B DATASET v1.0 Category: Typing Speed Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_WORDS 1000

typedef struct Word {
    char *word;
    int length;
} Word;

Word *createWord(char *word, int length) {
    Word *w = malloc(sizeof(Word));
    w->word = strdup(word);
    w->length = length;
    return w;
}

void freeWord(Word *w) {
    free(w->word);
    free(w);
}

int main() {
    srand(time(NULL));
    int words_per_test = rand() % MAX_WORDS + 1;
    char **words = malloc(words_per_test * sizeof(char *));
    for (int i = 0; i < words_per_test; i++) {
        words[i] = malloc(20 * sizeof(char));
        words[i] = "Hello, world!";
    }

    int speed_test_time = 3;
    double start_time = clock();
    for (int i = 0; i < words_per_test; i++) {
        printf("%s ", words[i]);
    }
    printf("\n");

    double end_time = clock();
    double time_taken = (end_time - start_time) / CLOCKS_PER_SEC;
    double words_per_second = (words_per_test * words_per_second) / time_taken;

    printf("Words per second: %.2lf\n", words_per_second);

    for (int i = 0; i < words_per_test; i++) {
        freeWord(words[i]);
    }
    free(words);

    return 0;
}