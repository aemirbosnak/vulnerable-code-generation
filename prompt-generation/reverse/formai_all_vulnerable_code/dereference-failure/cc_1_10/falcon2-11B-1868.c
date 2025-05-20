//Falcon2-11B DATASET v1.0 Category: Tower of Hanoi Problem ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DISKS 1000
#define MIN_DISK_SIZE 1
#define MAX_PEGS 3
#define DISK_SIZE(i) ((i + 1) * (i + 1))

typedef struct disk_state_t {
    int size;
    int peg;
    int move_peg;
    int move_peg_disk;
    struct disk_state_t* next;
} disk_state_t;

disk_state_t* new_disk_state(int size, int peg, int move_peg, int move_peg_disk) {
    disk_state_t* state = (disk_state_t*)malloc(sizeof(disk_state_t));
    state->size = size;
    state->peg = peg;
    state->move_peg = move_peg;
    state->move_peg_disk = move_peg_disk;
    state->next = NULL;
    return state;
}

void free_disk_state(disk_state_t* state) {
    if (state == NULL) {
        return;
    }
    free_disk_state(state->next);
    free(state);
}

int main() {
    int num_disks = 10;
    int num_pegs = 3;
    int move_peg = 0;
    int move_peg_disk = 1;

    clock_t start_time = clock();

    disk_state_t* root_state = new_disk_state(num_disks, move_peg, move_peg_disk, 0);
    root_state->next = NULL;

    int num_moves = 0;
    while (num_moves < num_disks * num_pegs) {
        int peg1 = move_peg;
        int peg2 = move_peg_disk;
        int peg3 = move_peg_disk + 1;

        if (peg1 == peg2 && peg1 == peg3) {
            continue;
        }

        if (peg1 == peg3) {
            if (peg2 == move_peg) {
                move_peg = peg2;
                move_peg_disk = peg2 + 1;
            } else if (peg2 == move_peg_disk) {
                move_peg_disk = peg2 + 1;
            } else {
                move_peg_disk = peg2;
            }
        } else if (peg1 == peg2) {
            if (peg3 == move_peg) {
                move_peg = peg3;
                move_peg_disk = peg3 + 1;
            } else if (peg3 == move_peg_disk) {
                move_peg_disk = peg3 + 1;
            } else {
                move_peg_disk = peg3;
            }
        } else {
            disk_state_t* disk = new_disk_state(num_disks, move_peg, move_peg_disk, 0);
            disk->next = root_state->next;
            root_state->next = disk;
        }

        num_moves++;
    }

    int num_moves_taken = num_moves;
    free_disk_state(root_state);

    clock_t end_time = clock();
    double time_taken = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Number of moves taken: %d\n", num_moves_taken);
    printf("Time taken: %.3f seconds\n", time_taken);

    return 0;
}