//LLAMA2-13B DATASET v1.0 Category: Checkers Game ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 800
#define HEIGHT 600

// Structure to represent a checker
typedef struct {
    int row;
    int col;
    char color;
} Checker;

// Function to print the checkerboard
void print_board(Checker** board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j].color == 'X') {
                printf("X ");
            } else if (board[i][j].color == 'O') {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// Function to make a move
void make_move(Checker** board, int row, int col) {
    // Check if the move is valid
    if (board[row][col].color == 'X' || board[row][col].color == 'O') {
        board[row][col].color = board[row][col].color == 'X' ? 'O' : 'X';
        board[row][col].row = row;
        board[row][col].col = col;
    }
}

// Function to check if the game is over
int check_game_over(Checker** board, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (board[i][j].color == 'X' && board[i][j+1].color == 'X' && board[i][j+2].color == 'X') {
                return 1; // Horizontal win
            } else if (board[i][j].color == 'O' && board[i][j+1].color == 'O' && board[i][j+2].color == 'O') {
                return 1; // Horizontal win
            } else if (board[i][j].color == 'X' && board[i+1][j].color == 'X' && board[i+2][j].color == 'X') {
                return 1; // Vertical win
            } else if (board[i][j].color == 'O' && board[i+1][j].color == 'O' && board[i+2][j].color == 'O') {
                return 1; // Vertical win
            }
        }
    }
    return 0; // Game is not over
}

// Function to get a random move
int get_random_move(Checker** board, int rows, int cols) {
    int row = rand() % rows;
    int col = rand() % cols;
    while (board[row][col].color != 'X' && board[row][col].color != 'O') {
        row = rand() % rows;
        col = rand() % cols;
    }
    return row * cols + col;
}

int main() {
    // Create the checkerboard
    Checker** board = (Checker**) calloc(HEIGHT, sizeof(Checker*));
    for (int i = 0; i < HEIGHT; i++) {
        board[i] = (Checker*) calloc(WIDTH, sizeof(Checker));
    }

    // Initialize the board
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j].row = i;
            board[i][j].col = j;
            board[i][j].color = 'X';
        }
    }

    // Play the game
    int move = 0;
    int game_over = 0;
    while (!game_over) {
        move = get_random_move(board, HEIGHT, WIDTH);
        make_move(board, move / WIDTH, move % WIDTH);
        game_over = check_game_over(board, HEIGHT, WIDTH);
    }

    // Print the final board
    print_board(board, HEIGHT, WIDTH);

    // Free the memory
    for (int i = 0; i < HEIGHT; i++) {
        free(board[i]);
    }
    free(board);

    return 0;
}