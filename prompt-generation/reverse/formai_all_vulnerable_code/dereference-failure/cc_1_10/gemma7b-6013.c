//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define MAX_NUM 5

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int is_winner;
} BingoCard;

void initialize_bingo_card(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = 0;
    }
    card->is_winner = 0;
}

void mark_bingo_card(BingoCard *card, int number) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == number) {
            card->numbers[i] = -1;
        }
    }
}

int check_bingo_card(BingoCard *card) {
    // Check rows
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == -1 && card->numbers[i+1] == -1 && card->numbers[i+2] == -1) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == -1 && card->numbers[i+MAX_NUM] == -1 && card->numbers[i+2*MAX_NUM] == -1) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0] == -1 && card->numbers[MAX_NUM-1] == -1 && card->numbers[2*MAX_NUM-1] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    BingoCard *card = malloc(sizeof(BingoCard));
    initialize_bingo_card(card);

    // Mark the card
    mark_bingo_card(card, 1);
    mark_bingo_card(card, 3);
    mark_bingo_card(card, 5);

    // Check if the card is winner
    if (check_bingo_card(card)) {
        printf("You are winner!");
    } else {
        printf("Sorry, you are not winner.");
    }

    free(card);

    return 0;
}