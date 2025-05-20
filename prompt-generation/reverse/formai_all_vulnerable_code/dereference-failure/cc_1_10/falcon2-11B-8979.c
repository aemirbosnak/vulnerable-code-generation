//Falcon2-11B DATASET v1.0 Category: Table Game ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 10
#define MAX_COLUMNS 10

typedef struct {
    int row;
    int column;
    char symbol;
} Tile;

typedef struct {
    Tile tiles[MAX_ROWS][MAX_COLUMNS];
} Board;

void printBoard(Board* board) {
    int i, j;
    for (i = 0; i < MAX_ROWS; i++) {
        for (j = 0; j < MAX_COLUMNS; j++) {
            printf("%c", board->tiles[i][j].symbol);
        }
        printf("\n");
    }
}

void placeTile(Board* board, int row, int column, char symbol) {
    board->tiles[row][column].row = row;
    board->tiles[row][column].column = column;
    board->tiles[row][column].symbol = symbol;
}

int main() {
    Board* board = (Board*) malloc(sizeof(Board));
    char symbol;
    char row, column;
    printf("Welcome to the C Table Game!\n");
    while (1) {
        printf("Enter a row number (0-9): ");
        scanf("%d", &row);
        printf("Enter a column number (0-9): ");
        scanf("%d", &column);
        printf("Enter a symbol ('X' or 'O'): ");
        scanf("%c", &symbol);
        placeTile(board, row, column, symbol);
        printf("Tile placed at (%d, %d)\n", row, column);
        if (row == 9 && column == 9) {
            printBoard(board);
            printf("Game over!\n");
            break;
        }
    }
    free(board);
    return 0;
}