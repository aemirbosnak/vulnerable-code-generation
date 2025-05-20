//GEMINI-pro DATASET v1.0 Category: Tic Tac Toe AI ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define BOARD_SIZE 3
#define NUM_THREADS 9

// The game board
char board[BOARD_SIZE][BOARD_SIZE];

// The current player
int current_player;

// Mutex to protect the game board
pthread_mutex_t board_mutex = PTHREAD_MUTEX_INITIALIZER;

// Condition variable to signal when the game is over
pthread_cond_t game_over_cond = PTHREAD_COND_INITIALIZER;

// Thread data structure
typedef struct {
    int row;
    int col;
} thread_data;

// Thread function
void *thread_func(void *arg) {
    // Get the thread data
    thread_data *data = (thread_data *)arg;

    // Lock the mutex
    pthread_mutex_lock(&board_mutex);

    // Check if the game is over
    if (board[data->row][data->col] != ' ') {
        // The game is over, so unlock the mutex and return
        pthread_mutex_unlock(&board_mutex);
        return NULL;
    }

    // Make the move
    board[data->row][data->col] = current_player == 1 ? 'X' : 'O';

    // Check if the game is over
    int winner = check_winner();
    if (winner != 0) {
        // The game is over, so signal the condition variable and unlock the mutex
        pthread_cond_signal(&game_over_cond);
        pthread_mutex_unlock(&board_mutex);
        return NULL;
    }

    // Switch to the other player
    current_player = current_player == 1 ? 2 : 1;

    // Unlock the mutex
    pthread_mutex_unlock(&board_mutex);

    return NULL;
}

// Check if the game is over
int check_winner() {
    // Check rows
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0] == 'X' ? 1 : 2;
        }
    }

    // Check columns
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i] == 'X' ? 1 : 2;
        }
    }

    // Check diagonals
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0] == 'X' ? 1 : 2;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2] == 'X' ? 1 : 2;
    }

    // No winner yet
    return 0;
}

// Print the game board
void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Initialize the game board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    // Set the current player
    current_player = 1;

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        thread_data *data = malloc(sizeof(thread_data));
        data->row = i / 3;
        data->col = i % 3;
        pthread_create(&threads[i], NULL, thread_func, data);
    }

    // Wait for the game to end
    pthread_cond_wait(&game_over_cond, &board_mutex);

    // Print the game board
    print_board();

    // Destroy the mutex and condition variable
    pthread_mutex_destroy(&board_mutex);
    pthread_cond_destroy(&game_over_cond);

    return 0;
}