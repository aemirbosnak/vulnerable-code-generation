//Gemma-7B DATASET v1.0 Category: Table Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_PILES 5
#define MAX_CARDS 10

typedef struct Card {
    int value;
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

void add_card_to_pile(Pile* p, int value) {
    Card* new_card = malloc(sizeof(Card));
    new_card->value = value;
    new_card->next = p->head;
    p->head = new_card;
    p->cards_left++;
}

void draw_card(Pile* p) {
    if (p->cards_left == 0) {
        return;
    }
    Card* old_head = p->head;
    p->head = p->head->next;
    p->cards_left--;
    free(old_head);
}

int main() {
    Pile* player_pile = malloc(sizeof(Pile));
    initialize_pile(player_pile);

    // Add some cards to the player's pile
    add_card_to_pile(player_pile, 5);
    add_card_to_pile(player_pile, 10);
    add_card_to_pile(player_pile, 15);

    // Draw a card from the player's pile
    draw_card(player_pile);

    // Print the card that was drawn
    printf("You drew a card worth %d.\n", player_pile->head->value);

    return 0;
}