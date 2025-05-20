//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4
#define NUM_PAIRS (GRID_SIZE * GRID_SIZE / 2)

void initializeBoard(char board[GRID_SIZE][GRID_SIZE]);
void shuffleBoard(char board[GRID_SIZE][GRID_SIZE]);
void displayBoard(char board[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]);
bool makeMove(char board[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE], int r1, int c1, int r2, int c2);
bool checkIfWon(bool revealed[GRID_SIZE][GRID_SIZE]);
void playGame();

int main() {
    playGame();
    return 0;
}

void initializeBoard(char board[GRID_SIZE][GRID_SIZE]) {
    char symbols[NUM_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < NUM_PAIRS; i++) {
        board[i / 2][i % 2] = symbols[i];
        board[(i + NUM_PAIRS) / 2][(i + NUM_PAIRS) % 2] = symbols[i];
    }
}

void shuffleBoard(char board[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < 100; i++) {
        int r1 = rand() % GRID_SIZE, c1 = rand() % GRID_SIZE;
        int r2 = rand() % GRID_SIZE, c2 = rand() % GRID_SIZE;
        char temp = board[r1][c1];
        board[r1][c1] = board[r2][c2];
        board[r2][c2] = temp;
    }
}

void displayBoard(char board[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE]) {
    printf("Current Board:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
}

bool makeMove(char board[GRID_SIZE][GRID_SIZE], bool revealed[GRID_SIZE][GRID_SIZE], int r1, int c1, int r2, int c2) {
    if (board[r1][c1] == board[r2][c2]) {
        revealed[r1][c1] = true;
        revealed[r2][c2] = true;
        return true;
    }
    return false;
}

bool checkIfWon(bool revealed[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!revealed[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void playGame() {
    char board[GRID_SIZE][GRID_SIZE];
    bool revealed[GRID_SIZE][GRID_SIZE] = {false};
    int turnCount = 0;

    srand(time(0)); // Seed the random number generator
    initializeBoard(board);
    shuffleBoard(board);

    printf("Welcome to the Memory Game!\n");

    while (!checkIfWon(revealed)) {
        displayBoard(board, revealed);
        printf("Turn %d: Pick two cards:\n", turnCount + 1);
        
        int r1, c1, r2, c2;
        printf("Enter coordinates for first card (row and column): ");
        scanf("%d %d", &r1, &c1);
        printf("Enter coordinates for second card (row and column): ");
        scanf("%d %d", &r2, &c2);
        
        if (makeMove(board, revealed, r1, c1, r2, c2)) {
            printf("It's a match!\n");
        } else {
            printf("Not a match!\n");
        }
        turnCount++;
    }

    printf("Congratulations! You've matched all pairs in %d turns!\n", turnCount);
}