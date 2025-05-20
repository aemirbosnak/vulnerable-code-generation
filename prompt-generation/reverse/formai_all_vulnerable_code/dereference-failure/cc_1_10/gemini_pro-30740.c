//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Game board size
#define BOARD_SIZE 3

// Game pieces
#define PLAYER_ONE 'X'
#define PLAYER_TWO 'O'
#define EMPTY ' '

// Game state
#define IN_PROGRESS 0
#define DRAW 1
#define PLAYER_ONE_WIN 2
#define PLAYER_TWO_WIN 3

// Function to check if the game is over
int check_game_over(char board[BOARD_SIZE][BOARD_SIZE]) {
    // Check for horizontal wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != EMPTY) {
            if (board[i][0] == PLAYER_ONE) {
                return PLAYER_ONE_WIN;
            } else {
                return PLAYER_TWO_WIN;
            }
        }
    }

    // Check for vertical wins
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != EMPTY) {
            if (board[0][i] == PLAYER_ONE) {
                return PLAYER_ONE_WIN;
            } else {
                return PLAYER_TWO_WIN;
            }
        }
    }

    // Check for diagonal wins
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != EMPTY) {
        if (board[0][0] == PLAYER_ONE) {
            return PLAYER_ONE_WIN;
        } else {
            return PLAYER_TWO_WIN;
        }
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != EMPTY) {
        if (board[0][2] == PLAYER_ONE) {
            return PLAYER_ONE_WIN;
        } else {
            return PLAYER_TWO_WIN;
        }
    }

    // Check for draw
    bool draw = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                draw = false;
            }
        }
    }

    if (draw) {
        return DRAW;
    }

    // Game is still in progress
    return IN_PROGRESS;
}

// Function to make a move
void make_move(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char player) {
    board[row][col] = player;
}

// Function to print the game board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to get the best move for the AI
int get_best_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    // Check if there is a winning move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                // Make the move
                make_move(board, i, j, player);

                // Check if the move results in a win
                int game_state = check_game_over(board);
                if (game_state == (player == PLAYER_ONE ? PLAYER_ONE_WIN : PLAYER_TWO_WIN)) {
                    // Undo the move
                    make_move(board, i, j, EMPTY);

                    // Return the move
                    return (i * BOARD_SIZE) + j;
                }

                // Undo the move
                make_move(board, i, j, EMPTY);
            }
        }
    }

    // Check if there is a blocking move
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY) {
                // Make the move
                make_move(board, i, j, player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE);

                // Check if the move results in a win for the opponent
                int game_state = check_game_over(board);
                if (game_state == (player == PLAYER_ONE ? PLAYER_TWO_WIN : PLAYER_ONE_WIN)) {
                    // Undo the move
                    make_move(board, i, j, EMPTY);

                    // Return the move
                    return (i * BOARD_SIZE) + j;
                }

                // Undo the move
                make_move(board, i, j, EMPTY);
            }
        }
    }

    // Choose a random move
    int move;
    do {
        move = rand() % (BOARD_SIZE * BOARD_SIZE);
    } while (board[move / BOARD_SIZE][move % BOARD_SIZE] != EMPTY);

    return move;
}

// Main function
int main() {
    // Initialize the game board
    char board[BOARD_SIZE][BOARD_SIZE] = {{EMPTY, EMPTY, EMPTY},
                                           {EMPTY, EMPTY, EMPTY},
                                           {EMPTY, EMPTY, EMPTY}};

    // Set the current player
    char current_player = PLAYER_ONE;

    // Game loop
    while (true) {
        // Print the game board
        print_board(board);

        // Get the player's move
        int move;
        if (current_player == PLAYER_ONE) {
            printf("Player one's turn: ");
            scanf("%d", &move);
        } else {
            move = get_best_move(board, current_player);
            printf("AI's move: %d\n", move);
        }

        // Make the move
        make_move(board, move / BOARD_SIZE, move % BOARD_SIZE, current_player);

        // Check if the game is over
        int game_state = check_game_over(board);
        if (game_state == PLAYER_ONE_WIN) {
            printf("Player one wins!\n");
            break;
        } else if (game_state == PLAYER_TWO_WIN) {
            printf("AI wins!\n");
            break;
        } else if (game_state == DRAW) {
            printf("Draw!\n");
            break;
        }

        // Switch the current player
        current_player = current_player == PLAYER_ONE ? PLAYER_TWO : PLAYER_ONE;
    }

    return 0;
}