//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int* cards;
    int size;
    bool isOpen;
} MemoryGame;

MemoryGame* createMemoryGame() {
    MemoryGame* game = (MemoryGame*)malloc(sizeof(MemoryGame));
    game->cards = (int*)malloc(MAX_SIZE * sizeof(int));
    game->size = 0;
    game->isOpen = true;
    return game;
}

void printCards(MemoryGame* game) {
    int i;
    for (i = 0; i < game->size; i++) {
        printf("%d ", game->cards[i]);
    }
    printf("\n");
}

void shuffleCards(MemoryGame* game) {
    int i, j;
    for (i = game->size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        int temp = game->cards[i];
        game->cards[i] = game->cards[j];
        game->cards[j] = temp;
    }
}

int main() {
    MemoryGame* game = createMemoryGame();
    shuffleCards(game);
    printf("Initial cards:\n");
    printCards(game);
    
    int matches = 0;
    for (int i = 0; i < game->size; i++) {
        printf("Match card %d with card ", i + 1);
        scanf("%d", &game->cards[i]);
    }
    
    for (int i = 0; i < game->size; i++) {
        for (int j = i + 1; j < game->size; j++) {
            if (game->cards[i] == game->cards[j]) {
                printf("Match!\n");
                matches++;
            }
        }
    }
    
    printf("Total matches: %d\n", matches);
    
    return 0;
}