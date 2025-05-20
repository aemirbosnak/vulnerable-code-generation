//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the bingo card structure
typedef struct BingoCard {
    int numbers[5][5];
    int freeSpaces;
    int bingo;
} BingoCard;

// Function to generate a bingo card
BingoCard* generateBingoCard() {
    BingoCard* card = malloc(sizeof(BingoCard));
    card->freeSpaces = 24;
    card->bingo = 0;

    // Generate the numbers for the card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            card->numbers[i][j] = rand() % 90 + 1;
        }
    }

    return card;
}

// Function to check if a number is on a bingo card
int isNumberOnCard(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                return 1;
            }
        }
    }

    return 0;
}

// Function to mark a number on a bingo card
void markNumberOnCard(BingoCard* card, int number) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (card->numbers[i][j] == number) {
                card->numbers[i][j] = -1;
            }
        }
    }
}

// Function to check if a player has won bingo
int hasWonBingo(BingoCard* card) {
    // Check if the player has won in a row
    for (int i = 0; i < 5; i++) {
        if (card->numbers[0][i] == -1 && card->numbers[1][i] == -1 && card->numbers[2][i] == -1 && card->numbers[3][i] == -1 && card->numbers[4][i] == -1) {
            return 1;
        }
    }

    // Check if the player has won in a column
    for (int j = 0; j < 5; j++) {
        if (card->numbers[j][0] == -1 && card->numbers[j][1] == -1 && card->numbers[j][2] == -1 && card->numbers[j][3] == -1 && card->numbers[j][4] == -1) {
            return 1;
        }
    }

    // Check if the player has won in the diagonal
    if (card->numbers[0][0] == -1 && card->numbers[1][1] == -1 && card->numbers[2][2] == -1 && card->numbers[3][3] == -1 && card->numbers[4][4] == -1) {
        return 1;
    }

    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard* card = generateBingoCard();

    // Print the bingo card
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", card->numbers[i][j]);
        }
        printf("\n");
    }

    // Draw numbers
    for (int i = 0; i < 20; i++) {
        int number = rand() % 90 + 1;

        // Check if the number is on the card
        if (isNumberOnCard(card, number)) {
            // Mark the number on the card
            markNumberOnCard(card, number);

            // Check if the player has won bingo
            if (hasWonBingo(card)) {
                printf("You have won bingo!");
                break;
            }
        }
    }

    return 0;
}