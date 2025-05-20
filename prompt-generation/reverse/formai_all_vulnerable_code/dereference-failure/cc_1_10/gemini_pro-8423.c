//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define NUM_TOWERS 3
#define NUM_DISKS 5

typedef struct disk {
    int size;
    struct disk *next;
} disk_t;

typedef struct tower {
    disk_t *disks;
    int num_disks;
} tower_t;

void print_towers(tower_t *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        disk_t *disk = towers[i].disks;
        while (disk) {
            printf("%d ", disk->size);
            disk = disk->next;
        }
        printf("\n");
    }
}

void move_disk(tower_t *towers, int from, int to) {
    disk_t *disk = towers[from].disks;
    if (disk) {
        towers[from].disks = disk->next;
        disk->next = towers[to].disks;
        towers[to].disks = disk;
        towers[to].num_disks++;
        towers[from].num_disks--;
    }
}

void solve_hanoi(tower_t *towers, int n, int from, int to, int via) {
    if (n == 1) {
        move_disk(towers, from, to);
    } else {
        solve_hanoi(towers, n - 1, from, via, to);
        move_disk(towers, from, to);
        solve_hanoi(towers, n - 1, via, to, from);
    }
}

int main() {
    tower_t towers[NUM_TOWERS];

    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].disks = NULL;
        towers[i].num_disks = 0;
    }

    for (int i = NUM_DISKS; i > 0; i--) {
        disk_t *disk = malloc(sizeof(disk_t));
        disk->size = i;
        disk->next = towers[0].disks;
        towers[0].disks = disk;
        towers[0].num_disks++;
    }

    print_towers(towers);

    solve_hanoi(towers, NUM_DISKS, 0, 2, 1);

    print_towers(towers);

    return 0;
}