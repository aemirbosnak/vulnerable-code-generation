//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 100

typedef struct {
    int num_disks;
    int* disks;
} Tower;

void init_tower(Tower* tower, int num_disks) {
    tower->num_disks = num_disks;
    tower->disks = malloc(num_disks * sizeof(int));
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = i;
    }
}

void print_tower(Tower* tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

void move_disk(Tower* from_tower, Tower* to_tower, int num_disks, int num_moves) {
    if (num_disks == 1) {
        to_tower->disks[0] = from_tower->disks[0];
        print_tower(from_tower);
        print_tower(to_tower);
        printf("Move disk 1 from %d to %d\n", from_tower->disks[0], to_tower->disks[0]);
        return;
    }

    int num_moves_left = num_moves - 1;
    int num_disks_left = num_disks - 1;

    Tower temp_tower;
    init_tower(&temp_tower, num_disks);

    for (int i = 0; i < num_disks; i++) {
        if (i!= num_disks - 1) {
            move_disk(from_tower, &temp_tower, num_disks_left, num_moves_left);
        } else {
            move_disk(&temp_tower, to_tower, num_disks_left, num_moves_left);
        }
    }
}

int main() {
    Tower from_tower, to_tower;
    init_tower(&from_tower, 3);
    init_tower(&to_tower, 0);
    move_disk(&from_tower, &to_tower, 3, 7);

    return 0;
}