//GPT-4o-mini DATASET v1.0 Category: Chess AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>

#define SIZE 8
#define MAX_DEPTH 3

typedef struct {
    char board[SIZE][SIZE];
    int is_ai_turn;
} GameState;

void initialize_board(GameState *game) {
    const char *initial_board[SIZE] = {
        "rnbqkbnr",
        "pppppppp",
        "........",
        "........",
        "........",
        "........",
        "PPPPPPPP",
        "RNBQKBNR"
    };
    
    for (int i = 0; i < SIZE; i++) {
        strcpy(game->board[i], initial_board[i]);
    }
    
    game->is_ai_turn = 0;
}

void print_board(GameState *game) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int is_valid_move(char board[SIZE][SIZE], char *move) {
    // For simplicity, any move is valid. Real validation needed.
    return 1;
}

void make_move(GameState *game, char *move) {
    if (!is_valid_move(game->board, move)) return;

    // Simple move: assuming format 'e2 e4'
    int from_x = move[1] - '1';
    int from_y = move[0] - 'a';
    int to_x = move[4] - '1';
    int to_y = move[3] - 'a';

    game->board[to_x][to_y] = game->board[from_x][from_y];
    game->board[from_x][from_y] = '.';
}

char *get_ai_move(GameState *game) {
    // For simplicity, AI picks the first available move.
    static char move[6];
    move[0] = 'e'; move[1] = '2'; move[2] = ' '; move[3] = 'e'; move[4] = '4'; move[5] = '\0';
    
    return move;
}

void *ai_thread(void *arg) {
    GameState *game = (GameState *)arg;
    
    while (1) {
        if (game->is_ai_turn) {
            char *move = get_ai_move(game);
            make_move(game, move);
            game->is_ai_turn = 0; // Switch turn
        }
        usleep(500000); // Sleep for a bit to prevent busy waiting
    }
    
    return NULL;
}

void play_game() {
    GameState game;
    initialize_board(&game);

    pthread_t ai_tid;
    pthread_create(&ai_tid, NULL, ai_thread, (void *)&game);

    char move[20];
    while (1) {
        print_board(&game);

        if (game.is_ai_turn) {
            printf("AI is thinking...\n");
            usleep(1000000); // Sleep to simulate thinking delay
        } else {
            printf("Your move (e.g., e2 e4): ");
            fgets(move, sizeof(move), stdin);
            move[strcspn(move, "\n")] = 0; // Remove newline character
            make_move(&game, move);
            game.is_ai_turn = 1; // Switch turn
        }
    }

    pthread_join(ai_tid, NULL);
}

int main() {
    play_game();
    return 0;
}