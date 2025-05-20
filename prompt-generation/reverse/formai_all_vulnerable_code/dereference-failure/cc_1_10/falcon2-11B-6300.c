//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define NUM_CARDS 8
#define MATCH_SCORE 1
#define NO_MATCH_SCORE 0

typedef struct {
    int card1;
    int card2;
} CardPair;

typedef struct {
    int numCards;
    CardPair* cards;
} MemoryGame;

void initializeMemoryGame(MemoryGame* game) {
    srand(time(NULL));
    game->numCards = NUM_CARDS;
    game->cards = (CardPair*)malloc(game->numCards * sizeof(CardPair));
    for (int i = 0; i < game->numCards; i++) {
        game->cards[i].card1 = rand() % NUM_CARDS + 1;
        game->cards[i].card2 = rand() % NUM_CARDS + 1;
    }
}

void printMemoryGame(MemoryGame game) {
    printf("Memory Game:\n");
    printf("Number of cards: %d\n", game.numCards);
    printf("Cards:\n");
    for (int i = 0; i < game.numCards; i++) {
        printf("Card %d: %d\n", i + 1, game.cards[i].card1);
        printf("Card %d: %d\n", i + 1, game.cards[i].card2);
    }
    printf("\n");
}

void matchCards(MemoryGame* game) {
    int matchCount = 0;
    bool matchFound = false;
    for (int i = 0; i < game->numCards; i++) {
        for (int j = i + 1; j < game->numCards; j++) {
            if (game->cards[i].card1 == game->cards[j].card1 && game->cards[i].card2 == game->cards[j].card2) {
                matchFound = true;
                matchCount++;
                break;
            }
        }
        if (matchFound) {
            break;
        }
    }
    if (matchFound) {
        printf("Match found! Score: %d\n", MATCH_SCORE);
    } else {
        printf("No match found. Score: %d\n", NO_MATCH_SCORE);
    }
}

int main() {
    MemoryGame game;
    initializeMemoryGame(&game);
    printMemoryGame(game);
    matchCards(&game);
    free(game.cards);
    return 0;
}