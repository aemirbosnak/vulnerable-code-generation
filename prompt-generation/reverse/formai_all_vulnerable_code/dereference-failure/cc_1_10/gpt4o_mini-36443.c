//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <unistd.h>

#define SIZE 4
#define MAX_TRIES 2

// Function to print the current state of the board
void printBoard(char board[SIZE][SIZE], int reveal[SIZE][SIZE]) {
    printf("\nMemory Game Board:\n");
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (reveal[i][j]) {
                printf(" %c ", board[i][j]);
            } else {
                printf(" ? ");
            }
        }
        printf("\n");
    }
}

// Function to shuffle the board
void shuffleBoard(char board[SIZE][SIZE]) {
    char symbols[SIZE * SIZE / 2] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    int index = 0;

    for (int i = 0; i < SIZE * SIZE / 2; ++i) {
        board[index / SIZE][index % SIZE] = symbols[i];
        board[index / SIZE + 1][index % SIZE] = symbols[i];
        index += 2;
    }

    for (int i = 0; i < SIZE * SIZE; ++i) {
        int r1 = rand() % (SIZE * SIZE);
        int r2 = rand() % (SIZE * SIZE);
        char temp = board[r1 / SIZE][r1 % SIZE];
        board[r1 / SIZE][r1 % SIZE] = board[r2 / SIZE][r2 % SIZE];
        board[r2 / SIZE][r2 % SIZE] = temp;
    }
}

// Function to check for a match
int checkMatch(char board[SIZE][SIZE], char first, char second) {
    return first == second;
}

// Main function to run the game
int main() {
    srand(time(NULL));
    
    char board[SIZE][SIZE];
    int reveal[SIZE][SIZE] = {0};
    int score = 0;

    shuffleBoard(board);

    printf("Welcome to the Brave Memory Game!\n");
    printf("Match all pairs to win!\n");

    for (int attempts = 0; attempts < (SIZE * SIZE / 2); ++attempts) {
        printBoard(board, reveal);

        int x1, y1, x2, y2;
        printf("Enter the coordinates of the first card (row col): ");
        scanf("%d %d", &x1, &y1);
        
        if (x1 < 0 || x1 >= SIZE || y1 < 0 || y1 >= SIZE || reveal[x1][y1]) {
            printf("Invalid input! Try again.\n");
            --attempts;
            continue;
        }
        
        reveal[x1][y1] = 1;
        printBoard(board, reveal);
        
        printf("Enter the coordinates of the second card (row col): ");
        scanf("%d %d", &x2, &y2);

        if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE || reveal[x2][y2] || (x1 == x2 && y1 == y2)) {
            printf("Invalid input! Try again.\n");
            reveal[x1][y1] = 0;
            --attempts;
            continue;
        }
        
        reveal[x2][y2] = 1;
        printBoard(board, reveal);

        if (checkMatch(board, board[x1][y1], board[x2][y2])) {
            printf("It's a match!\n");
            score++;
        } else {
            printf("Not a match! Try again.\n");
            sleep(2); // Show the cards for 2 seconds
            reveal[x1][y1] = 0;
            reveal[x2][y2] = 0;
        }
    }

    printf("Game Over! Your score: %d out of %d\n", score, SIZE * SIZE / 2);
    return 0;
}