//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 5

// A tower is a stack of disks.
struct tower {
    int num_disks;
    int *disks;
};

// A move is a transfer of a disk from one tower to another.
struct move {
    int from_tower;
    int to_tower;
};

// Create a new tower with the given number of disks.
struct tower *create_tower(int num_disks) {
    struct tower *tower = malloc(sizeof(struct tower));
    tower->num_disks = num_disks;
    tower->disks = malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = i + 1;
    }
    return tower;
}

// Print the current state of the towers.
void print_towers(struct tower *towers[NUM_TOWERS]) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i]->num_disks; j++) {
            printf("%d ", towers[i]->disks[j]);
        }
        printf("\n");
    }
}

// Check if the given move is valid.
int is_valid_move(struct tower *towers[NUM_TOWERS], struct move move) {
    // Check if the from tower has any disks.
    if (towers[move.from_tower]->num_disks == 0) {
        return 0;
    }

    // Check if the to tower has any disks.
    if (towers[move.to_tower]->num_disks == 0) {
        return 1;
    }

    // Check if the disk on the from tower is larger than the disk on the to tower.
    if (towers[move.from_tower]->disks[towers[move.from_tower]->num_disks - 1] > towers[move.to_tower]->disks[towers[move.to_tower]->num_disks - 1]) {
        return 0;
    }

    return 1;
}

// Perform the given move on the given towers.
void perform_move(struct tower *towers[NUM_TOWERS], struct move move) {
    // Move the disk from the from tower to the to tower.
    towers[move.to_tower]->disks[towers[move.to_tower]->num_disks] = towers[move.from_tower]->disks[towers[move.from_tower]->num_disks - 1];
    towers[move.to_tower]->num_disks++;
    towers[move.from_tower]->num_disks--;
}

// Solve the Tower of Hanoi problem.
int solve_tower_of_hanoi(struct tower *towers[NUM_TOWERS], int num_disks, int from_tower, int to_tower, int via_tower) {
    // Base case: there are no disks to move.
    if (num_disks == 0) {
        return 0;
    }

    // Move the top num_disks - 1 disks from the from tower to the via tower.
    solve_tower_of_hanoi(towers, num_disks - 1, from_tower, via_tower, to_tower);

    // Move the remaining disk from the from tower to the to tower.
    struct move move = {from_tower, to_tower};
    perform_move(towers, move);

    // Move the top num_disks - 1 disks from the via tower to the to tower.
    solve_tower_of_hanoi(towers, num_disks - 1, via_tower, to_tower, from_tower);

    return 0;
}

int main() {
    // Create the towers.
    struct tower *towers[NUM_TOWERS] = {create_tower(NUM_DISKS), create_tower(0), create_tower(0)};

    // Print the initial state of the towers.
    print_towers(towers);

    // Solve the Tower of Hanoi problem.
    solve_tower_of_hanoi(towers, NUM_DISKS, 0, 2, 1);

    // Print the final state of the towers.
    print_towers(towers);

    return 0;
}