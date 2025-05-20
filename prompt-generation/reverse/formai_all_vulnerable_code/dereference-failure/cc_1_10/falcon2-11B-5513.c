//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int num_players = atoi(argv[1]);
    int num_rounds = atoi(argv[2]);
    int *bingo_cards = malloc(num_players * sizeof(int));
    int *numbers = malloc(100 * sizeof(int));
    srand(time(NULL));

    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < 5; j++) {
            int num = rand() % 75;
            bingo_cards[i] |= (1 << num);
        }
    }

    for (int i = 0; i < num_rounds; i++) {
        printf("Round %d:\n", i + 1);
        for (int j = 0; j < num_players; j++) {
            printf("%d ", bingo_cards[j]);
            fflush(stdout);
        }
        printf("\n");

        for (int j = 0; j < 5; j++) {
            int num = rand() % 75;
            int index = rand() % num_players;
            printf("Number %d selected: %d\n", j + 1, num);
            fflush(stdout);
            bingo_cards[index] &= ~(1 << num);
        }
    }

    for (int i = 0; i < num_players; i++) {
        int winner = 0;
        for (int j = 1; j <= 5; j++) {
            int num = bingo_cards[i] & (1 << j);
            if (num == 0) {
                winner = 1;
                break;
            }
        }
        if (winner == 0) {
            printf("Player %d wins!\n", i + 1);
        } else {
            printf("No winner in this round\n");
        }
    }

    free(bingo_cards);
    free(numbers);
    return 0;
}