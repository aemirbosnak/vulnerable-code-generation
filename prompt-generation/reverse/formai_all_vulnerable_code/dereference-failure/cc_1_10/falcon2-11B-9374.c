//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

typedef struct {
    int value;
    int covered;
} Card;

typedef struct {
    int r;
    int c;
    Card* deck;
} Game;

Game createGame() {
    Game game;
    game.r = ROWS;
    game.c = COLS;
    game.deck = (Card*)malloc(game.r * game.c * sizeof(Card));
    for (int i = 0; i < game.r * game.c; i++) {
        game.deck[i].value = rand() % 10;
        game.deck[i].covered = 1;
    }
    return game;
}

void printDeck(Game game) {
    for (int i = 0; i < game.r; i++) {
        for (int j = 0; j < game.c; j++) {
            printf("%d ", game.deck[i * game.c + j].value);
        }
        printf("\n");
    }
}

int main() {
    Game game = createGame();
    printDeck(game);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (game.deck[i * game.c + j].covered) {
                printf("Card %d is %d\n", i + 1, game.deck[i * game.c + j].value);
                game.deck[i * game.c + j].covered = 0;
            }
        }
    }
    return 0;
}