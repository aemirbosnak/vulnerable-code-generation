//GEMINI-pro DATASET v1.0 Category: Table Game ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players and the maximum size of the table.
#define MAX_PLAYERS 4
#define MAX_TABLE_SIZE 10

// Define the different types of pieces that can be placed on the table.
typedef enum {
    EMPTY,
    PLAYER_1,
    PLAYER_2,
    PLAYER_3,
    PLAYER_4
} piece_type;

// Define the structure of a game move.
typedef struct {
    int player_number;  // The number of the player who made the move.
    int row;             // The row of the move.
    int column;          // The column of the move.
} move;

// Define the structure of a game state.
typedef struct {
    piece_type table[MAX_TABLE_SIZE][MAX_TABLE_SIZE];  // The game table.
    int num_players;                                    // The number of players in the game.
    int current_player;                                 // The number of the current player.
    move last_move;                                     // The last move that was made.
} game_state;

// Create a new game state.
game_state* new_game_state() {
    game_state* state = malloc(sizeof(game_state));
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        for (int j = 0; j < MAX_TABLE_SIZE; j++) {
            state->table[i][j] = EMPTY;
        }
    }
    state->num_players = 0;
    state->current_player = 0;
    state->last_move.player_number = -1;
    state->last_move.row = -1;
    state->last_move.column = -1;
    return state;
}

// Free a game state.
void free_game_state(game_state* state) {
    free(state);
}

// Add a player to the game.
void add_player(game_state* state, int player_number) {
    state->num_players++;
    state->current_player = player_number;
}

// Make a move on the game table.
void make_move(game_state* state, move move) {
    state->table[move.row][move.column] = move.player_number;
    state->last_move = move;
    state->current_player = (state->current_player + 1) % state->num_players;
}

// Check if a move is valid.
int is_valid_move(game_state* state, move move) {
    return move.row >= 0 && move.row < MAX_TABLE_SIZE &&
           move.column >= 0 && move.column < MAX_TABLE_SIZE &&
           state->table[move.row][move.column] == EMPTY;
}

// Check if the game is over.
int is_game_over(game_state* state) {
    // Check if there are any empty spaces on the table.
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        for (int j = 0; j < MAX_TABLE_SIZE; j++) {
            if (state->table[i][j] == EMPTY) {
                return 0;
            }
        }
    }

    // Check if any player has four pieces in a row, column, or diagonal.
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        // Check rows.
        for (int j = 0; j < MAX_TABLE_SIZE - 3; j++) {
            if (state->table[i][j] == state->table[i][j+1] &&
                state->table[i][j] == state->table[i][j+2] &&
                state->table[i][j] == state->table[i][j+3]) {
                return 1;
            }
        }

        // Check columns.
        for (int j = 0; j < MAX_TABLE_SIZE - 3; j++) {
            if (state->table[j][i] == state->table[j+1][i] &&
                state->table[j][i] == state->table[j+2][i] &&
                state->table[j][i] == state->table[j+3][i]) {
                return 1;
            }
        }

        // Check diagonals.
        for (int j = 0; j < MAX_TABLE_SIZE - 3; j++) {
            if (state->table[j][i] == state->table[j+1][i+1] &&
                state->table[j][i] == state->table[j+2][i+2] &&
                state->table[j][i] == state->table[j+3][i+3]) {
                return 1;
            }
        }

        for (int j = 3; j < MAX_TABLE_SIZE; j++) {
            if (state->table[j][i] == state->table[j-1][i+1] &&
                state->table[j][i] == state->table[j-2][i+2] &&
                state->table[j][i] == state->table[j-3][i+3]) {
                return 1;
            }
        }
    }

    // The game is not over.
    return 0;
}

// Get the winner of the game.
int get_winner(game_state* state) {
    return state->last_move.player_number;
}

// Print the game table.
void print_table(game_state* state) {
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        for (int j = 0; j < MAX_TABLE_SIZE; j++) {
            switch (state->table[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case PLAYER_1:
                    printf("1");
                    break;
                case PLAYER_2:
                    printf("2");
                    break;
                case PLAYER_3:
                    printf("3");
                    break;
                case PLAYER_4:
                    printf("4");
                    break;
            }
        }
        printf("\n");
    }
}

// Play a game of Connect Four.
void play_game() {
    // Create a new game state.
    game_state* state = new_game_state();

    // Add some players to the game.
    add_player(state, 1);
    add_player(state, 2);

    // Play the game until it is over.
    while (!is_game_over(state)) {
        // Get the move from the current player.
        move move;
        printf("Player %d, enter your move (row, column): ", state->current_player);
        scanf("%d %d", &move.row, &move.column);

        // Check if the move is valid.
        if (!is_valid_move(state, move)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move.
        make_move(state, move);

        // Print the game table.
        print_table(state);
    }

    // Get the winner of the game.
    int winner = get_winner(state);

    // Print the winner.
    printf("Player %d wins!\n", winner);

    // Free the game state.
    free_game_state(state);
}

// Main function.
int main() {
    // Play a game of Connect Four.
    play_game();

    return 0;
}