//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Game {
    Node** board;
    int turn;
    int winner;
} Game;

void initializeGame(Game* game) {
    game->board = (Node**)malloc(BOARD_SIZE * BOARD_SIZE * sizeof(Node));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        game->board[i] = NULL;
    }
    game->turn = 0;
    game->winner = -1;
}

void placeMove(Game* game, int row, int col) {
    if (game->board[row * BOARD_SIZE + col] != NULL) {
        return;
    }
    game->board[row * BOARD_SIZE + col] = malloc(sizeof(Node));
    game->board[row * BOARD_SIZE + col]->data = game->turn;
    game->board[row * BOARD_SIZE + col]->next = NULL;
    game->turn++;
}

int checkWin(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (game->board[i * BOARD_SIZE] != NULL &&
                game->board[i * BOARD_SIZE]->data == game->board[i * BOARD_SIZE + 1]->data &&
                game->board[i * BOARD_SIZE + 1]->data == game->board[i * BOARD_SIZE + 2]->data) {
            return game->board[i * BOARD_SIZE]->data;
        }

        // Check columns
        if (game->board[0] != NULL &&
                game->board[0]->data == game->board[BOARD_SIZE]->data &&
                game->board[BOARD_SIZE]->data == game->board[2 * BOARD_SIZE]->data) {
            return game->board[0]->data;
        }

        // Check diagonals
        if (game->board[0] != NULL &&
                game->board[0]->data == game->board[BOARD_SIZE + 1]->data &&
                game->board[BOARD_SIZE + 1]->data == game->board[2 * BOARD_SIZE - 1]->data) {
            return game->board[0]->data;
        }
    }

    // If all cells are occupied and there is no winner, it's a draw
    return -1;
}

int main() {
    Game game;
    initializeGame(&game);

    // Play the game
    placeMove(&game, 0, 0);
    placeMove(&game, 1, 1);
    placeMove(&game, 2, 2);
    placeMove(&game, 0, 1);
    placeMove(&game, 1, 0);

    // Check if there is a winner or draw
    int winner = checkWin(&game);

    // Print the winner or draw
    if (winner == -1) {
        printf("Draw!");
    } else {
        printf("Winner: Player %d", winner);
    }

    return 0;
}