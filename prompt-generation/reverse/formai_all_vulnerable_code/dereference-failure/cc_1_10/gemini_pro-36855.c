//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table size
#define TABLE_SIZE 10

// Define the number of players
#define NUM_PLAYERS 4

// Define the number of cards in a deck
#define NUM_CARDS 52

// Define the card suits
#define SUITS "♠♥♦♣"

// Define the card values
#define VALUES "23456789TJQKA"

// Define the table structure
typedef struct {
    int cards[NUM_PLAYERS][TABLE_SIZE];
    int num_cards[NUM_PLAYERS];
} table;

// Define the player structure
typedef struct {
    int hand[TABLE_SIZE];
    int num_cards;
} player;

// Define the deck structure
typedef struct {
    int cards[NUM_CARDS];
    int num_cards;
} deck;

// Create a new table
table* create_table() {
    table* t = malloc(sizeof(table));
    for (int i = 0; i < NUM_PLAYERS; i++) {
        t->num_cards[i] = 0;
        for (int j = 0; j < TABLE_SIZE; j++) {
            t->cards[i][j] = -1;
        }
    }
    return t;
}

// Create a new player
player* create_player() {
    player* p = malloc(sizeof(player));
    p->num_cards = 0;
    for (int i = 0; i < TABLE_SIZE; i++) {
        p->hand[i] = -1;
    }
    return p;
}

// Create a new deck
deck* create_deck() {
    deck* d = malloc(sizeof(deck));
    d->num_cards = NUM_CARDS;
    for (int i = 0; i < NUM_CARDS; i++) {
        d->cards[i] = i;
    }
    return d;
}

// Shuffle the deck
void shuffle_deck(deck* d) {
    for (int i = 0; i < d->num_cards; i++) {
        int r = rand() % d->num_cards;
        int temp = d->cards[i];
        d->cards[i] = d->cards[r];
        d->cards[r] = temp;
    }
}

// Deal the cards
void deal_cards(table* t, deck* d) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        for (int j = 0; j < TABLE_SIZE; j++) {
            t->cards[i][j] = d->cards[d->num_cards - 1];
            d->num_cards--;
            t->num_cards[i]++;
        }
    }
}

// Print the table
void print_table(table* t) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d:\n", i + 1);
        for (int j = 0; j < TABLE_SIZE; j++) {
            if (t->cards[i][j] == -1) {
                printf("  ");
            } else {
                printf("%c%c ", SUITS[t->cards[i][j] / 13], VALUES[t->cards[i][j] % 13]);
            }
        }
        printf("\n");
    }
}

// Check if a player has won
int check_win(table* t) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (t->num_cards[i] == 0) {
            return i + 1;
        }
    }
    return -1;
}

// Play the game
void play_game() {
    // Create the table, players, and deck
    table* t = create_table();
    player* players[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        players[i] = create_player();
    }
    deck* d = create_deck();

    // Shuffle the deck and deal the cards
    shuffle_deck(d);
    deal_cards(t, d);

    // Print the table
    print_table(t);

    // Loop until a player has won
    int winner = -1;
    while (winner == -1) {
        // Get the player's move
        int player;
        int card;
        printf("Player %d's turn:\n", t->num_cards[0] + 1);
        printf("Enter the card you want to play: ");
        scanf("%d %d", &player, &card);

        // Play the card
        t->cards[player - 1][t->num_cards[player - 1]] = card;
        t->num_cards[player - 1]++;

        // Print the table
        print_table(t);

        // Check if the player has won
        winner = check_win(t);
    }

    // Print the winner
    printf("Player %d has won!\n", winner);

    // Free the memory
    free(t);
    for (int i = 0; i < NUM_PLAYERS; i++) {
        free(players[i]);
    }
    free(d);
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Play the game
    play_game();

    return 0;
}