//GEMINI-pro DATASET v1.0 Category: Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Defines the board dimensions
#define ROWS 6
#define COLUMNS 7

// Defines the player types
#define PLAYER1 1
#define PLAYER2 2

// Defines the game states
#define PLAYING 0
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 3

// Creates a new game board
int** create_board() {
    int** board = (int**)malloc(ROWS * sizeof(int*));
    for (int i = 0; i < ROWS; i++) {
        board[i] = (int*)malloc(COLUMNS * sizeof(int));
    }
    return board;
}

// Frees the memory allocated for the game board
void free_board(int** board) {
    for (int i = 0; i < ROWS; i++) {
        free(board[i]);
    }
    free(board);
}

// Prints the game board to the console
void print_board(int** board) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Checks if the game is over
int check_game_over(int** board) {
    // Check for horizontal win
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return board[i][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
            }
        }
    }

    // Check for vertical win
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j]) {
                return board[i][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
            }
        }
    }

    // Check for diagonal win
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 0; j < COLUMNS - 3; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return board[i][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
            }
        }
    }

    // Check for anti-diagonal win
    for (int i = 0; i < ROWS - 3; i++) {
        for (int j = 3; j < COLUMNS; j++) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3]) {
                return board[i][j] == PLAYER1 ? PLAYER1_WIN : PLAYER2_WIN;
            }
        }
    }

    // Check for draw
    int count = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (board[i][j] != 0) {
                count++;
            }
        }
    }
    if (count == ROWS * COLUMNS) {
        return DRAW;
    }

    // Game is still playing
    return PLAYING;
}

// Gets the player's move
int get_move(int player) {
    int move;
    printf("Player %d, enter your move (1-%d): ", player, COLUMNS);
    scanf("%d", &move);
    return move - 1;
}

// Drops the player's piece into the board
void drop_piece(int** board, int player, int move) {
    for (int i = ROWS - 1; i >= 0; i--) {
        if (board[i][move] == 0) {
            board[i][move] = player;
            break;
        }
    }
}

// Main game loop
int main() {
    // Create a new game board
    int** board = create_board();

    // Set the game state to playing
    int game_state = PLAYING;

    // Get the players' names
    char player1_name[20];
    char player2_name[20];
    printf("Enter the name of player 1: ");
    scanf("%s", player1_name);
    printf("Enter the name of player 2: ");
    scanf("%s", player2_name);

    // The game loop
    while (game_state == PLAYING) {
        // Player 1's turn
        int move = get_move(PLAYER1);
        drop_piece(board, PLAYER1, move);

        // Check if the game is over
        game_state = check_game_over(board);

        // If the game is not over, it's player 2's turn
        if (game_state == PLAYING) {
            move = get_move(PLAYER2);
            drop_piece(board, PLAYER2, move);

            // Check if the game is over
            game_state = check_game_over(board);
        }
    }

    // Print the final game board
    print_board(board);

    // Determine the winner
    char* winner;
    switch (game_state) {
        case PLAYER1_WIN:
            winner = player1_name;
            break;
        case PLAYER2_WIN:
            winner = player2_name;
            break;
        case DRAW:
            winner = "Nobody";
            break;
    }

    // Print the winner
    printf("The winner is: %s\n", winner);

    // Free the memory allocated for the game board
    free_board(board);

    return 0;
}