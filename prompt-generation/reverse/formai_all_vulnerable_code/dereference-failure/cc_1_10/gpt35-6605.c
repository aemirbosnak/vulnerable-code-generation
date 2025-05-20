//FormAI DATASET v1.0 Category: Checkers Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8
#define EMPTY_SPACE '-'
#define PLAYER_ONE 'O'
#define PLAYER_TWO 'X'

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char player_one;
    char player_two;
    char current_player;
} CheckersGame;

CheckersGame* createCheckersGame(char player_one, char player_two) {
    CheckersGame* game = (CheckersGame*) malloc(sizeof(CheckersGame));
   
    // Initialize the board
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                game->board[i][j] = EMPTY_SPACE;
            } else if(i < 3) {
                game->board[i][j] = player_one;
            } else if(i > 4) {
                game->board[i][j] = player_two;
            } else {
                game->board[i][j] = EMPTY_SPACE;
            }
        }
    }
   
    game->player_one = player_one;
    game->player_two = player_two;
    game->current_player = player_one;
   
    return game;
}

bool isMoveValid(CheckersGame* game, int row1, int col1, int row2, int col2) {
    char player = game->current_player;
   
    // Check if the move is diagonal
    if(abs(row1 - row2) != abs(col1 - col2)) {
        return false;
    }
   
    // Check if there is a piece at the starting position
    if(game->board[row1][col1] != player && game->board[row1][col1] != player - 32) {
        return false;
    }
   
    // Check if there is a piece at the ending position
    if(game->board[row2][col2] != EMPTY_SPACE) {
        return false;
    }
   
    // Check if the move is in the right direction
    if(player == PLAYER_ONE && row1 < row2) {
        return false;
    }
   
    if(player == PLAYER_TWO && row1 > row2) {
        return false;
    }
   
    // Check if the move is a jump
    if(abs(row1 - row2) == 2) {
        int jump_row = (row1 + row2) / 2;
        int jump_col = (col1 + col2) / 2;
       
        if(game->board[jump_row][jump_col] != game->current_player &&
           game->board[jump_row][jump_col] != game->current_player - 32) {
            return false;
        }
    }
   
    return true;
}

void makeMove(CheckersGame* game, int row1, int col1, int row2, int col2) {
    // Make the move
    game->board[row2][col2] = game->board[row1][col1];
    game->board[row1][col1] = EMPTY_SPACE;
   
    // Check for a jump and remove the piece
    if(abs(row1 - row2) == 2) {
        int jump_row = (row1 + row2) / 2;
        int jump_col = (col1 + col2) / 2;
       
        game->board[jump_row][jump_col] = EMPTY_SPACE;
    }
   
    // Switch to the next player
    if(game->current_player == game->player_one) {
        game->current_player = game->player_two;
    } else {
        game->current_player = game->player_one;
    }
}

void printBoard(CheckersGame* game) {
    // Print the top row numbers
    printf("   ");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
   
    // Print the board with the side row letters
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%c: ", i + 'A');
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c ", game->board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Create a new game
    CheckersGame* game = createCheckersGame(PLAYER_ONE, PLAYER_TWO);
   
    // Print the initial board
    printBoard(game);
   
    // Game loop
    while(true) {
        printf("%c's turn\n", game->current_player);
       
        // Ask for the move
        char start_row, end_row;
        int start_col, end_col;
        printf("Enter coordinates of piece to move (ex: A0): ");
        scanf(" %c%d", &start_row, &start_col);
        printf("Enter coordinates to move the piece to (ex: B1): ");
        scanf(" %c%d", &end_row, &end_col);
       
        // Convert the letters to numbers
        int start_row_num = start_row - 'A';
        int end_row_num = end_row - 'A';
       
        // Check if move is valid and make the move
        if(isMoveValid(game, start_row_num, start_col, end_row_num, end_col)) {
            makeMove(game, start_row_num, start_col, end_row_num, end_col);
            printBoard(game);
        } else {
            printf("Invalid move, try again\n");
        }
       
        // Check if the game is over
        bool player_one_pieces = false;
        bool player_two_pieces = false;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(game->board[i][j] == PLAYER_ONE || game->board[i][j] == PLAYER_ONE - 32) {
                    player_one_pieces = true;
                } else if(game->board[i][j] == PLAYER_TWO || game->board[i][j] == PLAYER_TWO - 32) {
                    player_two_pieces = true;
                }
            }
        }
       
        if(!player_one_pieces) {
            printf("%c wins!\n", PLAYER_TWO);
            break;
        }
       
        if(!player_two_pieces) {
            printf("%c wins!\n", PLAYER_ONE);
            break;
        }
    }
}