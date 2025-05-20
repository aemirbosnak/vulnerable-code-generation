//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 64

typedef struct {
    int top;
    int capacity;
    int *disks;
} Tower;

void create_tower(Tower *tower, int capacity) {
    tower->top = -1;
    tower->capacity = capacity;
    tower->disks = (int *)malloc(capacity * sizeof(int));
}

void destroy_tower(Tower *tower) {
    free(tower->disks);
}

void push_disk(Tower *tower, int disk) {
    if (tower->top >= tower->capacity - 1) {
        printf("Tower is full\n");
        return;
    }
    tower->disks[++tower->top] = disk;
}

int pop_disk(Tower *tower) {
    if (tower->top < 0) {
        printf("Tower is empty\n");
        return -1;
    }
    return tower->disks[tower->top--];
}

void move_disk(Tower *from_tower, Tower *to_tower, int num_disks) {
    if (num_disks <= 0)
        return;
    if (from_tower->top < 0 || to_tower->top >= to_tower->capacity - 1) {
        printf("Invalid move\n");
        return;
    }
    for (int i = num_disks; i > 0; i--) {
        int disk = pop_disk(from_tower);
        push_disk(to_tower, disk);
    }
}

void print_tower(Tower *tower) {
    for (int i = tower->top; i >= 0; i--)
        printf("%d ", tower->disks[i]);
    printf("\n");
}

int main() {
    Tower from_tower, to_tower, aux_tower;
    create_tower(&from_tower, MAX_DISKS);
    create_tower(&to_tower, MAX_DISKS);
    create_tower(&aux_tower, MAX_DISKS);

    int num_disks = 5;
    for (int i = num_disks; i > 0; i--)
        push_disk(&from_tower, i);

    print_tower(&from_tower);

    move_disk(&from_tower, &to_tower, num_disks);

    print_tower(&from_tower);
    print_tower(&to_tower);

    destroy_tower(&from_tower);
    destroy_tower(&to_tower);
    destroy_tower(&aux_tower);

    return 0;
}