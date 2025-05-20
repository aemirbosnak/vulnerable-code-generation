//GPT-4o-mini DATASET v1.0 Category: Memory Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define GRID_SIZE 4
#define TOTAL_PAIRS (GRID_SIZE * GRID_SIZE) / 2

typedef struct {
    char value;
    bool isFlipped;
} Card;

void initializeBoard(Card board[GRID_SIZE][GRID_SIZE]) {
    char values[TOTAL_PAIRS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    for (int i = 0; i < TOTAL_PAIRS; i++) {
        board[i / GRID_SIZE][i % GRID_SIZE].value = values[i];
        board[i / GRID_SIZE][i % GRID_SIZE].isFlipped = false;
        board[TOTAL_PAIRS + i / GRID_SIZE][TOTAL_PAIRS + i % GRID_SIZE] = board[i / GRID_SIZE][i % GRID_SIZE];
    }

    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            int r = rand() % GRID_SIZE;
            int c = rand() % GRID_SIZE;
            Card temp = board[i][j];
            board[i][j] = board[r][c];
            board[r][c] = temp;
        }
    }
}

void printBoard(Card board[GRID_SIZE][GRID_SIZE]) {
    printf("\n   ");
    for (int j = 0; j < GRID_SIZE; j++) {
        printf(" %d ", j);
    }
    printf("\n");
    
    for (int i = 0; i < GRID_SIZE; i++) {
        printf(" %d ", i);
        for (int j = 0; j < GRID_SIZE; j++) {
            if (board[i][j].isFlipped) {
                printf(" %c ", board[i][j].value);
            } else {
                printf(" * ");
            }
        }
        printf("\n");
    }
}

bool flipCard(Card board[GRID_SIZE][GRID_SIZE], int row, int col) {
    if (row < 0 || row >= GRID_SIZE || col < 0 || col >= GRID_SIZE) {
        return false;
    }
    if (!board[row][col].isFlipped) {
        board[row][col].isFlipped = true;
        return true;
    }
    return false;
}

bool allMatched(Card board[GRID_SIZE][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (!board[i][j].isFlipped) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    srand(time(NULL));
    Card board[GRID_SIZE][GRID_SIZE];
    initializeBoard(board);

    int firstRow, firstCol, secondRow, secondCol;
    int moves = 0;
    bool matchFound;

    printf("Welcome to the Memory Game!\n");
    while (!allMatched(board)) {
        printBoard(board);
        printf("Select the first card (row and column): ");
        scanf("%d %d", &firstRow, &firstCol);
        if (!flipCard(board, firstRow, firstCol)) {
            printf("Invalid move. Try again.\n");
            continue;
        }
        
        printBoard(board);
        printf("Select the second card (row and column): ");
        scanf("%d %d", &secondRow, &secondCol);
        if (!flipCard(board, secondRow, secondCol)) {
            printf("Invalid move. Try again.\n");
            continue;
        }

        moves++;
        matchFound = (board[firstRow][firstCol].value == board[secondRow][secondCol].value);
        if (matchFound) {
            printf("You found a match! %c\n", board[firstRow][firstCol].value);
        } else {
            printf("No match! Try again.\n");
            board[firstRow][firstCol].isFlipped = false;
            board[secondRow][secondCol].isFlipped = false;
        }
    }

    printBoard(board);
    printf("Congratulations! You've matched all pairs in %d moves!\n", moves);
    return 0;
}