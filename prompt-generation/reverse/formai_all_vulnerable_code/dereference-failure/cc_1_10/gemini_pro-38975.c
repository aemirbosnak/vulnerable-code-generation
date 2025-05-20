//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 4

typedef struct {
    int num_disks;
    int *disks;
} tower;

tower towers[NUM_TOWERS];

void init_towers() {
    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].num_disks = 0;
        towers[i].disks = malloc(sizeof(int) * NUM_DISKS);
    }
}

void free_towers() {
    for (int i = 0; i < NUM_TOWERS; i++) {
        free(towers[i].disks);
    }
}

void move_disk(int from_tower, int to_tower) {
    int disk = towers[from_tower].disks[towers[from_tower].num_disks - 1];
    towers[from_tower].num_disks--;
    towers[to_tower].num_disks++;
    towers[to_tower].disks[towers[to_tower].num_disks - 1] = disk;
}

void print_towers() {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
    printf("\n");
}

void hanoi(int n, int from_tower, int to_tower, int aux_tower) {
    if (n == 1) {
        move_disk(from_tower, to_tower);
        return;
    }
    hanoi(n - 1, from_tower, aux_tower, to_tower);
    move_disk(from_tower, to_tower);
    hanoi(n - 1, aux_tower, to_tower, from_tower);
}

int main() {
    init_towers();

    // Initialize the towers with disks.
    for (int i = NUM_DISKS; i > 0; i--) {
        towers[0].disks[towers[0].num_disks++] = i;
    }

    // Print the initial state of the towers.
    print_towers();

    // Solve the Tower of Hanoi problem.
    hanoi(NUM_DISKS, 0, 2, 1);

    // Print the final state of the towers.
    print_towers();

    free_towers();

    return 0;
}