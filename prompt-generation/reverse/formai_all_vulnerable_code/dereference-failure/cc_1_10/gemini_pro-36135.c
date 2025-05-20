//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

// Function to create a new game board
char** create_board() {
    char** board = (char**)malloc(SIZE * sizeof(char*));
    for (int i = 0; i < SIZE; i++) {
        board[i] = (char*)malloc(SIZE * sizeof(char));
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    return board;
}

// Function to free the game board
void free_board(char** board) {
    for (int i = 0; i < SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// Function to print the game board
void print_board(char** board) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int check_game_over(char** board) {
    // Check for rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') {
            return board[i][0];
        }
    }

    // Check for columns
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ') {
            return board[0][j];
        }
    }

    // Check for diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') {
        return board[0][2];
    }

    // Check for draw
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] != ' ') {
                count++;
            }
        }
    }
    if (count == SIZE * SIZE) {
        return 'D';
    }

    // Game is not over
    return 'N';
}

// Function to get the best move for the AI
int get_best_move(char** board) {
    // Create an array to store the possible moves
    int moves[SIZE * SIZE];

    // Get the number of possible moves
    int num_moves = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') {
                moves[num_moves] = i * SIZE + j;
                num_moves++;
            }
        }
    }

    // If there are no possible moves, return -1
    if (num_moves == 0) {
        return -1;
    }

    // Choose a random move from the possible moves
    srand(time(NULL));
    int move = moves[rand() % num_moves];

    return move;
}

// Function to make a move on the game board
void make_move(char** board, int move, char player) {
    int row = move / SIZE;
    int col = move % SIZE;
    board[row][col] = player;
}

// Function to play the game
void play_game() {
    // Create a new game board
    char** board = create_board();

    // Get the first move from the AI
    int ai_move = get_best_move(board);
    make_move(board, ai_move, 'O');

    // Print the game board
    print_board(board);

    // Loop until the game is over
    while (check_game_over(board) == 'N') {
        // Get the player's move
        int player_move;
        printf("Enter your move (row, column): ");
        scanf("%d %d", &player_move, &player_move);

        // Make the player's move
        make_move(board, player_move, 'X');

        // Print the game board
        print_board(board);

        // Get the next move from the AI
        ai_move = get_best_move(board);
        make_move(board, ai_move, 'O');

        // Print the game board
        print_board(board);
    }

    // Check who won the game
    char winner = check_game_over(board);
    if (winner == 'X') {
        printf("You win!\n");
    } else if (winner == 'O') {
        printf("The AI wins!\n");
    } else {
        printf("Draw!\n");
    }

    // Free the game board
    free_board(board);
}

int main() {
    // Play the game
    play_game();

    return 0;
}