//FormAI DATASET v1.0 Category: Poker Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define HAND_SIZE 5

typedef struct Card {
    int suit;
    int rank;
} Card;

void shuffleDeck(Card *deck);
void printDeck(const Card *deck);
void printCard(const Card *card);
void dealHands(const Card *deck, Card **hands, const int numHands);
int findWinner(const Card **hands, const int numHands);

int main() {
    
    // Initialize deck of cards
    Card deck[NUM_CARDS];
    int i, j, k;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            k = i * NUM_RANKS + j;
            deck[k].suit = i;
            deck[k].rank = j;
        }
    }
    
    // Print unshuffled deck
    printf("========== Unshuffled Deck ==========\n");
    printDeck(deck);
    printf("\n");
    
    // Shuffle deck
    srand(time(NULL));
    shuffleDeck(deck);
    
    // Print shuffled deck
    printf("========== Shuffled Deck ==========\n");
    printDeck(deck);
    printf("\n");
    
    // Deal hands
    Card *hands[2];
    for (i = 0; i < 2; i++) {
        hands[i] = (Card*)malloc(HAND_SIZE * sizeof(Card));
    }
    dealHands(deck, hands, 2);
    
    // Print hands
    printf("========== Hands ==========\n");
    for (i = 0; i < 2; i++) {
        printf("Player %d: ", i+1);
        for (j = 0; j < HAND_SIZE; j++) {
            printCard(&(hands[i][j]));
            printf(" ");
        }
        printf("\n");
    }
    
    // Find winner
    int winner = findWinner((const Card**)hands, 2);
    
    // Print winner
    printf("========== Winner ==========\n");
    if (winner == -1) {
        printf("Tie!\n");
    } else {
        printf("Player %d wins!\n", winner+1);
    }
    
    // Free memory
    for (i = 0; i < 2; i++) {
        free(hands[i]);
    }
    
    return 0;
}

void shuffleDeck(Card *deck) {
    int i, j, k;
    Card temp;
    for (i = NUM_CARDS - 1; i > 0; i--) {
        j = rand() % (i + 1);
        k = i * NUM_RANKS + deck[j].rank;
        temp = deck[i * NUM_RANKS + deck[j].rank];
        deck[i * NUM_RANKS + deck[j].rank] = deck[k];
        deck[k] = temp;
    }
}

void printDeck(const Card *deck) {
    int i, j;
    for (i = 0; i < NUM_SUITS; i++) {
        for (j = 0; j < NUM_RANKS; j++) {
            printCard(&(deck[i * NUM_RANKS + j]));
            printf(" ");
        }
        printf("\n");
    }
}

void printCard(const Card *card) {
    const char suits[NUM_SUITS] = {'C', 'D', 'H', 'S'};
    const char ranks[NUM_RANKS] = {'2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A'};
    printf("%c%c", ranks[card->rank], suits[card->suit]);
}

void dealHands(const Card *deck, Card **hands, const int numHands) {
    int i, j, k;
    for (j = 0; j < HAND_SIZE; j++) {
        for (i = 0; i < numHands; i++) {
            k = i * HAND_SIZE + j;
            hands[i][j] = deck[k];
        }
    }
}

int findWinner(const Card **hands, const int numHands) {
    // TODO: Implement poker hand ranking logic
    return -1;
}