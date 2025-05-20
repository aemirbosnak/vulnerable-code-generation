//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to initialize the deck
void initDeck(int *deck, int size) {
    for(int i=0; i<size; i++) {
        deck[i] = i+1;
    }
}

// function to shuffle the deck
void shuffleDeck(int *deck, int size) {
    srand(time(NULL));
    for(int i=size-1; i>0; i--) {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to deal the cards
void dealCards(int *deck, int size, int numPlayers, int handSize) {
    int numCards = numPlayers * handSize;
    if(numCards > size) {
        printf("Error: Not enough cards in deck!\n");
        exit(1);
    }
    for(int i=0; i<numPlayers; i++) {
        printf("Player %d:\n", i+1);
        for(int j=0; j<handSize; j++) {
            printf("Card %d: %d\n", j+1, deck[i*handSize+j]);
        }
    }
}

int main(int argc, char *argv[]) {
    int deck[52];
    int numPlayers, handSize;
    // check command line arguments
    if(argc != 3) {
        printf("Error: Invalid number of arguments!\n");
        return 1;
    }
    numPlayers = atoi(argv[1]);
    handSize = atoi(argv[2]);
    // check number of players and hand size
    if(numPlayers < 2 || numPlayers > 10) {
        printf("Error: Number of players must be between 2 and 10!\n");
        return 1;
    }
    if(handSize < 1 || handSize > 5) {
        printf("Error: Hand size must be between 1 and 5!\n");
        return 1;
    }
    // initialize and shuffle the deck
    initDeck(deck, 52);
    shuffleDeck(deck, 52);
    // deal the cards
    dealCards(deck, 52, numPlayers, handSize);
    return 0;
}