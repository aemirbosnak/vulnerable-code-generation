//Gemma-7B DATASET v1.0 Category: Tic Tac Toe AI ; Style: satisfied
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
    int current_player;
    int winner;
} Game;

void init_game(Game* g) {
    g->board = (Node**)malloc(BOARD_SIZE * BOARD_SIZE * sizeof(Node));
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; i++) {
        g->board[i] = NULL;
    }

    g->current_player = 1;
    g->winner = 0;
}

int move_valid(Game* g, int move) {
    if (g->board[move] != NULL) {
        return 0;
    }

    return 1;
}

void make_move(Game* g, int move) {
    g->board[move] = (Node*)malloc(sizeof(Node));
    g->board[move]->data = g->current_player;
    g->board[move]->next = NULL;
}

int check_winner(Game* g) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (g->board[i * BOARD_SIZE]->data == g->board[i * BOARD_SIZE + 1]->data &&
            g->board[i * BOARD_SIZE]->data == g->board[i * BOARD_SIZE + 2]->data &&
            g->board[i * BOARD_SIZE]->data != 0) {
            return g->board[i * BOARD_SIZE]->data;
        }
    }

    // Check columns
    for (int j = 0; j < BOARD_SIZE; j++) {
        if (g->board[j]->data == g->board[j + BOARD_SIZE]->data &&
            g->board[j]->data == g->board[j + 2 * BOARD_SIZE]->data &&
            g->board[j]->data != 0) {
            return g->board[j]->data;
        }
    }

    // Check diagonals
    if (g->board[0]->data == g->board[4]->data &&
        g->board[0]->data == g->board[8]->data &&
        g->board[0]->data != 0) {
        return g->board[0]->data;
    }

    // If all cells are occupied and there is no winner, it's a draw
    return 3;
}

int main() {
    Game g;
    init_game(&g);

    // Play the game
    while (!check_winner(&g)) {
        int move = rand() % 9;
        if (move_valid(&g, move)) {
            make_move(&g, move);
        }
    }

    // Print the winner or draw
    switch (check_winner(&g)) {
        case 1:
            printf("Player 1 won!");
            break;
        case 2:
            printf("Player 2 won!");
            break;
        case 3:
            printf("It's a draw!");
            break;
    }

    return 0;
}