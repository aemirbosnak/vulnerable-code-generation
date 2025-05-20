//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: calm
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int num_disks;
    int **towers;
} towers_t;

// Create a new towers structure with the given number of disks.
towers_t *create_towers(int num_disks) {
    towers_t *towers = malloc(sizeof(towers_t));
    towers->num_disks = num_disks;

    // Allocate memory for the towers.
    towers->towers = malloc(sizeof(int *) * 3);
    for (int i = 0; i < 3; i++) {
        towers->towers[i] = malloc(sizeof(int) * num_disks);
    }

    // Initialize the towers.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < num_disks; j++) {
            towers->towers[i][j] = 0;
        }
    }

    return towers;
}

// Free the memory allocated for the towers structure.
void free_towers(towers_t *towers) {
    // Free the memory allocated for the towers.
    for (int i = 0; i < 3; i++) {
        free(towers->towers[i]);
    }

    // Free the memory allocated for the towers structure.
    free(towers);
}

// Print the current state of the towers.
void print_towers(towers_t *towers) {
    for (int i = towers->num_disks - 1; i >= 0; i--) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", towers->towers[j][i]);
        }
        printf("\n");
    }
    printf("\n");
}

// Move a disk from one tower to another.
void move_disk(towers_t *towers, int from, int to) {
    // Get the index of the top disk on the from tower.
    int from_top = -1;
    for (int i = 0; i < towers->num_disks; i++) {
        if (towers->towers[from][i] != 0) {
            from_top = i;
            break;
        }
    }

    // Get the index of the top disk on the to tower.
    int to_top = -1;
    for (int i = 0; i < towers->num_disks; i++) {
        if (towers->towers[to][i] != 0) {
            to_top = i;
            break;
        }
    }

    // Move the disk from the from tower to the to tower.
    towers->towers[to][to_top] = towers->towers[from][from_top];
    towers->towers[from][from_top] = 0;
}

// Solve the Tower of Hanoi problem.
void solve_tower_of_hanoi(towers_t *towers, int num_disks, int from, int to, int via) {
    // If there is only one disk, move it from the from tower to the to tower.
    if (num_disks == 1) {
        move_disk(towers, from, to);
        return;
    }

    // Move the top n-1 disks from the from tower to the via tower.
    solve_tower_of_hanoi(towers, num_disks - 1, from, via, to);

    // Move the nth disk from the from tower to the to tower.
    move_disk(towers, from, to);

    // Move the n-1 disks from the via tower to the to tower.
    solve_tower_of_hanoi(towers, num_disks - 1, via, to, from);
}

int main() {
    // Create a new towers structure with 3 disks.
    towers_t *towers = create_towers(3);

    // Solve the Tower of Hanoi problem.
    solve_tower_of_hanoi(towers, towers->num_disks, 0, 2, 1);

    // Print the final state of the towers.
    print_towers(towers);

    // Free the memory allocated for the towers structure.
    free_towers(towers);

    return 0;
}