//Falcon-180B DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159265358979323846

int main() {
    int x, y, i, j, n, m;
    printf("Enter the number of rows and columns of the chessboard: ");
    scanf("%d%d", &m, &n);
    int board[m][n];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            board[i][j] = 0;
        }
    }
    int player = 1;
    while (1) {
        system("clear");
        printf("Player %d's turn\n", player);
        printf("Enter your move: ");
        scanf("%d%d", &x, &y);
        if (board[x][y]!= 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[x][y] = player;
        player = (player == 1)? 2 : 1;
        if (checkmate(board, player)) {
            printf("Checkmate! Player %d wins!\n", player);
            break;
        }
    }
    return 0;
}

int checkmate(int board[8][8], int player) {
    int i, j, dx, dy;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (board[i][j] == player) {
                dx = i;
                dy = j;
                break;
            }
        }
    }
    int x = dx, y = dy, nx, ny, kx, ky;
    while (1) {
        nx = x + 1;
        ny = y + 1;
        if (nx >= 8 || ny >= 8 || board[nx][ny]!= player) {
            break;
        }
        x = nx;
        y = ny;
    }
    while (1) {
        kx = x - 1;
        ky = y - 1;
        if (kx < 0 || ky < 0 || board[kx][ky]!= player) {
            break;
        }
        x = kx;
        y = ky;
    }
    while (1) {
        nx = x + 1;
        ky = y - 1;
        if (nx >= 8 || ky < 0 || board[nx][ky]!= player) {
            break;
        }
        x = nx;
        y = ky;
    }
    while (1) {
        kx = x - 1;
        ny = y + 1;
        if (kx < 0 || ny >= 8 || board[kx][ny]!= player) {
            break;
        }
        x = kx;
        y = ny;
    }
    if (x == 7 && y == 0) {
        return 1;
    }
    return 0;
}