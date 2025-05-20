//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_DISKS 10
#define MAX_STEPS ((1 << MAX_DISKS) - 1)
#define HIST_SIZE 1024

typedef enum { RED, GREEN, BLUE } color_t;

typedef struct {
    color_t color;
    int size;
} disk_t;

typedef struct {
    disk_t *disks;
    int count;
} tower_t;

tower_t towers[3];
int num_disks;
int num_steps;
int history[HIST_SIZE];

void init_towers(void) {
    for (int i = 0; i < 3; ++i) {
        towers[i].count = 0;
        towers[i].disks = malloc(sizeof(disk_t) * MAX_DISKS);
    }
    num_disks = 0;
    num_steps = 0;
}

void cleanup_towers(void) {
    for (int i = 0; i < 3; ++i) {
        free(towers[i].disks);
    }
}

void add_disk(tower_t *tower, color_t color, int size) {
    tower->disks[tower->count].color = color;
    tower->disks[tower->count].size = size;
    tower->count++;
}

void print_tower(tower_t *tower) {
    for (int i = 0; i < tower->count; ++i) {
        printf("%c%d ", tower->disks[i].color, tower->disks[i].size);
    }
    printf("\n");
}

void print_towers(void) {
    for (int i = 0; i < 3; ++i) {
        printf("Tower %d: ", i + 1);
        print_tower(&towers[i]);
    }
}

bool move_disk(tower_t *from_tower, tower_t *to_tower) {
    if (from_tower->count == 0) {
        return false;
    }
    if (to_tower->count > 0 && from_tower->disks[from_tower->count - 1].size > to_tower->disks[to_tower->count - 1].size) {
        return false;
    }
    to_tower->disks[to_tower->count] = from_tower->disks[from_tower->count - 1];
    to_tower->count++;
    from_tower->count--;
    return true;
}

bool solve_toh(int disks, tower_t *from_tower, tower_t *to_tower, tower_t *aux_tower) {
    if (disks == 0) {
        return true;
    }
    if (solve_toh(disks - 1, from_tower, aux_tower, to_tower)) {
        move_disk(from_tower, to_tower);
        history[num_steps++] = (num_disks << 4) | (from_tower - towers) | ((to_tower - towers) << 2);
        if (solve_toh(disks - 1, aux_tower, to_tower, from_tower)) {
            return true;
        }
    }
    return false;
}

void print_history(void) {
    for (int i = 0; i < num_steps; ++i) {
        int from = (history[i] & 3);
        int to = (history[i] >> 2) & 3;
        int num_color = history[i] >> 4;
        printf("%d -> %d (%d)\n", from + 1, to + 1, num_color + 1);
    }
}

int main(int argc, char **argv) {
    int i, num_colors;
    disk_t disks[MAX_DISKS];

    init_towers();

    if (argc < 2) {
        fprintf(stderr, "Usage: %s num_disks num_colors\n", argv[0]);
        return 1;
    }
    num_disks = atoi(argv[1]);
    if (num_disks > MAX_DISKS) {
        fprintf(stderr, "Number of disks must be less than or equal to %d\n", MAX_DISKS);
        return 1;
    }
    if (argc < 3) {
        num_colors = 1;
    } else {
        num_colors = atoi(argv[2]);
        if (num_colors > 3) {
            fprintf(stderr, "Number of colors must be less than or equal to 3\n");
            return 1;
        }
    }

    for (i = num_disks - 1; i >= 0; --i) {
        disks[i].color = rand() % num_colors;
        disks[i].size = i + 1;
        add_disk(&towers[0], disks[i].color, disks[i].size);
    }

    print_towers();
    if (!solve_toh(num_disks, &towers[0], &towers[2], &towers[1])) {
        fprintf(stderr, "Unable to solve Tower of Hanoi problem\n");
        return 1;
    }
    print_history();
    cleanup_towers();

    return 0;
}