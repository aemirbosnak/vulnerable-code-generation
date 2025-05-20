//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_ROWS 5
#define NUM_COLS 5

// Define the bingo card structure
typedef struct {
    int numbers[NUM_ROWS][NUM_COLS];
    int marked[NUM_ROWS][NUM_COLS];
} BingoCard;

// Create a new bingo card
BingoCard* create_card() {
    BingoCard* card = malloc(sizeof(BingoCard));
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            card->numbers[i][j] = rand() % 100;
            card->marked[i][j] = 0;
        }
    }
    return card;
}

// Print a bingo card
void print_card(BingoCard* card) {
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }
}

// Check if a card has won
int check_win(BingoCard* card) {
    // Check for horizontal wins
    for (int i = 0; i < NUM_ROWS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_COLS; j++) {
            if (card->marked[i][j]) {
                count++;
            }
        }
        if (count == NUM_COLS) {
            return 1;
        }
    }

    // Check for vertical wins
    for (int i = 0; i < NUM_COLS; i++) {
        int count = 0;
        for (int j = 0; j < NUM_ROWS; j++) {
            if (card->marked[j][i]) {
                count++;
            }
        }
        if (count == NUM_ROWS) {
            return 1;
        }
    }

    // Check for diagonal wins
    int count1 = 0, count2 = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        if (card->marked[i][i]) {
            count1++;
        }
        if (card->marked[i][NUM_COLS - i - 1]) {
            count2++;
        }
    }
    if (count1 == NUM_ROWS || count2 == NUM_ROWS) {
        return 1;
    }

    return 0;
}

// Play a round of bingo
void play_round(BingoCard* cards[], int num_players, int* called_numbers) {
    // Get a random number
    int number = rand() % 100;
    called_numbers[number]++;

    // Mark the number on each card
    for (int i = 0; i < num_players; i++) {
        for (int j = 0; j < NUM_ROWS; j++) {
            for (int k = 0; k < NUM_COLS; k++) {
                if (cards[i]->numbers[j][k] == number) {
                    cards[i]->marked[j][k] = 1;
                }
            }
        }
    }

    // Check if any cards have won
    for (int i = 0; i < num_players; i++) {
        if (check_win(cards[i])) {
            printf("Player %d wins!\n", i + 1);
            return;
        }
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the bingo cards
    BingoCard* cards[NUM_PLAYERS];
    for (int i = 0; i < NUM_PLAYERS; i++) {
        cards[i] = create_card();
    }

    // Print the bingo cards
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's card:\n", i + 1);
        print_card(cards[i]);
        printf("\n");
    }

    // Create an array to store the called numbers
    int called_numbers[100] = {0};

    // Play the game until someone wins
    while (1) {
        play_round(cards, NUM_PLAYERS, called_numbers);
    }

    return 0;
}