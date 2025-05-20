//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PILES 3
#define MAX_CARDS_PER_PILE 5

typedef struct Card {
    int number;
    struct Card* next;
} Card;

typedef struct Pile {
    Card* head;
    int cards_left;
} Pile;

void initialize_piles(Pile** piles) {
    for (int i = 0; i < MAX_PILES; i++) {
        piles[i] = malloc(sizeof(Pile));
        piles[i]->head = NULL;
        piles[i]->cards_left = MAX_CARDS_PER_PILE;
    }
}

void deal_card(Pile* pile) {
    if (pile->cards_left > 0) {
        Card* new_card = malloc(sizeof(Card));
        new_card->number = rand() % MAX_CARDS_PER_PILE + 1;
        new_card->next = pile->head;
        pile->head = new_card;
        pile->cards_left--;
    } else {
        printf("No cards left!");
    }
}

int main() {
    Pile** piles = malloc(MAX_PILES * sizeof(Pile*));
    initialize_piles(piles);

    // Game loop
    while (1) {
        printf("Enter your move (draw/play): ");
        char move;
        scanf("%c", &move);

        switch (move) {
            case 'd':
                deal_card(piles[0]);
                break;
            case 'p':
                // Play card
                break;
            default:
                printf("Invalid move.");
        }

        // Check if game is over
        if (piles[0]->cards_left == 0) {
            printf("You won!");
            break;
        }
    }

    return 0;
}