//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the table game structure
struct game {
    int rows;
    int cols;
    char** board;
};

// Function to initialize the table game
void init_game(struct game* g) {
    g->rows = 10;
    g->cols = 10;
    g->board = malloc(g->rows * g->cols * sizeof(char*));
    for (int i = 0; i < g->rows; i++) {
        g->board[i] = malloc(g->cols * sizeof(char));
        for (int j = 0; j < g->cols; j++) {
            g->board[i][j] = ' ';
        }
    }
}

// Function to print the table game
void print_game(struct game* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            printf("%c", g->board[i][j]);
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(struct game* g, int row, int col) {
    char* temp = g->board[row][col];
    g->board[row][col] = 'X';
    g->board[row][g->cols - 1] = temp;
}

// Function to check if the game is over
int is_game_over(struct game* g) {
    for (int i = 0; i < g->rows; i++) {
        for (int j = 0; j < g->cols; j++) {
            if (g->board[i][j] != 'X' && g->board[i][j] != 'O') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    struct game g;
    init_game(&g);

    while (1) {
        print_game(&g);
        char move[2];
        scanf("%c%c", &move[0], &move[1]);

        int row = move[0] - 'A';
        int col = move[1] - '1';

        make_move(&g, row, col);

        if (is_game_over(&g)) {
            break;
        }
    }

    return 0;
}