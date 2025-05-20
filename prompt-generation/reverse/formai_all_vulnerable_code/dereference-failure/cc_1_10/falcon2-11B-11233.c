//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Card {
    int value;
    int suit;
} Card;

typedef struct Deck {
    Card* cards;
    int size;
} Deck;

void initDeck(Deck* deck) {
    deck->cards = (Card*)malloc(52 * sizeof(Card));
    deck->size = 52;
}

void shuffleDeck(Deck* deck) {
    for (int i = deck->size - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

Card getCard(Deck* deck) {
    return deck->cards[rand() % deck->size];
}

void displayDeck(Deck* deck) {
    for (int i = 0; i < deck->size; i++) {
        Card card = deck->cards[i];
        printf("%d of %d\n", card.value, card.suit);
    }
}

int main() {
    Deck deck;
    initDeck(&deck);
    shuffleDeck(&deck);
    displayDeck(&deck);

    int score = 0;
    int numGames = 0;

    while (numGames < 100) {
        Card card1 = getCard(&deck);
        Card card2 = getCard(&deck);

        if (card1.value == card2.value) {
            printf("Match!\n");
            score++;
        } else {
            printf("No match.\n");
        }

        numGames++;
    }

    printf("You won %d games out of %d.\n", score, numGames);
    return 0;
}