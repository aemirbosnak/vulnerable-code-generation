//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define ROWS 3
#define COLS 3
#define EMPTY -1

typedef struct {
    int board[ROWS][COLS];
    int winner;
    int turn;
} GameState;

int isWinner(GameState *state) {
    // Check rows
    for (int i = 0; i < ROWS; i++) {
        if (state->board[i][0] == state->board[i][1] && state->board[i][1] == state->board[i][2] && state->board[i][0]!= EMPTY) {
            state->winner = state->board[i][0];
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < COLS; i++) {
        if (state->board[0][i] == state->board[1][i] && state->board[1][i] == state->board[2][i] && state->board[0][i]!= EMPTY) {
            state->winner = state->board[0][i];
            return 1;
        }
    }

    // Check diagonals
    if (state->board[0][0] == state->board[1][1] && state->board[1][1] == state->board[2][2] && state->board[0][0]!= EMPTY) {
        state->winner = state->board[0][0];
        return 1;
    }

    if (state->board[0][2] == state->board[1][1] && state->board[1][1] == state->board[2][0] && state->board[0][2]!= EMPTY) {
        state->winner = state->board[0][2];
        return 1;
    }

    return 0;
}

void printBoard(GameState *state) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (state->board[i][j] == EMPTY)
                printf("-");
            else if (state->board[i][j] == 1)
                printf("X");
            else if (state->board[i][j] == 2)
                printf("O");
        }
        printf("\n");
    }
}

void makeMove(GameState *state, int player) {
    printf("Player %d, make a move: ", player);
    int move;
    scanf("%d", &move);

    if (state->board[move/COLS][move%COLS]!= EMPTY) {
        printf("Invalid move, try again.\n");
        makeMove(state, player);
    } else {
        state->board[move/COLS][move%COLS] = player;
        printf("Move recorded.\n");
    }
}

void aiMove(GameState *state, int player) {
    if (isWinner(state)) {
        printf("Player %d wins!\n", state->winner);
        exit(0);
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (state->board[i][j] == EMPTY) {
                state->board[i][j] = player;
                if (isWinner(state)) {
                    printf("Player %d wins!\n", state->winner);
                    exit(0);
                }
                state->board[i][j] = EMPTY;
            }
        }
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (state->board[i][j] == EMPTY) {
                state->board[i][j] = player;
                makeMove(state, -player);
                if (isWinner(state)) {
                    printf("Player %d wins!\n", state->winner);
                    exit(0);
                }
                state->board[i][j] = EMPTY;
            }
        }
    }
}

void *threadedAi(void *args) {
    GameState *state = (GameState*) args;
    aiMove(state, 1);
}

void playGame(GameState *state) {
    int player;
    printf("Player 1, choose X or O: ");
    scanf("%d", &player);

    printf("Player 2, choose X or O: ");
    scanf("%d", &player);

    if (player == 1) {
        state->turn = 1;
        makeMove(state, 1);
    } else {
        state->turn = 2;
        makeMove(state, 2);
    }

    while (!isWinner(state)) {
        if (state->turn == 1) {
            aiMove(state, 2);
        } else {
            aiMove(state, 1);
        }

        state->turn = 3 - state->turn;
        makeMove(state, state->turn);
    }

    if (state->winner == 1) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
}

int main() {
    GameState state;
    pthread_t thread1;

    state.board[0][0] = 1;
    state.board[0][1] = 2;
    state.board[0][2] = 1;
    state.board[1][0] = 2;
    state.board[1][1] = 1;
    state.board[1][2] = 2;
    state.board[2][0] = 1;
    state.board[2][1] = 2;
    state.board[2][2] = 1;
    state.winner = EMPTY;
    state.turn = 1;

    pthread_create(&thread1, NULL, threadedAi, &state);

    playGame(&state);

    pthread_join(thread1, NULL);

    return 0;
}