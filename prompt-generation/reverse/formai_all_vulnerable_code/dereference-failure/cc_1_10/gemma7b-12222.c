//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int cards_drawn;
    int bingo_status;
} BingoCard;

// Function to generate a bingo card
BingoCard* generate_bingo_card() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->cards_drawn = 0;
    card->bingo_status = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a card has won
int check_bingo(BingoCard* card) {
    // Check rows
    for (int i = 0; i < 5; i++) {
        if (card->numbers[i][0] == card->numbers[i][1] &&
            card->numbers[i][0] == card->numbers[i][2] &&
            card->numbers[i][0] == card->numbers[i][3] &&
            card->numbers[i][0] == card->numbers[i][4]) {
            return 1;
        }
    }

    // Check columns
    for (int j = 0; j < 5; j++) {
        if (card->numbers[0][j] == card->numbers[1][j] &&
            card->numbers[0][j] == card->numbers[2][j] &&
            card->numbers[0][j] == card->numbers[3][j] &&
            card->numbers[0][j] == card->numbers[4][j]) {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == card->numbers[2][2] &&
        card->numbers[0][0] == card->numbers[4][4] &&
        card->numbers[0][0] == card->numbers[3][3]) {
        return 1;
    }

    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard* card = generate_bingo_card();

    // Draw numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;

        // Check if the number is on the card
        if (card->numbers[number / 5][number % 5] == number) {
            // Mark the number as drawn
            card->numbers[number / 5][number % 5] = -1;

            // Check if the card has won
            if (check_bingo(card)) {
                // Print the winning card
                printf("Winner! The card is:\n");
                for (int i = 0; i < 5; i++) {
                    for (int j = 0; j < 5; j++) {
                        printf("%d ", card->numbers[i][j]);
                    }
                    printf("\n");
                }

                // Reset the card
                card->cards_drawn = 0;
                card->bingo_status = 0;
                generate_bingo_card(card);
            }
        }
    }

    return 0;
}