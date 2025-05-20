//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the game constants
#define ROWS 10
#define COLS 10
#define MAX_SCORE 100
#define MIN_SCORE 0

// Define the game structures
typedef struct {
    int row;
    int col;
} position_t;

typedef struct {
    position_t start;
    position_t end;
} line_t;

typedef struct {
    line_t lines[ROWS];
} board_t;

// Define the game functions
void init_board(board_t *board);
void print_board(board_t *board);
void handle_user_input(board_t *board, int row, int col);
void check_win(board_t *board, int row, int col);
void draw_line(board_t *board, int row, int col);

// Define the game main function
int main() {
    srand(time(NULL));

    // Create the game board
    board_t *board = malloc(sizeof(board_t));
    init_board(board);

    // Print the game board
    print_board(board);

    // Start the game loop
    while (1) {
        // Get the user input
        int row = -1, col = -1;
        printf("Enter row and col (row 1-10, col 1-10): ");
        scanf("%d%d", &row, &col);

        // Handle the user input
        handle_user_input(board, row, col);

        // Check for a win
        check_win(board, row, col);

        // Draw the line
        draw_line(board, row, col);
    }

    return 0;
}

// Define the game functions

// Initialize the game board
void init_board(board_t *board) {
    int i, j;

    // Initialize the game board with random values
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board->lines[i].start.row = i;
            board->lines[i].start.col = j;
            board->lines[i].end.row = i;
            board->lines[i].end.col = j + (rand() % 2) - (rand() % 2);
        }
    }
}

// Print the game board
void print_board(board_t *board) {
    int i, j;

    printf("    A B C D E F G H I J K\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board->lines[i].start.row == i && board->lines[i].start.col == j) {
                printf(" %c", 'A' + (i * COLS + j) % 26);
            } else {
                printf(" %c", 'A' + (i * COLS + j) % 26);
            }
        }
        printf("\n");
    }
}

// Handle the user input
void handle_user_input(board_t *board, int row, int col) {
    if (board->lines[row].start.row == row && board->lines[row].start.col == col) {
        // Add the line to the board
        board->lines[row].end.row = row;
        board->lines[row].end.col = col;
    } else {
        // Remove the line from the board
        board->lines[row].start.row = -1;
        board->lines[row].start.col = -1;
    }
}

// Check for a win
void check_win(board_t *board, int row, int col) {
    int i, j;

    // Check for a horizontal win
    for (i = 0; i < ROWS; i++) {
        if (board->lines[i].start.row == row && board->lines[i].end.row == row) {
            printf("You won! Congratulations!\n");
            return;
        }
    }

    // Check for a vertical win
    for (j = 0; j < COLS; j++) {
        if (board->lines[0].start.col == j && board->lines[ROWS - 1].end.col == j) {
            printf("You won! Congratulations!\n");
            return;
        }
    }

    // Check for a diagonal win
    for (i = 0; i < ROWS; i++) {
        if (board->lines[i].start.row == row && board->lines[i].end.row == ROWS - 1 - row) {
            printf("You won! Congratulations!\n");
            return;
        }
    }
}

// Draw the line
void draw_line(board_t *board, int row, int col) {
    int i, j;

    // Draw the line
    for (i = row; i < ROWS && board->lines[i].start.row == row && board->lines[i].end.row == row; i++) {
        for (j = col; j < COLS && board->lines[i].start.col == col && board->lines[i].end.col == col; j++) {
            printf("|");
        }
        printf("\n");
    }
}