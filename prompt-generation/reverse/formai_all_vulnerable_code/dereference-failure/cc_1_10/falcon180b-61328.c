//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 16
#define NUM_ROWS 4
#define NUM_COLS 4

void init_deck(int deck[][NUM_COLS]) {
    int i, j, card = 1;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            deck[i][j] = card++;
        }
    }
}

void shuffle_deck(int deck[][NUM_COLS]) {
    int i, j, k, temp;
    srand(time(0));
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS - 1; j++) {
            k = rand() % NUM_COLS;
            temp = deck[i][j];
            deck[i][j] = deck[i][k];
            deck[i][k] = temp;
        }
    }
}

void print_deck(int deck[][NUM_COLS]) {
    int i, j;
    for (i = 0; i < NUM_ROWS; i++) {
        for (j = 0; j < NUM_COLS; j++) {
            printf("%d ", deck[i][j]);
        }
        printf("\n");
    }
}

void play_game(int deck[][NUM_COLS]) {
    int i, j, num_flips = 0, match_count = 0;
    printf("Flip over two cards:\n");
    while (match_count < NUM_CARDS) {
        int card1, card2;
        scanf("%d %d", &card1, &card2);
        if (card1 < 1 || card1 > NUM_CARDS || card2 < 1 || card2 > NUM_CARDS) {
            printf("Invalid card number!\n");
            continue;
        }
        if (deck[card1 - 1][0] == deck[card2 - 1][0]) {
            match_count++;
            printf("Match found!\n");
        } else {
            printf("No match found.\n");
            deck[card1 - 1][0] = -1;
            deck[card2 - 1][0] = -1;
        }
        num_flips++;
    }
    printf("Game over. You flipped over %d cards.\n", num_flips);
}

int main() {
    int deck[NUM_ROWS][NUM_COLS];
    init_deck(deck);
    shuffle_deck(deck);
    print_deck(deck);
    play_game(deck);
    return 0;
}