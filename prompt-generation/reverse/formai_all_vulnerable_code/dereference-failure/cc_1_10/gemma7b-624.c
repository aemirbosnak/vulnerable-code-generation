//Gemma-7B DATASET v1.0 Category: Bingo Simulator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure to store bingo card data
typedef struct BingoCard {
    char **numbers;
    int rows;
    int columns;
} BingoCard;

// Function to generate a bingo card
BingoCard *generateBingoCard(int rows, int columns) {
    BingoCard *card = (BingoCard *)malloc(sizeof(BingoCard));
    card->rows = rows;
    card->columns = columns;
    card->numbers = (char **)malloc(rows * columns * sizeof(char *));
    for (int r = 0; r < rows; r++) {
        card->numbers[r] = (char *)malloc(columns * sizeof(char));
        for (int c = 0; c < columns; c++) {
            card->numbers[r][c] = ' ';
        }
    }
    return card;
}

// Function to mark a number on a bingo card
void markNumber(BingoCard *card, char number) {
    for (int r = 0; r < card->rows; r++) {
        for (int c = 0; c < card->columns; c++) {
            if (card->numbers[r][c] == number) {
                card->numbers[r][c] = 'X';
            }
        }
    }
}

// Function to check if a bingo card has won
int hasWon(BingoCard *card) {
    // Check rows
    for (int r = 0; r < card->rows; r++) {
        if (card->numbers[r][0] == 'X' && card->numbers[r][1] == 'X' && card->numbers[r][2] == 'X') {
            return 1;
        }
    }

    // Check columns
    for (int c = 0; c < card->columns; c++) {
        if (card->numbers[0][c] == 'X' && card->numbers[1][c] == 'X' && card->numbers[2][c] == 'X') {
            return 1;
        }
    }

    // Check diagonals
    if (card->numbers[0][0] == 'X' && card->numbers[1][1] == 'X' && card->numbers[2][2] == 'X') {
        return 1;
    }

    // If no win, return 0
    return 0;
}

int main() {
    // Generate a bingo card
    BingoCard *card = generateBingoCard(5, 5);

    // Mark numbers on the card
    markNumber(card, 'A');
    markNumber(card, 'B');
    markNumber(card, 'C');
    markNumber(card, 'D');
    markNumber(card, 'E');

    // Check if the card has won
    if (hasWon(card)) {
        printf("Congratulations, you have won!");
    } else {
        printf("Sorry, you have not won.");
    }

    return 0;
}