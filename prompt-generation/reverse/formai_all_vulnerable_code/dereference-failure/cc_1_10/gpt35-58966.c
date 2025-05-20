//FormAI DATASET v1.0 Category: Checkers Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h> // for malloc() and free()
#include <ctype.h> // for toupper()

#define BOARD_SIZE 8

// Board cell values
#define EMPTY 0
#define BLACK 'B'
#define WHITE 'W'

// A structure to hold a board cell coordinates in row and col
typedef struct Cell {
    int row;
    int col;
} Cell;

// A structure to hold a board cell's information (color and whether it is kinged or not)
typedef struct Token {
    char color;
    int isKing;
} Token;

// Function to initialize a new game board
Token** initialize_board() {
    Token** board = malloc(BOARD_SIZE * sizeof(Token*)); // Allocate BOARD_SIZE pointers
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(BOARD_SIZE * sizeof(Token)); // Allocate BOARD_SIZE Tokens per pointer
    }
    // Set the initial tokens on the board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i+j) % 2 == 0 && i < 3) {
                board[i][j].color = BLACK;
                board[i][j].isKing = 0;
            } else if ((i+j) % 2 == 0 && i > 4) {
                board[i][j].color = WHITE;
                board[i][j].isKing = 0;
            } else {
                board[i][j].color = EMPTY;
                board[i][j].isKing = 0;
            }
        }
    }
    return board;
}

// Function to print the Board, uses Unicode chars for a more elegant visualization
void print_board(Token** board) {
    printf("\n\n");
    printf("  |-------------------|\n");
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d | ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].color == EMPTY) {
                printf("\u25A1 "); // Unicode symbol for an empty square
            } else if (board[i][j].color == BLACK && !board[i][j].isKing) {
                printf("\u26C2 "); // Unicode symbol for a black pawn
            } else if (board[i][j].color == WHITE && !board[i][j].isKing) {
                printf("\u26C0 "); // Unicode symbol for a white pawn
            } else if (board[i][j].color == BLACK && board[i][j].isKing) {
                printf("\u2654 "); // Unicode symbol for a black king
            } else if (board[i][j].color == WHITE && board[i][j].isKing) {
                printf("\u265A "); // Unicode symbol for a white king
            }
        }
        printf("|\n");
    }
    printf("  |-------------------|\n");
    printf("   ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'A' + i);
    }
    printf("\n\n");
}

// Function to check whether a given move is legal or not
int is_legal_move(Token** board, int fromRow, int fromCol, int toRow, int toCol) {
    // First check if the destination cell is empty
    if (board[toRow][toCol].color != EMPTY) {
        return 0;
    }
    // Check if the move direction is legal for this token
    if (board[fromRow][fromCol].color == BLACK && toRow >= fromRow) {
        return 0;
    } else if (board[fromRow][fromCol].color == WHITE && toRow <= fromRow) {
        return 0;
    }
    // Determine the move direction
    int rowDir = (toRow - fromRow) / abs(toRow - fromRow);
    int colDir = (toCol - fromCol) / abs(toCol - fromCol);
    // Check if the move distance is legal (one or two cells, depending on whether there's an opponent's token in between)
    if (abs(toRow - fromRow) > 2) {
        return 0;
    } else if (abs(toRow - fromRow) == 2 && board[fromRow + rowDir][fromCol + colDir].color == EMPTY) {
        return 0;
    }
    // Check if the move captures an opponent's token
    if (abs(toRow - fromRow) == 2) {
        if (board[fromRow + rowDir][fromCol + colDir].color == EMPTY || board[fromRow + rowDir][fromCol + colDir].color == board[fromRow][fromCol].color) {
            return 0;
        }
    }
    return 1;
}

// Function to make a move on the board
void make_move(Token** board, int fromRow, int fromCol, int toRow, int toCol) {
    board[toRow][toCol].color = board[fromRow][fromCol].color;
    board[toRow][toCol].isKing = board[fromRow][fromCol].isKing;
    board[fromRow][fromCol].color = EMPTY;
    board[fromRow][fromCol].isKing = 0;
    // Check whether the moved pawn has become a king
    if (board[toRow][toCol].color == BLACK && toRow == BOARD_SIZE-1) {
        board[toRow][toCol].isKing = 1;
    } else if (board[toRow][toCol].color == WHITE && toRow == 0) {
        board[toRow][toCol].isKing = 1;
    } 
    // Handle the capturing of an opponent's pawn
    if (abs(toRow - fromRow) == 2) {
        int capturedRow = (fromRow + toRow) / 2;
        int capturedCol = (fromCol + toCol) / 2;
        board[capturedRow][capturedCol].color = EMPTY;
        board[capturedRow][capturedCol].isKing = 0;
    }
}

// Function to ask the user for a valid token to move
void get_valid_from_token(Token** board, int *fromRow, int *fromCol) {
    int invalidToken = 1;
    while (invalidToken) {
        char fromToken[3];
        printf("Enter the token you want to move (e.g. 'A1'): ");
        scanf("%s", fromToken);
        *fromCol = toupper(fromToken[0]) - 'A';
        *fromRow = fromToken[1] - '0' - 1;
        if (*fromRow < 0 || *fromRow >= BOARD_SIZE || *fromCol < 0 || *fromCol >= BOARD_SIZE) {
            printf("Invalid token, please try again.\n");
        } else if (board[*fromRow][*fromCol].color == EMPTY) {
            printf("This cell is empty, please try again.\n");
        } else {
            invalidToken = 0;
        }
    }
}

// Function to ask the user for a valid destination cell
void get_valid_to_cell(Token** board, int fromRow, int fromCol, int *toRow, int *toCol) {
    int invalidCell = 1;
    while (invalidCell) {
        char toCell[3];
        printf("Enter the cell you want to move to (e.g. 'B2'): ");
        scanf("%s", toCell);
        *toCol = toupper(toCell[0]) - 'A';
        *toRow = toCell[1] - '0' - 1;
        if (*toRow < 0 || *toRow >= BOARD_SIZE || *toCol < 0 || *toCol >= BOARD_SIZE) {
            printf("Invalid cell, please try again.\n");
        } else if (!is_legal_move(board, fromRow, fromCol, *toRow, *toCol)) {
            printf("This move is not legal, please try again.\n");
        } else {
            invalidCell = 0;
        }
    }
}

int main() {
    Token** board = initialize_board();
    int turn = 0;
    // Game loop
    while (1) {
        print_board(board);
        printf("Turn %d: %s\n", turn+1, (turn % 2 == 0) ? "Black" : "White");
        int fromRow, fromCol, toRow, toCol;
        get_valid_from_token(board, &fromRow, &fromCol);
        get_valid_to_cell(board, fromRow, fromCol, &toRow, &toCol);
        make_move(board, fromRow, fromCol, toRow, toCol);
        // Check if the game has ended (no more pawns of one color on the board)
        int blackLeft = 0, whiteLeft = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j].color == BLACK) {
                    blackLeft = 1;
                } else if (board[i][j].color == WHITE) {
                    whiteLeft = 1;
                }
            }
        }
        if (!blackLeft || !whiteLeft) {
            printf("Game over! %s wins.\n", (blackLeft) ? "Black" : "White");
            break;
        }
        turn++;
    }
    // Free the memory used by the board matrix
    for (int i = 0; i < BOARD_SIZE; i++) {
        free(board[i]);
    }
    free(board);
    return 0;
}