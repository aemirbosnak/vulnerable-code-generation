//Gemma-7B DATASET v1.0 Category: Terminal Based Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 5
#define MAX_CARDS_PER_PILE 10

typedef struct Card {
    int number;
    struct Card* next;
} Card;

typedef struct Pile {
    Card* head;
    int cards_left;
} Pile;

void initialize_pile(Pile* p) {
    p->head = NULL;
    p->cards_left = 0;
}

void add_card_to_pile(Pile* p, int number) {
    Card* new_card = malloc(sizeof(Card));
    new_card->number = number;
    new_card->next = NULL;

    if (p->head == NULL) {
        p->head = new_card;
    } else {
        p->head->next = new_card;
    }

    p->cards_left++;
}

int draw_card_from_pile(Pile* p) {
    if (p->cards_left == 0) {
        return -1;
    }

    Card* old_head = p->head;
    p->head = p->head->next;
    p->cards_left--;

    return old_head->number;
}

int main() {
    Pile* piles[MAX_PILES];

    for (int i = 0; i < MAX_PILES; i++) {
        initialize_pile(&piles[i]);
    }

    // Add cards to the piles
    add_card_to_pile(&piles[0], 2);
    add_card_to_pile(&piles[0], 4);
    add_card_to_pile(&piles[1], 6);
    add_card_to_pile(&piles[1], 8);

    // Draw cards from the piles
    int card_number = draw_card_from_pile(&piles[0]);
    printf("You drew card number %d from pile 0.\n", card_number);

    card_number = draw_card_from_pile(&piles[1]);
    printf("You drew card number %d from pile 1.\n", card_number);

    return 0;
}