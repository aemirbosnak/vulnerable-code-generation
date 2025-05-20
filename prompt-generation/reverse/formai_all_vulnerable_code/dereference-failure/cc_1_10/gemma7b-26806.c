//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 9

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int bingo;
} BingoCard;

void generateBingoCard(BingoCard *card) {
    srand(time(NULL));
    for (int i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }
    card->bingo = 0;
}

void checkBingo(BingoCard *card) {
    for (int i = 0; i < MAX_NUM; i++) {
        if (card->numbers[i] == card->bingo) {
            card->bingo = 0;
            return;
        }
    }
    return;
}

int main() {
    BingoCard card;
    generateBingoCard(&card);

    printf("Your bingo card:\n");
    for (int i = 0; i < MAX_NUM; i++) {
        printf("%d ", card.numbers[i]);
    }
    printf("\n");

    int numWins = 0;
    while (!card.bingo && numWins < 5) {
        printf("Draw a number: ");
        int number = atoi(gets(NULL));

        if (number == card.bingo) {
            card.bingo = 0;
            numWins++;
            printf("Congratulations! You won!\n");
        } else {
            printf("Sorry, that number is not on your card.\n");
        }
    }

    return 0;
}