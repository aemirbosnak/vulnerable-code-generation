//Falcon2-11B DATASET v1.0 Category: Memory Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NUM_CARDS 8
#define NUM_TRIES 4

typedef struct {
    int row;
    int col;
} Coord;

typedef struct {
    int row;
    int col;
} Location;

typedef struct {
    char *name;
    Location loc;
} Card;

Card cards[NUM_CARDS];

void shuffle(Card *deck, int n) {
    int i, j, temp;
    for (i = n - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i].loc.row;
        deck[i].loc.row = deck[j].loc.row;
        deck[j].loc.row = temp;
        temp = deck[i].loc.col;
        deck[i].loc.col = deck[j].loc.col;
        deck[j].loc.col = temp;
    }
}

void display_deck(Card *deck, int n) {
    int i;
    printf("Deck: ");
    for (i = 0; i < n; i++) {
        printf("%s (%d,%d) ", deck[i].name, deck[i].loc.row, deck[i].loc.col);
    }
    printf("\n");
}

void place_card(Card *deck, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("Card %d (%d,%d) ", i+1, deck[i].loc.row, deck[i].loc.col);
        printf("placed on table.\n");
    }
}

void reveal_card(Card *deck, int n) {
    int i;
    printf("Card %d (%d,%d) ", n, deck[n].loc.row, deck[n].loc.col);
    printf("is %s.\n", deck[n].name);
}

void flip_card(Card *deck, int n) {
    int i;
    printf("Card %d (%d,%d) ", n, deck[n].loc.row, deck[n].loc.col);
    printf("is now %s.\n", deck[n].name);
}

int main() {
    srand(time(NULL));

    Card *deck = (Card *) malloc(NUM_CARDS * sizeof(Card));

    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].name = "Card " + (i + 1);
        deck[i].loc.row = (rand() % 4) + 1;
        deck[i].loc.col = (rand() % 4) + 1;
    }

    shuffle(deck, NUM_CARDS);

    printf("Deck: ");
    display_deck(deck, NUM_CARDS);

    printf("\n");

    int tries = 0;
    int correct = 0;

    while (tries < NUM_TRIES) {
        printf("Round %d\n", tries + 1);
        printf("Deck: ");
        display_deck(deck, NUM_CARDS);

        printf("\n");

        printf("Turn over the cards to reveal their names.\n");

        int i;
        for (i = 0; i < NUM_CARDS; i++) {
            reveal_card(deck, i);
        }

        printf("\n");

        if (tries == 0) {
            printf("Which card is the same as the first one?\n");
        } else {
            printf("Which card is the same as the last one?\n");
        }

        int guess = -1;
        int num_guesses = 0;

        while (num_guesses < NUM_TRIES && guess < 0) {
            printf("Enter your guess (0-%d): ", NUM_CARDS - 1);
            scanf("%d", &guess);
            if (guess < 0 || guess >= NUM_CARDS) {
                printf("Invalid guess. Try again.\n");
                num_guesses++;
            } else {
                printf("Is %s the same as %s? (y/n): ", deck[guess].name, deck[(guess - 1) % NUM_CARDS].name);
                char answer;
                scanf(" %c", &answer);
                if (answer == 'y') {
                    printf("Correct!\n");
                    correct++;
                    printf("The matching cards are %s and %s.\n", deck[guess].name, deck[(guess - 1) % NUM_CARDS].name);
                } else {
                    printf("Incorrect.\n");
                    num_guesses++;
                }
            }
        }

        if (correct == NUM_CARDS) {
            printf("You win!\n");
            break;
        }

        if (num_guesses >= NUM_TRIES) {
            printf("You lose!\n");
            break;
        }

        printf("Deck: ");
        display_deck(deck, NUM_CARDS);

        printf("\n");

        printf("Flip the cards back over.\n");

        for (i = 0; i < NUM_CARDS; i++) {
            flip_card(deck, i);
        }

        printf("\n");

        tries++;
    }

    free(deck);

    return 0;
}