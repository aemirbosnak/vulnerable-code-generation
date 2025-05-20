//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    int num_disks;
    int *disks;
} Tower;

Tower* create_tower(int num_disks) {
    Tower* tower = (Tower*)malloc(sizeof(Tower));
    tower->num_disks = num_disks;
    tower->disks = (int*)malloc(num_disks * sizeof(int));
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i] = i + 1;
    }
    return tower;
}

void destroy_tower(Tower* tower) {
    free(tower->disks);
    free(tower);
}

void print_tower(Tower* tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disks[i]);
    }
    printf("\n");
}

void move_disk(Tower* tower, int num_moves, int from, int to, int aux) {
    if (num_moves == 1) {
        tower->disks[to] = tower->disks[from];
        tower->disks[from] = 0;
    } else {
        move_disk(tower, num_moves - 1, from, aux, to);
        tower->disks[to] = tower->disks[from];
        tower->disks[from] = 0;
        move_disk(tower, num_moves - 1, aux, to, from);
    }
}

int main() {
    srand(time(NULL));
    int num_disks = rand() % 10 + 1;
    Tower* tower = create_tower(num_disks);
    printf("Initial tower:\n");
    print_tower(tower);
    int num_moves = num_disks * 2 - 1;
    int from = 0;
    int to = 2;
    int aux = 1;
    move_disk(tower, num_moves, from, to, aux);
    printf("Final tower:\n");
    print_tower(tower);
    destroy_tower(tower);
    return 0;
}