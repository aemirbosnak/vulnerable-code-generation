//FormAI DATASET v1.0 Category: Chess AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Piece {
    char type;
    int x;
    int y;
} Piece;

typedef struct Board {
    Piece* grid[8][8];
} Board;

Board* createBoard();
void deleteBoard(Board* board);
void placePieces(Board* board);
void printBoard(Board* board);
bool isMoveValid(Board* board, int startX, int startY, int endX, int endY);
bool movePiece(Board* board, int startX, int startY, int endX, int endY);

int main() {
    Board* board = createBoard();
    placePieces(board);
    printBoard(board);

    int startX, startY, endX, endY;
    while (true) {
        printf("\nEnter move (ex. 'e2 e4'): ");
        scanf("%d %d %d %d", &startX, &startY, &endX, &endY);

        if (isMoveValid(board, startX, startY, endX, endY)) {
            movePiece(board, startX, startY, endX, endY);
            printBoard(board);
        } else {
            printf("Invalid move. Try again.\n");
        }
    }

    deleteBoard(board);
    return 0;
}

Board* createBoard() {
    Board* board = (Board*) malloc(sizeof(Board));

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            board->grid[i][j] = NULL;
        }
    }

    return board;
}

void deleteBoard(Board* board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board->grid[i][j] != NULL) {
                free(board->grid[i][j]);
            }
        }
    }

    free(board);
}

void placePieces(Board* board) {
    // TODO: Implement piece placement
}

void printBoard(Board* board) {
    printf("\n   A B C D E F G H\n");
    printf("  +-----------------+\n");

    for (int i = 0; i < 8; i++) {
        printf("%d |", i+1);

        for (int j = 0; j < 8; j++) {
            if (board->grid[i][j] == NULL) {
                printf(" ");
            } else {
                printf("%c", board->grid[i][j]->type);
            }

            printf("|");
        }

        printf(" %d\n", i+1);

        if (i != 7) {
            printf("  +-----------------+\n");
        }
    }

    printf("  +-----------------+\n");
    printf("   A B C D E F G H\n");
}

bool isMoveValid(Board* board, int startX, int startY, int endX, int endY) {
    // TODO: Implement move validity check
}

bool movePiece(Board* board, int startX, int startY, int endX, int endY) {
    // TODO: Implement piece movement
}