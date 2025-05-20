//GEMINI-pro DATASET v1.0 Category: Hexadecimal Converter ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PLAYERS 4
#define MAX_TURNS 10

// Define the player structure
typedef struct {
    char name[20];
    int score;
} Player;

// Define the game state
typedef struct {
    Player players[MAX_PLAYERS];
    int current_player;
    int current_turn;
    char input[20];
} GameState;

// Create a new game state
GameState* new_game_state() {
    GameState* state = malloc(sizeof(GameState));
    for (int i = 0; i < MAX_PLAYERS; i++) {
        state->players[i].score = 0;
    }
    state->current_player = 0;
    state->current_turn = 0;
    return state;
}

// Free the game state
void free_game_state(GameState* state) {
    free(state);
}

// Get the next player
int next_player(GameState* state) {
    return (state->current_player + 1) % MAX_PLAYERS;
}

// Get the next turn
int next_turn(GameState* state) {
    return state->current_turn + 1;
}

// Check if the game is over
int game_over(GameState* state) {
    return state->current_turn >= MAX_TURNS;
}

// Get the winner
Player* get_winner(GameState* state) {
    Player* winner = NULL;
    int max_score = -1;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (state->players[i].score > max_score) {
            winner = &state->players[i];
            max_score = state->players[i].score;
        }
    }
    return winner;
}

// Print the game state
void print_game_state(GameState* state) {
    printf("Current player: %s\n", state->players[state->current_player].name);
    printf("Current turn: %d\n", state->current_turn);
    printf("Scores:\n");
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("%s: %d\n", state->players[i].name, state->players[i].score);
    }
}

// Get the player's input
void get_input(GameState* state) {
    printf("Enter a hexadecimal number: ");
    scanf("%s", state->input);
}

// Check if the input is valid
int valid_input(char* input) {
    for (int i = 0; i < strlen(input); i++) {
        if (!isxdigit(input[i])) {
            return 0;
        }
    }
    return 1;
}

// Convert the input to an integer
int convert_input(char* input) {
    int number = 0;
    for (int i = 0; i < strlen(input); i++) {
        if (isdigit(input[i])) {
            number *= 16;
            number += input[i] - '0';
        } else {
            number *= 16;
            number += input[i] - 'a' + 10;
        }
    }
    return number;
}

// Update the game state
void update_game_state(GameState* state) {
    if (!valid_input(state->input)) {
        printf("Invalid input\n");
        return;
    }

    int number = convert_input(state->input);
    state->players[state->current_player].score += number;
    state->current_player = next_player(state);
    state->current_turn = next_turn(state);
}

// Main game loop
void game_loop(GameState* state) {
    while (!game_over(state)) {
        print_game_state(state);
        get_input(state);
        update_game_state(state);
    }
}

// Main function
int main() {
    GameState* state = new_game_state();

    // Get the player names
    for (int i = 0; i < MAX_PLAYERS; i++) {
        printf("Enter player %d's name: ", i + 1);
        scanf("%s", state->players[i].name);
    }

    // Start the game loop
    game_loop(state);

    // Print the winner
    Player* winner = get_winner(state);
    printf("The winner is %s!\n", winner->name);

    // Free the game state
    free_game_state(state);

    return 0;
}