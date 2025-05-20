//FormAI DATASET v1.0 Category: Table Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void display_board(char board[3][3]); // Function to display the board
void make_move(char board[3][3], char player); // Function to make a move
char check_win(char board[3][3], char player); // Function to check if someone has won
int is_board_full(char board[3][3]); // Function to check if the board is full

// Main function
int main()
{
    // Initialize the board
    char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    srand(time(NULL)); // Seed for random number generator
    
    // Randomly choose who goes first
    char player = rand() % 2 == 0 ? 'X' : 'O';
    printf("Player %c goes first!\n\n", player);
    
    while (1) {
        display_board(board); // Display the board
        
        make_move(board, player); // Make a move
        
        if (check_win(board, player)) { // Check if current player has won
            printf("Player %c has won the game!\n", player);
            display_board(board);
            break;
        }
        
        if (is_board_full(board)) { // Check if board is full
            printf("The game is a tie!");
            display_board(board);
            break;
        }
        
        // Switch to other player
        player = player == 'X' ? 'O' : 'X';
    }
    
    return 0;
}

// Function to display the board
void display_board(char board[3][3])
{
    printf("\n");

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("\t%c", board[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
}

// Function to make a move
void make_move(char board[3][3], char player)
{
    int row;
    int col;
    
    while (1) { // Loop until valid move is made
        printf("Player %c, Enter row number (1-3): ", player);
        scanf("%d", &row);
        
        printf("Player %c, Enter column number (1-3): ", player);
        scanf("%d", &col);
        
        // Check if position is already taken
        if (board[row-1][col-1] != 'X' && board[row-1][col-1] != 'O') {
            board[row-1][col-1] = player;
            break; // Valid move, break loop
        }
        
        printf("Invalid move, try again.\n");
    }
}

// Function to check if someone has won
char check_win(char board[3][3], char player)
{
    // Check rows
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return player; // Player has won
        }
    }
    
    // Check columns
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return player; // Player has won
        }
    }
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return player; // Player has won
    }
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return player; // Player has won
    }
    
    return '\0'; // No winner yet
}

// Function to check if the board is full
int is_board_full(char board[3][3])
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return 0; // Not full yet
            }
        }
    }
    return 1; // Full
}