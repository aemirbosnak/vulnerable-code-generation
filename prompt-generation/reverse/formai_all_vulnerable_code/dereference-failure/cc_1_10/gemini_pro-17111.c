//GEMINI-pro DATASET v1.0 Category: Tower of Hanoi Problem ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DISKS 10

static int num_moves;

typedef struct {
    int num_disks;
    int *disks;
} tower;

void print_tower(tower *t) {
    for (int i = 0; i < t->num_disks; i++) {
        printf("%d ", t->disks[i]);
    }
    printf("\n");
}

void move_disk(tower *from, tower *to) {
    int disk = from->disks[from->num_disks - 1];
    from->num_disks--;
    to->disks[to->num_disks++] = disk;
    num_moves++;
}

void solve_tower(tower *from, tower *to, tower *aux) {
    if (from->num_disks == 1) {
        move_disk(from, to);
        return;
    }
    solve_tower(from, aux, to);
    move_disk(from, to);
    solve_tower(aux, to, from);
}

int main(int argc, char **argv) {
    int num_disks;
    if (argc != 2) {
        printf("Usage: %s <num_disks>\n", argv[0]);
        return 1;
    }
    num_disks = atoi(argv[1]);
    if (num_disks < 1 || num_disks > MAX_DISKS) {
        printf("Invalid number of disks: %d\n", num_disks);
        return 1;
    }
    tower from, to, aux;
    from.num_disks = num_disks;
    to.num_disks = 0;
    aux.num_disks = 0;
    from.disks = malloc(num_disks * sizeof(int));
    to.disks = malloc(num_disks * sizeof(int));
    aux.disks = malloc(num_disks * sizeof(int));
    for (int i = 0; i < num_disks; i++) {
        from.disks[i] = num_disks - i;
        to.disks[i] = 0;
        aux.disks[i] = 0;
    }
    printf("Initial state:\n");
    print_tower(&from);
    print_tower(&to);
    print_tower(&aux);
    num_moves = 0;
    solve_tower(&from, &to, &aux);
    printf("\nFinal state:\n");
    print_tower(&from);
    print_tower(&to);
    print_tower(&aux);
    printf("\nNumber of moves: %d\n", num_moves);
    free(from.disks);
    free(to.disks);
    free(aux.disks);
    return 0;
}