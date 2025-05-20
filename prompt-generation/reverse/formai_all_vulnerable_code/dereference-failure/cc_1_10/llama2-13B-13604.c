//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define WIN_WIDTH 800
#define WIN_HEIGHT 600

typedef struct {
    int x, y;
    char symbol;
} cell_t;

typedef struct {
    cell_t cells[WIN_WIDTH * WIN_HEIGHT];
} game_board_t;

game_board_t* init_game_board(void) {
    game_board_t* board = malloc(sizeof(game_board_t));
    for (int i = 0; i < WIN_WIDTH * WIN_HEIGHT; i++) {
        board->cells[i].x = rand() % WIN_WIDTH;
        board->cells[i].y = rand() % WIN_HEIGHT;
        board->cells[i].symbol = '?';
    }
    return board;
}

void draw_game_board(game_board_t* board) {
    for (int i = 0; i < WIN_WIDTH * WIN_HEIGHT; i++) {
        printf("%c", board->cells[i].symbol);
    }
    printf("\n");
}

void update_game_board(game_board_t* board) {
    for (int i = 0; i < WIN_WIDTH * WIN_HEIGHT; i++) {
        if (board->cells[i].symbol == 'X') {
            board->cells[i].symbol = 'O';
        } else if (board->cells[i].symbol == 'O') {
            board->cells[i].symbol = 'X';
        }
    }
}

int check_win(game_board_t* board) {
    int row_win = 0, col_win = 0, diag_win = 0;
    for (int i = 0; i < WIN_WIDTH; i++) {
        if (board->cells[i].symbol == board->cells[i + 1].symbol &&
                board->cells[i].symbol == board->cells[i + 2].symbol) {
            row_win++;
        }
    }
    for (int i = 0; i < WIN_HEIGHT; i++) {
        if (board->cells[i].symbol == board->cells[i + 1].symbol &&
                board->cells[i].symbol == board->cells[i + 2].symbol) {
            col_win++;
        }
    }
    for (int i = 0; i < WIN_WIDTH; i++) {
        if (board->cells[i].symbol == board->cells[WIN_WIDTH - i - 1].symbol &&
                board->cells[i].symbol == board->cells[WIN_WIDTH - i - 2].symbol) {
            diag_win++;
        }
    }
    return row_win || col_win || diag_win;
}

int main(void) {
    srand(time(NULL));
    game_board_t* board = init_game_board();
    draw_game_board(board);
    update_game_board(board);
    while (1) {
        int player_move = getchar();
        if (player_move == 'X' || player_move == 'O') {
            board->cells[rand() % WIN_WIDTH * WIN_HEIGHT].symbol = player_move;
            update_game_board(board);
            if (check_win(board)) {
                printf("Player %c won!", player_move == 'X' ? 'X' : 'O');
                break;
            }
        }
    }
    free(board);
    return 0;
}