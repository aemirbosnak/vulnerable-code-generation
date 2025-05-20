//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>

#define MAX_TOWER_ROWS 3
#define MAX_TOWER_DISKS 3

typedef struct {
    int rows[MAX_TOWER_ROWS];
    int disks[MAX_TOWER_DISKS];
} Tower;

Tower towers[MAX_TOWER_ROWS];

void move_disk(Tower *source, int from_rod, int to_rod, int disk) {
    // Get the source tower and the rods to be moved
    Tower *tower = &towers[source->rows[from_rod]];
    int from_rod_start = tower->disks[from_rod];
    int to_rod_start = tower->disks[to_rod];

    // Move the disk from the source rod to the target rod
    tower->disks[from_rod] = to_rod_start;
    tower->disks[to_rod] = from_rod_start;
}

void print_tower(Tower *tower) {
    int i;
    for (i = 0; i < tower->rows; i++) {
        printf("%d: ", i);
        for (int j = 0; j < tower->disks[i]; j++) {
            printf(" * ");
        }
        printf("\n");
    }
    printf("\n");
}

void hanoi_tower(int tower, int from_rod, int to_rod, int num_disks) {
    if (num_disks > 0) {
        hanoi_tower(tower, from_rod, tower + 1, num_disks - 1);
        move_disk(&towers[tower], from_rod, to_rod, 0);
        hanoi_tower(tower, tower + 1, to_rod, num_disks - 1);
    }
}

int main() {
    int num_towers = 3;
    int num_disks = 5;

    // Create towers
    for (int i = 0; i < num_towers; i++) {
        towers[i].rows[i] = i;
        towers[i].disks[i] = num_disks;
    }

    // Print initial state of towers
    print_tower(&towers[0]);

    // Move all disks to the destination tower
    hanoi_tower(0, 0, 1, num_disks);

    // Print final state of towers
    print_tower(&towers[0]);

    return 0;
}