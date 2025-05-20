//Falcon-180B DATASET v1.0 Category: Tic Tac Toe AI ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2)
                printf("|");
        }
        printf("\n");
        if (i < 2)
            printf("---|---|---\n");
    }
}

int checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    return 0;
}

void getMove(char board[3][3], int player) {
    int x, y;
    do {
        printf("\nPlayer %d, enter your move: ", player);
        scanf("%d%d", &x, &y);
        x--;
        y--;
    } while (board[x][y]!= '\0');
    board[x][y] = (player == 1)? 'X' : 'O';
}

int main() {
    srand(time(0));
    char board[3][3] = { { '\0', '\0', '\0' }, { '\0', '\0', '\0' }, { '\0', '\0', '\0' } };
    int player = rand() % 2 + 1;
    int moves = 0;

    while (1) {
        system("clear");
        drawBoard(board);
        printf("\nPlayer %d's turn.\n", player);
        getMove(board, player);
        player = (player == 1)? 2 : 1;
        moves++;

        if (checkWin(board)) {
            drawBoard(board);
            printf("\nPlayer %d wins!\n", player);
            break;
        } else if (moves == 9) {
            drawBoard(board);
            printf("\nIt's a draw.\n");
            break;
        }
    }

    return 0;
}