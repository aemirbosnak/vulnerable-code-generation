//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_CONSPIRACIES 1000
#define MAX_WORDS 50

typedef struct {
    char *words[MAX_WORDS];
    int num_words;
} ConspiracyTheory;

void generate_theory(ConspiracyTheory *theory) {
    srand(time(NULL));

    theory->num_words = rand() % MAX_WORDS + 1;

    for (int i = 0; i < theory->num_words; i++) {
        theory->words[i] = malloc(sizeof(char) * 20);
        sprintf(theory->words[i], "word_%d", i);
    }
}

void print_theory(ConspiracyTheory *theory) {
    printf("Conspiracy Theory:\n");
    for (int i = 0; i < theory->num_words; i++) {
        printf("%s ", theory->words[i]);
    }
    printf("\n");
}

void free_theory(ConspiracyTheory *theory) {
    for (int i = 0; i < theory->num_words; i++) {
        free(theory->words[i]);
    }
    free(theory);
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <num_theories>\n", argv[0]);
        return 1;
    }

    int num_theories = atoi(argv[1]);

    ConspiracyTheory *theories = malloc(sizeof(ConspiracyTheory) * num_theories);

    for (int i = 0; i < num_theories; i++) {
        generate_theory(&theories[i]);
        print_theory(&theories[i]);
    }

    for (int i = 0; i < num_theories; i++) {
        free_theory(&theories[i]);
    }

    free(theories);

    return 0;
}