//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int index;
    int value;
} Card;

typedef struct {
    Card* cards;
    int size;
} Deck;

void shuffle(Deck* deck) {
    int i, j;
    for (i = deck->size - 1; i > 0; i--) {
        j = rand() % (i + 1);
        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

void display_deck(Deck* deck) {
    int i;
    for (i = 0; i < deck->size; i++) {
        printf("%d\n", deck->cards[i].value);
    }
}

int main() {
    Deck deck;
    deck.cards = (Card*)malloc(sizeof(Card) * 4);
    deck.size = 4;

    for (int i = 0; i < deck.size; i++) {
        deck.cards[i].index = i;
        deck.cards[i].value = rand() % 10 + 1;
    }

    shuffle(&deck);
    display_deck(&deck);

    int player_guess;
    while (1) {
        printf("Guess a card's index: ");
        scanf("%d", &player_guess);

        if (player_guess < 0 || player_guess >= deck.size) {
            printf("Invalid index.\n");
            continue;
        }

        if (deck.cards[player_guess].value == player_guess) {
            printf("Congratulations! You guessed the correct card!\n");
            break;
        }

        printf("Sorry, the card is not %d. Try again.\n", player_guess);
    }

    return 0;
}