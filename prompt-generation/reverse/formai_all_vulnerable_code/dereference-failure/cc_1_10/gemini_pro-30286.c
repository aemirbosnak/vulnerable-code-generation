//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Tower of Hanoi problem with a dynamic array implementation.

// The `tower` structure represents a tower of disks.
typedef struct tower {
    int *disks; // The array of disks.
    int num_disks; // The number of disks in the tower.
} tower;

// The `move_disk()` function moves a disk from one tower to another.
void move_disk(tower *from, tower *to) {
    // Check if the from tower has any disks.
    if (from->num_disks == 0) {
        printf("Error: cannot move a disk from an empty tower.\n");
        return;
    }

    // Check if the to tower can accommodate the disk.
    if (to->num_disks > 0 && from->disks[from->num_disks - 1] > to->disks[to->num_disks - 1]) {
        printf("Error: cannot move a larger disk onto a smaller disk.\n");
        return;
    }

    // Move the disk from the from tower to the to tower.
    to->disks[to->num_disks++] = from->disks[--from->num_disks];
}

// The `solve_tower_of_hanoi()` function solves the Tower of Hanoi problem for the given number of disks.
void solve_tower_of_hanoi(int num_disks, tower *from, tower *to, tower *aux) {
    // Check if the number of disks is valid.
    if (num_disks < 1) {
        printf("Error: invalid number of disks.\n");
        return;
    }

    // Solve the problem recursively.
    if (num_disks == 1) {
        move_disk(from, to);
    } else {
        solve_tower_of_hanoi(num_disks - 1, from, aux, to);
        move_disk(from, to);
        solve_tower_of_hanoi(num_disks - 1, aux, to, from);
    }
}

// The `main()` function is the entry point of the program.
int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid.
    if (argc != 2) {
        printf("Usage: %s num_disks\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the number of disks from the command line argument.
    int num_disks = atoi(argv[1]);

    // Create the three towers.
    tower from, to, aux;
    from.disks = malloc(num_disks * sizeof(int));
    to.disks = malloc(num_disks * sizeof(int));
    aux.disks = malloc(num_disks * sizeof(int));
    from.num_disks = num_disks;
    to.num_disks = 0;
    aux.num_disks = 0;

    // Initialize the disks.
    for (int i = 0; i < num_disks; i++) {
        from.disks[i] = num_disks - i;
    }

    // Solve the problem.
    solve_tower_of_hanoi(num_disks, &from, &to, &aux);

    // Print the solution.
    printf("The solution is:\n");
    for (int i = 0; i < num_disks; i++) {
        printf("%d\n", to.disks[i]);
    }

    // Free the memory allocated for the towers.
    free(from.disks);
    free(to.disks);
    free(aux.disks);

    return EXIT_SUCCESS;
}