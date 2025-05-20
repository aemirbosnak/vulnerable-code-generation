//MISTRAL-7B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

typedef struct rod {
    int name;
    int top;
} rod;

void print_rods(rod rods[], int num_disks) {
    int i;
    for (i = 0; i < 3; i++) {
        printf("Rod %d: ", i + 1);
        if (rods[i].top == -1) {
            printf("Empty\n");
        } else {
            printf("Disk %d\n", rods[i].top);
        }
    }
}

void move_disk(int from_rod, int to_rod, rod rods[]) {
    if (rods[from_rod].top >= 0) {
        rods[to_rod].top = rods[from_rod].top;
        rods[from_rod].top = -1;

        printf("Move disk %d from rod %d to rod %d\n", rods[from_rod].top, from_rod + 1, to_rod + 1);
    } else {
        printf("Error: Cannot move empty rod\n");
    }
}

void hanoi(int num_disks, int from_rod, int to_rod, int aux_rod, rod rods[]) {
    if (num_disks <= 0) {
        return;
    }

    hanoi(num_disks - 1, from_rod, aux_rod, to_rod, rods);
    move_disk(from_rod, to_rod, rods);
    hanoi(num_disks - 1, aux_rod, to_rod, from_rod, rods);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <number_of_disks>\n", argv[0]);
        return 1;
    }

    int num_disks = atoi(argv[1]);

    if (num_disks <= 0) {
        printf("Error: Invalid number of disks\n");
        return 1;
    }

    rod rods[3];
    for (int i = 0; i < 3; i++) {
        rods[i].name = i;
        rods[i].top = -1;
    }

    printf("Initial configuration:\n");
    print_rods(rods, num_disks);

    srand(time(NULL));
    int from_rod = rand() % 3;
    int to_rod = (from_rod + 1) % 3;
    int aux_rod = (from_rod + 2) % 3;

    hanoi(num_disks, from_rod, aux_rod, to_rod, rods);

    printf("Final configuration:\n");
    print_rods(rods, num_disks);

    return 0;
}