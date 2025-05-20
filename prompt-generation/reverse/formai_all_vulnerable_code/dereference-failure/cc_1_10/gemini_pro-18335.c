//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX_DISKS 7
typedef struct {
    int num_disks;
    int from;
    int to;
    int via;
} move_t;

static int num_moves = 0;

static void print_move(move_t move) {
    printf("Move disk %d from peg %d to peg %d\n",
           move.num_disks, move.from, move.to);
}

static void tower_of_hanoi(int num_disks, int from, int to, int via) {
    if (num_disks == 1) {
        move_t move = { .num_disks = num_disks, .from = from, .to = to, .via = via };
        print_move(move);
        num_moves++;
    } else {
        tower_of_hanoi(num_disks - 1, from, via, to);

        move_t move = { .num_disks = num_disks, .from = from, .to = to, .via = via };
        print_move(move);
        num_moves++;

        tower_of_hanoi(num_disks - 1, via, to, from);
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s num_disks\n", argv[0]);
        return EXIT_FAILURE;
    }

    int num_disks = atoi(argv[1]);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        fprintf(stderr, "Invalid number of disks: %d\n", num_disks);
        return EXIT_FAILURE;
    }

    tower_of_hanoi(num_disks, 1, 3, 2);

    printf("Number of moves: %d\n", num_moves);

    return EXIT_SUCCESS;
}