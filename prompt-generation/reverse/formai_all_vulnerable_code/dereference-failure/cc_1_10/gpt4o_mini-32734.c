//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2
#define HIDDEN 'X'
#define MAX_TRIES 10

void initializeBoard(char board[SIZE][SIZE], int numbers[TOTAL_PAIRS]) {
    int index = 0;
    // Filling the board with pairs of numbers
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        numbers[i] = i + 1;
    }
    // Shuffle numbers and place them on the board
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        int r = rand() % TOTAL_PAIRS;
        int temp = numbers[i];
        numbers[i] = numbers[r];
        numbers[r] = temp;
    }
    // Place shuffled pairs onto the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (index < TOTAL_PAIRS) {
                board[i][j] = numbers[index / 2] + '0'; // Convert to char
                index++;
            } else {
                board[i][j] = HIDDEN;
            }
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int checkMatch(char board[SIZE][SIZE], int firstX, int firstY, int secondX, int secondY) {
    return board[firstX][firstY] == board[secondX][secondY];
}

void game() {
    char board[SIZE][SIZE];
    int numbers[TOTAL_PAIRS];
    char choice[10];
    int firstGuessX, firstGuessY, secondGuessX, secondGuessY;
    int matches = 0;
    
    srand(time(NULL));
    initializeBoard(board, numbers);
    
    while (matches < TOTAL_PAIRS) {
        displayBoard(board);
        printf("You have %d tries left.\n", MAX_TRIES - (matches * 2));
        printf("Enter first position (row col): ");
        scanf("%d %d", &firstGuessX, &firstGuessY);
        firstGuessX--;
        firstGuessY--;

        if (board[firstGuessX][firstGuessY] == HIDDEN) {
            board[firstGuessX][firstGuessY] = board[firstGuessX][firstGuessY]; // Reveal it
            displayBoard(board);
            printf("Enter second position (row col): ");
            scanf("%d %d", &secondGuessX, &secondGuessY);
            secondGuessX--;
            secondGuessY--;

            if (checkMatch(board, firstGuessX, firstGuessY, secondGuessX, secondGuessY)) {
                printf("It's a match!\n");
                matches++;
            } else {
                printf("Not a match. Try again.\n");
                board[firstGuessX][firstGuessY] = HIDDEN; // Hide again
            }
        } else {
            printf("You've already revealed this card!\n");
        }
        
        if (matches == TOTAL_PAIRS) {
            printf("Congratulations! You've matched all pairs!\n");
            break;
        }
    }
}

int main() {
    game();
    return 0;
}