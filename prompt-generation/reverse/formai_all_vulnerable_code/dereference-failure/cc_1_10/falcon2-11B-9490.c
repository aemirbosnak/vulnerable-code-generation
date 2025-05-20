//Falcon2-11B DATASET v1.0 Category: Pathfinding algorithms ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    int size;
    Point* board;
} Board;

void initBoard(Board* board, int size) {
    board->size = size;
    board->board = (Point*) malloc(size * sizeof(Point));
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int x = rand() % size;
            int y = rand() % size;
            board->board[i * size + j].x = x;
            board->board[i * size + j].y = y;
        }
    }
}

void printBoard(Board* board) {
    for (int i = 0; i < board->size; i++) {
        for (int j = 0; j < board->size; j++) {
            printf("%c", board->board[i * board->size + j].x + 65 + 'A');
        }
        printf("\n");
    }
}

int main() {
    int size = 10; // Set the size of the board
    Board board;
    initBoard(&board, size);
    printf("Initial board:\n");
    printBoard(&board);
    int numPlayers = 2; // Set the number of players
    int currentPlayer = 0; // Start with player 1

    while (1) {
        printf("Player %d, enter your move (x, y):\n", currentPlayer + 1);
        int x, y;
        scanf("%d %d", &x, &y);

        if (x < 0 || y < 0 || x >= size || y >= size) {
            printf("Invalid move, try again.\n");
            continue;
        }

        int newX = x + board.board[x * size + y].x - 'A';
        int newY = y + board.board[x * size + y].y - 'A';

        if (newX >= 0 && newY >= 0 && newX < size && newY < size &&
            board.board[newX * size + newY].x == 0) {
            board.board[newX * size + newY].x = currentPlayer + 1;
            board.board[newX * size + newY].y = currentPlayer + 2;
            printBoard(&board);
        } else {
            printf("Invalid move, try again.\n");
        }

        if (currentPlayer >= numPlayers) {
            currentPlayer = 0;
        } else {
            currentPlayer++;
        }
    }

    return 0;
}