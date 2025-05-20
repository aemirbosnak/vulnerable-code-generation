//GEMINI-pro DATASET v1.0 Category: Bingo Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card size
#define CARD_SIZE 5

// Define the number of bingo cards to generate
#define NUM_CARDS 10

// Define the range of numbers for the bingo balls
#define MIN_BALL 1
#define MAX_BALL 75

// Create a bingo card
int** create_card() {
    // Allocate memory for the card
    int** card = (int**)malloc(CARD_SIZE * sizeof(int*));
    for (int i = 0; i < CARD_SIZE; i++) {
        card[i] = (int*)malloc(CARD_SIZE * sizeof(int));
    }

    // Fill the card with random numbers
    srand(time(NULL));
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            card[i][j] = rand() % (MAX_BALL - MIN_BALL + 1) + MIN_BALL;
        }
    }

    // Sort the card
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            for (int k = j + 1; k < CARD_SIZE; k++) {
                if (card[i][j] > card[i][k]) {
                    int temp = card[i][j];
                    card[i][j] = card[i][k];
                    card[i][k] = temp;
                }
            }
        }
    }

    return card;
}

// Draw a bingo ball
int draw_ball() {
    // Generate a random number between MIN_BALL and MAX_BALL
    return rand() % (MAX_BALL - MIN_BALL + 1) + MIN_BALL;
}

// Check if a card has won
int check_card(int** card, int ball) {
    // Check each row
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card[i][j] == ball) {
                count++;
            }
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check each column
    for (int i = 0; i < CARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < CARD_SIZE; j++) {
            if (card[j][i] == ball) {
                count++;
            }
        }
        if (count == CARD_SIZE) {
            return 1;
        }
    }

    // Check the diagonals
    int count1 = 0;
    int count2 = 0;
    for (int i = 0; i < CARD_SIZE; i++) {
        if (card[i][i] == ball) {
            count1++;
        }
        if (card[i][CARD_SIZE - i - 1] == ball) {
            count2++;
        }
    }
    if (count1 == CARD_SIZE || count2 == CARD_SIZE) {
        return 1;
    }

    return 0;
}

// Print a bingo card
void print_card(int** card) {
    for (int i = 0; i < CARD_SIZE; i++) {
        for (int j = 0; j < CARD_SIZE; j++) {
            printf("%2d ", card[i][j]);
        }
        printf("\n");
    }
}

// Play a game of bingo
void play_bingo() {
    // Create the bingo cards
    int** cards[NUM_CARDS];
    for (int i = 0; i < NUM_CARDS; i++) {
        cards[i] = create_card();
    }

    // Draw bingo balls until a card wins
    int ball;
    int winner = -1;
    while (winner == -1) {
        ball = draw_ball();
        printf("Ball drawn: %d\n", ball);

        // Check each card for a winner
        for (int i = 0; i < NUM_CARDS; i++) {
            if (check_card(cards[i], ball)) {
                winner = i;
                break;
            }
        }
    }

    // Print the winning card
    printf("Winning card:\n");
    print_card(cards[winner]);
}

// Main function
int main() {
    // Play a game of bingo
    play_bingo();

    return 0;
}