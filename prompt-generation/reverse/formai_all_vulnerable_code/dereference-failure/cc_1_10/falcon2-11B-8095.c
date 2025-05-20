//Falcon2-11B DATASET v1.0 Category: Terminal Based Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

// Define the board size
#define BOARD_SIZE 3

// Define the board structure
typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player;
    int moves;
} Board;

// Function to print the game board
void printBoard(Board* board) {
    int i, j;

    // Print horizontal line
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("   ");
    }
    printf("   |\n");

    // Print rows
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%2d", board->board[i][j]);
            if (j < BOARD_SIZE - 1) {
                printf("|");
            } else if (i < BOARD_SIZE - 1) {
                printf("\n");
            } else {
                printf("   |\n");
            }
        }
    }
}

// Function to check for a winning move
int isWinningMove(Board* board, int player) {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board->board[j][i] == player) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == player && board->board[1][1] == player && board->board[2][2] == player) {
        return 1;
    } else if (board->board[0][2] == player && board->board[1][1] == player && board->board[2][0] == player) {
        return 1;
    }

    return 0;
}

// Function to check for a draw
int isDraw(Board* board) {
    int i, j;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board->board[i][j] == 0) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        int count = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board->board[j][i] == 0) {
                count++;
            }
        }
        if (count == BOARD_SIZE) {
            return 1;
        }
    }

    // Check diagonals
    if (board->board[0][0] == 0 && board->board[1][1] == 0 && board->board[2][2] == 0) {
        return 1;
    } else if (board->board[0][2] == 0 && board->board[1][1] == 0 && board->board[2][0] == 0) {
        return 1;
    }

    return 0;
}

// Function to determine the winner
int getWinner(Board* board) {
    if (isWinningMove(board, 1)) {
        return 1;
    } else if (isWinningMove(board, 2)) {
        return 2;
    } else if (isDraw(board)) {
        return 3;
    } else {
        return 0;
    }
}

// Function to handle user moves
int handleMove(Board* board, int player, int x, int y) {
    if (board->board[x][y] == 0) {
        board->board[x][y] = player;
        board->moves++;
        if (isWinningMove(board, player)) {
            return 1;
        } else if (isDraw(board)) {
            return 2;
        }
        return 0;
    } else {
        return -1;
    }
}

// Function to initialize the board
void initializeBoard(Board* board) {
    int i, j;

    // Initialize board
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board->board[i][j] = 0;
        }
    }
    board->player = 1;
    board->moves = 0;
}

int main() {
    // Initialize board
    Board board;
    initializeBoard(&board);

    // Print game board
    printf("Player 1: 1 2 3\n");
    printf("Player 2: 4 5 6\n");
    printf("-----------------\n");
    printBoard(&board);

    // Handle user moves
    while (1) {
        // Get move from user
        int x, y;
        printf("Enter x and y coordinates: ");
        scanf("%d %d", &x, &y);

        // Handle move
        int result = handleMove(&board, board.player, x, y);
        if (result == -1) {
            printf("Invalid move.\n");
        } else if (result == 0) {
            printf("No change.\n");
        } else if (result == 1) {
            printf("Player %d won!\n", result);
            break;
        } else if (result == 2) {
            printf("Draw!\n");
            break;
        }

        // Switch player
        board.player = (board.player + 1) % 2;

        // Print game board
        printf("Player %d: 1 2 3\n", board.player);
        printf("Player %d: 4 5 6\n", (board.player + 1) % 2);
        printf("-----------------\n");
        printBoard(&board);
    }

    return 0;
}