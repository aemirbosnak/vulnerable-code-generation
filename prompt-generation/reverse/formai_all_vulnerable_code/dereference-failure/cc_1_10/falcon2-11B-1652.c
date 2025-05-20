//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define MAX_CARDS 52
#define CARD_SIZE 10

typedef struct {
    char data[CARD_SIZE];
    struct card *next;
} card;

card *create_card(const char *data) {
    card *new_card = (card *)malloc(sizeof(card));
    strcpy(new_card->data, data);
    new_card->next = NULL;
    return new_card;
}

void add_card(card **cards, const char *data) {
    card *new_card = create_card(data);
    if (*cards == NULL) {
        *cards = new_card;
    } else {
        card *temp = *cards;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = new_card;
    }
}

void print_cards(card *cards) {
    while (cards!= NULL) {
        printf("%s\n", cards->data);
        cards = cards->next;
    }
}

int main() {
    card *cards = NULL;
    add_card(&cards, "Ace of Spades");
    add_card(&cards, "King of Hearts");
    add_card(&cards, "Queen of Diamonds");
    add_card(&cards, "Jack of Clubs");
    add_card(&cards, "10 of Spades");
    add_card(&cards, "9 of Hearts");
    add_card(&cards, "8 of Diamonds");
    add_card(&cards, "7 of Clubs");
    add_card(&cards, "6 of Spades");
    add_card(&cards, "5 of Hearts");
    add_card(&cards, "4 of Diamonds");
    add_card(&cards, "3 of Clubs");
    add_card(&cards, "2 of Spades");

    print_cards(cards);

    return 0;
}