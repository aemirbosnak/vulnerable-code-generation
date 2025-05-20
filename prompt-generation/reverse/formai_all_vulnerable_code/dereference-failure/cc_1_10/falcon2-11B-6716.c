//Falcon2-11B DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x;
    int y;
    int color;
} piece;

typedef struct {
    int size;
    int color;
    piece* board;
} board;

board create_board(int size, int color) {
    board b;
    b.size = size;
    b.color = color;
    b.board = (piece*)malloc(size * sizeof(piece));
    return b;
}

void print_board(board b) {
    int i;
    printf("+-----------+\n");
    for (i = 0; i < b.size; i++) {
        printf("|");
        for (int j = 0; j < b.size; j++) {
            printf("%d ", b.board[i * b.size + j].color);
        }
        printf("|\n");
    }
    printf("+-----------+\n");
}

void make_move(board b, int x, int y) {
    if (x < 0 || x >= b.size || y < 0 || y >= b.size) {
        printf("Invalid move\n");
        return;
    }

    b.board[x * b.size + y].color = b.board[x * b.size + y].color == 1? 2 : 1;
    printf("Move made at (%d,%d)\n", x, y);
}

int main() {
    board b = create_board(8, 2);
    int move_x, move_y;
    int flag = 0;

    while (!flag) {
        printf("Enter move in the format (x,y): ");
        scanf("%d %d", &move_x, &move_y);
        if (move_x > 7 || move_y > 7) {
            printf("Invalid move\n");
        } else {
            make_move(b, move_x, move_y);
        }
    }

    print_board(b);
    return 0;
}