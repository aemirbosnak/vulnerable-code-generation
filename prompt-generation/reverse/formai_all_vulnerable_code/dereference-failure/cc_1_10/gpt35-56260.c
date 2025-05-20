//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 6 // Define the size of the game board
#define MAX_ATTEMPTS 15 // Define the maximum number of attempts for the user
#define EMPTY -1 // Define an empty cell

// Define a struct to hold game board information
typedef struct {
    int** board; // 2D array to hold the game board
    int row; // Current row position of the user
    int col; // Current column position of the user
    int attempts; // Number of attempts made by the user
    int pairs_match; // Number of pairs matched by the user
} Game;

// Function prototypes
Game* initialize_game();
void print_board(Game* game);
int** allocate_board();
void fill_board(Game* game);
void shuffle_board(Game* game);
int is_game_over(Game* game);
int make_move(Game* game, int row, int col);

int main() {
    srand(time(NULL)); // Set the seed for the random number generator
    
    Game* game = initialize_game(); // Create a new game
    
    // Display the instructions to the user
    printf("Welcome to the Memory Game! The objective of the game is to match all the pairs of numbers on the board in %d or less attempts.\n", MAX_ATTEMPTS);
    printf("To make a move, enter the row and column coordinates of the cell you want to flip.\n");
    
    while (!is_game_over(game)) { // Loop until the game is over
        print_board(game); // Display the current state of the game board
        
        int row, col;
        printf("Enter coordinates of cell to flip: ");
        scanf("%d %d", &row, &col); // Read the user's move from input
        
        if (make_move(game, row, col)) { // Check if the move is valid
            printf("Pair matched!\n");
        } else {
            printf("Pair not matched.\n");
        }
        
        printf("\n");
    }
    
    // Game is over, display the final state of the board
    print_board(game);
    
    if (game->pairs_match == BOARD_SIZE * BOARD_SIZE / 2) {
        printf("Congratulations! You matched all the pairs in %d attempts.\n", game->attempts);
    } else {
        printf("Sorry, you did not match all the pairs in %d attempts. Better luck next time!\n", MAX_ATTEMPTS);
    }
    
    // Clean up the memory used by the game
    free(game->board[0]);
    free(game->board);
    free(game);
    
    return 0;
}

// Function to initialize a new game
Game* initialize_game() {
    Game* game = malloc(sizeof(Game)); // Allocate memory for the game struct
    
    game->board = allocate_board(); // Allocate memory for the game board
    game->row = rand() % BOARD_SIZE; // Initialize the row position of the user
    game->col = rand() % BOARD_SIZE; // Initialize the column position of the user
    game->attempts = 0; // Initialize the number of attempts made by the user
    game->pairs_match = 0; // Initialize the number of pairs matched by the user
    
    fill_board(game); // Fill the game board with numbers
    shuffle_board(game); // Shuffle the numbers on the game board
    
    return game;
}

// Function to allocate memory for the game board
int** allocate_board() {
    int** board = malloc(sizeof(int*) * BOARD_SIZE); // Allocate memory for the rows of the board
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[i] = malloc(sizeof(int) * BOARD_SIZE); // Allocate memory for the columns of the board
    }
    
    return board;
}

// Function to fill the game board with numbers
void fill_board(Game* game) {
    int count = 1; // Initialize the starting number to fill the board
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            game->board[i][j] = count++; // Fill each cell with the next number in sequence
        }
    }
}

// Function to shuffle the numbers on the game board
void shuffle_board(Game* game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            int rand_row = rand() % BOARD_SIZE; // Generate a random row position
            int rand_col = rand() % BOARD_SIZE; // Generate a random column position
            
            // Swap the current cell with the random cell
            int temp = game->board[i][j];
            game->board[i][j] = game->board[rand_row][rand_col];
            game->board[rand_row][rand_col] = temp;
        }
    }
}

// Function to check if the game is over
int is_game_over(Game* game) {
    return game->pairs_match == BOARD_SIZE * BOARD_SIZE / 2 || game->attempts == MAX_ATTEMPTS;
}

// Function to make a move on the game board
int make_move(Game* game, int row, int col) {
    game->attempts++; // Increment the number of attempts made by the user
    
    // Check if the move is valid
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || game->board[row][col] == EMPTY || (row == game->row && col == game->col)) {
        return 0;
    }
    
    // Check if the move matches the current cell
    if (game->board[row][col] == game->board[game->row][game->col]) {
        game->pairs_match++; // Increment the number of pairs matched by the user
        game->board[row][col] = EMPTY; // Set the current cell to empty
        game->board[game->row][game->col] = EMPTY; // Set the matched cell to empty
        game->row = rand() % BOARD_SIZE; // Set the row position of the user to a random value
        game->col = rand() % BOARD_SIZE; // Set the column position of the user to a random value
        return 1;
    } else {
        game->row = row; // Update the row position of the user
        game->col = col; // Update the column position of the user
        return 0;
    }
}

// Function to print the game board
void print_board(Game* game) {
    printf("Attempts: %d\n", game->attempts);
    printf("Pairs matched: %d\n", game->pairs_match);
    printf("  ");
    
    for (int j = 0; j < BOARD_SIZE; j++) {
        printf("%d ", j);
    }
    
    printf("\n");
    
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == EMPTY) {
                printf("* ");
            } else {
                printf("%d ", game->board[i][j]);
            }
        }
        
        printf("\n");
    }
}