//FormAI DATASET v1.0 Category: Game ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 3
#define COLS 3

// Initialize the game board
void initialize_board(char board[][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

// Prints the current board status
void display_board(char board[][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf(" %c ", board[i][j]);
        }
        printf("\n");
    }
}

// Check if the game has been won
int game_has_winner(char board[][COLS], char symbol) {
    int i, j, row_win, col_win, diag1_win, diag2_win;
    for (i = 0; i < ROWS; i++) {
        row_win = 1;
        col_win = 1;
        diag1_win = 1;
        diag2_win = 1;
        // Check rows
        for (j = 0; j < COLS; j++) {
            if (board[i][j] != symbol) {
                row_win = 0;
            }
            if (board[j][i] != symbol) {
                col_win = 0;
            }
            if (board[j][j] != symbol) {
                diag1_win = 0;
            }
            if (board[j][COLS - 1 - j] != symbol) {
                diag2_win = 0;
            }
        }
        if (row_win || col_win || diag1_win || diag2_win) {
            return 1;
        }
    }
    return 0;
}

// Check if the game is a draw
int game_is_draw(char board[][COLS]) {
    int i, j, space_count = 0;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                space_count++;
            }
        }
    }
    if (space_count == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Make a move on the board
void make_move(char board[][COLS], char symbol, int row, int col) {
    if (board[row][col] == '-') {
        board[row][col] = symbol;
    } else {
        printf("That space is already taken, try again\n");
    }
}

// Get a random available move
void get_random_move(char board[][COLS], int *row, int *col) {
    int available_moves[ROWS * COLS][2], total_moves = 0, i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == '-') {
                available_moves[total_moves][0] = i;
                available_moves[total_moves][1] = j;
                total_moves++;
            }
        }
    }
    if (total_moves > 0) {
        int random_index = rand() % total_moves;
        *row = available_moves[random_index][0];
        *col = available_moves[random_index][1];
    }
}

// Main function
int main() {
    char board[ROWS][COLS];
    char player_symbol, computer_symbol;
    int row, col;
    srand(time(NULL));
    initialize_board(board);
    printf("Welcome to Tic Tac Toe!\n");
    printf("Which do you want to be, X or O? ");
    scanf("%c", &player_symbol);
    computer_symbol = (player_symbol == 'X') ? 'O' : 'X';
    printf("You will be %c\n", player_symbol);
    printf("The computer will be %c\n", computer_symbol);
    while (1) {
        // Player's turn
        printf("Your turn:\n");
        printf("Enter a row number (0-2): ");
        scanf("%d", &row);
        printf("Enter a column number (0-2): ");
        scanf("%d", &col);
        make_move(board, player_symbol, row, col);
        display_board(board);
        if (game_has_winner(board, player_symbol)) {
            printf("Congratulations, you have won!\n");
            break;
        }
        if (game_is_draw(board)) {
            printf("It's a draw!\n");
            break;
        }
        // Computer's turn
        printf("Computer's turn:\n");
        get_random_move(board, &row, &col);
        make_move(board, computer_symbol, row, col);
        display_board(board);
        if (game_has_winner(board, computer_symbol)) {
            printf("Sorry, you have lost.\n");
            break;
        }
        if (game_is_draw(board)) {
            printf("It's a draw!\n");
            break;
        }
    }
    return 0;
}