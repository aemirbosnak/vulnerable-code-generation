//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define NUM_OF_BINGO_CARDS 50

typedef struct {
    int **card;
    int card_size;
    int card_num;
} BingoCard;

BingoCard create_bingo_card(int card_size) {
    BingoCard card;
    card.card_size = card_size;
    card.card_num = NUM_OF_BINGO_CARDS;
    card.card = (int **)malloc(card.card_size * sizeof(int *));

    for (int i = 0; i < card.card_size; i++) {
        card.card[i] = (int *)malloc(card.card_size * sizeof(int));
        for (int j = 0; j < card.card_size; j++) {
            card.card[i][j] = rand() % card.card_size + 1;
        }
    }
    return card;
}

void print_bingo_card(BingoCard card) {
    for (int i = 0; i < card.card_size; i++) {
        for (int j = 0; j < card.card_size; j++) {
            printf("%d ", card.card[i][j]);
        }
        printf("\n");
    }
}

void update_bingo_card(BingoCard *card, int row, int column) {
    card->card[row][column] = 0;
}

void print_winner(BingoCard *card) {
    int winner = -1;
    for (int i = 0; i < card->card_size; i++) {
        for (int j = 0; j < card->card_size; j++) {
            if (card->card[i][j]!= 0 && card->card[i][j] == winner) {
                printf("Bingo!\n");
                winner = -1;
                break;
            }
        }
    }
}

int main() {
    srand(time(NULL));

    int card_size = 5;
    int card_num = 10;

    for (int i = 0; i < card_num; i++) {
        BingoCard card = create_bingo_card(card_size);
        print_bingo_card(card);
        printf("\n");

        for (int j = 0; j < card_size; j++) {
            int column = rand() % card_size + 1;
            while (card.card[rand() % card_size][column]!= 0) {
                column = rand() % card_size + 1;
            }
            update_bingo_card(&card, rand() % card_size, column);
        }

        print_bingo_card(card);
        printf("\n");
        print_winner(&card);
    }

    return 0;
}