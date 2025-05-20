//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int pegs[3];
} toh_state;

toh_state *new_state(int num_disks) {
    toh_state *state = malloc(sizeof(toh_state));
    state->num_disks = num_disks;
    for (int i = 0; i < 3; i++) {
        state->pegs[i] = 0;
    }
    return state;
}

void free_state(toh_state *state) {
    free(state);
}

int is_valid_move(toh_state *state, int from, int to) {
    if (from < 0 || from > 2 || to < 0 || to > 2) {
        return 0;
    }
    if (state->pegs[from] == 0) {
        return 0;
    }
    if (state->pegs[to] > 0 && state->pegs[from] > state->pegs[to]) {
        return 0;
    }
    return 1;
}

void move_disk(toh_state *state, int from, int to) {
    state->pegs[to] += state->pegs[from];
    state->pegs[from] = 0;
}

int is_goal_state(toh_state *state) {
    return state->pegs[2] == state->num_disks;
}

void print_state(toh_state *state) {
    for (int i = 0; i < 3; i++) {
        printf("Peg %d: %d\n", i, state->pegs[i]);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    toh_state *state = new_state(num_disks);
    state->pegs[0] = num_disks;

    while (!is_goal_state(state)) {
        int from, to;
        printf("Enter the move (from, to): ");
        scanf("%d %d", &from, &to);

        if (is_valid_move(state, from, to)) {
            move_disk(state, from, to);
        } else {
            printf("Invalid move.\n");
        }

        print_state(state);
    }

    printf("Solved!\n");

    free_state(state);

    return 0;
}