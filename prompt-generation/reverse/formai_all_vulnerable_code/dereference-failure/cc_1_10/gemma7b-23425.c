//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

#define MAX_BINGO_CARD_SIZE 5

typedef struct BingoCard {
    int numbers[MAX_BINGO_CARD_SIZE];
    int numCards;
} BingoCard;

BingoCard *createBingoCard(int numCards) {
    BingoCard *card = malloc(sizeof(BingoCard));
    card->numCards = numCards;

    for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
        card->numbers[i] = 0;
    }

    return card;
}

void playBingo(BingoCard *card) {
    // Generate random numbers
    int numDrawn = rand() % MAX_BINGO_CARD_SIZE;
    card->numbers[numDrawn] = 1;

    // Check if the player has won
    int won = 0;
    for (int i = 0; i < MAX_BINGO_CARD_SIZE; i++) {
        if (card->numbers[i] == 1) {
            won = 1;
        }
    }

    // Print the results
    if (won) {
        printf("You won!\n");
    } else {
        printf("Sorry, you lost.\n");
    }
}

int main() {
    // Create a bingo card
    BingoCard *card = createBingoCard(1);

    // Play bingo
    playBingo(card);

    return 0;
}