//GEMINI-pro DATASET v1.0 Category: Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define the number of rows and columns on the board
#define ROWS 6
#define COLUMNS 6

// Define the different types of pieces
#define EMPTY 0
#define BLACK 1
#define WHITE 2

// Define the different states of the game
#define PLAYING 1
#define BLACK_WON 2
#define WHITE_WON 3
#define DRAW 4

// Define the different directions
#define UP 0
#define DOWN 1
#define LEFT 2
#define RIGHT 3

// Define the structure of a board position
typedef struct {
    int row;
    int column;
} Position;

// Define the structure of a game board
typedef struct {
    int rows;
    int columns;
    int pieces[ROWS][COLUMNS];
} Board;

// Create a new board
Board* create_board() {
    Board* board = (Board*)malloc(sizeof(Board));
    board->rows = ROWS;
    board->columns = COLUMNS;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            board->pieces[i][j] = EMPTY;
        }
    }
    return board;
}

// Free the memory allocated for a board
void free_board(Board* board) {
    free(board);
}

// Print the board to the console
void print_board(Board* board) {
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->columns; j++) {
            if (board->pieces[i][j] == EMPTY) {
                printf("  ");
            } else if (board->pieces[i][j] == BLACK) {
                printf(" B");
            } else if (board->pieces[i][j] == WHITE) {
                printf(" W");
            }
        }
        printf("\n");
    }
}

// Get the state of the game
int get_state(Board* board) {
    // Check if there are any empty spaces on the board
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->columns; j++) {
            if (board->pieces[i][j] == EMPTY) {
                return PLAYING;
            }
        }
    }

    // Check if there are any winning combinations on the board
    for (int i = 0; i < board->rows; i++) {
        for (int j = 0; j < board->columns; j++) {
            if (board->pieces[i][j] != EMPTY) {
                // Check if there are four pieces in a row
                if (check_for_four_in_a_row(board, i, j, UP) ||
                    check_for_four_in_a_row(board, i, j, DOWN) ||
                    check_for_four_in_a_row(board, i, j, LEFT) ||
                    check_for_four_in_a_row(board, i, j, RIGHT)) {
                    return board->pieces[i][j] == BLACK ? BLACK_WON : WHITE_WON;
                }
            }
        }
    }

    // The game is a draw
    return DRAW;
}

// Check if there are four pieces in a row in a given direction
int check_for_four_in_a_row(Board* board, int row, int column, int direction) {
    int count = 1;
    int piece = board->pieces[row][column];

    // Check in the given direction
    switch (direction) {
        case UP:
            for (int i = row - 1; i >= 0; i--) {
                if (board->pieces[i][column] == piece) {
                    count++;
                } else {
                    break;
                }
            }
            break;
        case DOWN:
            for (int i = row + 1; i < board->rows; i++) {
                if (board->pieces[i][column] == piece) {
                    count++;
                } else {
                    break;
                }
            }
            break;
        case LEFT:
            for (int j = column - 1; j >= 0; j--) {
                if (board->pieces[row][j] == piece) {
                    count++;
                } else {
                    break;
                }
            }
            break;
        case RIGHT:
            for (int j = column + 1; j < board->columns; j++) {
                if (board->pieces[row][j] == piece) {
                    count++;
                } else {
                    break;
                }
            }
            break;
    }

    // Return true if there are four pieces in a row
    return count >= 4;
}

// Get the next move for the AI
Position get_next_move(Board* board, int piece) {
    // Generate a random move
    srand(time(NULL));
    Position move;
    move.row = rand() % board->rows;
    move.column = rand() % board->columns;

    // Check if the move is valid
    while (board->pieces[move.row][move.column] != EMPTY) {
        move.row = rand() % board->rows;
        move.column = rand() % board->columns;
    }

    // Return the move
    return move;
}

// Play the game
void play_game() {
    // Create a new board
    Board* board = create_board();

    // Print the initial board
    print_board(board);

    // Set the current player to black
    int current_player = BLACK;

    // Loop until the game is over
    while (get_state(board) == PLAYING) {
        // Get the next move for the current player
        Position move;
        if (current_player == BLACK) {
            move = get_next_move(board, BLACK);
        } else {
            move = get_next_move(board, WHITE);
        }

        // Place the piece on the board
        board->pieces[move.row][move.column] = current_player;

        // Print the updated board
        print_board(board);

        // Switch the current player
        current_player = current_player == BLACK ? WHITE : BLACK;
    }

    // Get the state of the game
    int state = get_state(board);

    // Print the final message
    if (state == BLACK_WON) {
        printf("Black wins!");
    } else if (state == WHITE_WON) {
        printf("White wins!");
    } else if (state == DRAW) {
        printf("Draw!");
    }

    // Free the memory allocated for the board
    free_board(board);
}

// Main function
int main() {
    // Play the game
    play_game();

    return 0;
}