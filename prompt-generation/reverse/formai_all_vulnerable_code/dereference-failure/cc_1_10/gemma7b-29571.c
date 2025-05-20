//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

typedef struct Game {
    Node* head;
    int turn, winner, board[BOARD_SIZE][BOARD_SIZE];
} Game;

void initializeGame(Game* game) {
    game->head = NULL;
    game->turn = 0;
    game->winner = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = 0;
        }
    }
}

void makeMove(Game* game, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = game->head;
    game->head = newNode;

    game->board[x][y] = game->turn;
    game->turn++;
}

int checkWin(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i][0] == game->board[i][1] && game->board[i][0] == game->board[i][2] && game->board[i][0] != 0) {
            return game->board[i][0];
        }
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        if (game->board[0][j] == game->board[1][j] && game->board[0][j] == game->board[2][j] && game->board[0][j] != 0) {
            return game->board[0][j];
        }
    }

    if (game->board[0][0] == game->board[1][1] && game->board[0][0] == game->board[2][2] && game->board[0][0] != 0) {
        return game->board[0][0];
    }

    return 0;
}

int main() {
    Game game;
    initializeGame(&game);

    // Play the game
    makeMove(&game, 1, 1);
    makeMove(&game, 0, 0);
    makeMove(&game, 2, 2);
    makeMove(&game, 0, 1);
    makeMove(&game, 2, 1);
    makeMove(&game, 1, 0);

    // Check if there is a winner
    int winner = checkWin(&game);

    // Print the winner
    if (winner) {
        printf("The winner is player %d.\n", winner);
    } else {
        printf("It's a draw.\n");
    }

    return 0;
}