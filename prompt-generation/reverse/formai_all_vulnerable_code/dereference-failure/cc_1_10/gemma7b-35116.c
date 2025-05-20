//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: scalable
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
    int currentPlayer;
    int winner;
    int gameStatus;
} Game;

void initializeGame(Game* game) {
    game->board = (Node**)malloc(BOARD_SIZE * BOARD_SIZE * sizeof(Node));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        game->board[i] = NULL;
    }

    game->currentPlayer = 1;
    game->winner = 0;
    game->gameStatus = 0;
}

void makeMove(Game* game, int move) {
    if (game->board[move] != NULL) {
        return;
    }

    game->board[move] = (Node*)malloc(sizeof(Node));
    game->board[move]->data = game->currentPlayer;
    game->board[move]->next = NULL;

    game->currentPlayer *= -1;
}

int checkWin(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i] != NULL && game->board[i]->data == game->winner) {
            return 1;
        }
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game->board[i] != NULL && game->board[i]->data == game->winner) {
            return 1;
        }
    }

    return 0;
}

void playGame(Game* game) {
    int move = rand() % 9;
    makeMove(game, move);

    if (checkWin(game) == 1) {
        game->winner = game->currentPlayer;
        game->gameStatus = 1;
    } else if (game->board[0] == NULL && game->board[1] == NULL && game->board[2] == NULL) {
        game->gameStatus = 2;
    }
}

int main() {
    Game game;
    initializeGame(&game);

    while (!game.gameStatus) {
        playGame(&game);
    }

    if (game.winner) {
        printf("Winner: Player %d\n", game.winner);
    } else {
        printf("Draw\n");
    }

    return 0;
}