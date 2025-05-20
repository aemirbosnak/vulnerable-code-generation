//MISTRAL-7B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_THEORIES 10
#define WORDS_COUNT 5

typedef struct {
    char *words[WORDS_COUNT];
} Theory;

Theory theories[MAX_THEORIES];

char *conspiracy_words[] = {
    "lizard", "alien", "Mason", "Illuminati", "robot",
    "shadow", "government", "NSA", "JFK", "moon landing"
};

void generate_theory(Theory *t) {
    for (int i = 0; i < WORDS_COUNT; i++) {
        int index = rand() % (sizeof(conspiracy_words) / sizeof(char *));
        t->words[i] = malloc(strlen(conspiracy_words[index]) + 1);
        strcpy(t->words[i], conspiracy_words[index]);
        conspiracy_words[index] = conspiracy_words[sizeof(conspiracy_words) / sizeof(char *) - 1];
        conspiracy_words[sizeof(conspiracy_words) / sizeof(char *) - 1] = 0;
    }
}

void print_theory(Theory t) {
    printf("Conspiracy Theory #%d:\n", rand() % MAX_THEORIES + 1);
    for (int i = 0; i < WORDS_COUNT; i++) {
        printf("%s ", t.words[i]);
    }
    printf("\n");

    for (int i = 0; i < WORDS_COUNT; i++) {
        free(t.words[i]);
    }
}

int main() {
    srand(time(NULL));

    for (int i = 0; i < MAX_THEORIES; i++) {
        generate_theory(&theories[i]);
    }

    for (int i = 0; i < MAX_THEORIES; i++) {
        print_theory(theories[i]);
    }

    return 0;
}