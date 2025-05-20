//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACY_LENGTH 1000
#define MAX_WORDS 100

typedef struct {
    char *word;
    int length;
} Word;

typedef struct {
    Word *words;
    int num_words;
} ConspiracyTheory;

void generate_conspiracy_theory(ConspiracyTheory *theory) {
    srand(time(0));

    theory->num_words = rand() % MAX_WORDS + 1;
    theory->words = malloc(theory->num_words * sizeof(Word));

    for (int i = 0; i < theory->num_words; i++) {
        theory->words[i].word = malloc(MAX_CONSPIRACY_LENGTH * sizeof(char));
        theory->words[i].length = rand() % MAX_CONSPIRACY_LENGTH + 1;

        for (int j = 0; j < theory->words[i].length; j++) {
            theory->words[i].word[j] = rand() % 26 + 'a';
        }

        theory->words[i].word[theory->words[i].length] = '\0';
    }
}

void print_conspiracy_theory(ConspiracyTheory *theory) {
    for (int i = 0; i < theory->num_words; i++) {
        printf("%s ", theory->words[i].word);
    }
}

void free_conspiracy_theory(ConspiracyTheory *theory) {
    for (int i = 0; i < theory->num_words; i++) {
        free(theory->words[i].word);
    }

    free(theory->words);
}

int main() {
    ConspiracyTheory theory;

    generate_conspiracy_theory(&theory);
    print_conspiracy_theory(&theory);
    free_conspiracy_theory(&theory);

    return 0;
}