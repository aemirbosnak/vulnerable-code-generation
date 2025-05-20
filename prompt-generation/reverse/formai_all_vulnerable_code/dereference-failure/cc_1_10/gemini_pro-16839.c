//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: lively
#include <stdio.h>
#include <stdlib.h>

// Define the tower structure
typedef struct tower {
    int num_disks;
    char *name;
} tower;

// Define the game state
typedef struct game_state {
    tower towers[3];
} game_state;

// Create a new game state
game_state *new_game_state() {
    game_state *state = malloc(sizeof(game_state));
    state->towers[0].num_disks = 3;
    state->towers[0].name = "A";
    state->towers[1].num_disks = 0;
    state->towers[1].name = "B";
    state->towers[2].num_disks = 0;
    state->towers[2].name = "C";
    return state;
}

// Check if the game is over
int is_game_over(game_state *state) {
    return state->towers[2].num_disks == 3;
}

// Move a disk from one tower to another
void move_disk(game_state *state, int from, int to) {
    if (state->towers[from].num_disks == 0) {
        printf("Error: Can't move a disk from an empty tower\n");
    } else if (state->towers[to].num_disks > 0 && state->towers[from].num_disks > state->towers[to].num_disks) {
        printf("Error: Can't move a larger disk onto a smaller disk\n");
    } else {
        state->towers[to].num_disks++;
        state->towers[from].num_disks--;
    }
}

// Print the current game state
void print_game_state(game_state *state) {
    printf("Tower A: %d\n", state->towers[0].num_disks);
    printf("Tower B: %d\n", state->towers[1].num_disks);
    printf("Tower C: %d\n", state->towers[2].num_disks);
}

// Handle user input
int handle_input(game_state *state) {
    char input[3];
    printf("Enter your move (e.g. A B): ");
    scanf("%s", input);
    int from = input[0] - 'A';
    int to = input[2] - 'A';
    move_disk(state, from, to);
    return 0;
}

// Play the game
int play_game() {
    game_state *state = new_game_state();
    while (!is_game_over(state)) {
        print_game_state(state);
        handle_input(state);
    }
    printf("Congratulations! You solved the Tower of Hanoi puzzle!\n");
    return 0;
}

// Main function
int main() {
    play_game();
    return 0;
}