//FormAI DATASET v1.0 Category: Poker Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes
void shuffle(int *deck);
void deal(int *deck, int **players, int num_players);

int main()
{
    srand(time(NULL));  // Seed random number generator

    int deck[52];
    int *players[4];

    // Initialize deck array
    for (int i = 0; i < 52; i++) {
        deck[i] = i + 1;
    }

    shuffle(deck);

    // Allocate memory for player hands
    for (int i = 0; i < 4; i++) {
        players[i] = malloc(5 * sizeof(int));
    }

    deal(deck, players, 4);  // Deal cards to players

    // Print each player's hand
    for (int i = 0; i < 4; i++) {
        printf("Player %d: ", i + 1);
        for (int j = 0; j < 5; j++) {
            printf("%d ", players[i][j]);
        }
        printf("\n");
    }

    // Free memory used by player hands
    for (int i = 0; i < 4; i++) {
        free(players[i]);
    }

    return 0;
}

// Shuffle deck
void shuffle(int *deck)
{
    for (int i = 0; i < 52; i++) {
        int random_index = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[random_index];
        deck[random_index] = temp;
    }
}

// Deal cards to players
void deal(int *deck, int **players, int num_players)
{
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < num_players; j++) {
            players[j][i] = deck[i * num_players + j];
        }
    }
}