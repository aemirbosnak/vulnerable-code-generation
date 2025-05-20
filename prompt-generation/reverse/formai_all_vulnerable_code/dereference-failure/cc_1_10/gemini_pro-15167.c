//GEMINI-pro DATASET v1.0 Category: Game ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10
#define MAX_NUMBERS 100

// Function to generate a random number between min and max
int random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Function to create a new game board
int **create_board() {
    int **board = (int **)malloc(MAX_SIZE * sizeof(int *));
    for (int i = 0; i < MAX_SIZE; i++) {
        board[i] = (int *)malloc(MAX_SIZE * sizeof(int));
        for (int j = 0; j < MAX_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    return board;
}

// Function to free the game board
void free_board(int **board) {
    for (int i = 0; i < MAX_SIZE; i++) {
        free(board[i]);
    }
    free(board);
}

// Function to print the game board
void print_board(int **board) {
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the game is over
int is_game_over(int **board) {
    // Check if there are any empty cells
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }

    // Check if there are any possible moves
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            if (i > 0 && board[i - 1][j] == board[i][j]) {
                return 0;
            }
            if (j > 0 && board[i][j - 1] == board[i][j]) {
                return 0;
            }
        }
    }

    return 1;
}

// Function to get the score of the board
int get_score(int **board) {
    int score = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            score += board[i][j];
        }
    }
    return score;
}

// Function to make a move on the board
void make_move(int **board, int x, int y) {
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE) {
        return;
    }

    if (board[x][y] == 0) {
        board[x][y] = random_number(1, MAX_NUMBERS);
        return;
    }

    if (x > 0 && board[x - 1][y] == board[x][y]) {
        board[x - 1][y] += board[x][y];
        board[x][y] = 0;
        return;
    }

    if (y > 0 && board[x][y - 1] == board[x][y]) {
        board[x][y - 1] += board[x][y];
        board[x][y] = 0;
        return;
    }
}

// Function to play the game
void play_game() {
    int **board = create_board();
    int score = 0;

    while (!is_game_over(board)) {
        // Print the board
        print_board(board);

        // Get the player's move
        int x, y;
        printf("Enter your move (x, y): ");
        scanf("%d %d", &x, &y);

        // Make the move
        make_move(board, x, y);

        // Update the score
        score = get_score(board);
        printf("Score: %d\n", score);
    }

    // Print the final board
    print_board(board);

    // Free the board
    free_board(board);

    printf("Game over! Your score is %d.\n", score);
}

int main() {
    srand(time(NULL));
    play_game();
    return 0;
}