//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 100
#define MAX_RODS 3

typedef struct {
    int num_disks;
    int rods[MAX_RODS];
    int moves;
} Tower;

void init_tower(Tower *tower, int num_disks) {
    tower->num_disks = num_disks;
    for (int i = 0; i < MAX_RODS; i++) {
        tower->rods[i] = 0;
    }
    tower->rods[0] = num_disks;
    tower->moves = 0;
}

void print_tower(Tower *tower) {
    for (int i = 0; i < MAX_RODS; i++) {
        printf("Rod %d: ", i + 1);
        for (int j = 0; j < tower->rods[i]; j++) {
            printf("O ");
        }
        printf("\n");
    }
    printf("Moves: %d\n", tower->moves);
}

int move_disk(Tower *tower, int src_rod, int dst_rod) {
    if (tower->rods[src_rod] == 0) {
        printf("Error: No disk on source rod.\n");
        return -1;
    }
    if (tower->rods[dst_rod] > 0 && tower->rods[src_rod] > tower->rods[dst_rod]) {
        printf("Error: Cannot move a larger disk onto a smaller disk.\n");
        return -1;
    }
    tower->rods[dst_rod]++;
    tower->rods[src_rod]--;
    tower->moves++;
    return 0;
}

int solve_tower(Tower *tower, int num_disks, int src_rod, int dst_rod, int tmp_rod) {
    if (num_disks == 1) {
        return move_disk(tower, src_rod, dst_rod);
    }
    int ret = solve_tower(tower, num_disks - 1, src_rod, tmp_rod, dst_rod);
    if (ret < 0) {
        return ret;
    }
    ret = move_disk(tower, src_rod, dst_rod);
    if (ret < 0) {
        return ret;
    }
    ret = solve_tower(tower, num_disks - 1, tmp_rod, dst_rod, src_rod);
    if (ret < 0) {
        return ret;
    }
    return 0;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <num_disks>\n", argv[0]);
        return -1;
    }
    int num_disks = atoi(argv[1]);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Error: Invalid number of disks (%d).\n", num_disks);
        return -1;
    }
    Tower tower;
    init_tower(&tower, num_disks);
    print_tower(&tower);
    int ret = solve_tower(&tower, num_disks, 0, 2, 1);
    if (ret < 0) {
        printf("Error: Failed to solve tower.\n");
        return -1;
    }
    print_tower(&tower);
    return 0;
}