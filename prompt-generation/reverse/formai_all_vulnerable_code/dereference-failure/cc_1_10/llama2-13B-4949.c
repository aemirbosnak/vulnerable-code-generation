//LLAMA2-13B DATASET v1.0 Category: Chess engine ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define MAX_MOVES 1000
#define BOARD_SIZE 8

typedef struct {
    char pieces[8][8];
    int move_count;
} game_state;

void init_board(game_state *state) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            state->pieces[i][j] = ' ';
        }
    }
    state->move_count = 0;
}

void print_board(game_state *state) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c", state->pieces[i][j]);
        }
        printf("\n");
    }
}

void make_move(game_state *state, int from, int to) {
    if (from < 0 || from >= 8 || to < 0 || to >= 8) {
        printf("Invalid move\n");
        return;
    }
    state->pieces[from][state->move_count] = 'X';
    state->pieces[to][state->move_count] = 'O';
    state->move_count++;
}

int check_win(game_state *state) {
    for (int i = 0; i < 8; i++) {
        if (state->pieces[i][0] == 'X' && state->pieces[i][1] == 'X' && state->pieces[i][2] == 'X') {
            return 1;
        }
        if (state->pieces[i][7] == 'X' && state->pieces[i][6] == 'X' && state->pieces[i][5] == 'X') {
            return 1;
        }
    }
    for (int i = 0; i < 8; i++) {
        if (state->pieces[0][i] == 'X' && state->pieces[1][i] == 'X' && state->pieces[2][i] == 'X') {
            return 1;
        }
        if (state->pieces[7][i] == 'X' && state->pieces[6][i] == 'X' && state->pieces[5][i] == 'X') {
            return 1;
        }
    }
    return 0;
}

int main() {
    srand(time(NULL));
    game_state state;
    init_board(&state);
    print_board(&state);

    int move_count = 0;
    while (move_count < MAX_MOVES) {
        int from, to;
        char move_str[3];
        scanf("%c%c%c", &from, &to, move_str);
        if (from == 'q' && to == 'u' && move_str[0] == 'a') {
            // Special move, quit the game
            break;
        }
        make_move(&state, from, to);
        print_board(&state);
        move_count++;
    }

    if (check_win(&state)) {
        printf("You won\n");
    } else {
        printf("You lost\n");
    }

    return 0;
}