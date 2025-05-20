//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BINGO_CARDS 5
#define MAX_BALLS 20

typedef struct BingoCard {
    int **numbers;
    int cards_won;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    card->numbers = malloc(MAX_BALLS * sizeof(int));
    for (int i = 0; i < MAX_BALLS; i++) {
        card->numbers[i] = 0;
    }
    card->cards_won = 0;
}

void mark_bingo_card(BingoCard *card, int number) {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (card->numbers[i] == number) {
            card->numbers[i] = -1;
        }
    }
}

int check_bingo_card(BingoCard *card) {
    for (int i = 0; i < MAX_BALLS; i++) {
        if (card->numbers[i] == -1) {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    BingoCard cards[MAX_BINGO_CARDS];
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        initialize_bingo_card(&cards[i]);
    }

    int balls_drawn = 0;
    int winning_card = -1;
    while (balls_drawn < MAX_BALLS && winning_card == -1) {
        int number = rand() % MAX_BALLS + 1;
        for (int i = 0; i < MAX_BINGO_CARDS; i++) {
            mark_bingo_card(&cards[i], number);
            if (check_bingo_card(&cards[i])) {
                winning_card = i;
            }
        }
        balls_drawn++;
    }

    if (winning_card != -1) {
        printf("Winner: card %d\n", winning_card);
    } else {
        printf("No winner\n");
    }

    return 0;
}