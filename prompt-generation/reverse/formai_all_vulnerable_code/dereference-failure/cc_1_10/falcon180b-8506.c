//Falcon-180B DATASET v1.0 Category: Random Conspiracy Theory Generator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_CONSPIRACIES 100
#define MAX_WORDS_PER_CONSPIRACY 10
#define MAX_WORD_LENGTH 20

typedef struct {
    char words[MAX_WORDS_PER_CONSPIRACY][MAX_WORD_LENGTH];
    int num_words;
} ConspiracyTheory;

void generate_theory(ConspiracyTheory* theory) {
    int i;
    for (i = 0; i < theory->num_words; i++) {
        int word_length = rand() % MAX_WORD_LENGTH + 1;
        theory->words[i][0] = 'A' + rand() % 26;
        for (int j = 1; j < word_length; j++) {
            theory->words[i][j] = 'A' + rand() % 26;
        }
        theory->words[i][word_length] = '\0';
    }
}

int main() {
    srand(time(NULL));

    ConspiracyTheory* theories = malloc(MAX_CONSPIRACIES * sizeof(ConspiracyTheory));

    int num_theories = 0;

    while (num_theories < MAX_CONSPIRACIES) {
        ConspiracyTheory theory;
        generate_theory(&theory);

        int found = 0;
        for (int i = 0; i < num_theories; i++) {
            if (strcmp(theory.words[0], theories[i].words[0]) == 0) {
                found = 1;
                break;
            }
        }

        if (!found) {
            memcpy(&theories[num_theories], &theory, sizeof(ConspiracyTheory));
            num_theories++;
        }
    }

    for (int i = 0; i < num_theories; i++) {
        printf("Conspiracy Theory #%d:\n", i + 1);
        for (int j = 0; j < theories[i].num_words; j++) {
            printf("%s ", theories[i].words[j]);
        }
        printf("\n");
    }

    free(theories);

    return 0;
}