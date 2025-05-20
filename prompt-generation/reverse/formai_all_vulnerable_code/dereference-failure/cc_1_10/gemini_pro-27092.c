//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOWER_HEIGHT 5

typedef struct Tower {
    int disks;
    int *disk_sizes;
} Tower;

Tower towers[3];

void initialize_towers() {
    towers[0].disks = TOWER_HEIGHT;
    towers[0].disk_sizes = malloc(TOWER_HEIGHT * sizeof(int));
    for (int i = 0; i < TOWER_HEIGHT; i++) {
        towers[0].disk_sizes[i] = TOWER_HEIGHT - i;
    }

    towers[1].disks = 0;
    towers[1].disk_sizes = NULL;

    towers[2].disks = 0;
    towers[2].disk_sizes = NULL;
}

void print_towers() {
    for (int i = 0; i < 3; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].disks; j++) {
            printf("%d ", towers[i].disk_sizes[j]);
        }
        printf("\n");
    }
}

void move_disk(int from, int to) {
    if (towers[from].disks == 0) {
        printf("Error: Trying to move a disk from an empty tower.\n");
        return;
    }

    if (towers[to].disks > 0 && towers[to].disk_sizes[towers[to].disks - 1] < towers[from].disk_sizes[towers[from].disks - 1]) {
        printf("Error: Trying to move a larger disk onto a smaller disk.\n");
        return;
    }

    towers[to].disk_sizes[towers[to].disks++] = towers[from].disk_sizes[--towers[from].disks];
}

void solve_towers(int n, int from, int to, int via) {
    if (n == 1) {
        move_disk(from, to);
        return;
    }

    solve_towers(n - 1, from, via, to);
    move_disk(from, to);
    solve_towers(n - 1, via, to, from);
}

int main() {
    srand(time(NULL));

    initialize_towers();
    print_towers();

    solve_towers(TOWER_HEIGHT, 0, 2, 1);

    print_towers();

    return 0;
}