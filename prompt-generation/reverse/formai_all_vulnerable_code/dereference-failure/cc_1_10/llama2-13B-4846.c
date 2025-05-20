//LLAMA2-13B DATASET v1.0 Category: Table Game ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SQUARE_SIZE 50
#define WINDOW_TITLE "Table Game"

// Structure to represent a game board
typedef struct {
    char board[ROWS][COLS];
    int x, y;
} game_board;

// Function to print the game board
void print_board(game_board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%c", board->board[i][j]);
        }
        printf("\n");
    }
}

// Function to get a random coordinate on the board
int get_random_coord(game_board *board) {
    int x = rand() % COLS;
    int y = rand() % ROWS;
    return x + y * COLS;
}

// Function to check if a given coordinate is a valid move
int is_valid_move(game_board *board, int x, int y) {
    return (x >= 0 && x < COLS && y >= 0 && y < ROWS) && board->board[y][x] == '.';
}

// Function to make a move on the board
void make_move(game_board *board, int x, int y) {
    if (is_valid_move(board, x, y)) {
        board->board[y][x] = 'X';
        board->x = x;
        board->y = y;
        printf("You placed your X at %d, %d\n", x, y);
    } else {
        printf("Invalid move. Try again.\n");
    }
}

// Function to check if the game is over
int is_game_over(game_board *board) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board->board[i][j] == 'X') {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    srand(time(NULL));

    // Create a new game board
    game_board *board = malloc(sizeof(game_board));
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board->board[i][j] = '.';
        }
    }

    // Print the initial game board
    print_board(board);

    // Get the player's move
    int x, y;
    printf("Enter a coordinate (row, col) to place your X: ");
    scanf("%d%d", &x, &y);

    // Make the move
    make_move(board, x, y);

    // Check if the game is over
    while (!is_game_over(board)) {
        // Get the player's move again
        printf("It's your turn again. Enter a coordinate (row, col) to place your X: ");
        scanf("%d%d", &x, &y);

        // Make the move
        make_move(board, x, y);
    }

    // Print the final game board
    print_board(board);

    // Free the game board memory
    free(board);

    return 0;
}