//FormAI DATASET v1.0 Category: Chess AI ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

char** allocate_board() {
    int i;
    char** board = (char**) malloc(sizeof(char*) * BOARD_SIZE);
    for (i = 0; i < BOARD_SIZE; i++) {
        board[i] = (char*) malloc(sizeof(char) * BOARD_SIZE);
        memset(board[i], ' ', BOARD_SIZE);
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'P';
        board[6][i] = 'p';
    }
    board[0][0] = board[0][7] = 'R';
    board[7][0] = board[7][7] = 'r';
    board[0][1] = board[0][6] = 'N';
    board[7][1] = board[7][6] = 'n';
    board[0][2] = board[0][5] = 'B';
    board[7][2] = board[7][5] = 'b';
    board[0][3] = 'Q';
    board[7][3] = 'q';
    board[0][4] = 'K';
    board[7][4] = 'k';
    return board;
}

void print_board(char** board) {
    int i, j;
    printf("\n  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", i + 'a');
    }
    printf("\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("|%d\n", BOARD_SIZE - i);
    }
    printf("  ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf(" %c ", i + 'a');
    }
    printf("\n");
}

int parse_move(char* move, int* src, int* dst) {
    if (strlen(move) != 4) {
        return 0;
    }
    int src_row = move[1] - '1';
    int src_col = move[0] - 'a';
    int dst_row = move[3] - '1';
    int dst_col = move[2] - 'a';
    if (src_row < 0 || src_row >= BOARD_SIZE
        || src_col < 0 || src_col >= BOARD_SIZE
        || dst_row < 0 || dst_row >= BOARD_SIZE
        || dst_col < 0 || dst_col >= BOARD_SIZE) {
            return 0;
    }
    *src = BOARD_SIZE * src_row + src_col;
    *dst = BOARD_SIZE * dst_row + dst_col;
    return 1;
}

int make_move(char** board, int src, int dst) {
    int src_row = src / BOARD_SIZE;
    int src_col = src % BOARD_SIZE;
    int dst_row = dst / BOARD_SIZE;
    int dst_col = dst % BOARD_SIZE;
    if (src_row < 0 || src_row >= BOARD_SIZE
        || src_col < 0 || src_col >= BOARD_SIZE
        || dst_row < 0 || dst_row >= BOARD_SIZE
        || dst_col < 0 || dst_col >= BOARD_SIZE) {
        return 0;
    }
    char piece = board[src_row][src_col];
    if (piece == ' ') {
        return 0;
    }
    if (piece == 'P' && dst_row == BOARD_SIZE - 1) {
        piece = 'Q';
    }
    if (piece == 'p' && dst_row == 0) {
        piece = 'q';
    }
    if (board[dst_row][dst_col] != ' ') {
        return 0;
    }
    board[src_row][src_col] = ' ';
    board[dst_row][dst_col] = piece;
    return 1;
}

int main() {
    char** board = allocate_board();
    print_board(board);
    char move[5];
    int src, dst;
    while (1) {
        printf("Enter move: ");
        scanf("%s", move);
        if (strcmp(move, "quit") == 0) {
            break;
        }
        if (!parse_move(move, &src, &dst)) {
            printf("Invalid move\n");
            continue;
        }
        if (!make_move(board, src, dst)) {
            printf("Invalid move\n");
            continue;
        }
        print_board(board);
    }
    return 0;
}