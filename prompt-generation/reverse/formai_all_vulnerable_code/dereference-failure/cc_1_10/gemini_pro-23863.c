//GEMINI-pro DATASET v1.0 Category: Memory Game ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Post-apocalyptic style definitions
#define RUSTY_BUCKET     "Rusty Bucket"
#define BROKEN_GLASS     "Broken Glass"
#define MUTATED_RAT      "Mutated Rat"
#define ABANDONED_CAR    "Abandoned Car"
#define RUINED_BUILDING  "Ruined Building"

// Game constants
#define NUM_PAIRS       5
#define NUM_CARDS       (NUM_PAIRS * 2)
#define MAX_ATTEMPTS    10

// Card struct
typedef struct {
    char *name;
    int is_matched;
} card_t;

// Function prototypes
void print_intro();
void create_deck(card_t deck[]);
void shuffle_deck(card_t deck[]);
void print_deck(card_t deck[]);
void get_player_input(int *row1, int *col1, int *row2, int *col2);
int check_match(card_t deck[], int row1, int col1, int row2, int col2);
void print_result(int result);
void print_outro(int attempts, int matches);

int main() {
    // Introduction
    print_intro();

    // Create and shuffle the deck
    card_t deck[NUM_CARDS];
    create_deck(deck);
    shuffle_deck(deck);

    // Print the initial deck
    printf("Initial deck:\n");
    print_deck(deck);

    // Get player input
    int row1, col1, row2, col2;
    int attempts = 0;
    int matches = 0;
    while (attempts < MAX_ATTEMPTS && matches < NUM_PAIRS) {
        get_player_input(&row1, &col1, &row2, &col2);

        // Check for a match
        int result = check_match(deck, row1, col1, row2, col2);

        // Print the result
        print_result(result);

        // Update the deck and count
        if (result == 1) {
            matches++;
            deck[row1 * 4 + col1].is_matched = 1;
            deck[row2 * 4 + col2].is_matched = 1;
        }

        attempts++;
    }

    // Outro
    print_outro(attempts, matches);

    return 0;
}

void print_intro() {
    printf("Welcome to the Post-Apocalyptic Memory Game!\n");
    printf("In this game, you will try to match pairs of cards.\n");
    printf("The cards are hidden under rusty buckets, broken glass, mutated rats, abandoned cars, and ruined buildings.\n");
    printf("You have %d attempts to find all %d pairs.\n", MAX_ATTEMPTS, NUM_PAIRS);
}

void create_deck(card_t deck[]) {
    // Create pairs of cards
    for (int i = 0; i < NUM_PAIRS; i++) {
        deck[i * 2].name = RUSTY_BUCKET;
        deck[i * 2 + 1].name = RUSTY_BUCKET;
        deck[i * 2 + 2].name = BROKEN_GLASS;
        deck[i * 2 + 3].name = BROKEN_GLASS;
        deck[i * 2 + 4].name = MUTATED_RAT;
        deck[i * 2 + 5].name = MUTATED_RAT;
        deck[i * 2 + 6].name = ABANDONED_CAR;
        deck[i * 2 + 7].name = ABANDONED_CAR;
        deck[i * 2 + 8].name = RUINED_BUILDING;
        deck[i * 2 + 9].name = RUINED_BUILDING;
    }

    // Set all cards to not matched
    for (int i = 0; i < NUM_CARDS; i++) {
        deck[i].is_matched = 0;
    }
}

void shuffle_deck(card_t deck[]) {
    // Shuffle the deck using the Fisher-Yates algorithm
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        card_t temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_deck(card_t deck[]) {
    // Print the deck in a 4x5 grid
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            if (deck[i * 4 + j].is_matched) {
                printf("  ");
            } else {
                printf("%s ", deck[i * 4 + j].name);
            }
        }
        printf("\n");
    }
}

void get_player_input(int *row1, int *col1, int *row2, int *col2) {
    // Get the first card's row and column
    printf("Enter the row and column of the first card (e.g. 1 2): ");
    scanf("%d %d", row1, col1);

    // Get the second card's row and column
    printf("Enter the row and column of the second card (e.g. 1 2): ");
    scanf("%d %d", row2, col2);
}

int check_match(card_t deck[], int row1, int col1, int row2, int col2) {
    // Check if the cards match
    if (strcmp(deck[row1 * 4 + col1].name, deck[row2 * 4 + col2].name) == 0) {
        return 1;
    } else {
        return 0;
    }
}

void print_result(int result) {
    // Print the result of the match
    if (result == 1) {
        printf("Match!\n");
    } else {
        printf("No match.\n");
    }
}

void print_outro(int attempts, int matches) {
    // Print the outro
    if (matches == NUM_PAIRS) {
        printf("Congratulations! You found all the pairs in %d attempts.\n", attempts);
    } else {
        printf("Game over. You found %d out of %d pairs.\n", matches, NUM_PAIRS);
    }
}