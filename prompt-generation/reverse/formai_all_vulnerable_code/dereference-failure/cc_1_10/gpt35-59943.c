//FormAI DATASET v1.0 Category: Chess AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

char board[SIZE][SIZE];
int player = 1; // 1 for white, 2 for black
int moveCount = 0;
char *pieces = "PRNBQK";

int row(char c) {
    return (int)(c - '0') - 1;
}

int col(char c) {
    return (int)(c - 'a');
}

void initBoard() {
    memset(board, ' ', sizeof(board));
    for (int i = 0; i < SIZE; i++) {
        board[0][i] = pieces[i];
        board[1][i] = 'P';
        board[6][i] = 'p';
        board[7][i] = pieces[i] + 32;
    }
}

void printBoard() {
    printf("\n   a b c d e f g h\n");
    printf("  +----------------+\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d |", i + 1);
        for (int j = 0; j < SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf(" %d\n", i + 1);
    }
    printf("  +----------------+\n");
    printf("   a b c d e f g h\n\n");
}

int inBounds(int row, int col) {
    return row >= 0 && col >= 0 && row < SIZE && col < SIZE;
}

int isWhite(char c) {
    return c >= 65 && c <= 90;
}

int isBlack(char c) {
    return c >= 97 && c <= 122;
}

int isPiece(char c) {
    return strchr(pieces, c) != NULL;
}

int isEmpty(int row, int col) {
    return board[row][col] == ' ';
}

int isCapturable(int row, int col) {
    char c = board[row][col];
    return (isWhite(c) && player == 2) || (isBlack(c) && player == 1);
}

int canMoveTo(int fromRow, int fromCol, int toRow, int toCol) {
    char c = board[fromRow][fromCol];
    if (isPiece(c)) {
        int dRow = toRow - fromRow;
        int dCol = toCol - fromCol;
        int absDRow = abs(dRow);
        int absDCol = abs(dCol);

        if (dRow == 0 && dCol == 0) {
            return 0;
        }

        if (isWhite(c) && player == 2) {
            return 0;
        }

        if (isBlack(c) && player == 1) {
            return 0;
        }

        if (dRow != 0 && dCol != 0) {
            if (absDRow != absDCol) {
                return 0;
            }

            int dRowSign = dRow / absDRow;
            int dColSign = dCol / absDCol;

            for (int i = 1; i < absDRow; i++) {
                if (!isEmpty(fromRow + (dRowSign * i), fromCol + (dColSign * i))) {
                    return 0;
                }
            }
        }

        if (c == 'P' || c == 'p') {
            if (dRow == 0) {
                return 0;
            }

            if (player == 1) {
                if (dRow != -1 && dRow != -2) {
                    return 0;
                }

                if (dRow == -2 && moveCount > 0) {
                    return 0;
                }

                if (dCol != 0) {
                    if (!isCapturable(toRow, toCol)) {
                        return 0;
                    }
                } else {
                    if (!isEmpty(toRow, toCol)) {
                        return 0;
                    }
                }
            } else {
                if (dRow != 1 && dRow != 2) {
                    return 0;
                }

                if (dRow == 2 && moveCount > 0) {
                    return 0;
                }

                if (dCol != 0) {
                    if (!isCapturable(toRow, toCol)) {
                        return 0;
                    }
                } else {
                    if (!isEmpty(toRow, toCol)) {
                        return 0;
                    }
                }
            }
        } else {
            if (absDRow > 1 || absDCol > 1) {
                return 0;
            }

            if (!isEmpty(toRow, toCol) && !isCapturable(toRow, toCol)) {
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

void move(int fromRow, int fromCol, int toRow, int toCol) {
    char c = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
    board[toRow][toCol] = c;

    moveCount++;
    player = (player % 2) + 1;
}

void play() {
    char input[10];
    int validInput = 0;
    int fromRow, fromCol, toRow, toCol;

    while (!validInput) {
        printf("Enter your move: ");
        fgets(input, 10, stdin);

        if (strlen(input) == 5) {
            fromCol = col(input[0]);
            fromRow = row(input[1]);
            toCol = col(input[3]);
            toRow = row(input[4]);

            if (inBounds(fromRow, fromCol) && inBounds(toRow, toCol) && canMoveTo(fromRow, fromCol, toRow, toCol)) {
                move(fromRow, fromCol, toRow, toCol);
                validInput = 1;
            }
        }

        if (!validInput) {
            printf("Invalid move\n");
        }
    }
}

int main() {
    initBoard();
    printBoard();

    while (1) {
        play();
        printBoard();
    }

    return 0;
}