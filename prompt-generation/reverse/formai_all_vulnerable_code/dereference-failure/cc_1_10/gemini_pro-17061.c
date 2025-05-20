//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_TOWERS 3
#define NUM_DISKS 8

typedef struct {
    int num_disks;
    int *disks;
} tower;

void init_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        towers[i].num_disks = 0;
        towers[i].disks = NULL;
    }
}

void free_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        free(towers[i].disks);
    }
}

void print_towers(tower *towers) {
    for (int i = 0; i < NUM_TOWERS; i++) {
        printf("Tower %d: ", i + 1);
        for (int j = 0; j < towers[i].num_disks; j++) {
            printf("%d ", towers[i].disks[j]);
        }
        printf("\n");
    }
}

int get_smallest_disk(tower *towers) {
    int smallest_disk = -1;
    int smallest_disk_tower = -1;
    for (int i = 0; i < NUM_TOWERS; i++) {
        if (towers[i].num_disks > 0) {
            if (smallest_disk == -1 || towers[i].disks[towers[i].num_disks - 1] < smallest_disk) {
                smallest_disk = towers[i].disks[towers[i].num_disks - 1];
                smallest_disk_tower = i;
            }
        }
    }
    return smallest_disk_tower;
}

int get_largest_disk(tower *towers) {
    int largest_disk = -1;
    int largest_disk_tower = -1;
    for (int i = 0; i < NUM_TOWERS; i++) {
        if (towers[i].num_disks > 0) {
            if (largest_disk == -1 || towers[i].disks[towers[i].num_disks - 1] > largest_disk) {
                largest_disk = towers[i].disks[towers[i].num_disks - 1];
                largest_disk_tower = i;
            }
        }
    }
    return largest_disk_tower;
}

int get_middle_disk(tower *towers) {
    int smallest_disk = get_smallest_disk(towers);
    int largest_disk = get_largest_disk(towers);
    for (int i = 0; i < NUM_TOWERS; i++) {
        if (towers[i].num_disks > 0 && towers[i].disks[towers[i].num_disks - 1] > smallest_disk && towers[i].disks[towers[i].num_disks - 1] < largest_disk) {
            return i;
        }
    }
    return -1;
}

void move_disk(tower *towers, int from_tower, int to_tower) {
    int disk = towers[from_tower].disks[towers[from_tower].num_disks - 1];
    towers[from_tower].num_disks--;
    towers[to_tower].num_disks++;
    towers[to_tower].disks = realloc(towers[to_tower].disks, towers[to_tower].num_disks * sizeof(int));
    towers[to_tower].disks[towers[to_tower].num_disks - 1] = disk;
}

void solve_tower_of_hanoi(tower *towers, int num_disks) {
    if (num_disks == 1) {
        move_disk(towers, get_smallest_disk(towers), get_largest_disk(towers));
        return;
    }

    int smallest_disk_tower = get_smallest_disk(towers);
    int largest_disk_tower = get_largest_disk(towers);
    int middle_disk_tower = get_middle_disk(towers);

    solve_tower_of_hanoi(towers, num_disks - 1);

    move_disk(towers, smallest_disk_tower, middle_disk_tower);

    solve_tower_of_hanoi(towers, num_disks - 1);

    move_disk(towers, largest_disk_tower, middle_disk_tower);

    solve_tower_of_hanoi(towers, num_disks - 1);
}

int main() {
    srand(time(NULL));

    tower towers[NUM_TOWERS];
    init_towers(towers);

    for (int i = 0; i < NUM_DISKS; i++) {
        int disk = rand() % 100 + 1;
        int tower = rand() % NUM_TOWERS;
        towers[tower].num_disks++;
        towers[tower].disks = realloc(towers[tower].disks, towers[tower].num_disks * sizeof(int));
        towers[tower].disks[towers[tower].num_disks - 1] = disk;
    }

    print_towers(towers);

    solve_tower_of_hanoi(towers, NUM_DISKS);

    print_towers(towers);

    free_towers(towers);

    return 0;
}