//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct card {
    int number;
    int position;
    struct card *next;
};

struct deck {
    int size;
    int capacity;
    struct card *cards;
};

void shuffle(struct deck *deck) {
    int i, j;
    for (i = deck->size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        struct card *temp = deck->cards[i].next;
        deck->cards[i].next = deck->cards[j].next;
        deck->cards[j].next = temp;
    }
}

void print_deck(struct deck *deck) {
    struct card *card = deck->cards;
    printf("Deck size: %d\n", deck->size);
    printf("Deck capacity: %d\n", deck->capacity);
    printf("Deck: ");
    while (card!= NULL) {
        printf("%d ", card->number);
        card = card->next;
    }
    printf("\n");
}

void deal_card(struct deck *deck) {
    struct card *card = deck->cards;
    struct card *new_card = malloc(sizeof(struct card));
    new_card->number = rand() % 52;
    new_card->position = -1;
    new_card->next = NULL;
    if (deck->size < deck->capacity) {
        deck->cards = card;
        deck->size++;
        new_card->next = card;
        card = card->next;
    } else {
        printf("Deck is empty!\n");
    }
}

int main() {
    struct deck deck;
    deck.size = 0;
    deck.capacity = 52;
    deck.cards = malloc(sizeof(struct card));
    deck.cards->next = NULL;
    deck.cards->number = 0;
    deck.cards->position = 0;
    shuffle(&deck);
    print_deck(&deck);
    while (deck.size > 0) {
        printf("Turn: ");
        deal_card(&deck);
        printf("Turn: ");
        print_deck(&deck);
        printf("\n");
    }
    return 0;
}