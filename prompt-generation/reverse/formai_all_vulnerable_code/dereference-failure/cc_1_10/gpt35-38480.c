//FormAI DATASET v1.0 Category: Chess AI ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char current_player;
} GameState;

void initialize_board(char board[][BOARD_SIZE]) {
    char pieces[] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[0][i] = pieces[i];
        board[7][i] = pieces[i] + 32; // to make black pieces lower-case
        board[1][i] = 'P';
        board[6][i] = 'P' + 32; // to make black pieces lower-case
        for (int j = 2; j < 6; j++) {
            board[j][i] = ' ';
        }
    }
}

void print_board(char board[][BOARD_SIZE]) {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d ", BOARD_SIZE - i);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

bool is_valid_move(int x1, int y1, int x2, int y2, char board[][BOARD_SIZE]) {
    char piece = board[x1][y1];
    char target = board[x2][y2];
    if (piece == 'P') {
        // check for valid pawn moves
        if (x2 - x1 == 1 && y1 == y2 && target == ' ') {
            return true;
        } else if (x2 - x1 == 2 && x1 == 1 && y1 == y2 && target == ' '
                   && board[x1 + 1][y1] == ' ') {
            return true;
        } else if (x2 - x1 == 1 && abs(y2 - y1) == 1
                   && target != ' ' && target > 'Z') {
            return true;
        } else {
            return false;
        }
    } else if (piece == 'p') {
        // check for valid pawn moves
        if (x1 - x2 == 1 && y1 == y2 && target == ' ') {
            return true;
        } else if (x1 - x2 == 2 && x1 == 6 && y1 == y2 && target == ' '
                   && board[x1 - 1][y1] == ' ') {
            return true;
        } else if (x1 - x2 == 1 && abs(y2 - y1) == 1
                   && target != ' ' && target < 'a') {
            return true;
        } else {
            return false;
        }
    } else {
        // check for valid moves for other pieces
        // not implemented yet
        return true;
    }
}

bool is_valid_input(char input[]) {
    if (strlen(input) != 4) {
        return false;
    }
    return true;
}

void make_move(char input[], char board[][BOARD_SIZE]) {
    int x1 = BOARD_SIZE - (input[1] - '0');
    int y1 = input[0] - 'a';
    int x2 = BOARD_SIZE - (input[3] - '0');
    int y2 = input[2] - 'a';
    if (is_valid_move(x1, y1, x2, y2, board)) {
        board[x2][y2] = board[x1][y1];
        board[x1][y1] = ' ';
    }
}

void play_game() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    char current_player = 'w';
    bool game_over = false;
    char input[5];
    while (!game_over) {
        print_board(board);
        printf("It's %c's turn. Enter your move: ", current_player);
        scanf("%s", input);
        if (!is_valid_input(input)) {
            printf("Invalid input. Please enter your move in the format 'a1a2'.\n");
            continue;
        }
        make_move(input, board);
        current_player = (current_player == 'w') ? 'b' : 'w';
    }
}

int main() {
    play_game();
    return 0;
}