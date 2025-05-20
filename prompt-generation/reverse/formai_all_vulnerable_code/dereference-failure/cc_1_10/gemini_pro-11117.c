//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define the number of disks
#define NUM_DISKS 3

// Define the source, destination, and auxiliary towers
#define SOURCE 1
#define DESTINATION 2
#define AUXILIARY 3

// Function to print the current state of the towers
void print_towers(int towers[3][NUM_DISKS]) {
    for (int i = 0; i < NUM_DISKS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < 3; j++) {
            printf("%d ", towers[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to move a disk from one tower to another
void move_disk(int towers[3][NUM_DISKS], int from_tower, int to_tower) {
    // Find the top disk on the from tower
    int from_disk = 0;
    while (towers[from_tower - 1][from_disk] == 0) {
        from_disk++;
    }

    // Find the top disk on the to tower
    int to_disk = 0;
    while (towers[to_tower - 1][to_disk] == 0) {
        to_disk++;
    }

    // Move the disk from the from tower to the to tower
    towers[to_tower - 1][to_disk] = towers[from_tower - 1][from_disk];
    towers[from_tower - 1][from_disk] = 0;

    // Print the current state of the towers
    print_towers(towers);
}

// Function to solve the Tower of Hanoi problem
void tower_of_hanoi(int towers[3][NUM_DISKS], int num_disks, int from_tower, int to_tower, int auxiliary_tower) {
    // If there are no disks, do nothing
    if (num_disks == 0) {
        return;
    }

    // Move the top n-1 disks from the from tower to the auxiliary tower
    tower_of_hanoi(towers, num_disks - 1, from_tower, auxiliary_tower, to_tower);

    // Move the remaining disk from the from tower to the to tower
    move_disk(towers, from_tower, to_tower);

    // Move the n-1 disks from the auxiliary tower to the to tower
    tower_of_hanoi(towers, num_disks - 1, auxiliary_tower, to_tower, from_tower);
}

// Main function
int main() {
    // Initialize the towers
    int towers[3][NUM_DISKS] = {
        {3, 2, 1},
        {0, 0, 0},
        {0, 0, 0}
    };

    // Print the initial state of the towers
    print_towers(towers);

    // Solve the Tower of Hanoi problem
    tower_of_hanoi(towers, NUM_DISKS, SOURCE, DESTINATION, AUXILIARY);

    return 0;
}