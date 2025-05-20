//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 6

typedef struct {
    int num_disks;
    int *disks;
} tower;

void print_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
}

void move_disk(tower *towers, int from, int to) {
    int disk = towers[from].disks[towers[from].num_disks - 1];
    towers[from].num_disks--;
    towers[to].num_disks++;
    towers[to].disks[towers[to].num_disks - 1] = disk;
}

int main() {
    tower towers[NUM_TOWERS];
    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].num_disks = 0;
        towers[i].disks = malloc(sizeof(int) * NUM_DISKS);
    }

    // Initialize the first tower with all the disks
    for (int i = 0; i < NUM_DISKS; i++) {
        towers[0].disks[i] = i + 1;
        towers[0].num_disks++;
    }

    // Print the initial state of the towers
    print_towers(towers);

    // Solve the Tower of Hanoi problem
    int num_moves = 0;
    int from = 0;
    int to = 2;
    while (towers[2].num_disks < NUM_DISKS) {
        move_disk(towers, from, to);
        num_moves++;
        from = (from + 1) % NUM_TOWERS;
        to = (to + 1) % NUM_TOWERS;
    }

    // Print the final state of the towers
    print_towers(towers);

    // Print the number of moves
    printf("Number of moves: %d\n", num_moves);

    return 0;
}