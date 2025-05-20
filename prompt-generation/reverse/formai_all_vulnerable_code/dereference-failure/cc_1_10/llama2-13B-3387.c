//LLAMA2-13B DATASET v1.0 Category: Memory Game ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MEMORY_GAME_SIZE 10
#define PAIR_SIZE 2

typedef struct {
    char *word;
    int frequency;
} pair_t;

pair_t pairs[MEMORY_GAME_SIZE][PAIR_SIZE];
int current_pair = 0;

void init_pairs(void) {
    int i, j;

    for (i = 0; i < MEMORY_GAME_SIZE; i++) {
        for (j = 0; j < PAIR_SIZE; j++) {
            pairs[i][j].word = malloc(sizeof(char *) * (i + 1));
            pairs[i][j].frequency = rand() % 10 + 1;
            pairs[i][j].word[0] = malloc(sizeof(char) * (i + 1));
            strcpy(pairs[i][j].word[0], "Love");
            for (int k = 1; k < i + 1; k++) {
                pairs[i][j].word[k] = malloc(sizeof(char) * (i + 1));
                strcat(pairs[i][j].word[k], " is in the air");
            }
        }
    }
}

void print_pairs(void) {
    int i, j;

    for (i = 0; i < MEMORY_GAME_SIZE; i++) {
        for (j = 0; j < PAIR_SIZE; j++) {
            printf("%d. %s\n", i * PAIR_SIZE + j + 1, pairs[i][j].word);
        }
    }
}

void play_game(void) {
    int i, j, k, correct = 0;

    for (i = 0; i < MEMORY_GAME_SIZE; i++) {
        for (j = 0; j < PAIR_SIZE; j++) {
            printf("%d. %s\n", i * PAIR_SIZE + j + 1, pairs[i][j].word);
        }
        for (j = 0; j < PAIR_SIZE; j++) {
            printf("Enter the word %d and %d: ", i + 1, j + 1);
            scanf("%s", pairs[i][j].word);
        }
        for (j = 0; j < PAIR_SIZE; j++) {
            if (strcmp(pairs[i][j].word, pairs[i][j].word + 1) == 0) {
                correct++;
            }
        }
    }
    printf("You got %d correct pairs out of %d\n", correct, MEMORY_GAME_SIZE * PAIR_SIZE);
}

int main(void) {
    srand(time(NULL));
    init_pairs();
    play_game();
    return 0;
}