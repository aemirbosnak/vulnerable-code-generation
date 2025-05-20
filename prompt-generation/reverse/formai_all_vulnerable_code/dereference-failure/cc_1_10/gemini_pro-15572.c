//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

typedef enum {
    LEFT,
    MIDDLE,
    RIGHT,
    NUM_PEGS
} peg_t;

typedef struct {
    peg_t peg;
    int size;
} disk_t;

typedef struct {
    disk_t *disks;
    int num_disks;
} tower_t;

tower_t *create_tower(int num_disks) {
    tower_t *tower = malloc(sizeof(tower_t));
    tower->num_disks = num_disks;
    tower->disks = malloc(sizeof(disk_t) * num_disks);
    for (int i = 0; i < num_disks; i++) {
        tower->disks[i].size = num_disks - i;
        tower->disks[i].peg = LEFT;
    }
    return tower;
}

void free_tower(tower_t *tower) {
    free(tower->disks);
    free(tower);
}

void move_disk(tower_t *tower, peg_t from, peg_t to) {
    for (int i = 0; i < tower->num_disks; i++) {
        if (tower->disks[i].peg == from) {
            tower->disks[i].peg = to;
            break;
        }
    }
}

void print_tower(tower_t *tower) {
    for (int i = 0; i < tower->num_disks; i++) {
        printf("%d ", tower->disks[i].size);
    }
    printf("\n");
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <number of disks>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_disks = atoi(argv[1]);
    tower_t *tower = create_tower(num_disks);

    print_tower(tower);

    for (int i = 0; i < num_disks; i++) {
        move_disk(tower, LEFT, MIDDLE);
        print_tower(tower);
        move_disk(tower, LEFT, RIGHT);
        print_tower(tower);
        move_disk(tower, MIDDLE, RIGHT);
        print_tower(tower);
    }

    free_tower(tower);

    return EXIT_SUCCESS;
}