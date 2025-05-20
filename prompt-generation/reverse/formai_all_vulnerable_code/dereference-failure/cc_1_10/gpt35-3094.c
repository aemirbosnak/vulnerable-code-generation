//FormAI DATASET v1.0 Category: Checkers Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to initialize the board
void initialize_board(char** board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else {
                if (i < 3) {
                    board[i][j] = 'b'; // Player 1's pieces are represented by 'b'
                } else if (i > 4) {
                    board[i][j] = 'w'; // Player 2's pieces are represented by 'w'
                } else {
                    board[i][j] = ' ';
                }
            }
        }
    }
}

// Function to print the board
void print_board(char** board) {
    printf("  0 1 2 3 4 5 6 7 \n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if a move is valid
int is_valid_move(char** board, int row, int col, int row_move, int col_move) {
    // Check if the move is within the bounds of the board
    if (row + row_move < 0 || row + row_move > 7 || col + col_move < 0 || col + col_move > 7) {
        return 0;
    }
    // Check if the space is empty
    if (board[row + row_move][col + col_move] != ' ') {
        return 0;
    }
    return 1;
}

// Function to execute a move
void execute_move(char** board, int row, int col, int row_move, int col_move) {
    board[row + row_move][col + col_move] = board[row][col];
    board[row][col] = ' ';
}

int main() {
    // Initialize the board
    char** board = (char**) malloc(sizeof(char*) * 8);
    for (int i = 0; i < 8; i++) {
        board[i] = (char*) malloc(sizeof(char) * 8);
    }
    initialize_board(board);
    
    // Print the initial board
    printf("Welcome to the Checkers game!\n");
    printf("Player 1 is represented by 'b', and Player 2 is represented by 'w'.\n");
    print_board(board);
    
    // Start the game loop
    int turn = 1; // Player 1 goes first
    int game_over = 0;
    while (!game_over) {
        printf("It is Player %d's turn.\n", turn);
        
        int valid_move = 0;
        while (!valid_move) {
            // Get player input
            int row, col, row_move, col_move;
            printf("Enter the row and column of the piece you want to move: ");
            scanf("%d %d", &row, &col);
            printf("Enter the row and column of the space you want to move to: ");
            scanf("%d %d", &row_move, &col_move);
            
            // Check if move is valid
            if (!is_valid_move(board, row, col, row_move, col_move)) {
                printf("Invalid move. Try again.\n");
            } else {
                execute_move(board, row, col, row_move, col_move);
                valid_move = 1;
            }
        }
        
        // Check if the other player has any valid moves
        int other_player = (turn % 2) + 1;
        int has_valid_move = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'b' && other_player == 1) { // Check for black pieces if it's white's turn
                    if (is_valid_move(board, i, j, 1, 1) || is_valid_move(board, i, j, 1, -1)) {
                        has_valid_move = 1;
                        break;
                    }
                } else if (board[i][j] == 'w' && other_player == 2) { // Check for white pieces if it's black's turn
                    if (is_valid_move(board, i, j, -1, 1) || is_valid_move(board, i, j, -1, -1)) {
                        has_valid_move = 1;
                        break;
                    }
                }
            }
            if (has_valid_move) {
                break;
            }
        }
        
        if (!has_valid_move) {
            printf("Player %d has no valid moves. Game over!\n", other_player);
            game_over = 1;
        }
        
        // Check if a player has won
        int player_1_pieces = 0, player_2_pieces = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'b') {
                    player_1_pieces++;
                } else if (board[i][j] == 'w') {
                    player_2_pieces++;
                }
            }
        }
        
        if (player_1_pieces == 0) {
            printf("Player 2 wins! Game over.\n");
            game_over = 1;
        } else if (player_2_pieces == 0) {
            printf("Player 1 wins! Game over.\n");
            game_over = 1;
        }
        
        // Print the current board
        print_board(board);
        // Switch turns
        turn = other_player;
    }
    
    // Free memory
    for (int i = 0; i < 8; i++) {
        free(board[i]);
    }
    free(board);
    
    return 0;
}