//MISTRAL-7B DATASET v1.0 Category: Poker Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct Card {
    int suit;
    int value;
};

void printCard(struct Card card) {
    switch(card.suit) {
        case 0: printf("Spade "); break;
        case 1: printf("Heart "); break;
        case 2: printf("Diamond "); break;
        case 3: printf("Club "); break;
    }

    switch(card.value) {
        case 1: printf("Ace\n"); break;
        case 11: printf("Jack\n"); break;
        case 12: printf("Queen\n"); break;
        case 13: printf("King\n"); break;
        default: printf("%d\n", card.value);
    }
}

void shuffle(struct Card *deck, int n) {
    for(int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void dealCards(struct Card *deck, int nPlayers, int cardsPerPlayer) {
    for(int player = 0; player < nPlayers; player++) {
        for(int i = 0; i < cardsPerPlayer; i++) {
            printf("Player %d draws a card:\n", player + 1);
            printCard(deck[player * cardsPerPlayer + i]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int nPlayers = 4;
    int nDecks = 1;
    int cardsPerPlayer = 5;

    int nCardsTotal = nPlayers * cardsPerPlayer;

    struct Card *deck = malloc(sizeof(struct Card) * (nDecks * 52));

    for(int suit = 0; suit < 4; suit++) {
        for(int value = 1; value <= 13; value++) {
            int index = suit * 13 + value - 1;
            deck[index].suit = suit;
            deck[index].value = value;
        }
    }

    shuffle(deck, nDecks * 52);

    int remainingCards = nDecks * 52 - nCardsTotal;

    printf("Shuffled deck:\n");
    for(int i = 0; i < nDecks * 52; i++) {
        if(i > 0 && i % 13 == 0) printf("\n");
        printCard(deck[i]);
    }

    printf("\n");

    dealCards(deck, nPlayers, cardsPerPlayer);

    free(deck);

    if(remainingCards > 0) {
        printf("There are %d remaining cards in the deck.\n", remainingCards);
    } else {
        printf("Deck is empty.\n");
    }

    return 0;
}