//Falcon2-11B DATASET v1.0 Category: Bingo Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int number;
    int column;
} BingoCard;

typedef struct {
    BingoCard* cards;
    int cardCount;
} BingoGame;

int main(int argc, char* argv[]) {
    srand(time(NULL));

    int numCards = 10;
    int cardSize = 5;
    int maxNumber = 100;

    BingoGame game = {
       .cards = (BingoCard*) malloc(numCards * sizeof(BingoCard)),
       .cardCount = numCards,
    };

    for (int i = 0; i < numCards; i++) {
        game.cards[i].number = rand() % maxNumber + 1;
        game.cards[i].column = i % cardSize;
    }

    printf("Bingo Game\n\n");
    printf("Card 1\n");
    printf("  1   2   3   4   5   6   7   8   9\n");
    for (int i = 0; i < cardSize; i++) {
        if (i < game.cards[0].column)
            printf("  X");
        else
            printf("%d", game.cards[0].number);
        printf(" |");
    }
    printf("\n");

    for (int i = 1; i < numCards; i++) {
        printf("\nCard %d\n", i + 1);
        printf("  1   2   3   4   5   6   7   8   9\n");
        for (int i = 0; i < cardSize; i++) {
            if (i < game.cards[i].column)
                printf("  X");
            else
                printf("%d", game.cards[i].number);
            printf(" |");
        }
        printf("\n");
    }

    return 0;
}