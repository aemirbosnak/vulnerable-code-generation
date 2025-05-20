//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int *tower_state;
} Tower;

void print_tower(Tower *tower) {
    int i;
    for (i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->tower_state[i]);
    }
    printf("\n");
}

void move_disk(Tower *tower, int from, int to) {
    int i;
    for (i = tower->num_disks - 1; i >= from; i--) {
        tower->tower_state[i + 1] = tower->tower_state[i];
    }
    tower->tower_state[to] = tower->tower_state[from];
}

void hanoi(Tower *tower, int num_disks, int from, int to, int aux) {
    if (num_disks == 1) {
        move_disk(tower, from, to);
        return;
    }
    hanoi(tower, num_disks - 1, from, aux, to);
    move_disk(tower, from, to);
    hanoi(tower, num_disks - 1, aux, to, from);
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }
    srand(time(NULL));
    Tower tower;
    tower.num_disks = num_disks;
    tower.tower_state = (int *)malloc(num_disks * sizeof(int));
    int i;
    for (i = 0; i < num_disks; i++) {
        tower.tower_state[i] = i + 1;
    }
    printf("Initial state:\n");
    print_tower(&tower);
    int from = 0, to = num_disks - 1, aux = (num_disks - 1) / 2;
    hanoi(&tower, num_disks, from, to, aux);
    printf("Final state:\n");
    print_tower(&tower);
    free(tower.tower_state);
    return 0;
}