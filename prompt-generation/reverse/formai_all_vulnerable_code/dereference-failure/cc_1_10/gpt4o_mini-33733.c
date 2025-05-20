//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define SIZE 4
#define TOTAL_PAIRS (SIZE * SIZE) / 2

// Function prototypes
void initializeBoard(char **board, int size);
void shuffleBoard(char **board, int size);
void printBoard(char **board, bool **flipped, int size);
bool checkMatch(char **board, int row1, int col1, int row2, int col2);
bool isGameWon(bool **flipped, int size);
void freeMemory(char **board, bool **flipped, int size);

int main() {
    srand(time(NULL));
    
    // Allocate memory for the board and flipped status
    char **board = malloc(SIZE * sizeof(char *));
    bool **flipped = malloc(SIZE * sizeof(bool *));
    for (int i = 0; i < SIZE; i++) {
        board[i] = malloc(SIZE * sizeof(char));
        flipped[i] = malloc(SIZE * sizeof(bool));
    }

    initializeBoard(board, SIZE);
    shuffleBoard(board, SIZE);

    printf("Welcome to the Memory Game!\n");
    int moves = 0;

    while (!isGameWon(flipped, SIZE)) {
        printBoard(board, flipped, SIZE);
        
        printf("Flip two cards (row and column, space-separated): ");
        
        int row1, col1, row2, col2;
        scanf("%d %d", &row1, &col1);
        scanf("%d %d", &row2, &col2);
        
        if (row1 < 0 || row1 >= SIZE || col1 < 0 || col1 >= SIZE || 
            row2 < 0 || row2 >= SIZE || col2 < 0 || col2 >= SIZE || 
            (row1 == row2 && col1 == col2) || flipped[row1][col1] || flipped[row2][col2]) {
            printf("Invalid selections. Please try again.\n");
            continue;
        }

        flipped[row1][col1] = true;
        flipped[row2][col2] = true;
        moves++;

        printBoard(board, flipped, SIZE);
        
        if (!checkMatch(board, row1, col1, row2, col2)) {
            printf("Not a match! Try again.\n");
            flipped[row1][col1] = false;
            flipped[row2][col2] = false;
        } else {
            printf("You found a match!\n");
        }
    }

    printf("Congratulations! You've matched all pairs in %d moves.\n", moves);
    freeMemory(board, flipped, SIZE);
    
    return 0;
}

void initializeBoard(char **board, int size) {
    char card = 'A';
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            board[i][j] = (i * size + j) < TOTAL_PAIRS ? card : ' ';
            if ((i * size + j) % 2 == 1) {
                card++;
            }
        }
    }
}

void shuffleBoard(char **board, int size) {
    for (int i = 0; i < size * size; i++) {
        int r1 = rand() % (size * size);
        int r2 = rand() % (size * size);
        char temp = board[r1 / size][r1 % size];
        board[r1 / size][r1 % size] = board[r2 / size][r2 % size];
        board[r2 / size][r2 % size] = temp;
    }
}

void printBoard(char **board, bool **flipped, int size) {
    printf("\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (flipped[i][j]) {
                printf("%c ", board[i][j]);
            } else {
                printf("* ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool checkMatch(char **board, int row1, int col1, int row2, int col2) {
    return board[row1][col1] == board[row2][col2];
}

bool isGameWon(bool **flipped, int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (!flipped[i][j]) return false;
        }
    }
    return true;
}

void freeMemory(char **board, bool **flipped, int size) {
    for (int i = 0; i < size; i++) {
        free(board[i]);
        free(flipped[i]);
    }
    free(board);
    free(flipped);
}