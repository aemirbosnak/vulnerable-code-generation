//Falcon-180B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define MAX_DISKS 10

typedef struct {
    int num_disks;
    int moves;
    int depth;
    int time;
} Tower;

Tower* create_tower(int num_disks) {
    Tower* tower = malloc(sizeof(Tower));
    tower->num_disks = num_disks;
    tower->moves = 0;
    tower->depth = 0;
    tower->time = time(NULL);
    return tower;
}

void print_tower(Tower* tower) {
    int i;
    printf("Num Disks: %d\n", tower->num_disks);
    printf("Moves: %d\n", tower->moves);
    printf("Depth: %d\n", tower->depth);
    printf("Time: %ld\n", tower->time);
}

void move_disk(Tower* tower, int from, int to) {
    if (tower->num_disks == 1) {
        printf("Move disk from %d to %d\n", from, to);
        return;
    }
    move_disk(tower, from, 6 - from - to);
    move_disk(tower, 6 - from - to, to);
    tower->moves++;
}

int main() {
    int num_disks;
    printf("Enter the number of disks: ");
    scanf("%d", &num_disks);

    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks.\n");
        return 1;
    }

    Tower* tower = create_tower(num_disks);
    printf("Initial tower:\n");
    print_tower(tower);

    move_disk(tower, 0, 6);

    printf("\nFinal tower:\n");
    print_tower(tower);

    free(tower);
    return 0;
}