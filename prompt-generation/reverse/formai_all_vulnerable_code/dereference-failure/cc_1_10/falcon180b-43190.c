//Falcon-180B DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 4
#define NUM_CARDS 8

typedef struct {
    int value;
    int flipped;
} Card;

void initDeck(Card deck[NUM_CARDS]) {
    int i;
    for(i = 0; i < NUM_CARDS; i++) {
        deck[i].value = i + 1;
        deck[i].flipped = 0;
    }
}

void shuffleDeck(Card deck[NUM_CARDS]) {
    int i, j, temp;
    srand(time(NULL));
    for(i = 0; i < NUM_CARDS; i++) {
        j = rand() % NUM_CARDS;
        temp = deck[i].value;
        deck[i].value = deck[j].value;
        deck[j].value = temp;
        deck[i].flipped = deck[j].flipped;
        deck[j].flipped =!deck[j].flipped;
    }
}

void printDeck(Card deck[NUM_CARDS]) {
    int i;
    for(i = 0; i < NUM_CARDS; i++) {
        if(deck[i].flipped) {
            printf("Card %d is face up\n", deck[i].value);
        } else {
            printf("Card %d is face down\n", deck[i].value);
        }
    }
}

int matchCards(Card deck[NUM_CARDS], int card1, int card2) {
    if(deck[card1 - 1].value == deck[card2 - 1].value) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    Card deck[NUM_CARDS];
    int i, j, choice, matchCount = 0;

    initDeck(deck);
    shuffleDeck(deck);

    printf("Welcome to the memory game!\n");
    printf("There are %d cards in total.\n", NUM_CARDS);

    while(1) {
        printf("\n");
        printDeck(deck);
        printf("Enter the number of the first card: ");
        scanf("%d", &choice);
        printf("Enter the number of the second card: ");
        scanf("%d", &j);

        if(matchCards(deck, choice, j)) {
            printf("Match! Try again.\n");
            matchCount++;
        } else {
            printf("No match. Try again.\n");
            matchCount = 0;
        }

        if(matchCount == NUM_CARDS / 2) {
            printf("Congratulations! You have matched all the cards.\n");
            break;
        }
    }

    return 0;
}