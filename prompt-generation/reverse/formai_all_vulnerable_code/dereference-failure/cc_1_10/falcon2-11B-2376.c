//Falcon2-11B DATASET v1.0 Category: Poker Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Card {
    char suit;
    int value;
} Card;

typedef struct Player {
    Card* cards;
    int handValue;
} Player;

void shuffle(Card* deck) {
    srand(time(NULL));
    for (int i = 0; i < sizeof(deck)/sizeof(deck[0]); i++) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printDeck(Card* deck, int size) {
    printf("Deck: ");
    for (int i = 0; i < size; i++) {
        printf("%d %c ", deck[i].value, deck[i].suit);
    }
    printf("\n");
}

void printPlayer(Player* player) {
    printf("Player %d: ", player->handValue);
    for (int i = 0; i < 5; i++) {
        printf("%d %c ", player->cards[i].value, player->cards[i].suit);
    }
    printf("\n");
}

void playerHand(Card* deck, int size, Player* player) {
    int i = 0;
    while (i < 5) {
        player->cards[i] = deck[i];
        i++;
        if (i >= size) {
            break;
        }
    }
    player->handValue = calculateHandValue(player->cards);
}

int calculateHandValue(Card* cards) {
    int value = 0;
    for (int i = 0; i < 5; i++) {
        if (cards[i].value == 1) {
            value++;
        } else if (cards[i].value == 11) {
            value += 10;
        } else if (cards[i].value == 12) {
            value += 10;
        } else if (cards[i].value == 13) {
            value += 10;
        }
    }
    return value;
}

void playGame(Card* deck, int size) {
    srand(time(NULL));
    shuffle(deck);

    Player player1;
    Player player2;

    playerHand(deck, size, &player1);
    playerHand(deck, size, &player2);

    while (player1.handValue > player2.handValue) {
        printf("Player 1 wins!\n");
        break;
    }

    while (player1.handValue < player2.handValue) {
        printf("Player 2 wins!\n");
        break;
    }
}

int main() {
    Card deck[] = {
        { 'S', 2 }, { 'S', 3 }, { 'S', 4 }, { 'S', 5 }, { 'S', 6 },
        { 'H', 2 }, { 'H', 3 }, { 'H', 4 }, { 'H', 5 }, { 'H', 6 },
        { 'C', 2 }, { 'C', 3 }, { 'C', 4 }, { 'C', 5 }, { 'C', 6 },
        { 'D', 2 }, { 'D', 3 }, { 'D', 4 }, { 'D', 5 }, { 'D', 6 }
    };

    int size = sizeof(deck)/sizeof(deck[0]);
    playGame(deck, size);

    return 0;
}