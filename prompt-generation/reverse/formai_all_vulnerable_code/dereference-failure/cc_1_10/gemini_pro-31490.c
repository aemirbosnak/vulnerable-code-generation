//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TOWERS 3
#define NUM_DISKS 5

// Function to print the current state of the towers
void print_towers(int towers[NUM_TOWERS][NUM_DISKS]) {
    for (int i = 0; i < NUM_DISKS; i++) {
        for (int j = 0; j < NUM_TOWERS; j++) {
            printf("%d ", towers[j][i]);
        }
        printf("\n");
    }
}

// Function to move a disk from one tower to another
void move_disk(int towers[NUM_TOWERS][NUM_DISKS], int from_tower, int to_tower) {
    // Find the top disk on the from tower
    int from_disk = -1;
    for (int i = 0; i < NUM_DISKS; i++) {
        if (towers[from_tower][i] != 0) {
            from_disk = i;
            break;
        }
    }

    // Find the top disk on the to tower
    int to_disk = -1;
    for (int i = 0; i < NUM_DISKS; i++) {
        if (towers[to_tower][i] != 0) {
            to_disk = i;
            break;
        }
    }

    // Move the disk from the from tower to the to tower
    towers[to_tower][to_disk] = towers[from_tower][from_disk];
    towers[from_tower][from_disk] = 0;
}

// Function to solve the Tower of Hanoi problem
void solve_tower_of_hanoi(int towers[NUM_TOWERS][NUM_DISKS], int num_disks, int from_tower, int to_tower, int aux_tower) {
    // Base case: if there are no disks, do nothing
    if (num_disks == 0) {
        return;
    }

    // Recursive case: move the top n-1 disks from the from tower to the aux tower
    solve_tower_of_hanoi(towers, num_disks - 1, from_tower, aux_tower, to_tower);

    // Move the remaining disk from the from tower to the to tower
    move_disk(towers, from_tower, to_tower);

    // Recursive case: move the n-1 disks from the aux tower to the to tower
    solve_tower_of_hanoi(towers, num_disks - 1, aux_tower, to_tower, from_tower);
}

int main() {
    // Initialize the towers
    int towers[NUM_TOWERS][NUM_DISKS];
    for (int i = 0; i < NUM_TOWERS; i++) {
        for (int j = 0; j < NUM_DISKS; j++) {
            towers[i][j] = 0;
        }
    }

    // Place the disks on the first tower
    for (int i = 0; i < NUM_DISKS; i++) {
        towers[0][i] = NUM_DISKS - i;
    }

    // Solve the Tower of Hanoi problem
    solve_tower_of_hanoi(towers, NUM_DISKS, 0, 2, 1);

    // Print the final state of the towers
    print_towers(towers);

    return 0;
}