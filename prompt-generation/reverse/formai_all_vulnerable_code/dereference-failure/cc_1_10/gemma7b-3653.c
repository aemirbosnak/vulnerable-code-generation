//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARDS 10

typedef struct BingoCard {
    int **numbers;
    int rows;
    int cols;
    int wins;
} BingoCard;

BingoCard *createBingoCard() {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->rows = 5;
    card->cols = 5;
    card->numbers = (int **)malloc(card->rows * sizeof(int *));
    for (int r = 0; r < card->rows; r++) {
        card->numbers[r] = (int *)malloc(card->cols * sizeof(int));
    }
    card->wins = 0;
    return card;
}

void addNumbersToBingoCard(BingoCard *card, int num) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->cols; c++) {
            if (card->numbers[r][c] == 0) {
                card->numbers[r][c] = num;
                return;
            }
        }
    }
    return;
}

int checkBingo(BingoCard *card) {
    for (int r = 0; r < card->rows; r++) {
        if (card->numbers[r][0] == card->numbers[r][1] && card->numbers[r][0] == card->numbers[r][2] && card->numbers[r][0] == card->numbers[r][3] && card->numbers[r][0] == card->numbers[r][4]) {
            return 1;
        }
    }
    for (int c = 0; c < card->cols; c++) {
        if (card->numbers[0][c] == card->numbers[1][c] && card->numbers[0][c] == card->numbers[2][c] && card->numbers[0][c] == card->numbers[3][c] && card->numbers[0][c] == card->numbers[4][c]) {
            return 1;
        }
    }
    if (card->numbers[0][0] == card->numbers[1][1] && card->numbers[0][0] == card->numbers[2][2] && card->numbers[0][0] == card->numbers[3][3] && card->numbers[0][0] == card->numbers[4][4]) {
        return 1;
    }
    return 0;
}

int main() {
    BingoCard *cards[MAX_BINGO_CARDS];
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        cards[i] = createBingoCard();
    }

    // Add numbers to the cards
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        addNumbersToBingoCard(cards[i], 1);
        addNumbersToBingoCard(cards[i], 2);
        addNumbersToBingoCard(cards[i], 3);
        addNumbersToBingoCard(cards[i], 4);
        addNumbersToBingoCard(cards[i], 5);
    }

    // Check for bingo
    for (int i = 0; i < MAX_BINGO_CARDS; i++) {
        if (checkBingo(cards[i])) {
            cards[i]->wins++;
            printf("Bingo! Card %d has won!\n", i);
        }
    }

    return 0;
}