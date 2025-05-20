//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

// Define the number of disks and the three rods.
#define NUM_DISKS 5
#define ROD_A 'A'
#define ROD_B 'B'
#define ROD_C 'C'

// Print the current state of the rods.
void print_rods(char *rods[]) {
    printf("%s %s %s\n", rods[0], rods[1], rods[2]);
}

// Move a disk from one rod to another.
void move_disk(char *rods[], char from_rod, char to_rod) {
    // Find the index of the top disk on the from rod.
    int from_idx = 0;
    while (rods[from_idx][0] != ' ') {
        from_idx++;
    }

    // Find the index of the top disk on the to rod.
    int to_idx = 0;
    while (rods[to_idx][0] != ' ') {
        to_idx++;
    }

    // Move the disk from the from rod to the to rod.
    rods[to_idx][0] = rods[from_idx][0];
    rods[from_idx][0] = ' ';
}

// Solve the Tower of Hanoi problem.
void solve_tower_of_hanoi(char *rods[], int num_disks, char from_rod, char to_rod, char aux_rod) {
    // Base case: no more disks to move.
    if (num_disks == 0) {
        return;
    }

    // Move the top n-1 disks from the from rod to the aux rod.
    solve_tower_of_hanoi(rods, num_disks - 1, from_rod, aux_rod, to_rod);

    // Move the remaining disk from the from rod to the to rod.
    move_disk(rods, from_rod, to_rod);

    // Move the n-1 disks from the aux rod to the to rod.
    solve_tower_of_hanoi(rods, num_disks - 1, aux_rod, to_rod, from_rod);
}

// Main function.
int main() {
    // Create the three rods.
    char *rods[] = {
        "-------|-------|-------",
        "-------|-------|-------",
        "-------|-------|-------",
    };

    // Print the initial state of the rods.
    print_rods(rods);

    // Solve the Tower of Hanoi problem.
    solve_tower_of_hanoi(rods, NUM_DISKS, ROD_A, ROD_C, ROD_B);

    // Print the final state of the rods.
    print_rods(rods);

    return 0;
}