//Falcon2-11B DATASET v1.0 Category: Tic Tac Toe AI ; Style: careful
#include <stdio.h>
#include <stdbool.h>

typedef enum {
    EMPTY,
    X,
    O
} Piece;

typedef struct {
    Piece piece;
    int row;
    int col;
} Cell;

typedef struct {
    Cell cells[3][3];
} Board;

void printBoard(Board *board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c", (board->cells[i][j].piece == EMPTY)? '-' : ('X' + board->cells[i][j].piece));
        }
        printf("\n");
    }
}

bool checkWin(Board *board, Piece piece) {
    for (int i = 0; i < 3; i++) {
        if (board->cells[i][0].piece == piece && board->cells[i][1].piece == piece && board->cells[i][2].piece == piece)
            return true;
        if (board->cells[0][i].piece == piece && board->cells[1][i].piece == piece && board->cells[2][i].piece == piece)
            return true;
        if (board->cells[0][0].piece == piece && board->cells[1][1].piece == piece && board->cells[2][2].piece == piece)
            return true;
        if (board->cells[2][0].piece == piece && board->cells[1][1].piece == piece && board->cells[0][2].piece == piece)
            return true;
    }
    return false;
}

void playerMove(Board *board, Piece player) {
    int row, col;
    printf("It's %c's turn. Please enter row and column numbers: ", ('X' + player));
    scanf("%d%d", &row, &col);
    while (board->cells[row][col].piece!= EMPTY) {
        printf("Invalid move. Please try again: ");
        scanf("%d%d", &row, &col);
    }
    board->cells[row][col].piece = player;
}

void aiMove(Board *board, Piece player) {
    int row, col, bestRow, bestCol;
    bool win = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board->cells[i][j].piece == EMPTY) {
                if (checkWin(board, player)) {
                    board->cells[i][j].piece = player;
                    win = true;
                    break;
                }
                board->cells[i][j].piece = player;
                bestRow = i;
                bestCol = j;
            }
        }
        if (win)
            break;
    }
    board->cells[bestRow][bestCol].piece = player;
}

int main() {
    Board board;
    Cell cell = {.piece = EMPTY,.row = -1,.col = -1};
    Piece player;
    while (true) {
        printBoard(&board);
        if (cell.piece!= EMPTY) {
            player = cell.piece == X? O : X;
            break;
        }
        playerMove(&board, player);
    }
    while (true) {
        if (checkWin(&board, X)) {
            printf("X wins!\n");
            break;
        }
        if (checkWin(&board, O)) {
            printf("O wins!\n");
            break;
        }
        aiMove(&board, X);
        playerMove(&board, O);
    }
    return 0;
}