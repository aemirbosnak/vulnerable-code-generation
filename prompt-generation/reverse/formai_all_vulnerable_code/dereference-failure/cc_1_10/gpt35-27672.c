//FormAI DATASET v1.0 Category: Poker Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle the deck
void shuffle(int *deck, int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        int j = rand() % size;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to print the cards in a hand
void print_hand(int *hand, int size) {
    for (int i = 0; i < size; i++) {
        int card = hand[i];
        char *suit;
        char *face;
        switch (card % 4) {
            case 0:
                suit = "Spades";
                break;
            case 1:
                suit = "Hearts";
                break;
            case 2:
                suit = "Diamonds";
                break;
            case 3:
                suit = "Clubs";
                break;
        }
        switch (card / 4) {
            case 0:
                face = "Ace";
                break;
            case 10:
                face = "Jack";
                break;
            case 11:
                face = "Queen";
                break;
            case 12:
                face = "King";
                break;
            default:
                face = calloc(2, sizeof(char));
                face[0] = '2' + card / 4;
        }
        printf("%s of %s\n", face, suit);
    }
}

int main() {
    // Initialize deck
    int deck[52];
    for (int i = 0; i < 52; i++) {
        deck[i] = i;
    }

    // Shuffle deck
    shuffle(deck, 52);

    // Deal cards
    int player1[5];
    int player2[5];
    for (int i = 0; i < 5; i++) {
        player1[i] = deck[i];
        player2[i] = deck[i + 5];
    }

    // Print hands
    printf("Player 1's hand:\n");
    print_hand(player1, 5);
    printf("Player 2's hand:\n");
    print_hand(player2, 5);

    return 0;
}