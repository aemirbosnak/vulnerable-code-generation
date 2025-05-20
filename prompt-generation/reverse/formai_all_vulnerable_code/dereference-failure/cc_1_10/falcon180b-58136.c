//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 20

typedef struct {
    int num_disks;
    int top;
    int *towers;
} Tower;

Tower *create_tower(int num_disks) {
    Tower *tower = (Tower *) malloc(sizeof(Tower));
    tower->num_disks = num_disks;
    tower->top = 0;
    tower->towers = (int *) malloc(sizeof(int) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        tower->towers[i] = -1;
    }
    return tower;
}

void destroy_tower(Tower *tower) {
    free(tower->towers);
    free(tower);
}

void move_disk(Tower *tower, int from, int to) {
    if (from < 0 || from >= tower->num_disks || to < 0 || to >= tower->num_disks) {
        printf("Invalid move\n");
        return;
    }
    if (from == to) {
        return;
    }
    if (from < to) {
        for (int i = from + 1; i <= to - 1; i++) {
            move_disk(tower, i, i + 1);
        }
        move_disk(tower, from, to);
    } else {
        for (int i = from - 1; i >= to + 1; i--) {
            move_disk(tower, i, i - 1);
        }
        move_disk(tower, from, to);
    }
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks\n");
        return 1;
    }
    Tower *tower = create_tower(num_disks);
    int from_tower, to_tower;
    printf("Enter the starting tower: ");
    scanf("%d", &from_tower);
    printf("Enter the ending tower: ");
    scanf("%d", &to_tower);
    if (from_tower < 0 || from_tower >= 3 || to_tower < 0 || to_tower >= 3) {
        printf("Invalid towers\n");
        return 1;
    }
    move_disk(tower, from_tower, to_tower);
    destroy_tower(tower);
    return 0;
}