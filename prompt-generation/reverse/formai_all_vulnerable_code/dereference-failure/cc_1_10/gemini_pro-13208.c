//GEMINI-pro DATASET v1.0 Category: Poker Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Card suits
#define CLUBS 0
#define DIAMONDS 1
#define HEARTS 2
#define SPADES 3

// Card ranks
#define TWO 0
#define THREE 1
#define FOUR 2
#define FIVE 3
#define SIX 4
#define SEVEN 5
#define EIGHT 6
#define NINE 7
#define TEN 8
#define JACK 9
#define QUEEN 10
#define KING 11
#define ACE 12

// Card values
int cardValues[] = {
    2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10, 11
};

// Card struct
typedef struct {
    int suit;
    int rank;
} Card;

// Deck of cards struct
typedef struct {
    Card cards[52];
    int numCards;
} Deck;

// Player struct
typedef struct {
    char name[20];
    int handValue;
    Card hand[5];
    int handSize;
} Player;

// Function to create a new deck of cards
Deck* createDeck() {
    Deck* deck = malloc(sizeof(Deck));
    deck->numCards = 52;

    int i = 0;
    for (int suit = CLUBS; suit <= SPADES; suit++) {
        for (int rank = TWO; rank <= ACE; rank++) {
            deck->cards[i].suit = suit;
            deck->cards[i].rank = rank;
            i++;
        }
    }

    return deck;
}

// Function to shuffle the deck of cards
void shuffleDeck(Deck* deck) {
    srand(time(NULL));

    for (int i = 0; i < deck->numCards; i++) {
        int j = rand() % deck->numCards;

        Card temp = deck->cards[i];
        deck->cards[i] = deck->cards[j];
        deck->cards[j] = temp;
    }
}

// Function to deal a card to a player
void dealCard(Deck* deck, Player* player) {
    player->hand[player->handSize] = deck->cards[deck->numCards - 1];
    player->handSize++;
    deck->numCards--;
}

// Function to calculate the value of a hand
int calculateHandValue(Player* player) {
    int handValue = 0;

    for (int i = 0; i < player->handSize; i++) {
        handValue += cardValues[player->hand[i].rank];
    }

    return handValue;
}

// Function to compare two hands
int compareHands(Player* player1, Player* player2) {
    int player1HandValue = calculateHandValue(player1);
    int player2HandValue = calculateHandValue(player2);

    if (player1HandValue > player2HandValue) {
        return 1;
    } else if (player1HandValue < player2HandValue) {
        return -1;
    } else {
        return 0;
    }
}

// Function to print the player's hand
void printHand(Player* player) {
    printf("%s's hand: ", player->name);

    for (int i = 0; i < player->handSize; i++) {
        printf("%s of %s, ", player->hand[i].rank == ACE ? "Ace" : player->hand[i].rank == JACK ? "Jack" : player->hand[i].rank == QUEEN ? "Queen" : player->hand[i].rank == KING ? "King" : player->hand[i].rank + 2, player->hand[i].suit == CLUBS ? "Clubs" : player->hand[i].suit == DIAMONDS ? "Diamonds" : player->hand[i].suit == HEARTS ? "Hearts" : "Spades");
    }

    printf("\n");
}

// Function to play a game of poker
void playPoker() {
    // Create a deck of cards
    Deck* deck = createDeck();

    // Shuffle the deck
    shuffleDeck(deck);

    // Create two players
    Player player1;
    strcpy(player1.name, "Player 1");
    player1.handSize = 0;

    Player player2;
    strcpy(player2.name, "Player 2");
    player2.handSize = 0;

    // Deal five cards to each player
    for (int i = 0; i < 5; i++) {
        dealCard(deck, &player1);
        dealCard(deck, &player2);
    }

    // Calculate the value of each player's hand
    player1.handValue = calculateHandValue(&player1);
    player2.handValue = calculateHandValue(&player2);

    // Print the players' hands
    printHand(&player1);
    printHand(&player2);

    // Compare the players' hands
    int result = compareHands(&player1, &player2);

    // Print the result
    if (result == 1) {
        printf("%s wins!\n", player1.name);
    } else if (result == -1) {
        printf("%s wins!\n", player2.name);
    } else {
        printf("Tie!\n");
    }

    // Free the deck
    free(deck);
}

int main() {
    // Play a game of poker
    playPoker();

    return 0;
}