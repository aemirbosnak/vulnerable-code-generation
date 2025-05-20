//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 10

typedef struct BingoCard {
    int numbers[MAX_NUM];
    int freeSpaces;
    int mark[MAX_NUM];
} BingoCard;

void generateBingoCard(BingoCard *card) {
    int i;
    srand(time(NULL));

    for (i = 0; i < MAX_NUM; i++) {
        card->numbers[i] = rand() % MAX_NUM + 1;
    }

    card->freeSpaces = MAX_NUM - 5;
    card->mark[0] = 1;
}

void playBingo(BingoCard *card) {
    int numberDrawn;

    printf("Enter the number drawn: ");
    scanf("%d", &numberDrawn);

    if (card->mark[numberDrawn] == 0) {
        card->mark[numberDrawn] = 1;
        card->freeSpaces--;

        if (card->freeSpaces == 0) {
            printf("You win!\n");
        } else {
            printf("Number drawn: %d\n", numberDrawn);
        }
    } else {
        printf("Sorry, number already drawn.\n");
    }
}

int main() {
    BingoCard card;
    generateBingoCard(&card);
    playBingo(&card);

    return 0;
}