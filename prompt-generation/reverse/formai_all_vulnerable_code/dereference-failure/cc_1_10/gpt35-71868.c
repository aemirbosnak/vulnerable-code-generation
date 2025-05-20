//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { EMPTY, RED, BLACK } Piece;

typedef struct {
    Piece piece;
    int row, col;
} Square;

// Initialize the board
Square** init_board() {
    Square** board = (Square**) malloc(BOARD_SIZE * sizeof(Square*));
    for(int i = 0; i < BOARD_SIZE; ++i) {
        board[i] = (Square*) malloc(BOARD_SIZE * sizeof(Square));
        for(int j = 0; j < BOARD_SIZE; ++j) {
            board[i][j].row = i;
            board[i][j].col = j;
            if(i < 3 && (i+j)%2 == 0) {
                board[i][j].piece = BLACK;
            } else if(i > 4 && (i+j)%2 == 0) {
                board[i][j].piece = RED;
            } else {
                board[i][j].piece = EMPTY;
            }
        }
    }
    return board;
}

// Print the board
void print_board(Square** board) {
    printf("\n    A B C D E F G H");
    for(int i = 0; i < BOARD_SIZE; ++i) {
        printf("\n %d  ", i+1);
        for(int j = 0; j < BOARD_SIZE; ++j) {
            switch(board[i][j].piece) {
                case EMPTY:
                    printf("- ");
                    break;
                case RED:
                    printf("R ");
                    break;
                case BLACK:
                    printf("B ");
                    break;
            }
        }
    }
}

// Check if a move is valid
int is_valid_move(Square** board, Square start, Square end) {
    if(end.piece != EMPTY) {
        return 0;
    }
    int row_diff = end.row - start.row;
    int col_diff = end.col - start.col;
    if(row_diff < 0 && start.piece == BLACK) {
        return 0;
    }
    if(row_diff > 0 && start.piece == RED) {
        return 0;
    }
    if(abs(row_diff) == 1 && abs(col_diff) == 1) {
        return 1;
    }
    Square mid_square;
    if(abs(row_diff) == 2 && abs(col_diff) == 2) {
        mid_square.row = (start.row + end.row) / 2;
        mid_square.col = (start.col + end.col) / 2;
        mid_square.piece = board[mid_square.row][mid_square.col].piece;
        if(mid_square.piece == EMPTY) {
            return 0;
        } else if(mid_square.piece == start.piece) {
            return 0;
        } else {
            return 1;
        }
    }
    return 0;
}

// Make a move
int make_move(Square** board, Square start, Square end) {
    if(!is_valid_move(board, start, end)) {
        return 0;
    }
    board[end.row][end.col].piece = start.piece;
    board[start.row][start.col].piece = EMPTY;
    if(abs(end.row - start.row) == 2) {
        Square mid_square;
        mid_square.row = (start.row + end.row) / 2;
        mid_square.col = (start.col + end.col) / 2;
        board[mid_square.row][mid_square.col].piece = EMPTY;
    }
    return 1;
}

// Check if a player has won
int check_win(Square** board, Piece player) {
    for(int i = 0; i < BOARD_SIZE; ++i) {
        for(int j = 0; j < BOARD_SIZE; ++j) {
            if(board[i][j].piece == player) {
                if(player == BLACK && i < BOARD_SIZE - 1) {
                    if(j < BOARD_SIZE - 1 && board[i+1][j+1].piece == EMPTY) {
                        return 0;
                    } else if(j > 0 && board[i+1][j-1].piece == EMPTY) {
                        return 0;
                    } else if(j < BOARD_SIZE - 2 && board[i+1][j+1].piece == RED && board[i+2][j+2].piece == EMPTY) {
                        return 0;
                    } else if(j > 1 && board[i+1][j-1].piece == RED && board[i+2][j-2].piece == EMPTY) {
                        return 0;
                    }
                } else if(player == RED && i > 0) {
                    if(j < BOARD_SIZE - 1 && board[i-1][j+1].piece == EMPTY) {
                        return 0;
                    } else if(j > 0 && board[i-1][j-1].piece == EMPTY) {
                        return 0;
                    } else if(j < BOARD_SIZE - 2 && board[i-1][j+1].piece == BLACK && board[i-2][j+2].piece == EMPTY) {
                        return 0;
                    } else if(j > 1 && board[i-1][j-1].piece == BLACK && board[i-2][j-2].piece == EMPTY) {
                        return 0;
                    }
                }
            }
        }
    }
    return 1;
}

// Play the game
void play_game() {
    Square** board = init_board();
    print_board(board);
    Piece player = RED;
    while(!check_win(board, player)) {
        int valid_move = 0;
        Square start, end;
        while(!valid_move) {
            printf("\n %c's turn", player == RED ? 'R' : 'B');
            printf("\n Move from: ");
            char col;
            int row;
            scanf(" %c%d", &col, &row);
            start.row = row - 1;
            start.col = col - 'A';
            printf(" Move to: ");
            scanf(" %c%d", &col, &row);
            end.row = row - 1;
            end.col = col - 'A';
            valid_move = make_move(board, start, end);
            if(!valid_move) {
                printf("\n Invalid move. Please try again.");
            }
        }
        print_board(board);
        player = player == RED ? BLACK : RED;
    }
    printf("\n %c wins!", player == RED ? 'B' : 'R');
    for(int i = 0; i < BOARD_SIZE; ++i) {
        free(board[i]);
    }
    free(board);
}

// Main function
int main() {
    play_game();
    return 0;
}