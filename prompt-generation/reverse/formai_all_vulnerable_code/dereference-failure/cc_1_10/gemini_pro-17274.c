//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 10

// Define the tower data structure
typedef struct tower {
    int num_disks;
    int *disks;
} tower;

// Initialize the towers
void initialize_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].num_disks = 0;
        towers[i].disks = NULL;
    }
}

// Push a disk onto a tower
void push_disk(tower *tower, int disk) {
    tower->disks = realloc(tower->disks, (tower->num_disks + 1) * sizeof(int));
    tower->disks[tower->num_disks++] = disk;
}

// Pop a disk from a tower
int pop_disk(tower *tower) {
    if (tower->num_disks == 0) {
        return -1;
    }

    int disk = tower->disks[tower->num_disks - 1];
    tower->num_disks--;
    tower->disks = realloc(tower->disks, tower->num_disks * sizeof(int));
    return disk;
}

// Print the towers
void print_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
}

// Solve the Tower of Hanoi problem
void solve_tower_of_hanoi(tower *towers, int num_disks, int from_tower, int to_tower, int aux_tower) {
    // Base case: no more disks to move
    if (num_disks == 0) {
        return;
    }

    // Move the top num_disks - 1 disks from the from_tower to the aux_tower
    solve_tower_of_hanoi(towers, num_disks - 1, from_tower, aux_tower, to_tower);

    // Move the remaining disk from the from_tower to the to_tower
    int disk = pop_disk(&towers[from_tower]);
    push_disk(&towers[to_tower], disk);

    // Move the num_disks - 1 disks from the aux_tower to the to_tower
    solve_tower_of_hanoi(towers, num_disks - 1, aux_tower, to_tower, from_tower);
}

int main() {
    // Initialize the towers
    tower towers[NUM_TOWERS];
    initialize_towers(towers);

    // Push the disks onto the first tower
    for (int i = NUM_DISKS; i >= 1; i--) {
        push_disk(&towers[0], i);
    }

    // Print the initial state of the towers
    printf("Initial state:\n");
    print_towers(towers);

    // Solve the Tower of Hanoi problem
    solve_tower_of_hanoi(towers, NUM_DISKS, 0, 2, 1);

    // Print the final state of the towers
    printf("Final state:\n");
    print_towers(towers);

    return 0;
}