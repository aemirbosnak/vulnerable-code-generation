//FormAI DATASET v1.0 Category: Chess AI ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];
char current_color = 'w';

// Function to print the current state of the board
void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d", BOARD_SIZE - i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c", board[i][j]);
        }
        printf(" %d", BOARD_SIZE - i);
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

// Function to initialize the board with starting pieces
void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    board[0][0] = 'R';
    board[0][7] = 'R';
    board[0][1] = 'N';
    board[0][6] = 'N';
    board[0][2] = 'B';
    board[0][5] = 'B';
    board[0][3] = 'Q';
    board[0][4] = 'K';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
    }

    board[7][0] = 'r';
    board[7][7] = 'r';
    board[7][1] = 'n';
    board[7][6] = 'n';
    board[7][2] = 'b';
    board[7][5] = 'b';
    board[7][3] = 'q';
    board[7][4] = 'k';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[6][i] = 'p';
    }
}

// Function to get the move from user and parse it
void get_move(char *move) {
    printf("%c's turn: ", current_color);
    scanf("%s", move);
}

// Function to check if move is valid
int is_valid_move(char *move) {
    if (strlen(move) != 4) {
        return 0;
    }
    int start_row = BOARD_SIZE - (move[1] - '0');
    int start_col = move[0] - 'a';
    int end_row = BOARD_SIZE - (move[3] - '0');
    int end_col = move[2] - 'a';

    char piece = board[start_row][start_col];
    if (piece == ' ') {
        return 0;
    }
    if (islower(piece) && current_color == 'w') {
        return 0;
    }
    if (isupper(piece) && current_color == 'b') {
        return 0;
    }

    if (piece == 'p') {
        // Handle pawn move
        int row_diff = end_row - start_row;
        int col_diff = end_col - start_col;
        if (row_diff == 0 || col_diff > 1 || col_diff < -1) {
            return 0;
        }
        if (current_color == 'w') {
            if (row_diff == -1 && board[end_row][end_col] == ' ') {
                return 1;
            }
            if (row_diff == -2 && start_row == 6 && board[end_row][end_col] == ' ' \
                && board[end_row+1][end_col] == ' ') {
                return 1;
            }
            if (row_diff == -1 && board[end_row][end_col] != ' ' && islower(board[end_row][end_col])) {
                return 1;
            }
        } else {
            if (row_diff == 1 && board[end_row][end_col] == ' ') {
                return 1;
            }
            if (row_diff == 2 && start_row == 1 && board[end_row][end_col] == ' ' \
                && board[end_row-1][end_col] == ' ') {
                return 1;
            }
            if (row_diff == 1 && board[end_row][end_col] != ' ' && isupper(board[end_row][end_col])) {
                return 1;
            }
        }
        return 0;
    } else {
        // Handle other pieces
        // TODO: Implement
        return 0;
    }
}

// Function to make the move
void make_move(char *move) {
    int start_row = BOARD_SIZE - (move[1] - '0');
    int start_col = move[0] - 'a';
    int end_row = BOARD_SIZE - (move[3] - '0');
    int end_col = move[2] - 'a';

    board[end_row][end_col] = board[start_row][start_col];
    board[start_row][start_col] = ' ';
}

int main() {
    initialize_board();
    print_board();

    char move[5];
    while (1) {
        get_move(move);
        if (strcmp(move, "quit") == 0) {
            break;
        }

        if (!is_valid_move(move)) {
            printf("Invalid move!\n");
            continue;
        }

        make_move(move);

        if (current_color == 'w') {
            current_color = 'b';
        } else {
            current_color = 'w';
        }

        print_board();
    }

    return 0;
}